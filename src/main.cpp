#include <cstdint>
#include <cstddef>
 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
#include "random_number_generator.h"
 
int main()
{
  std::vector<std::int8_t> vector;
  std::map<std::size_t, std::int8_t> map;
 
  RandomIntegerGenerator<int> data_generator{1,9};
  
  // Filling containers with random-generated data
  for (int i = 0; i < 30; ++i)
  { 
    vector.push_back(static_cast<std::uint8_t>(static_cast<uint8_t>(data_generator.Generate())));
    map.insert(std::pair<std::size_t, std::int8_t>(i, static_cast<uint8_t>(data_generator.Generate())));
  }
  
  for (auto it : vector)
    std::cout << static_cast<int>(it) << ' ';
  std::cout << std::endl;
  for (auto pair : map)
    std::cout << static_cast<int>(pair.second)  << ' ';
  std::cout << std::endl;
  
  // Remove 15 random elements from two containers
  RandomIntegerGenerator<std::size_t> vector_position_generator{0, vector.size()};
  RandomIntegerGenerator<std::size_t> map_position_generator{0, map.size()};
  
  for (int i = 0; i < 15; ++i)
  {
    auto vector_iterator = vector.begin();
    auto map_iterator = map.begin();
    
    // erase element from vector
    vector_position_generator.SetNewBoundaries(0, vector.size() - 1);
    std::advance(vector_iterator, vector_position_generator.Generate());
    vector.erase(vector_iterator);
    
    // erase element from map
    map_position_generator.SetNewBoundaries(0, map.size() - 1);
    std::advance(map_iterator, map_position_generator.Generate());
    map.erase(map_iterator);
  }
 
  for (auto it : vector)
    std::cout << static_cast<int>(it) << ' ';
  std::cout << std::endl;
  for (auto pair : map)
    std::cout << static_cast<int>(pair.second)  << ' ';
  std::cout << std::endl;
  
  // vector synchronization
  for (auto vector_iterator = vector.begin(); vector_iterator != vector.end();)
  {
    auto curr_vector_iterator_value = *vector_iterator;
    
    auto map_founded_iterator = std::find_if(map.begin(), map.end(),
      [&curr_vector_iterator_value](const std::pair<std::size_t, std::int8_t> &p)
      { return  p.second == curr_vector_iterator_value; });
      
    if (map_founded_iterator == map.end()) // not founded
      vector_iterator = vector.erase(vector_iterator);
    else
      ++vector_iterator;
  }
  
  for (auto it : vector)
    std::cout << static_cast<int>(it) << ' ';
  std::cout << std::endl;
  for (auto pair : map)
    std::cout << static_cast<int>(pair.second)  << ' ';
  std::cout << std::endl;  
  
  // map synchronization
  for (auto map_iterator = map.begin(); map_iterator != map.end();)
  {
    if (std::find(vector.begin(), vector.end(), map_iterator->second) == vector.end()) // not founded
      map_iterator = map.erase(map_iterator);
    else
      ++map_iterator;
  }
    
  for (auto it : vector)
    std::cout << static_cast<int>(it) << ' ';
  std::cout << std::endl;
  for (auto pair : map)
    std::cout << static_cast<int>(pair.second)  << ' ';
  std::cout << std::endl;
  
  return 0;
}