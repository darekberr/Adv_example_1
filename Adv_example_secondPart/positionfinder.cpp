#include <iostream>
//#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include "positionfinder.hpp"


PositionFinder::PositionFinder()
    : m_coordinate {std::make_pair(0, 0)}, m_direction{Directions::NORTH}, m_visited {0, 0}, m_allSteps{0}
{}


void PositionFinder::holdPosition(const std::pair<int, int> & new_pairPosition)
{
    typedef std::vector<std::pair<int,int>> VectorOfPair;
    typedef std::pair<int,int> Pair;

    Pair tempPair;
    tempPair = tempPair + new_pairPosition;
//    std::cout << "Starting _temp pair is:  " << tempPair.first << " " << tempPair.second << std::endl;

    VectorOfPair tempCoordinate; tempCoordinate.push_back(tempPair);

    auto backIt = m_coordinate.end()-1;
    tempPair = std::make_pair(backIt->first + tempPair.first, backIt->second + tempPair.second);
//    std::cout << "Latest pair _temp pair is:  " << tempPair.first << " " << tempPair.second << std::endl;

    typedef std::vector<SingleStep>::iterator ITER;
    ITER itMsteps (m_allSteps.begin()), itMstepsEnd(m_allSteps.end()-1);


    m_coordinate.push_back(tempPair);
//    auto back_it = m_coordinate.end()-1;
//    std::cout << "Only last element m_coordinate:  " << back_it->first << " " << back_it->second << std::endl;
}

int PositionFinder::moveToPosition(const char directionNext, const int& step)
{
//    std::cout << "Current direction is (before): " << as_integer(m_direction) << std::endl;

    int  pos[2] {};

    switch (directionNext)
    {
    case 'L':
        m_direction = static_cast<Directions>( (as_integer(m_direction) +3) %4);

        break;
    case 'R':
        m_direction = static_cast<Directions>( (as_integer(m_direction) +1) %4);
        break;
    default:
        std::cerr << "Invalid instruction for move" << std::endl;
        return(1);
    }
//    std::cout << "Current direction is (Changed): " << as_integer(m_direction) << std::endl;

    switch (m_direction)
    {
    case Directions::EAST:
        pos[0] = 1; pos[1] = 0;
        stepEast(m_direction, pos, step);
        break;

    case Directions::NORTH:
        pos[0] = 0; pos[1] = 1;
        stepNorth(m_direction, pos, step);
        break;

    case Directions::SOUTH:
        pos[0] = 0; pos[1] = -1;
        stepSouth(m_direction, pos, step);
        break;

    case Directions::WEST:
        pos[0] = -1; pos[1] = 0;
        stepWest(m_direction, pos, step);
        break;
    default:
        std::cerr << "I wont' move anywhere" << std::endl;
        break;
    }

    return 0;
}


std::vector<std::pair<int, int>> PositionFinder::getPosiotion()
{
    std::cout << std::get<0>(m_coordinate[0]) << " " << std::get<1>(m_coordinate[0]) << std::endl;
    return m_coordinate;
}


int PositionFinder::getShortestDistance()
{
    std::cout << "Shortest distance: ";
    auto back_it = m_coordinate.end()-1;
    std::cout << std::abs(back_it->first) + std::abs(back_it->second) << std::endl;
    return std::abs(back_it->first) + std::abs(back_it->second);
//    std::cout << std::abs(std::get<0>(m_coordinate[0])) + std::abs(std::get<1>(m_coordinate[0])) << std::endl;
//    return std::abs(std::get<0>(m_coordinate[0])) + std::abs(std::get<1>(m_coordinate[0]));
}


void PositionFinder::moveOneStepAndValidate(const int& l_x, const int& l_y)
//void PositionFinder::moveOneStepAndValidate()
{
//    typedef std::vector<SingleStep>::iterator ITER;
    SingleStep pointed;
    pointed.xPos = l_x; pointed.yPos = l_y;
    m_allSteps.push_back(pointed);

//    ITER itMsteps (m_allSteps.begin()), itMstepsEnd(m_allSteps.end()-1);

//  Print all members of struct
//    for ( ; itMsteps !=itMstepsEnd; itMsteps++)
//    {
//        std::cout << "Member of struct  " << itMsteps->xPos << "  " << itMsteps->yPos << std::endl;
//    }


    auto visitedPosition = std::find(m_allSteps.begin(), m_allSteps.end()-1, pointed);

    if( visitedPosition != m_allSteps.end()-1)
    {
        std::cout << "\tI got it!  " << visitedPosition->xPos << " " << visitedPosition->yPos
                  << "\n\t  and the shortest distance from block is  "
                  << std::abs(visitedPosition->xPos) + std::abs(visitedPosition->yPos)
                  << "\n\tAnd the m_allSteps are:  " << (m_allSteps.end()-1)->xPos << "  " << (m_allSteps.end()-1)->yPos << std::endl;
    }

}

void PositionFinder::stepEast(Directions, const int move[], const int &dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//              << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairEast {std::make_pair(move[0]*dist, move[1]) };

    for(auto step = 0; step < dist; ++step)
    {
        m_visited.xPos += 1;
        moveOneStepAndValidate( m_visited.xPos, m_visited.yPos);
        std::cout << "Kolejne kroki na EAST:  " << m_visited.xPos << "  " << m_visited.yPos << std::endl;
    }

    holdPosition(pairEast);
}

void PositionFinder::stepNorth(Directions, const int move[], const int& dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//                  << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairNorth {std::make_pair(move[0], move[1]*dist)};

    for(auto step = 0; step < dist; ++step)
    {
        m_visited.yPos += 1;
        moveOneStepAndValidate( m_visited.xPos, m_visited.yPos);
        std::cout << "Kolejne kroki na NORTH:  " << m_visited.xPos << "  " << m_visited.yPos << std::endl;
    }

    holdPosition(pairNorth);

//    auto back_it = m_coordinate.end()-1;
//    std::cout << "Only last element(NORTH):  " << back_it->first << " " << back_it->second << std::endl;
}

void PositionFinder::stepSouth(Directions, const int move[], const int& dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//                  << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairSouth {std::make_pair(move[0], move[1]*dist)};


    for(auto step = 0; step < dist; ++step)
    {
        m_visited.yPos -= 1;
        moveOneStepAndValidate( m_visited.xPos, m_visited.yPos);
        std::cout << "Kolejne kroki na SOUTH:  " << m_visited.xPos << "  " << m_visited.yPos << std::endl;
    }

    holdPosition(pairSouth);

//    auto back_it = m_coordinate.end()-1;
//    std::cout << "Only last element(SOUTH):  " << back_it->first << " " << back_it->second << std::endl;
}

void PositionFinder::stepWest(Directions, const int move[], const int& dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//              << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairWest {std::make_pair(move[0]*dist, move[1])};

    for(auto step = 0; step < dist; ++step)
    {
        m_visited.xPos -= 1;
        moveOneStepAndValidate( m_visited.xPos, m_visited.yPos);
        std::cout << "Kolejne kroki na WEST:  " << m_visited.xPos << "  " << m_visited.yPos << std::endl;
    }

    holdPosition(pairWest);

//    auto back_it = m_coordinate.end()-1;
//    std::cout << "Only last element(WEST):  " << back_it->first << " " << back_it->second << std::endl;
}
