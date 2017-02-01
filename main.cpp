#include <iostream>
#include <fstream>



int main()
{
    std::cout << "Hello Easter Bunny HQ!\n\n" << std::endl;


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
        int  pos[2]{0, 0};
        char rotation;

        for (int index{1}, dist; myPositionsByText >> rotation >> dist; myPositionsByText.ignore(1, ','))
        {
//                std::cout << "Idx start " << index << "  " <<  rotation << "  przed  " << dist << std::endl;
            index += ~rotation & 3;
//                std::cout << "Idx po kroku  " << index << std::endl;
            std::cout << "Position Before move  " << pos[0] << " " << pos[1]  << std::endl;

            for (int step{0}; step < dist; ++step)
            {
              pos[index & 1] += 1 - (index & 2);
            }
            std::cout << "Position After move  " << pos[0] << " " << pos[1]  << std::endl;
            std::cout << (std::abs(pos[0]) + std::abs(pos[1])) << std::endl;
        }



//        while(!myPositionsByText.eof())
//        {
//            std::getline(myPositionsByText, outputSteps);

//            //myPositionsByText >> outputSteps;
//            std::cout << outputSteps << std::endl;

//        }
    }    myPositionsByText.close();

    return 0;
}
