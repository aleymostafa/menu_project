#include <iostream>

int main() {
  // when we dynamically create an array, we can specify the length
  // of the array using a variable
  int n = 10;
  int *array = new int[n];
std::cin>>n;
  // iterate over the loop and set the elements to some values
  for (int i = 0; i < n; i++) {
    std::cout << "Resistor Value " << i << " = "  << std::endl;
    std::cin>>array[i+1];
  }
  
  // when we've finished, delete the memory and null the pointer to be safe
   for (int i = 0; i < n; i++) {
   // array[i] = i * i;
    std::cout << "array[" << i << "] = " << array[i] << std::endl;
  }
  
  delete[] array;
  array = nullptr;
}
return new_sum