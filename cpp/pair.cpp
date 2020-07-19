#include <iostream>
//#include <utility>
//#include <memory>
#include <string>

int main ()
{
    std::pair<int, std::string> pair1;
    pair1.first = 15;
    pair1.second = "Foo";

    //std::pair<int, std::string> pair(pair1);

    std::pair<int, std::string> pair2 = std::make_pair<int, std::string> (12, "Bar");
    std::pair<int, std::string> *pair3 = new std::pair<int, std::string> (17, "Baz");

    std::cout << "pair1.First: " << pair1.first << std::endl;
    std::cout << "pair1.Second: " << pair1.second << std::endl;

    std::cout << "pair2.First: " << pair2.first << std::endl;
    std::cout << "pair2.Second: " << pair2.second << std::endl;

    std::cout << "pair3->First: " << pair3->first << std::endl;
    std::cout << "pair3->Second: " << pair3->second << std::endl;

    return 0;
}

