#include "LC.h"
#include "math.h"
#include <iostream>

// calculates and returns the total impedance of an RLC circuit given the
// resistance, capacitor value, inductor value and frequency.
double LC::get_lc_impedance(double cap, double ind, double freq) {
 // find Xc
  double xc = (1 / (2 * PI * freq * cap)) * (pow(10.0, 3.0));
  // find Xl
  double xl = 2 * PI * freq * ind;
  // find the total impedance
  double z = (2 * PI * freq * ind) - (1 / 2 * PI * freq * cap);
  // display xc and xl
  std::cout << "The capacitive reactance is " << xc << " mΩ.\n";
  std::cout << "The inductive reactance is " << xl << " Ω.\n";
  std::cout << "The total impedance is " << z << " Ω.\n";
  // return the result
  return z;
}
