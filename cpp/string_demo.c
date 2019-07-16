#include <iostream>
#include <string>

int main ()
{
    // String constructors demo
    std::string s0("Dummy");         // Dummy string.. Will explain more below
    std::cout << "s0: " << s0 << std::endl;

    std::string s1;                  // Constructs an empty string with 0 characters
    std::cout << "s1: " << s1 << std::endl;

    std::string s2(s0);              // Constructs a copy of str;
    std::cout << "s2: " << s2 << std::endl;

    std::string s3(s0, 1, 4);        // Copy sub string from given position and length
    std::cout << "s3: " << s3 << std::endl;

    std::string s4("Hello World");   // Construct string class object from C-string
    std::cout << "s4: " << s4 << std::endl;

    std::string s5(s0, 5);           // Copy first n consecutive characters from s0
    std::cout << "s5: " << s5 << std::endl;

    std::string s6(7, 'j');          // Fill the string with n consecutive copies of the character passed
    std::cout << "s6: " << s6 << std::endl;

    std::string s7(s0.begin(), s0.begin() + 5);  // Copies the sequence of characters in the range [first, last), in the same order
    std::cout << "s7: " << s7 << std::endl;

    // String operation demo
    std::string s8 = s0;             // Assignment operator.. Copies the string 
    std::cout << "s8: " << s8 << std::endl;

    // Capacity related operations demo
    std::cout << "Size of s8 = " << s8.size() << std::endl;     //size() and length() both are synonyms
    std::cout << "Length of s8 = " << s8.size() << std::endl;
    std::cout << "Capacity of s1 = " << s1.capacity() << std::endl;
    std::cout << "max_size of s8 = " << s8.max_size() << std::endl;   //max_size number of characters a string object can hold

    //Element access
    std::cout << "Get character at index 2: " <<  s8.at(2) << std::endl;         //Returns character at given index
#if 0
    std::cout << s8.front() << std::endl;       //Returns first character
    std::cout << s8.back() << std::endl;        //Returns last character
#endif

    std::cout << "C type string: " << s8.c_str() << std::endl;       //Returns C type string
    std::cout << "Append Dummy: " << s4.append(s0, 0, 5) << std::endl;
    std::cout << "Substring Hello " << s4.substr(0, 5) << std::endl;

    std::string s9(s4);
    std::cout << "Erase substring: " << s4.erase(6, 5) << std::endl;

    return 0;
}
