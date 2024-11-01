#include "VECTOR2.h"

VECTOR2 operator+(VECTOR2 vec1, VECTOR2 vec2)
{
    return VECTOR2(vec1.x + vec2.x, vec1.y + vec2.y);
}

VECTOR2 operator-(VECTOR2 vec1, VECTOR2 vec2)
{
    return VECTOR2(vec1.x - vec2.x, vec1.y - vec2.y);
}