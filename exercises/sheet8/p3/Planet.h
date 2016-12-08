#ifndef P3_PLANET_H
#define P3_PLANET_H

#include <string>

class Planet
{
public:
    /**
     * \brief Constructor
     * \param data
     */
    Planet ( const std::string& data, unsigned length );

    virtual ~Planet ();

    /**
     * \brief Getter for the value named 'name'
     * \param name
     * \return the value of the requested field
     */
    double get_value ( const std::string& name ) const;

    /**
     * \brief Prints the data in readable way
     */
    void print_data () const;

    /** The name of the planet */
    const std::string myName;

    /** The names of the datafields */
    static std::string _dataName[];
private:
    const unsigned _length;
    /** The data of the planet, using array we have to hardcode the length */
    std::string* _myData;
};


#endif //P3_PLANET_H
