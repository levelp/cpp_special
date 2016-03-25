/// Запись и чтение файлов
/// ======================
// Uses Windows;
#include <iostream>
#include <cstdio>
#include <tchar.h>
#include <windows.h>

using namespace std;

// Routine Description:
// Retrieve and output the system error message for the last-error code
void DisplayError(const char* functionName) {
  LPVOID lpMsgBuf;
  LPVOID lpDisplayBuf;
  DWORD dw = GetLastError();

  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    dw,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPTSTR) &lpMsgBuf,
    0,
    NULL);

  lpDisplayBuf = (LPVOID) LocalAlloc(LMEM_ZEROINIT,
                                     (lstrlen((LPCTSTR) lpMsgBuf) + lstrlen(functionName)
                                      + 40) // account for format string
                                     * sizeof(TCHAR));

  wsprintf((LPTSTR) lpDisplayBuf, TEXT("%s failed with error code %d as follows:\n%s"),
           functionName,
           dw,
           lpMsgBuf);

  _tprintf((LPTSTR) lpDisplayBuf);

  LocalFree(lpMsgBuf);
  LocalFree(lpDisplayBuf);
}

int main(int argc, TCHAR* argv[]) {
  char DataBuffer[] = "This is some test data to write to the file.";
  DWORD dwBytesToWrite = (DWORD) strlen(DataBuffer);
  DWORD dwBytesWritten = 0;
  BOOL bErrorFlag;

  const char* FileName = "MyFile.txt";

  SECURITY_ATTRIBUTES securityAttributes;
  securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
  securityAttributes.lpSecurityDescriptor = NULL;
  securityAttributes.bInheritHandle = TRUE;

  printf("\n");

  // 1. Открываем файл на запись
  // ---------------------------
  // HANDLE - идентификатор внутреннего объекта Windows.
  // Есть объекты внутри нашей программы, которые находятся в памяти нашего процесса.
  // А есть внешние объекты, принадлежащие операционной системе.
  // Windows не может дать нам указатель на кусок памяти внутри себя.
  // Поэтому Windows возвращает нам "системный" номер области памяти.
  // Этот "псевдоукатель" и называется HANDLE
  HANDLE hFile = CreateFile(FileName,               // Имя файла
                            GENERIC_WRITE | GENERIC_READ, // Открываем его для записи
                            0,                      // dwShareMode - не раздеяем с другими процессами
                            NULL,                   // lpSecurityAttributes - NULL - текущий пользователь, текущие права
                            CREATE_ALWAYS,          // Создаём файл и перезаписываем при необходимости
                            // CREATE_NEW - создаём файл, только если его не существует, если существует получаем INVALID HANDLE
                            // OPEN_ALWAYS - открываем и создаём файл если его нет
                            // OPEN_EXISTING - открываем только, только если файл существует
                            FILE_ATTRIBUTE_NORMAL,  // normal file
                            NULL);                  // no attr. template

  if (hFile == INVALID_HANDLE_VALUE) {
    cout << "INVALID_HANDLE_VALUE" << endl;
    DisplayError((LPTSTR) TEXT("CreateFile"));
    _tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), FileName);
    return 1;
  }

  _tprintf(TEXT("Writing %d bytes to \"%s\".\n"), (int) dwBytesToWrite, FileName);

  // 2. Пишем что-то в файл
  // ----------------------
  bErrorFlag = WriteFile(
                 hFile,           // open file handle
                 DataBuffer,      // start of data to write
                 dwBytesToWrite,  // number of bytes to write
                 &dwBytesWritten, // number of bytes that were written
                 NULL);            // no overlapped structure

  if (FALSE == bErrorFlag) {
    DisplayError((LPTSTR) TEXT("WriteFile"));
    printf("Terminal failure: Unable to write to file.\n");
  } else {
    if (dwBytesWritten != dwBytesToWrite) {
      // This is an error because a synchronous write that results in
      // success (WriteFile returns TRUE) should write all data as
      // requested. This would not necessarily be the case for
      // asynchronous writes.
      printf("Error: dwBytesWritten != dwBytesToWrite\n");
    } else
      _tprintf(TEXT("Wrote %d bytes to \"%s\" successfully.\n"), (int) dwBytesWritten, FileName);
  }

  // 3. Закрываем файл
  // -----------------
  CloseHandle(hFile);

  return 0;
}