// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_

#include "MyStack.h"
#include <string>

std::string infix2postfix(std::string infix);
int prior(char a);

#endif  //  INCLUDE_POSTFIX_H_
