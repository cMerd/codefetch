#include <iostream>
#include <locale>
#include <string>

#include "card.hpp"
#include "fetch.hpp"
#include "json.hpp"
#include "user.hpp"

using json = nlohmann::json;

int main(int argc, char *argv[]) {
  std::setlocale(LC_ALL, "en_US.UTF-8");

  if (argc < 2) {
    std::cerr << "Usage: codefetch <handles>\n";
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    std::string url = "https://codeforces.com/api/user.info?lang=en&handles=" +
                      std::string(argv[i]);

    std::string res = fetch(url);
    json fetchData = json::parse(res);

    if (fetchData["status"] != "OK") {
      std::cerr << "Fetching data failed: ";
      std::cerr << fetchData["comment"] << '\n';
      return 1;
    }

    json userData = fetchData["result"].front();
    user user(userData);

    card profile(user);
    profile.print();
  }

  return 0;
}
