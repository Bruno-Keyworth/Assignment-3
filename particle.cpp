// PHYS30762 Programming in C++
// Assignment 3
// Header file containing particle and detector classes.
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include "particle.h"
// test test test

// Beginning of particle class
void Particle::set_type(std::string ptype)
{
  if(ptype=="positron") { ptype = "antielectron"; }
  auto index = std::find(leptons.begin(), leptons.end(), (ptype.rfind("anti", 0) == 0) ? ptype.substr(3) : ptype);
  if (index != leptons.end()) {
      charge = (ptype.rfind("anti", 0) == 0) ? 1 : -1;
      type = ptype;
      rest_mass = lepton_masses[std::distance(leptons.begin(), index)];
  }
  else throw "Error: particle type not recognised: " + ptype;
}

void Particle::set_beta(double pbeta)
{
  if(pbeta<1) { beta = pbeta; speed = beta * light_speed;}
  else { throw std::string("Error: beta value cannot be greater than 1"); }
}

void Particle::set_speed(double pspeed)
{
  if(pspeed<light_speed) { beta = pspeed/light_speed; speed = pspeed;}
  else { throw std::string("Error: particle speed must be less than the speed of light (299792458 m/s)"); }
}

void Particle::set_mass(double pmass)
{
  
}

void Particle::print_data()
{
  std::cout << type << " " << charge << " " << beta << std::endl;
}
