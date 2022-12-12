#ifndef RLC_H
#define RLC_H

#define PI 3.1415926535

class RLC {
public:
  // adds up all the values in the array
  double get_rlc_impedance(double res, double cap, double ind, double freq);

private:
};

#endif