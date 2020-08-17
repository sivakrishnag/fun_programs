#include "Integer.h"
#include <iostream>

Integer Add(const Integer &a, const Integer &b)
{
  Integer temp;
  temp.SetValue(a.GetValue() + b.GetValue());
  return temp;
}

int main ()
{
  Integer i(20);
  Integer i1;
  Integer i2;

  i1 = i2 = i;
  
  std::cout << "Value in i: " << i.GetValue() << std::endl;
  std::cout << "Value in i1: " << i1.GetValue() << std::endl;
  return 0;
}

