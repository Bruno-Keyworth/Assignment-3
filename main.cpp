// PHYS30762 Programming in C++
// Assignment 3
// Programme to simulate detector response to leptons.
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "particle.h"
#include "detector.h"

// Main program
int main()
{
  std::vector<Particle> particles;
  std::vector<std::string> particle_types = {"electron", "electron", "muon", "muon", "muon", "muon", "antielectron", "antimuon"};
  particles.reserve(particle_types.size());
  
  std::cout<<std::string(80, '-')<<std::endl;
  std::cout<<"Particle Type | Mass (MeV) | Charge (e) | Beta "<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  for(std::string ptype : particle_types)
  {
    particles.emplace_back(ptype, 0.5);
    particles.back().printData();
  }
  std::cout<<std::string(80, '-')<<std::endl;

  Detector tracker("tracker", true);
  Detector calorimeter("calorimeter", true);
  Detector muon_chamber("muon chamber", true);
  for(int i=0; i<particles.size(); ++i)
  {
    tracker.detect(particles[i]);
    calorimeter.detect(particles[i]);
    muon_chamber.detect(particles[i]);
  }
  tracker.switchOff();
  calorimeter.switchOff();
  muon_chamber.switchOff();
  std::cout<<std::string(50, '-')<<std::endl;
  std::cout<<"Detector     | e- | e+ | mu- | mu+ | total "<<std::endl;
  std::cout<<std::string(50, '-')<<std::endl;
  tracker.printData();
  calorimeter.printData();
  muon_chamber.printData();
  std::cout<<std::string(50, '-')<<std::endl;
  
  

  return 0;
}
