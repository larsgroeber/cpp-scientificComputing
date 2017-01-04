#ifndef ROCHE_LIMIT_OBJECT_H
#define ROCHE_LIMIT_OBJECT_H

#include "../helper/include/Vector.h"

namespace LH
{
    /**
     * \brief Definition of a circular object (think planet, asteroid, mass point).
     */
    struct Body
    {
        LH::Vector pos;
        LH::Vector vel;
        long double radius;
        long double mass;
    };
}

#endif //ROCHE_LIMIT_OBJECT_H
