#include <iostream>
#include <typeinfo>
 
int main ()
{
  using namespace std;
  auto i = 10;   // type of i is int
  cout << "typeid(i) = " << typeid(i).name() << endl;
  
  auto j = 5;   // type of i is int
  cout << "typeid(j) = " << typeid(j).name() << endl;

  auto sum = i + j;  // type sum becomes int
  cout << "typeid(sum) = " << typeid(sum).name() << endl;

  auto sum1 = i + 4.3f;  // type of sum1 becomes float
  cout << "typeid(sum1) = " << typeid(sum1).name() << endl;

  static auto y = 10;
  cout << "typeid(y) = " << typeid(y).name() << endl;

  const int x = 10;
  cout << "typeid(x) = " << typeid(x).name() << endl;

  auto var = x;   // Here qualifier of x which is const is discarded
  cout << "typeid(var) = " << typeid(var).name() << endl;

  const auto var1 = x;
  cout << "typeid(var1) = " << typeid(var1).name() << endl;
 
  auto &var2 = x;  // Here const qualifier of x will not be discarded
  cout << "typeid(var2) = " << typeid(var2).name() << endl;

  auto var3 = &x;  // Here const qualifier of x will not be discarded
  cout << "typeid(var3) = " << typeid(var3).name() << endl;
                   // * is not needed when an address is being assigned to an auto variable

 // auto list {1, 2, 3, 4, 5, 6, 7}; // This is invalid and compiler cannot deduce the type of list as array of integers.
  auto list {1};  // This is valid and compiler can happily deduce the type of list as int.
  cout << "typeid(list) = " << typeid(list).name() << endl;
  
  
  
  return 0;
} 

