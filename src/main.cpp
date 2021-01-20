// Copyright 2021 Shirokov Alexander

#include <iostream>
#include "postfix.h"

int main() {
  std::string inf1 = "8 / 2 * (2 + 2)";
  std::string postf1 = infix2postfix(inf1);
  std::cout << postf1 << std::endl;  // 8 2 / 2 2 + *

  std::string inf2 = "(5 + (14 - 2)) - 3 * 10 / 2 - (10 * 32)";
  std::string postf2 = infix2postfix(inf2);
  std::cout << postf2 << std::endl;  // 5 14 2 - + 3 10 * 2 / - 10 32 * -

  std::string inf3 = "(0.1 + 0.8) * (4.5 - 0.1)";
  std::string postf3 = infix2postfix(inf3);
  std::cout << postf3 << std::endl;  // 0.1 0.8 + 4.5 0.1 - *;
}
