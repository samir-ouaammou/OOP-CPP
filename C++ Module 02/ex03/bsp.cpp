#include "Point.hpp"
#include <cmath>

float   distance(Point const &A, Point const &B)
{
    float dx = A.getX().toFloat() - B.getX().toFloat();
    float dy = A.getY().toFloat() - B.getY().toFloat();
    return (std::sqrt(dx * dx + dy * dy));
}

float   heronArea(float a, float b, float c)
{
    float s = (a + b + c) / 2.0f;
    return (std::sqrt(s * (s - a) * (s - b) * (s - c)));
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    float ab = distance(a, b);
    float bc = distance(b, c);
    float ca = distance(c, a);

    float ap = distance(a, point);
    float bp = distance(b, point);
    float cp = distance(c, point);

    float areaABC = heronArea(ab, bc, ca);
    float areaABP = heronArea(ab, ap, bp);
    float areaBCP = heronArea(bc, bp, cp);
    float areaCAP = heronArea(ca, cp, ap);

    if (areaABP == 0 || areaBCP == 0 || areaCAP == 0)
        return (false);

    float total = areaABP + areaBCP + areaCAP;
    
    return (std::fabs(total - areaABC) < 0.0001f);
}
