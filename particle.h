// PHYS30762 Programming in C++
// Assignment 3
// Header file containing particle and detector classes.
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.
#ifndef PARTICLE_H

#define PARTICLE_H
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

// test test test

// Beginning of particle class
class Particle
{
private:
  std::string type;
  int rest_mass; // MeV
  int charge; // e
  double speed; // m/s
  double beta;

  const double light_speed = 2.99792458e8;
  const std::vector<std::string> leptons = {"electron", "muon", "tau"};
  const std::vector<double> lepton_masses = {0.511, 106, 1777};

public:

  void print_data();
  void set_type(std::string ptype);
  void set_beta(double pbeta);
  void set_speed(double pspeed);
  void set_mass(double pmass);
  
  Particle() = default;
  Particle(std::string ptype, double pbeta)
  {
    try { set_beta(pbeta); }
    catch(const std::string error) { std::cout<<error<<std::endl; }
    try { set_type(ptype); }
    catch(const std::string error) { std::cout<<error<<std::endl; }
  }
  Particle(int mass, double pspeed, int charge)
  {
    try { set_speed(pspeed); }
    catch(const std::string error) { std::cout<<error<<std::endl; }
  }
  ~Particle(){ std::cout<<"Destroying: "<<type<<std::endl; }

  // Getter functions (accessors) to 
  // This should include function returning beta value 

  // Setter functions, to change value of data members
  // Make sure you check input validity before changing something
  // Hint: you can use the input checking functions you used in assignment 1

  // Function to print info about a particle

};

#endif
