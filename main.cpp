#include <iostream>
#include <memory>

using namespace std;


class bar;

class foo
{
public:
    foo(const std::shared_ptr<bar>& b)
        : forward_reference{b}  { }

private:
    std::shared_ptr<bar> forward_reference;
};



int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
    unsigned a;
    unsigned b;
}
