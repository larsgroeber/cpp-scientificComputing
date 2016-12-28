#ifndef ROCHE_LIMIT_SIMULATION_H
#define ROCHE_LIMIT_SIMULATION_H

#include <vector>
#include "Body.h"

namespace LH
{
    /**
     * \brief Main simulation
     * Defines everythin regarding the simulation, like potentials, main loop etc.
     */
    class Simulation
    {
    public:
        Simulation ();

        virtual ~Simulation ();

        void run ();

    private:
        /**
         * \brief Calculates the gravity acting on A given object B.
         * If you want to calculate the force acting on B just reverse the vector.
         * \param A Object on which the force acts.
         * \param B Object which "generates" the force.
         * \return The force vector pointing from A to B.
         */
        LH::Vector gravity ( const LH::Body* A, const LH::Body* B ) const;
        std::vector<LH::Body*> _massPoints;
    };
}

#endif //ROCHE_LIMIT_SIMULATION_H
