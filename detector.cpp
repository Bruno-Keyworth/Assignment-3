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

bool Detector::detect(Particle& p)
{
  if(!status) return false;
  std::string ptype = p.getType();
  auto index = std::find(can_detect.begin(), can_detect.end(), ptype);
  if (index != can_detect.end())
  {
    count[std::distance(can_detect.begin(), index)]++;
    std::cout<<ptype<<" was detected"<<std::endl;
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
  } else throw "Error: particle type not recognised: " + ptype;
}

void Detector::printData()
{
  std::cout<<"Data for "<<type<<":"<<std::endl;
  for(std::string ptype : can_detect)
  {
    std::cout<<ptype<<" count is "<<getCount(ptype)<<std::endl;
  }
  std::cout<<"Total count is "<<getCount()<<std::endl;
}

void Detector::trySet(const std::function<void()>& setter)
{
  try { setter(); }
  catch (const std::string& error) { std::cout << error << std::endl; }
}
