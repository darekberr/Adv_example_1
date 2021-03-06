#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "positionfinder.hpp"


int main()
{
    std::cout << "Hello Easter Bunny HQ!\n\n" << std::endl;


    std::ifstream myPositionsByText;
    myPositionsByText.open("01_oryginal.txt");
//    myPositionsByText.open("02.txt");

    if(myPositionsByText.fail())
    {
        std::cout << "sorry, can't open it" << std::endl;
        exit(1);
    }

    PositionFinder goForward {};

    if(myPositionsByText.is_open())
    {
        char rotation;
        for (int dist; myPositionsByText >> rotation >> dist; myPositionsByText.ignore(1, ','))
        {
//            std::cout << "Rotation:  " <<  rotation << "  przed  " << dist << std::endl;
            goForward.moveToPosition(rotation, dist);
        }
        goForward.getShortestDistance();
    }

    myPositionsByText.close();

//    PositionFinder goForward33 {};
//    std::vector<std::pair<int, int> >  step33 {std::make_pair(2,4)};
//    goForward33.holdPosition(step33);
//    std::cout << std::get<0>(step33[0]) << " " << std::get<1>(step33[0]) << std::endl;
//    std::cout << "The shortest distance is:  " << goForward33.getShortestDistance() << std::endl;
//    myPositionsByText.close();

    return 0;
}
