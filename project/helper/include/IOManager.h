#ifndef TEST_GRAVITY_IO_H
#define TEST_GRAVITY_IO_H

#include <string>
#include <fstream>

namespace LH
{
    class IOManager
    {
    public:
        /**
         * \brief Constructor
         * \param fileName Path to the file being used
         */
        IOManager ( const std::string fileName );

        /**
         * \brief Destructor
         * Closes file.
         */
        virtual ~IOManager ();

        /**
         * \brief Template function to write into the file.
         * \param o The value which will be written into the file.
         */
        template <typename T>
        void operator<< ( T o )
        {
            file << o;
        }

    private:
        /** File to write into */
        std::ofstream file;

    };
}

#endif //TEST_GRAVITY_IO_H
