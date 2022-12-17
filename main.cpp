#include <iostream>
#include <string_view>
#include <windows.h>

std::wstring ConvertToUTF16(std::string_view source)
{
	int requiredSize = MultiByteToWideChar(CP_UTF8, 0, &source[0], -1, NULL, 0);
	std::wstring result(requiredSize, '\0');
	MultiByteToWideChar(CP_UTF8, 0, &source[0], -1, &result[0], requiredSize);
	return result;
}

int main()
{
	std::string str = "\xE7\xB9\x81\xE4\xBD\x93\xE5\xAD\x97";
	std::wstring result = ConvertToUTF16(str);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteConsole(h, &result[0], result.length(), 0, 0);
}