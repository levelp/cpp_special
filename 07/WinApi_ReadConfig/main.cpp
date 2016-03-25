#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <cstdio>

using namespace std;

// Вывод подробного сообщения об ошибке
// Retrieve and output the system error message for the last-error code
void DisplayError(LPCTSTR functionName) {
  // Код последней ошибки
  DWORD lastErrorCode = GetLastError();

  LPTSTR lpMsgBuf;
  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    lastErrorCode,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPSTR) &lpMsgBuf,
    0,
    NULL);

  _tprintf(TEXT("\"%s\" failed with error code %d as follows:\n%s"), functionName, (int) lastErrorCode, lpMsgBuf);

  LocalFree(lpMsgBuf);
}

int main() {
  // Имя файла для инициалиазации
  const char* FileName = "IniFile.txt";

  // 1. Открываем файл для чтения
  // ---------------------------
  // HANDLE - идентификатор внутреннего объекта Windows.
  HANDLE hFile = CreateFile(FileName,         // Имя файла
                            GENERIC_READ,     // Открываем файл для чтения
                            0,                      // dwShareMode - не раздеяем с другими процессами
                            NULL,                   // lpSecurityAttributes - NULL - текущий пользователь, текущие права
                            OPEN_EXISTING,          // Открываем файл только если файл существует
                            FILE_ATTRIBUTE_NORMAL,  // normal file
                            NULL);                  // no attr. template

  if (hFile == INVALID_HANDLE_VALUE) {
    DisplayError((LPTSTR) TEXT("CreateFile"));
    _tprintf(TEXT("ERROR: Unable to open file \"%s\" for read.\n"), FileName);
    return 1;
  }


  DWORD fileSize;  // Переменная для хранения размера файла
  DWORD result = GetFileSize(
                   hFile, // HANDLE-файла для которого нужно определить размер
                   &fileSize // Передаём указатель на fileSize чтобы функция его заполнила
                 );
  if (result == INVALID_FILE_SIZE) {
    DisplayError(TEXT("GetFileSize"));
    _tprintf(TEXT("ERROR: Unable to get file size \"%s\".\n"), FileName);
    return 1;
  }
  _tprintf("File size: %d", (int) fileSize);


  // Прочитатать строки и вывести их в консоль

  // Заводим буффер нужного размера
  char* ReadBuffer = new char[fileSize + 1];

  // Read one character less than the buffer size to save room for
  // the terminating NULL character.
  DWORD numberOfBytesRead = 0;
  if (FALSE == ReadFile(hFile,
                        ReadBuffer, // Буфер для чтения
                        fileSize,   // Сколько прочитать байт
                        &numberOfBytesRead, // Количество прочитанных байт
                        NULL)) {
    DisplayError(TEXT("ReadFile"));
    printf("Terminal failure: Unable to read from file.\n GetLastError=%08x\n", GetLastError());
    CloseHandle(hFile);
    return 1;
  }
  SleepEx(5000, TRUE);

  _tprintf(ReadBuffer);

  // Закрываем файл
  CloseHandle(hFile);

  return 0;
}