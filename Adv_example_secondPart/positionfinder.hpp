#pragma once
#include <vector>


class PositionFinder
{
public:
    PositionFinder();
//    void holdposition(const int &a, const int &b);
//    void holdPosition(const std::pair<int, int> &new_pairPosition);
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

    void stepEast (Directions, const int move[], const int& dist);
    void stepNorth (Directions, const int move[], const int& dist);
    void stepSouth (Directions, const int move[], const int& dist);
    void stepWest (Directions, const int move[], const int& dist);
    void holdPosition(const std::pair<int, int> &new_pairPosition);

    std::vector<std::pair<int, int>> m_coordinate;

    Directions m_direction;
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
