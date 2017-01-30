#include <iostream>
#include <memory>
#include <fstream>

using namespace std;


//class bar;

//class foo
//{
//public:
//    foo(const std::shared_ptr<bar>& b)
//        : forward_reference{b}  { }

//private:
//    std::shared_ptr<bar> forward_reference;
//};



int main(int argc, char *argv[])
{
    cout << "Hello Easter Bunny HQ!" << endl;

    string x;
    int count_position;
    count_position = 0;


    ifstream myPositionsByText;
    myPositionsByText.open("01.txt");
    char outputSteps;
    if(myPositionsByText.is_open())
    {
        while(!myPositionsByText.eof())
        {
            myPositionsByText >> outputSteps;
            cout << outputSteps;
        }
    }

//    fstream fcin;

    return 0;
//    unsigned a;
//    unsigned b;
}
