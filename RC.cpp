#include "RC.h"
#include "math.h"
#include <iostream>

// calculates and returns the total impedance of an RLC circuit given the
// resistance, capacitor value, inductor value and frequency.
double RC::get_rc_impedance(double res, double cap, double freq) {
  // find Xc
  double xc = (1 / (2 * PI * freq * cap)) * (pow(10.0, 3.0));
  // find the total impedance
  double z = sqrt((res * res) + (1 / (2 * PI * freq * cap) * (2 * PI * freq * cap)));
  // display xc and xl
  std::cout << "The capacitive reactance is " << xc << " mΩ.\n";
  std::cout << "The total impedance is " << z << " Ω.\n";
  // return the result
  return z;
}