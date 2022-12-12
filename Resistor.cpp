#include "Resistor.h"

int Resistor::sum_of_array(const double array[], double n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }
  return sum;
}

double Resistor::parallel_resistance(const double array[], double n) {
  // 1/rt = 1/r1 + 1/r2 + 1/r3 ... where rt is the total resistance in a
  // parallel circuit.
  // Step 1: Find 1/r1 + 1/r2 + 1/r3 ... 1/rn
  // Step 2: Find the inverse of the sum in step 1 to get rt
  float inverse_sum = 0;
  for (int i = 0; i < n; i++) {
    inverse_sum += (1 / array[i]);
  }
  // return the inverse of the sum of 1/rn
  return 1 / inverse_sum;
}
