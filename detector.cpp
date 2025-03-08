// PHYS30762 Programming in C++
// Assignment 3
// Implementation of detector class.
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<numeric>
#include "detector.h"
#include "functions.h"

bool Detector::detect(Particle& p)
{
  if(!status) return false;
  std::string ptype = p.getType();
  auto index = std::find(can_detect.begin(), can_detect.end(), ptype);
  if (index != can_detect.end())
  {
    count[std::distance(can_detect.begin(), index)]++;
    std::cout<<ptype<<" was detected by "<<type<<std::endl;
    return true;
  } else return false;
}

void Detector::setType(std::string dtype)
{
  auto index = std::find(detectors.begin(), detectors.end(), dtype);
  if (index != detectors.end())
  {
    type = dtype;
    can_detect = detected_particles[std::distance(detectors.begin(), index)];
    count = std::vector(can_detect.size(), 0);
  } else throw "Error: detector type not recognised: " + dtype;
}

int Detector::getCount(std::string ptype)
{
  if(ptype=="all") { return std::accumulate(count.begin(), count.end(), 0); }
  auto index = std::find(can_detect.begin(), can_detect.end(), ptype);
  if (index != can_detect.end())
  {
    return count[std::distance(can_detect.begin(), index)];
  } else return 0;
}

void Detector::printData()
{
  std::string row;
  row += add_spaces(type, 12);
  row += " | " + add_spaces(std::to_string(getCount("electron")), 2);
  row += " | " + add_spaces(std::to_string(getCount("antielectron")), 2);
  row += " | " + add_spaces(std::to_string(getCount("muon")), 3);
  row += " | " + add_spaces(std::to_string(getCount("antimuon")), 3);
  row += " | " + std::to_string(getCount());
  std::cout<<row<<std::endl;
}

void Detector::trySet(const std::function<void()>& setter)
{
  try { setter(); }
  catch (const std::string& error) { std::cout << error << std::endl; }
}
