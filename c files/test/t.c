#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    // Set locale to support UTF-8 output
    setlocale(LC_ALL, "");

    // Example UTF-8 encoded string
    char utf8_string[] = "anjan@🥲অ";

    // Print UTF-8 encoded string using normal string handling (char array)
    printf("String in C/C++ (UTF-8): %s\n", utf8_string);

    // Convert UTF-8 input to wide-character string (wchar_t array)
    wchar_t wide_string[100]; // Assuming a max size
    mbstowcs(wide_string, utf8_string, sizeof(wide_string)/sizeof(wchar_t));

    // Print wide-character string for UTF-8 input
    wprintf(L"String in C/C++ (wide-char): %ls\n", wide_string);

    return 0;
}
