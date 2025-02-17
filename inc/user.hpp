#pragma once

#include <string>

#include "colors.hpp"
#include "json.hpp"

struct user {
  using json = nlohmann::json;

  std::wstring handle;
  std::wstring firstName;
  std::wstring lastName;
  std::wstring country;
  std::wstring city;
  std::wstring organization;
  std::wstring rank;
  std::wstring maxRank;

  int contribution;
  int rating;
  int maxRating;

  user(const json &data);
  std::wstring getColor() const;
};
