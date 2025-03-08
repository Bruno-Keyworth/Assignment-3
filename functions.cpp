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
#include <sstream>
#include <iomanip>

std::string add_spaces(std::string str, int length)
{ // Fills out string to given length by adding spaces to the end
  str.append(length - str.size(), ' ');
  return str;
}

std::string to_string_trimmed(double value) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(10) << value;  // Adjust precision as needed
    std::string str = out.str();

    // Remove trailing zeros and unnecessary decimal points
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str.back() == '.') {
        str.pop_back();  // Remove trailing decimal point if necessary
    }
    return str;
}

#endif
