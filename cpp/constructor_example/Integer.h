#include <iostream>
class Integer
{
  int *m_pInt;
public:
  //Default constructor
  Integer ();
  
  //Parameterized constructor
  Integer (int value);

  //Copy constructor
  Integer (const Integer &src);

#ifdef __HAVE_MOVE__
  //Move constructor
  Integer (Integer &&src);
#endif

  //Assignment operator
  Integer& operator =(const Integer &rvalue);

  int GetValue() const;
  void SetValue(int value);

  //Destructor
  ~Integer();
};
