#include <iostream>
#include <utility>
#include "positionfinder.hpp"


PositionFinder::PositionFinder()
    : m_coordinate {std::make_pair(0, 0)}, m_direction{Directions::NORTH}
{}


void PositionFinder::holdPosition(std::vector<std::pair<int, int>> new_position)
{
    m_coordinate = new_position;
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
    std::cout << std::abs(std::get<0>(m_coordinate[0])) + std::abs(std::get<1>(m_coordinate[0])) << std::endl;
    return std::abs(std::get<0>(m_coordinate[0])) + std::abs(std::get<1>(m_coordinate[0]));
}


void PositionFinder::stepEast(Directions, const int move[], const int &dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//              << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairEast {std::make_pair(move[0], move[1]*dist)};

    std::get<0>(m_coordinate[0]) += pairEast.first;
    std::get<1>(m_coordinate[0]) += pairEast.second;

    std::cout << "Position moved to coordinate:  "
              << std::get<0>(m_coordinate[0])
              << "  " << std::get<1>(m_coordinate[0]) << std::endl;
}

void PositionFinder::stepNorth(Directions, const int move[], const int& dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//                  << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairNorth {std::make_pair(move[0], move[1]*dist)};

    std::get<0>(m_coordinate[0]) += pairNorth.first;
    std::get<1>(m_coordinate[0]) += pairNorth.second;

    std::cout << "Position moved to coordinate:  "
              << std::get<0>(m_coordinate[0])
              << "  " << std::get<1>(m_coordinate[0]) << std::endl;
}

void PositionFinder::stepSouth(Directions, const int move[], const int& dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//                  << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairSouth {std::make_pair(move[0], move[1]*dist)};

    std::get<0>(m_coordinate[0]) += pairSouth.first;
    std::get<1>(m_coordinate[0]) += pairSouth.second;

    std::cout << "Position moved to coordinate:  "
              << std::get<0>(m_coordinate[0])
              << "  " << std::get<1>(m_coordinate[0]) << std::endl;
}

void PositionFinder::stepWest(Directions, const int move[], const int& dist)
{
//    std::cout << "Instruction(s):  " << as_integer(m_direction) << "  MOVE: " << move[0] << "  " << move[1]
//              << "   DIST: " << dist << std::endl;
    std::pair<int, int> pairWest {std::make_pair(move[0]*dist, move[1])};

    std::get<0>(m_coordinate[0]) += pairWest.first;
    std::get<1>(m_coordinate[0]) += pairWest.second;

    std::cout << "Position moved to coordinate:  "
              << std::get<0>(m_coordinate[0])
              << "  " << std::get<1>(m_coordinate[0]) << std::endl;
}
