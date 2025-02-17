#pragma once

#include <string>

#include "colors.hpp"
#include "json.hpp"

struct user {
  using json = nlohmann::json;

  std::wstring handle = L"";
  std::wstring firstName = L"";
  std::wstring lastName = L"";
  std::wstring country = L"";
  std::wstring city = L"";
  std::wstring organization = L"";
  std::wstring rank = L"";
  std::wstring maxRank = L"";

  int contribution = 0;
  int rating = 0;
  int maxRating = 0;

  user(const json &data);
  std::wstring getColor() const;
};
