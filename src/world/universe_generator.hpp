#pragma once

#include <random>
#include "universe.hpp"


namespace space_wars {

class UniverseGenerator {
 public:
  UniverseGenerator(int seed);

  Universe* Generate(int num_players, int neutral_systems_ratio);
  System* GenerateSystem(int i);
  System* GenerateHomeSystem(int id, int player_id);
  Sun* GenerateSun(int system);
  std::vector<Planet*> GeneratePlanets(int system, Sun* sun);
  Planet* GeneratePlanet(int system, int id, CelestialBody* previous);

  void ConnectPlanets(int system, Sun* sun, std::vector<Planet*>& planets);

 private:
  int seed_;
  std::mt19937 random_;

  unsigned int in_range(unsigned int min, unsigned int max);

  void seed(const std::vector<int>& seeds);
};

}
