#ifndef ROCHE_LIMIT_SIMULATION_H
#define ROCHE_LIMIT_SIMULATION_H

#include <vector>
#include "Body.h"
#include "../graphics/graphic.h"
#include "Constants.h"

namespace LH
{
    /**
     * \brief Main simulation
     * Defines everything regarding the simulation, like potentials, main loop etc.
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
#ifdef GRAPHICS
        void make_graphics ();
        Graphic _graphic;
#endif
        /**
         * \brief Resolves the collision between A and B.
         * We use an inelastic impact.
         * \param A LH::Body
         * \param B LH::Body
         */
        void collision ( LH::Body* A, LH::Body* B );

        /**
         * \brief Calculates the gravity acting on A given object B.
         * If you want to calculate the force acting on B just reverse the vector.
         * \param A Object on which the force acts.
         * \param B Object which "generates" the force.
         * \return The force vector pointing from A to B.
         */
        LH::Vector gravity ( const LH::Body* A, const LH::Body* B ) const;

        /** Vector holding all bodies */
        std::vector<LH::Body*> _massPoints;

        /** Viewpoint for the camera */
        LH::Body* _view;
        /** The planet */
        LH::Body* _planet;
    };
}

#endif //ROCHE_LIMIT_SIMULATION_H
