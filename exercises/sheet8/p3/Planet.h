/**
 * Solution to problem 3 sheet 8
 * by Lars Gröber and Hendrik Edelmann
 *
 * (the main.cpp file just shows how to use the class and can be deleted)
 */

#ifndef P3_PLANET_H
#define P3_PLANET_H

#include <string>

class Planet
{
public:
    /**
     * \brief Constructor
     * \param data   The data string containing information about the planet (including the name)
     * \param length How many values were given by data (needs to be one less as the size of _dataName)
     */
    Planet ( const std::string& data, unsigned length );

    /**
     * \brief Destructor
     * We need this here because we assign _myData to an array and have to delete it.
     */
    virtual ~Planet ();

    /*
     * Note:
     * We actually need here a copy and copy-assignment constructor to prevent the destructor
     * to be called twice, but I skip them as we don't use them.
     */

    /**
     * \brief Getter for the value named 'name'
     * \param name The name of the value to return, has to match one field in dataName
     * \return The value of the requested field
     */
    double get_value ( const std::string& name ) const;

    /**
     * \brief Prints the data in a readable way
     */
    void print_data () const;

    /** The name of the planet */
    const std::string myName;

    /** The names of the data fields */
    static std::string dataName[];
private:
    /** How many values are given by data */
    const unsigned _length;
    /** The data of the planet, we will assign this to an array
     *  Important: does not keep track of the name! */
    std::string* _myData;
};


#endif //P3_PLANET_H
