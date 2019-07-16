// shared_ptr constructor example
#include <iostream>
#include <memory>

class CyclicDemo
{
    private:
    std::shared_ptr<CyclicDemo> var;
    //std::weak_ptr<CyclicDemo> var;
    std::string name;

    public:
        CyclicDemo(std::string my_name) {
            name = my_name;
            std::cout << name << ": CyclicDemo Constructor" << std::endl;
        }

        ~CyclicDemo() {
            std::cout << name << ": CyclicDemo Destructor" << std::endl;
        }

        void
        set_var(std::shared_ptr<CyclicDemo> v) {
          var = v;
        }

        std::string
        get_name() {
            return name;
        }
};

int main ()
{
    std::cout << "Main function start" << std::endl;
        std::shared_ptr<CyclicDemo> a = std::make_shared<CyclicDemo>(std::string("a"));
        std::cout << a->get_name() << ": use_count = " << a.use_count() << std::endl;

        std::shared_ptr<CyclicDemo> b = std::make_shared<CyclicDemo>(std::string("b"));
        std::cout << a->get_name() << ": use_count = " << a.use_count() << std::endl;
        std::cout << b->get_name() << ": use_count = " << b.use_count() << std::endl;

        a->set_var(b);
        std::cout << a->get_name() << ": use_count = " << a.use_count() << std::endl;
        std::cout << b->get_name() << ": use_count = " << b.use_count() << std::endl;
        b->set_var(a);
        std::cout << a->get_name() << ": use_count = " << a.use_count() << std::endl;
        std::cout << b->get_name() << ": use_count = " << b.use_count() << std::endl;
    std::cout << "Main function end" << std::endl;

    return 0;
}
