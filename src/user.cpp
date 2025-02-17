#include <string>

#include "colors.hpp"
#include "json.hpp"
#include "user.hpp"

user::user(const json &data) {
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

  handle = converter.from_bytes(data["handle"]);

  if (data.contains("firstName")) {
    firstName = converter.from_bytes(data["firstName"]);
  }

  if (data.contains("lastName")) {
    lastName = converter.from_bytes(data["lastName"]);
  }

  if (data.contains("country")) {
    country = converter.from_bytes(data["country"]);
  }

  if (data.contains("city")) {
    city = converter.from_bytes(data["city"]);
  }

  if (data.contains("organization")) {
    organization = converter.from_bytes(data["organization"]);
  }

  if (data.contains("rank")) {
    rank = converter.from_bytes(data["rank"]);
  }

  if (data.contains("maxRank")) {
    maxRank = converter.from_bytes(data["maxRank"]);
  }

  if (data.contains("contribution")) {
    contribution = data["contribution"];
  }

  if (data.contains("rating")) {
    rating = data["rating"];
  }

  if (data.contains("maxRating")) {
    maxRating = data["maxRating"];
  }
}

std::wstring user::getColor() const {
  if (rank == L"newbie" || rank == L"unrated") {
    return colors::gray;
  } else if (rank == L"pupil") {
    return colors::green;
  } else if (rank == L"specialist") {
    return colors::cyan;
  } else if (rank == L"expert") {
    return colors::blue;
  } else if (rank == L"candidate master") {
    return colors::magenta;
  } else if (rank == L"master") {
    return colors::yellow;
  } else if (rank == L"international master") {
    return colors::orange;
  } else if (rank == L"grandmaster") {
    return colors::red;
  } else if (rank == L"international grandmaster" ||
             rank == L"legendary grandmaster" || rank == handle) {
    return colors::darkRed;
  }
  return colors::reset;
}