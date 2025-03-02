// PHYS30762 Programming in C++
// Assignment 3
// Header file containing particle and detector classes.
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.
#ifndef DETECTOR_H
#define DETECTOR_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

// test test test

// Beginning of particle class
class detector
{
private:
  std::string type;

public:
  detector() = default;
  detector(std::string ptype) : type{ptype}{}
  ~detector(){ std::cout<<"Destroying: "<<type<<std::endl; }
  void print_type() { std::cout << type << std::endl; }
  void set_type(std::string ptype){ type = ptype; }

  // Getter functions (accessors) to 
  // This should include function returning beta value 

  // Setter functions, to change value of data members
  // Make sure you check input validity before changing something
  // Hint: you can use the input checking functions you used in assignment 1

  // Function to print info about a particle
  void print_data();

};

// Implementation of print_data function goes here

// End of particle class and associated member functions

// Beginning of detector class

#endif
// Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
// - write a function that takes a particle 
//   and returns a bool and a print-out on whether this type of detector detected the particle
//   depending on the detector/particle combination (see slides on BB)
// - have data members that keep track of how many particles were detected by this particular detector, 
//   and of which type
// - write a function (accessor) that prints how many particles passed through this detector

// End of detector class
