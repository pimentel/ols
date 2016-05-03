#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "ols.hpp"

std::vector<double> read_file(const std::string& f_name) {
  std::vector<double> ret;

  std::ifstream input;
  input.open(f_name);

  double tmp;
  while (input >> tmp) {
    ret.push_back(tmp);
  }

  input.close();

  return ret;
}

int main(int argc, char const *argv[]) {

  std::vector<double> x = read_file(std::string(argv[1]));
  std::vector<double> y = read_file(std::string(argv[2]));

  std::pair<double, double> beta = ols(x, y);

  std::cout << std::setprecision(8);
  std::cout << beta.first << '\t' << beta.second << std::endl;

  // std::pair<double, double>
  return 0;
}
