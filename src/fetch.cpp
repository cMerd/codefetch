#include <curl/curl.h>
#include <iostream>
#include <string>

#include "fetch.hpp"

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t totalSize = size * nmemb;
  std::string *str = reinterpret_cast<std::string *>(userp);
  str->append(reinterpret_cast<char *>(contents), totalSize);
  return totalSize;
}

std::string fetch(const std::string &url) {
  CURL *curl;
  CURLcode res;
  std::string response;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      std::cerr << "Request failed: " << curl_easy_strerror(res) << '\n';
      exit(1);
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return response;
}
