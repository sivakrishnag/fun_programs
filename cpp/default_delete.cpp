#include <iostream>

class Integer
{
  int m_Value{0};

public:
  Integer() = default; //Without this, compiler won't synthesize default constructor

  Integer(int value)
  {
    using namespace std;
    cout << "Integer(int value)" << endl;
    m_Value = value;
  }

  Integer(const Integer &) = delete;
  Integer(float) = delete;
};

int main ()
{
  Integer i1; //This wouldn't have been possible without 
              //either default keyword or explicity default constructor code
  Integer i2(3);
  Integer i3(i2); //This will not work as copy constructor has been marked as delete;
  //Integer f(3.2f); // This will not work

  return 0;
}
