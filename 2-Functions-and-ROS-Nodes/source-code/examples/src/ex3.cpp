  #include <iostream> 

  int increment(int &value) {
      value++;
    return value;
  }

  int main() {

      int num = 10;
      int total = increment(num);
      std::cout << "num value: " << num << std::endl;
      std::cout << "total value: " << total << std::endl; 
      return 0;
  }