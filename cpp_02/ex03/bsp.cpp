#include "Point.hpp"

static Fixed crossProduct(const Point p1, const Point p2, const Point p3)
{
    return Fixed((p1.getXcord() - p3.getXcord()) * (p2.getYcord() - p3.getYcord())) - ((p2.getXcord() - p3.getXcord()) * (p1.getYcord() - p3.getYcord()));
}

//* Uses crossProduct
//* AB * AP
//* BC * BP
//* CA * CP
bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    if (a.getXcord() == b.getXcord() && a.getYcord() == b.getYcord())
        return (false);
    if (b.getXcord() == c.getXcord() && b.getYcord() == c.getYcord())
        return (false);
    if (c.getXcord() == a.getXcord() && c.getYcord() == a.getYcord())
        return (false);
    if (crossProduct(a, b, c) == Fixed(0))
        return false;
    Fixed cross1 = crossProduct(a, b, point);
    Fixed cross2 = crossProduct(b, c, point);
    Fixed cross3 = crossProduct(c, a, point);

    bool has_neg, has_pos;

    has_neg = (cross1 <= Fixed(0)) || (cross2 <= Fixed(0)) || (cross3 <= Fixed(0));
    has_pos = (cross1 >= Fixed(0)) || (cross2 >= Fixed(0)) || (cross3 >= Fixed(0));

    return !(has_neg && has_pos);
}