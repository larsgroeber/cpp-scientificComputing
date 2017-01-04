#ifndef CPP_SCIENTIFICCOMPUTING_BODYCLOUD_H
#define CPP_SCIENTIFICCOMPUTING_BODYCLOUD_H

namespace LH
{
//    class BodyCloud
//    {
//    public:
//        BodyCloud ();
//
//        virtual ~BodyCloud ();

        /**
         * @brief creates a bodyCloud in the shape of an archimedic spiral
         */
        void LH::BodyCloud::buildSpiral ();

//    private:

        std::vector<LH::Body*> _bodyCloud;

//    };
}

#endif //CPP_SCIENTIFICCOMPUTING_BODYCLOUD_H