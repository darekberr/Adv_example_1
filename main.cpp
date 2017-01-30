#include <iostream>
#include <memory>
#include <fstream>

//using namespace std;


//class bar;

//class foo
//{
//public:
//    foo(const std::shared_ptr<bar>& b)
//        : forward_reference{b}  { }

//private:
//    std::shared_ptr<bar> forward_reference;
//};



int main()
{
    std::cout << "Hello Easter Bunny HQ!" << std::endl;

    int count_position = 0;


    std::ifstream myPositionsByText;
    myPositionsByText.open("01.txt");

    if(myPositionsByText.fail())
    {
        std::cout << "sorry, can't open it" << std::endl;
        exit(1);
    }

    std::string outputSteps;
    if(myPositionsByText.is_open())
    {
        while(!myPositionsByText.eof())
        {
            myPositionsByText >> outputSteps;
            std::cout << outputSteps << std::endl;

            int i;
            for (i = 0; i < outputSteps.length(); i++)
            {
                if(outputSteps[i] == '(')
                    count_position++;
                else
                {
                    std::cout << outputSteps[i] << std::endl;
                    count_position--;
                }
            }

            std::cout << count_position << std::endl;
        }
    }
    myPositionsByText.close();


    std::cout << count_position << std::endl;

    return 0;
}
