// Copyright 2021 Shirokov Alexander

#include "postfix.h"
#include <iostream>

std::string infix2postfix(std::string infix) {
  MyStack <char> oper(300);
  std::string out;
  std::string tmp;

  for (int i = 0; i < infix.length(); i++) {
    if (infix[i] >= '0' && infix[i] <= '9' || infix[i] == '.') {
      tmp.push_back(infix[i]);
      continue;
    }
    if (!tmp.empty()) {
      out += tmp;
      out.push_back(' ');
      tmp.clear();
    }

    int pr = prior(infix[i]);
    if (pr > prior(oper.get()) || pr > -1 && oper.isEmpty() || pr == 0) {
      oper.push(infix[i]);
    } else if (pr == 1) {
      while (oper.get() != '(') {
        out.push_back(oper.pop());
        out.push_back(' ');
      }
      oper.pop();
    } else if (pr > -1) {
      while (!oper.isEmpty() && prior(oper.get()) >= pr) {
        out.push_back(oper.pop());
        out.push_back(' ');
      }
      oper.push(infix[i]);
    }
  }

  if (!tmp.empty()) {
    out += tmp;
    out.push_back(' ');
  }
  while (!oper.isEmpty()) {
    out.push_back(oper.pop());
    out.push_back(' ');
  }
  out.pop_back();
  return out;
}

int prior(char a) {
  switch (a) {
    case '*':
    case '/':
      return 3;
    case '-':
    case '+':
      return 2;
    case ')':
      return 1;
    case '(':
      return 0;
    default:
      return -1;
  }
}
