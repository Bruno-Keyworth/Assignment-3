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
  Detector(std::string dtype, bool on = false) { trySet([&] { setType(dtype); }); status = on;}
  ~Detector(){ std::cout<<"Destroying: "<<type<<std::endl; }
};

#endif
