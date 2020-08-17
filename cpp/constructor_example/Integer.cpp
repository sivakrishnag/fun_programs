#include "Integer.h"
#include <iostream>

Integer::Integer()
{
  std::cout << "Default constructor: Integer()" << std::endl;
  m_pInt = new int(0);
}

Integer::Integer(int value)
{
  std::cout << "Parameterized constructor: Integer(int)" << std::endl;
  m_pInt = new int(value);
}

Integer::Integer(const Integer &src)
{
  std::cout << "Copy constructor: Integer(const Integer&)" << std::endl;
  m_pInt = new int(*src.m_pInt);
}

#ifdef __HAVE_MOVE__
Integer::Integer(Integer &&src)
{
  std::cout << "Move constructor: Integer(Integer&&)" << std::endl;
  m_pInt = src.m_pInt;
  src.m_pInt = nullptr;
}
#endif

Integer&
Integer::operator =(const Integer &rvalue)
{
  std::cout << "Assignment operator: Integer(const Integer&)" << std::endl;
  if (&rvalue == this) {
    return *this;
  }
  
  *m_pInt = *rvalue.m_pInt;
  return *this;
}

int Integer::GetValue() const
{
  std::cout << "GetValue()" << std::endl;
  return *m_pInt;
}

void Integer::SetValue(int value)
{
  std::cout << "SetValue()" << std::endl;
  *m_pInt = value;
}

Integer::~Integer()
{
  std::cout << "Destructor: ~Integer()" << std::endl;
  delete m_pInt;
}
