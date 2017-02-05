#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "positionfinder.hpp"


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

    //Oversee initialization
    PositionFinder goForward {};
    std::vector<std::pair<int, int> >  middleStep;
    middleStep = goForward.getPosiotion();


    if(myPositionsByText.is_open())
    {
        char rotation;
        for (int dist; myPositionsByText >> rotation >> dist; myPositionsByText.ignore(1, ','))
        {
            std::cout << "Rotation:  " <<  rotation << "  przed  " << dist << std::endl;
            goForward.moveToPosition(rotation, dist);
//            goForward.getShortestDistance();
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


//  Second solution with indexes!
//    std::string outputSteps;
//    if(myPositionsByText.is_open())
//    {
//        int  pos[2]{0, 0};
//        char rotation;

//        for (int index{1}, dist; myPositionsByText >> rotation >> dist; myPositionsByText.ignore(1, ','))
//        {
//                std::cout << "Idx start " << index << "  " <<  rotation << "  przed  " << dist << std::endl;
//            index += ~rotation & 3;
//                std::cout << "Idx po kroku  " << index << std::endl;
//            std::cout << "Position Before move  " << pos[0] << " " << pos[1]  << std::endl;

//            for (int step{0}; step < dist; ++step)
//            {
//              pos[index & 1] += 1 - (index & 2);
//            }
//            std::cout << "Position After move  " << pos[0] << " " << pos[1]  << std::endl;
//            std::cout << (std::abs(pos[0]) + std::abs(pos[1])) << std::endl;
//        }
//    }
//    myPositionsByText.close();

    return 0;
}
