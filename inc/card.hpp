#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "colors.hpp"
#include "user.hpp"

class card {
public:
  card(const user &profile);
  void print() const;

private:
  std::vector<std::pair<std::wstring, int>> rows = {};
  std::wstring titleRow = L"";
  int titleRowSize = 0;
  int maxRowSize = 0;
};