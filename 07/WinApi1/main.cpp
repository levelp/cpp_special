/// Получение информации о системе Windows
/// ======================================
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <tlhelp32.h>
#include "Lmcons.h"
#include "Toolhelp.h"
#include "fmtErr.h"

using namespace std;

string toOem(const string& ansiStr) {
  char* buf = (char*) _alloca(ansiStr.size() + 1);
  CharToOem(ansiStr.c_str(), buf);
  return string(buf);
}

// Получить имя текущего пользователя
string getUserName() {
  char userName[UNLEN + 1];
  DWORD size = sizeof(userName);
  // BOOL WINAPI GetUserName(
  //         _Out_   LPTSTR  lpBuffer,
  //         _Inout_ LPDWORD lpnSize
  // );
  if (!GetUserName(userName, &size))
    return string("<UNKNOWN>");
  return string(userName);
}

string getProcessorArchitectureStr(WORD pa) {
  switch (pa) {
    case PROCESSOR_ARCHITECTURE_INTEL:
      return string("INTEL");
    case PROCESSOR_ARCHITECTURE_MIPS:
      return string("MIPS");
    case PROCESSOR_ARCHITECTURE_ALPHA:
      return string("ALPHA");
    case PROCESSOR_ARCHITECTURE_PPC:
      return string("PPC");
    case PROCESSOR_ARCHITECTURE_IA64:
      return string("IA64");
    case PROCESSOR_ARCHITECTURE_AMD64:
      return string("AMD64");
    default:
      return string("UNKNOWN");
  };
}

string getLogicalDriveTypeStr(UINT lgType) {
  switch (lgType) {
    case DRIVE_REMOVABLE:
      return string("Diskette/Flash Drive");
    case DRIVE_FIXED:
      return string("HDD");
    case DRIVE_REMOTE:
      return string("Network drive");
    case DRIVE_CDROM:
      return string("CD/DVD-ROM");
    case DRIVE_RAMDISK:
      return string("RAM-Disk");
    case DRIVE_NO_ROOT_DIR:
      return string("Root path is invalid ", "(no volume is mounted)");
    default:
      return string("The drive type cannot be determined");
  }
}

string getWindowsDirectory() {
  char buf[MAX_PATH];
  GetWindowsDirectory(buf, MAX_PATH);
  return string(buf);
}

string getCurrentDirectory() {
  char ch = 0;
  char* buf = &ch;
  DWORD size = GetCurrentDirectory(1, buf);
  buf = (char*) _alloca(size);
  GetCurrentDirectory(size, buf);
  return string(buf);
}

DWORD getParentProcessId(DWORD pid /* child PID */) {
  CToolhelp th(TH32CS_SNAPPROCESS, 0);
  PROCESSENTRY32 pe = {sizeof(pe)};

  for (BOOL fProcOk = th.ProcessFirst(&pe);
       fProcOk;
       fProcOk = th.ProcessNext(&pe)) {
    if (pe.th32ProcessID == pid) return pe.th32ParentProcessID;
  }

  return 0;
}


int main(int argc, char* argv[]) {
  cout << "User name: " << getUserName() << "\n\n";
  // Получение информации о системе
  // VOID GetSystemInfo( // Получение информации о системе
  //         LPSYSTEM_INFO lpSystemInfo // system information - информация о системе [out]
  // );
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  cout << "System Information\n";
  cout << "      Processor Architecture: " << getProcessorArchitectureStr(si.wProcessorArchitecture) << "\n";
  cout << "      Level: " << si.wProcessorLevel;

  if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL) {
    if (si.wProcessorLevel > 4)
      cout << "   Model: " << ((si.wProcessorRevision >> 8) & 0xFF) << "   Stepping: " <<
           (si.wProcessorRevision & 0xFF) << "\n";
    else {
      WORD xx = (si.wProcessorRevision >> 8) & 0xFF;

      if (xx == 0xFF)
        cout << "   Model: " << ((si.wProcessorRevision >> 4) & 0x0F) << "   Stepping: " <<
             (si.wProcessorRevision & 0x0F) << "\n";
      else
        cout << "   Stepping: " << (char('A' + (si.wProcessorRevision >> 4) & 0x0F)) << "." <<
             (si.wProcessorRevision & 0x0F) << "\n";
    }
  } else
    cout << "   Revision: " << si.wProcessorRevision << "\n";

  cout << "      Page size: " << si.dwPageSize << " bytes\n";
  cout << std::uppercase << hex;
  cout << "      Minimum Application Address: " << setw(8) << setfill('0') << si.lpMinimumApplicationAddress <<
       "\n";
  cout << "      Maximum Application Address: " << setw(8) << setfill('0') << si.lpMaximumApplicationAddress <<
       "\n";
  cout << setw(0) << setfill(' ') << dec;
  // Количество ядер (процессоров)
  cout << "      Number of cores: " << si.dwNumberOfProcessors << "\n";
  cout << "      Active processors: ";
  bool first = true;

  for (int activeProcessor = 0; activeProcessor < 32; ++activeProcessor) {
    if (si.dwActiveProcessorMask & 1) {
      if (!first) cout << ", ";
      cout << "#" << activeProcessor + 1;
      first = false;
    }
    si.dwActiveProcessorMask >>= 1;
  }

  cout << "\n";
  cout << "      Allocation granularity: " << si.dwAllocationGranularity << "\n";

  cout << "\nLogical Drive Information\n";

  char DriveBuf[109];
  GetLogicalDriveStrings(108, DriveBuf);
  char driveNameBuf[4];
  WORD i = 0;

  while (DriveBuf[i * 4] != 0) {
    driveNameBuf[0] = DriveBuf[i * 4 + 0];
    driveNameBuf[1] = DriveBuf[i * 4 + 1];
    driveNameBuf[2] = DriveBuf[i * 4 + 2];
    driveNameBuf[3] = DriveBuf[i * 4 + 3];

    cout << driveNameBuf << " - " << getLogicalDriveTypeStr(GetDriveType(driveNameBuf));
    cout << "\n";

    char NameBuffer[MAX_PATH], SysNameBuffer[MAX_PATH];
    DWORD VSNumber, MCLength, FileSF;

    if (GetVolumeInformation(driveNameBuf, NameBuffer, sizeof(NameBuffer), &VSNumber, &MCLength, &FileSF,
                             SysNameBuffer, sizeof(SysNameBuffer))) {
      cout << "             Volume name: " << NameBuffer << "\n";
      cout << "        File system name: " << SysNameBuffer << "\n";
      cout << "    Volume serial number: " << VSNumber << "\n";
      cout << "Maximum file name length: " << MCLength << "\n";
    }
    i++;
  }

  cout << "\n";


  // Работа с каталогами
  cout << "Windows directory : " << toOem(getWindowsDirectory()) << "\n";
  cout << "Current directory : " << toOem(getCurrentDirectory()) << "\n";

  return 0;
}
