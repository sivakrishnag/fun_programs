#include <iostream>

void Swap (int &x, int &y) 
{
   int temp = x;
   x = y;
   y = temp;
}

void Print (int &p)
{
  using namespace std;
  cout << p << endl;
}

int main ()
{
  using namespace std;
  int a = 5, b = 10;

  Swap(a, b);
  cout << "a: ";
  Print(a);

  cout << "b: ";
  Print(b);

  //Print(nullptr); // This leads to compilation error
  return 0;
}
