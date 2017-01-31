#include <iostream>
#include <fstream>
#include <set>



int main()
{
    std::cout << "Hello Easter Bunny HQ!\n\n" << std::endl;

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

        std::set<std::pair<int, int>> visited;
        int  pos[2]{0, 0};
        char d;

        for (int index{1}, dist; myPositionsByText >> d >> dist; myPositionsByText.ignore(1, ','))
        {
            std::cout << "Idx start " << index << "  " <<  d << "  przed  " << dist << std::endl;
            std::cout << ~d << "  " << ~'P' << std::endl;
            index += ~d & 3;
            std::cout << "Idx po kroku  " << index << "  " <<  d << "  " << dist << std::endl;
            std::cout << "Position before move  " << pos[index & 1] << " " << pos[index & 2]  << std::endl;

            for (int i{0}; i < dist; ++i)
            {
              pos[index & 1] += 1 - (index & 2);
              std::cout << "Position afte move  " << pos[index & 1] << " " << pos[index & 2]  << std::endl;

              if (!visited.emplace(pos[0], pos[1]).second)
              {
                std::cout << "Coś się dzieje  " << (std::abs(pos[0]) + std::abs(pos[1])) << std::endl;
//                return;
              }
            }
        }

        while(!myPositionsByText.eof())
        {
            std::getline(myPositionsByText, outputSteps);

            //myPositionsByText >> outputSteps;
            std::cout << outputSteps << std::endl;


//            int i;
//            for (i = 0; i < outputSteps.length(); i++)
//            {
//                if(outputSteps[i] == '(')
//                    count_position++;
//                else if (outputSteps[i] == ' ' || outputSteps[i] == ',' ) continue;
//                else
//                {
//                    std::cout << outputSteps[i] << std::endl;
//                    count_position--;
//                }
//            }
        }
        myPositionsByText.close();
    }

    return 0;
}
