#pragma once
#include <string>
#include <sstream>
#include <random>

//The UUID is used for uniquely referencing an entity when, for example, it is stored as a Memento
//Basically it replaces pointer values as a safer way of referencing objects over time
typedef std::string UUID;

//Initialize generators for UUID
static std::random_device              rd;
static std::mt19937                    gen(rd());
static std::uniform_int_distribution<> uuidUniformDistribution(0, 15);

UUID generateUUID()
{
  std::stringstream ss;

  ss << std::hex;

  for (int i = 0; i < 32; i++) {
      ss << uuidUniformDistribution(gen);
  }

  return ss.str();
}

//Return uniformly distributed random int in range [min, max] inclusive
int randomInt(int min, int max)
{
    std::uniform_int_distribution<> uniformDistribution(min, max);
    return uniformDistribution(gen);
}