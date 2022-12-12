#ifndef RESISTOR_H
#define RESISTOR_H

class Resistor {
public:
  // adds up all the values in the array
  int sum_of_array(const double array[], double n);

  // finds the total resistance of a set of parallel resistors
  double parallel_resistance(const double array[], double n);

private:
};

#endif