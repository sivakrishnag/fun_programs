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

/* If array is passed as a reference, to a function, then its size must be mentioned */
void printArray (int (&p)[5])
{
    using namespace std;
    for (int i = 0; i < sizeof(p)/sizeof(p[0]); i++)
    {
        cout << "p[i] = " << p[i] << endl;
    }
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

  int arr[] {1, 2, 3, 4, 5};
  cout << "arr[1] = ";
  Print(arr[1]);
  printArray(arr);

  return 0;
}
