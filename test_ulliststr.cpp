#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;

  dat.push_back("A");
  dat.push_back("B");
  dat.push_back("C");

  std::cout << "After push_back: " << dat.get(0) << dat.get(1) << dat.get(2) << std::endl;

  dat.push_front("D");
  dat.push_front("E");
  dat.push_front("F");

  std::cout << "After push_front: ";
  for (size_t i = 0; i < dat.size(); i++){
    std::cout << dat.get(i) << " ";
  }
  std::cout << std::endl;

  dat.pop_back();
  std::cout << "After pop_back: ";
  for (size_t i = 0; i < dat.size(); i++){
    std::cout << dat.get(i) << " ";
  }
  std::cout << std::endl;

  dat.pop_front();
  std::cout << "After pop_front: ";
  for (size_t i = 0; i < dat.size(); i++){
    std::cout << dat.get(i) << " ";
  }
  std::cout << std::endl;

  std::cout << "Front: " << dat.front() << ", Back: " << dat.back() << std::endl;
  
  std::cout << "Size: " << dat.size() << std::endl;

  return 0;
}
