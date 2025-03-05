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
  Particle p("antimuon", 0.5);
  p.print_data();
  
  detector d("tracker");
  // Create the following particles:
  // two electrons, four muons, one antielectron, one antimuon
  // Use the parameterised constructor

  // Print out the data from all the particles (put them in a vector)

  // Create the following detectors: a tracker, a calorimeter, a muon chamber

  // Pass the list of particles into each detector

  // Print a summary of how many particles were detected

  return 0;
}
