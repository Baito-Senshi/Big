#include <windows.h>
#include <direct.h>
#include <iostream>
#include <string>

#define GCC_ERROR(str)\
do \
{\
static Logger::ErrorMessenger* pErrorMessenger = \
GCC_NEW Logger::ErrorMessenger; \
std::string s((str)); \
pErrorMessenger->Show(s, false, __FUNCTION__, __FILE__, __LINE__); \
}\
while (0)\

#define GCC_ERROR(str) do { (void)sizeof(str); } while (0)
#if defined _DEBUG
static int counter = 0;
#define GCC_NEW new(_NORMAL_BLOCK,__FILE__, counter++)
#endif

bool IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS)
	{
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd)
		{
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			std::cout << "Instance already running." << '\n';
			return false;
		}
	}
	std::cout << "Only this instance is running." << '\n';
	return true;
}

bool CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		GCC_ERROR("CheckStorage Failure : Not enough physical storage.");
		std::cout << "You do not have " << diskSpaceNeeded / 1000000 << " MB of space available." << '\n';
		return false;
	}
	std::cout << "You have enough space available." << '\n';
	return true;
}

bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded)
	{
		GCC_ERROR("CheckMemory Failure : Not enough physical memory.");
		std::cout << "You do not have enough physical memory." << '\n';
		return false;
	}
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		GCC_ERROR("CheckMemory Failure : Not enough virtual memory.");
		std::cout << "You do not have enough virtual memory." << '\n';
		return false;
	}

	char *buff = GCC_NEW char[virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else
	{
		GCC_ERROR("CheckMemory Failure : Not enough contiguous memory.");
		std::cout << "You do not have enough contiguous memory." << '\n';
		return false;
	}
	std::cout << "You have enough memory." << '\n';
	std::cout << "You have " << status.ullAvailVirtual / 1000000 << " MB of virtual memory." << '\n';
	return true;
}

DWORD ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}
	std::cout << "Your speed CPU speed is: " << dwMHz << '\n';
	return dwMHz;
}

std::string ReadCPUArc()
{
	DWORD BufSize = sizeof(TCHAR) * 1000;
	TCHAR arch[1000];
	DWORD type = REG_SZ;
	HKEY hKey;
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "Identifier", NULL, &type, (LPBYTE)&arch, &BufSize);
	}
	std::cout << "Your architecture is: " << arch << '\n';
	return arch;
}

int main() 
{
	IsOnlyInstance("Source");
	CheckStorage(300000000);
	CheckMemory(44234,43340);
	ReadCPUSpeed();
	ReadCPUArc();
	return 0;
}