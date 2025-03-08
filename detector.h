// PHYS30762 Programming in C++
// Assignment 3
// Definition of detector class.
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.
#ifndef DETECTOR_H
#define DETECTOR_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"particle.h"

class Detector
{
private:
  std::string type;
  bool status = false; // detector is on if true
  std::vector<std::string> can_detect;
  std::vector<int> count; // stores counts of different particle types.

  const double light_speed = 2.99792458e8;
  const std::vector<std::string> detectors = {"tracker", "calorimeter", "muon chamber"};
  const std::vector<std::vector<std::string>> detected_particles = {{"electron", "antielectron", "muon", "antimuon"}, {"electron", "antielectron"}, {"muon", "antimuon"}};
  
  void trySet(const std::function<void()>& setter);

public:
  void printData();
  void setType(std::string dtype);
  void switchOn() { status = true; }
  void switchOff() { status = false; }
  std::string getType() const { return type; }
  int getCount(std::string ptype="all");
  bool getStatus() const { return status; }
  bool detect(Particle& p);
  
  Detector() = default;
  Detector(std::string dtype) { trySet([&] { setType(dtype); }); }
  ~Detector(){ std::cout<<"Destroying: "<<type<<std::endl; }
};

#endif
// Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
// - write a function that takes a particle 
//   and returns a bool and a print-out on whether this type of detector detected the particle
//   depending on the detector/particle combination (see slides on BB)
// - have data members that keep track of how many particles were detected by this particular detector, 
//   and of which type
// - write a function (accessor) that prints how many particles passed through this detector

// End of detector class
