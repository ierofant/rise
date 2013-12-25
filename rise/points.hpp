#ifndef RISE_POINTS_HPP_INCLUDED
#define RISE_POINTS_HPP_INCLUDED

#include <deque>

namespace rise
{
    struct point
    {
	point(double _x = 0, double _y = 0);
	double x;
	double y;
    };

    typedef std::deque<rise::point> points;
}

#endif //RISE_POINTS_HPP_INCLUDED
