#include "RLC.h"
#include "RC.h"
#include "LC.h"
#include "Resistor.h"
#include "math.h"
#include <iostream>
#include <regex>

void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);
void menu_op_parallel_resistor();
void menu_op_series_resistor();
void menu_op_rlc();
void menu_op_rc();
void menu_op_lc();
double a = 0;
double b = 0;


int main(int argc, char const *argv[]) {
  main_menu();
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 6;

  do {
    std::cout << "\nChoose type of connection: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else { // if it is an int, check whether in range
      input = std::stoi(input_string); // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
  case 1:
    menu_op_parallel_resistor();
    break;
  case 2:
    menu_op_series_resistor();
    break;
  case 3:
    menu_op_rlc();
    break;
  case 4:
    menu_op_rc();
    break;
  case 5:
    menu_op_lc();
    break;
  default:
    exit(1);
    break;
  }
}

void print_main_menu() {
  std::cout << "\n-------Aley's Main menu -----------\n";
  std::cout << "|\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Parallel Resistors\t|\n";
  std::cout << "|\t2. Series Resistors\t\t|\n";
  std::cout << "|\t3. RLC Circuit \t\t\t|\n";
  std::cout << "|\t4. RC Circuit \t\t\t|\n";
  std::cout << "|\t5. LC Circuit \t\t\t|\n";
  std::cout << "|\t6. Exit\t\t\t\t\t|\n";
  std::cout << "---------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to the main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

// ask for parallel resister count and values then calculate and return the
// total resistance
void menu_op_parallel_resistor() {
  std::cout << "\n>> Parallel\n";
  // when we dynamically create an array, we can specify the length
  // of the array using a variable
  double n;
  double *array = new double[n];
  std::cout << "How many resistors are you using?"
            << "\n";
  std::cin >> n;
  // iterate over the loop and set the elements to some values
  for (int i = 0; i < n; i++) {
    std::cout << "Resistor " << i + 1 << " Value in Ω = " << std::endl;
    std::cin >> array[i];
  }

  // when we've finished, delete the memory and null the pointer to be safe
  for (int i = 0; i < n; i++) {
    // array[i] = i * i;
    std::cout << "Resistor[" << i + 1 << "] = " << array[i] << std::endl;
  }

  // create a resistor object
  Resistor Resistor;
  double total_parallel_resistance =    Resistor.parallel_resistance(array, n);
  std::cout << "The total resistance is " << total_parallel_resistance
            << " Ω.\n";

  delete[] array;
  array = nullptr;

  // you can call a function from here that handles menu 2
  go_back_to_main();
}

// ask for series resister count and values then calculate and return the total
// resistance
void menu_op_series_resistor() {
  std::cout << "\n>> series\n";
  // when we dynamically create an array, we can specify the length
  // of the array using a variable
  double n;
  double *array = new double[n];
  std::cout << "How many resistors are you using?"
            << "\n";
  std::cin >> n;
  // iterate over the loop and set the elements to some values
  for (int i = 0; i < n; i++) {
    std::cout << "Resistor " << i + 1 << " Value in Ω = " << std::endl;
    std::cin >> array[i];
  }

  // when we've finished, delete the memory and null the pointer to be safe
  for (int i = 0; i < n; i++) {
    // array[i] = i * i;
    std::cout << "Resistor[" << i + 1 << "] = " << array[i] << std::endl;
  }

  // create a resistor object
  Resistor Resistor;
  double sum = Resistor.sum_of_array(array, n);
  std::cout << "The total resistance is " << sum << " Ω.\n";

  delete[] array;
  array = nullptr;

  // you can call a function from here that handles menu 2
  go_back_to_main();
}

// RLC Circuit: Ask for the values of the resistor, capacitor and inductor. Also
// ask for the frequency. Then calculate and return the total impedance.
void menu_op_rlc() {
  std::cout << "\n>> RLC Circuit\n";
  // initialise the empty variables to accept the input values
  double res;
  double cap;
  double ind;
  double freq;
  double z;
  std::cout << "What is the resistance value? (in Ω)\n";
  std::cin >> res;
  std::cout << "What is the capacitance value? (in F)\n";
  std::cin >> cap;
  std::cout << "What is the inductance value? (in H)\n";
  std::cin >> ind;
  std::cout << "What is the frequency (in Hz)?\n";
  std::cin >> freq;

  // initialise an RLC circuit object
  RLC RLC;
  // use the RLC object to calculate the total impedence
  z = RLC.get_rlc_impedance(res, cap, ind, freq);
  // display the result
  //std::cout << "The total impedance is " << z << " Ω.\n";

  // you can call a function from here that handles menu 2
  go_back_to_main();
}

// RC Circuit: Ask for the values of the resistor and capacitor. Also
// ask for the frequency. Then calculate and return the total impedance.
void menu_op_rc() {
  std::cout << "\n>> RC Circuit\n";
  // initialise the empty variables to accept the input values
  double res;
  double cap;
  double freq;
  double z;
  std::cout << "What is the resistance value? (in Ω)\n";
  std::cin >> res;
  std::cout << "What is the capacitance value? (in F)\n";
  std::cin >> cap;
  std::cout << "What is the frequency (in Hz)?\n";
  std::cin >> freq;

  RC RC;
  // use the RLC object to calculate the total impedence
  z = RC.get_rc_impedance(res, cap, freq);
  // display the result
 // std::cout << "The total impedance is " << z << " Ω.\n";

  // you can call a function from here that handles menu 2
  go_back_to_main();
}

// LC Circuit: Ask for the values of the inductor and capacitor. Also
// ask for the frequency. Then calculate and return the total impedance.
void menu_op_lc() {
  std::cout << "\n>> LC Circuit\n";
  // initialise the empty variables to accept the input values
  double cap;
  double ind;
  double freq;
  double z;
  std::cout << "What is the inductance value? (in H)\n";
  std::cin >> ind;
  std::cout << "What is the capacitance value? (in F)\n";
  std::cin >> cap;
  std::cout << "What is the frequency (in Hz)?\n";
  std::cin >> freq;

LC LC;
  // use the RLC object to calculate the total impedence
  z = LC.get_lc_impedance(cap, ind, freq);
  // you can call a function from here that handles menu 2
  go_back_to_main();
}