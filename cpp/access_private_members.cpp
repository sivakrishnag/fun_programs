/*
 * If we pass a pointer to another object of the same class. using this second pointer we will be able to access private members
 */

#include <iostream>

class Animal
{
    public:
        /* Default Constructor */
        Animal()
        {
            std::cout << "class Animal: Default constructor called" << std::endl;
            _name = std::string("Animal");
        }

        /* Constructor with an argument */
        Animal(std::string name)
        {
            _name = name;
        }

        /* Copy construtor */
        Animal(const Animal &src)
        {
            this->_name = src._name;  // >>>>>>>>>>>>>>>>>>This is Okay..!!!!
        }
        
        /* Destructor */
        ~Animal()
        {
            std::cout << "class Animal: destructor called" << std::endl;
        }

    private:
        std::string _name;
};

class Bird
{
    public:
        /* Default Constructor */
        Bird()
        {
            std::cout << "class Bird: Default constructor called" << std::endl;
            _name = std::string("Bird");
        }

        /* Constructor with an argument */
        Bird(std::string name)
        {
            _name = name;
        }

        /* Copy construtor */
        Bird(const Animal &src)
        {
#if 0
            this->_name = src._name;  // >>>>>>>>>>>>>>>>>>This is *not* Okay..!!!
#endif
        }

        /* Destructor */
        ~Bird()
        {
            std::cout << "class Bird: destructor called" << std::endl;
        }

        /* Method */
        std::string
        get_animal_name (const Animal &other)
        {
            std::cout << "Other class object's private member access is restricted" << std::endl;
#if 0
            return other._name;       // >>>>>>>>>>>>>>>>>>This is *not* Okay..!!!
#endif
            return std::string("Access restricted");
        }

        /* method */
        std::string
        get_bird_name (const Bird &other)
        {
            std::cout << "Same class object's private member access is allowed" << std::endl;
            return other._name;
        }

    private:
        std::string _name;
};

int main ()
{
    Animal s(std::string("Elephant"));
    Bird t(std::string("Peacock"));

    std::cout << "Animal name from Bird class instance: " << t.get_animal_name(s) << std::endl;
    std::cout << "Bird name from Bird class instance: " << t.get_bird_name(t) << std::endl;

    return 0;
}
