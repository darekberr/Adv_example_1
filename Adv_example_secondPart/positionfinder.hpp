#pragma once
#include <vector>
#include <tuple>


class PositionFinder
{
public:
    PositionFinder();
    int moveToPosition(const char directionNext, const int &);
    std::vector<std::pair<int, int>> getPosiotion();
    int getShortestDistance();

private:
    enum class Directions
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    typedef struct StepPosition
    {
        int xPos;
        int yPos;

        bool operator==(const StepPosition & point)
        {
                    return std::tie(xPos, yPos) == std::tie(point.xPos, point.yPos);
        }
    } SingleStep;

    void stepEast (Directions, const int move[], const int& dist);
    void stepNorth (Directions, const int move[], const int& dist);
    void stepSouth (Directions, const int move[], const int& dist);
    void stepWest (Directions, const int move[], const int& dist);
    void holdPosition(const std::pair<int, int> &new_pairPosition);
    void moveOneStepAndValidate(const int& l_x, const int& l_y);
    void printAllMembersOfSteps();

    std::vector<std::pair<int, int>> m_coordinate;
    Directions m_direction;
    SingleStep m_visited;
    std::vector<SingleStep> m_allSteps;
};


template <typename Directions>
auto as_integer(Directions const value)
    -> typename std::underlying_type<Directions>::type
{
    return static_cast<typename std::underlying_type<Directions>::type>(value);
}


template <typename T,typename U, typename V,typename W>
auto operator+(const std::pair<T,U> & l,const std::pair<V,W> & r)
-> std::pair<decltype(l.first+r.first),decltype(l.second+r.second)>
{
    return {l.first+r.first,l.second+r.second};
}
