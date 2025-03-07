// PHYS30762 Programming in C++
// Assignment 3
// Declaration of particle class
// Created by Bruno Keyworth (ID: 11021856) on 23/02/2025.
#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<functional>

// test test test

// Beginning of particle class
class Particle
{
private:
  std::string type;
  double rest_mass; // MeV
  int charge; // e
  double speed; // m/s
  double beta;

  const double light_speed = 2.99792458e8;
  const std::vector<std::string> leptons = {"electron", "muon", "tau"};
  const std::vector<double> lepton_masses = {0.511, 106, 1777};
  
  void trySet(const std::function<void()>& setter);

public:

  void printData();
  void setType(std::string ptype);
  void setBeta(double pbeta);
  void setSpeed(double pspeed);
  void setMass(double pmass);
  void setCharge(int pcharge);
  std::string getType() const { return type; }
  double getMass() const { return rest_mass; }
  double getSpeed() const { return speed; }
  double getBeta() const { return beta; }
  int getCharge() const { return charge; }
  
  Particle() = default;
  Particle(std::string ptype, double pbeta)
  {
    trySet([&] { setType(ptype); });
    trySet([&] { setBeta(pbeta); });
  }
  Particle(double pmass, double pspeed, int pcharge)
  {
    trySet([&] { setSpeed(pspeed); });
    trySet([&] { setCharge(pcharge); });
    trySet([&] { setMass(pmass); });
  }
  ~Particle(){ std::cout<<"Destroying: "<<type<<std::endl; }
};

#endif
