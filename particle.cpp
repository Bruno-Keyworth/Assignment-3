// PHYS30762 Programming in C++
// Assignment 3
// Implimentation of particle class
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include "particle.h"
// test test test

// Beginning of particle class
void Particle::setType(std::string ptype)
{
  if(ptype=="positron") { ptype = "antielectron"; }
  std::string particle_type = (ptype.rfind("anti", 0) == 0) ? ptype.substr(4) : ptype;
  auto index = std::find(leptons.begin(), leptons.end(), particle_type);
  if (index != leptons.end()) {
      charge = (ptype.rfind("anti", 0) == 0) ? 1 : -1;
      type = ptype;
      rest_mass = lepton_masses[std::distance(leptons.begin(), index)];
  } else throw "Error: particle type not recognised: " + ptype;
}

void Particle::setBeta(double pbeta)
{
  if(pbeta<1) { beta = pbeta; speed = beta * light_speed;}
  else { throw std::string("Error: beta value cannot be greater than 1"); }
}

void Particle::setSpeed(double pspeed)
{
  if(pspeed<light_speed) { beta = pspeed/light_speed; speed = pspeed;}
  else { throw std::string("Error: particle speed must be less than the speed of light (299792458 m/s)"); }
}

void Particle::setCharge(int pcharge)
{
  if((pcharge==-1) or (pcharge==1)) { charge = pcharge; }
  else throw "Error: charge must be +1 or -1";
}

void Particle::setMass(double pmass)
{
  rest_mass = pmass;
  auto index = std::find(lepton_masses.begin(), lepton_masses.end(), pmass);
  if(index != lepton_masses.end()) {
    type = leptons[std::distance(lepton_masses.begin(), index)];
    if(charge == 1) { type = "anti" + type; }
  } else { type = "unknown particle"; };
}

void Particle::printData()
{
  std::cout << type << " " << charge << " " << beta << " " << rest_mass << std::endl;
}

void Particle::trySet(const std::function<void()>& setter)
{
  try { setter(); }
  catch (const std::string& error) { std::cout << error << std::endl; }
}
