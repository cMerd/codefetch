#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "card.hpp"
#include "colors.hpp"
#include "user.hpp"

card::card(const user &profile) {
  const std::wstring rankColor = profile.getColor();

  titleRow = rankColor + L"" + colors::reset + L" " + rankColor +
             profile.rank + colors::reset + L" " + profile.handle;

  titleRowSize = 3 + (int)profile.rank.size() + (int)profile.handle.size();
  maxRowSize = std::max(maxRowSize, titleRowSize);

  if (!profile.firstName.empty() || !profile.lastName.empty()) {
    rows.emplace_back(L" Full name: ", 0);

    if (!profile.firstName.empty()) {
      rows.back().first += profile.firstName + L" ";
    }

    if (!profile.lastName.empty()) {
      rows.back().first += profile.lastName;
    }

    rows.back().second = 13 + (!profile.firstName.empty() ? 1 : 0) +
                         (int)profile.firstName.size() +
                         (int)profile.lastName.size();
    maxRowSize = std::max(maxRowSize, rows.back().second);
  }

  if (!profile.city.empty() || !profile.country.empty()) {
    rows.emplace_back(L" From ", 0);

    if (!profile.city.empty()) {
      rows.back().first += colors::link + colors::underline + profile.city +
                           colors::reset + L", ";
    }

    if (!profile.country.empty()) {
      rows.back().first +=
          colors::link + colors::underline + profile.country + colors::reset;
    }

    rows.back().second = 7 + (!profile.city.empty() ? 2 : 0) +
                         (int)profile.city.size() + (int)profile.country.size();
    maxRowSize = std::max(maxRowSize, rows.back().second);
  }

  if (!profile.organization.empty()) {
    rows.emplace_back(L" At " + colors::link + colors::underline +
                          profile.organization + colors::reset,
                      5 + (int)profile.organization.size());
    maxRowSize = std::max(maxRowSize, rows.back().second);
  }

  rows.emplace_back(
      rankColor + L"" + colors::reset + L" Rating: " + rankColor +
          std::to_wstring(profile.rating) + colors::reset + L"(max. " +
          rankColor + std::to_wstring(profile.maxRating) + colors::reset +
          L", " + rankColor + profile.maxRank + colors::reset + L")",
      19 + (int)std::to_string(profile.rating).size() +
          (int)std::to_string(profile.maxRating).size() +
          (int)profile.maxRank.size());
  maxRowSize = std::max(maxRowSize, rows.back().second);

  rows.emplace_back(
      colors::blue + L"" + colors::reset + L" Contribution: " +
          (profile.contribution > 0 ? colors::green + L"+" : colors::gray) +
          std::to_wstring(profile.contribution) + colors::reset,
      16 + (profile.contribution > 0 ? 1 : 0) +
          (int)std::to_wstring(profile.contribution).size());
  maxRowSize = std::max(maxRowSize, rows.back().second);

  maxRowSize += 2;
}

void card::print() const {
  std::wcout << L"╭";
  for (int i = 0; i < maxRowSize; i++) {
    std::wcout << L"─";
  }
  std::wcout << L"╮" << '\n';

  std::wcout << L"│ " << titleRow;
  for (int i = titleRowSize + 1; i < maxRowSize; i++) {
    std::wcout << L' ';
  }
  std::wcout << L"│" << '\n';

  std::wcout << L"├";
  for (int i = 0; i < maxRowSize; i++) {
    std::wcout << L"─";
  }
  std::wcout << L"┤" << '\n';

  for (const auto &[row, len] : rows) {
    if (row.empty()) {
      continue;
    }

    std::wcout << L"│ " << row;
    for (int i = len + 1; i < maxRowSize; i++) {
      std::wcout << ' ';
    }
    std::wcout << L"│" << '\n';
  }

  std::wcout << L"╰";
  for (int i = 0; i < maxRowSize; i++) {
    std::wcout << L"─";
  }
  std::wcout << L"╯" << '\n';
}