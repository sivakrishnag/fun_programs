#include <iostream>

class Car {
public:
   Car ()
   {
     std::cout << "Car()" << std::endl;
     
     fuel = 0;
     speed = 0;
     passengers = 0;
   }
   
   Car (float amount)
   {
     std::cout << "Car(float amount)" << std::endl;
   
     fuel = amount;
     speed = 0;
     passengers = 0;
   }
   
   void dashboard () const
   {
     using namespace std;
     cout << "Fuel = " << fuel << endl;
     cout << "Speed  = " << speed << endl;
     cout << "Passengers  = " << passengers << endl;
   }

   void dashboard1 ()
   {
     using namespace std;
     cout << "Fuel = " << fuel << endl;
     cout << "Speed  = " << speed << endl;
     cout << "Passengers  = " << passengers << endl;
   }
   
   ~Car ()
   {
     std::cout << "~Car()" << std::endl;
   }

private:
   float fuel;
   float speed;
   int passengers;
};

int main ()
{
  const Car c;
  c.dashboard();
  //c.dashboard1(); // const objects can only call const member functions
  return 0;
}
