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

        /**
         * @brief calls function gravity and writes all data into a stream thats passed on to gnuplot later
         */
        void run ();

        /**
         * @brief creates a bodyCloud in the shape of an archimedic spiral and adds it to _massPoints
         */
        void buildSpiral ();

//        void LH::Simulation::buildAsteroid ();

        /**
         * @brief creates a body cloud by placing particles around a massive one in the middle and let gravity do its work
         * @param massPoints
         * @param n number of particles ( n = 6*x+1 , x element of N)
         * @param diam diameter of particles
         */
//        void bodyCloudInit ( Vector massPoints, int n, double diam );

        /**
         * @brief creates a point cloud in a honeycomb shape, by placing circles layerwise around the first
         * @param massPoints
         * @param n number of particles ( n = 6*x+1 , x element of N)
         * @param diam diameter of particles
         */
//        void LH::Simulation::HoneycombBodyCloud ( Vector massPoints, int n, double diam );

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
        std::vector<LH::Body*> _bodyCloud;
    };
}

#endif //ROCHE_LIMIT_SIMULATION_H
