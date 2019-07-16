#include <iostream>
#include <vector>

class Sample
{
    public:
    Sample (std::string str) : _name(str)
    {
        _name = str;
        std::cout << _name << ": Constructor called" << std::endl;
    }

    Sample (const Sample &s)
    {
        //_name = s.get_name();
        _name = s._name + ".d";
        std::cout << _name << ": Copy constructor called" << std::endl;
    }

    ~Sample ()
    {
        std::cout << _name << ": Destructor called" << std::endl;
    }

    std::string get_name()
        {
            return _name;
        }

    private:
        std::string _name;
};

int main ()
{
    Sample s1(std::string("SivaG1"));
    Sample s2(std::string("SivaG2"));
    Sample s3(std::string("SivaG3"));

    std::vector<Sample> v;
    std::cout << "*** Before pushing s1 ***" << std::endl;
    v.push_back(s1);
    std::cout << "*** After pushing s1 ***" << std::endl;

    std::cout << "*** Before pushing s2 ***" << std::endl;
    v.push_back(s2);
    std::cout << "*** After pushing s2 ***" << std::endl;

    std::cout << "*** Before pushing s3 ***" << std::endl;
    v.push_back(s3);
    std::cout << "*** After pushing s3 ***" << std::endl;

    return 0;
}
