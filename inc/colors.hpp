#pragma once

#include <string>

namespace colors {
#if !defined(__linux__) && !defined(__APPLE__)
const std::wstring gray = L"";
const std::wstring green = L"";
const std::wstring link = L"";
const std::wstring cyan = L"";
const std::wstring blue = L"";
const std::wstring magenta = L"";
const std::wstring yellow = L"";
const std::wstring orange = L"";
const std::wstring red = L"";
const std::wstring darkRed = L"";
const std::wstring underline = L"";
const std::wstring reset = L"";
#else
const std::wstring gray = L"\033[38;2;152;143;129m";
const std::wstring green = L"\033[38;2;56;227;48m";
const std::wstring link = L"\033[38;2;51;145;255m";
const std::wstring cyan = L"\033[38;2;64;255;249m";
const std::wstring blue = L"\033[38;2;0;30;255m";
const std::wstring magenta = L"\033[38;2;251;23;255m";
const std::wstring yellow = L"\033[38;2;235;186;40m";
const std::wstring orange = L"\033[38;2;255;165;0m";
const std::wstring red = L"\033[38;2;255;26;26m";
const std::wstring darkRed = L"\033[38;2;230;5;0m";
const std::wstring underline = L"\033[4m";
const std::wstring reset = L"\033[0m";
#endif
} // namespace colors
