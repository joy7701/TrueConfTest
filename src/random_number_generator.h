#ifndef RANDOM_NUMBER_GENERATOR_H_
#define RANDOM_NUMBER_GENERATOR_H_

#include <cstdint>

#include <random>
#include <type_traits>

template<typename T>
class RandomIntegerGenerator {
 public:
  RandomIntegerGenerator() = delete;
  explicit RandomIntegerGenerator(const T lower_bound,const T upper_bound)
  {
    static_assert(std::is_integral<T>::value, "Integral is required.");
    distribution = std::uniform_int_distribution<T>(lower_bound, upper_bound);
  }
  T Generate()
  {
    return distribution(generator);
  }
  void SetNewBoundaries(const T lower_bound, const T upper_bound)
  {
    distribution = std::uniform_int_distribution<T>{lower_bound, upper_bound};
  }
 private:
  std::random_device generator;
  std::uniform_int_distribution<T> distribution;
};

#endif // RANDOM_NUMBER_GENERATOR_H_
