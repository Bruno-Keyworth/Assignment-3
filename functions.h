// PHYS30762 Programming in C++
// Assignment 3
// Definition of detector class.
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.
#ifndef FUNCTION_H
#define FUNCTION_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

std::string add_spaces(std::string str, int length)
{ // Fills out string to given length by adding spaces to the end
  str.append(length - str.size(), ' ');
  return str;
}

#endif
