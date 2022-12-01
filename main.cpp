#include <iostream>
#include <regex>

void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);
void menu_item_1();
void menu_item_2();
//void menu_item_3(); 
//void menu_item_4();
//void menu_item_5();
double a = 0;
double b = 0;
float PI = 3.1415926535;

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
  int menu_items = 3;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
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
      menu_item_1();
      break;
    case 2:
      menu_item_2();
      break;
    //case 3:
      //menu_item_3();
      //break;
    //case 4:
      //menu_item_4();
      //break;
    //case 5:
      //menu_item_5();
      //break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n----------- Main menu -----------\n";
  std::cout << "|\t\t\t\t\t\t|\n";
  std::cout << "|\t1. parallel\t\t\t|\n";
  std::cout << "|\t2. series\t\t\t|\n";
  std::cout << "|\t3. Exit\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t|\n";
  std::cout << "---------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to add another resistor: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void menu_item_1() {
  std::cout << "\n>> parallel\n";
  std::cout << "\nSelect an integer\n";
  std::cin >> a;
  std::cout << "\nSelect another integer\n";
  std::cin >> b;
  std::cout << "The final resistance of these two resistors is " << (a*b)/(a+b) << " Ω.\n";
  // you can call a function from here that handles menu 1
  go_back_to_main();
}
void menu_item_2() {
  std::cout << "\n>> series\n";
  std::cout << "\nSelect an integer\n";
  std::cin >> a;
  std::cout << "\nSelect another integer\n";
  std::cin >> b;
  std::cout << "The difference of these 2 integers is " << a+b << " Ω.\n";
  // you can call a function from here that handles menu 2
  go_back_to_main();
}