#pragma once

#include <curl/curl.h>
#include <iostream>
#include <string>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
std::string fetch(const std::string &url);