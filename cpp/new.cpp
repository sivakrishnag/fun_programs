#include <iostream>
#include <string.h>

void New ()
{
  int *p = new int(5);
  *p = 7;

  std::cout << *p << std::endl;
  delete p;
  p = nullptr;
}

void NewArrays ()
{
  int *p = new int[5];
  
  for (int i = 0; i < 5; i++)
  {
    p[i] = i;
  }

  delete []p;
}

void Strings()
{
  char *p = new char[4];
  strcpy(p, "C++");
  std::cout << p << std::endl;
  delete []p;
}

int main ()
{
  New();
  NewArrays();
  Strings();

  return 0;
}
