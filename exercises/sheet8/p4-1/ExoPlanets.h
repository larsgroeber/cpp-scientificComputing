#ifndef P2_2_IO_H
#define P2_2_IO_H

#include <vector>
#include <string>

/**
 * \brief A static class which reads the exoplanet data, stripps all error
 *        values and writes the remaining data into a file.
 */
class ExoPlanets
{
public:
    /**
     * \brief Function to read the exoplanets file into 'data' and 'comments'
     * \param filePath The file to read
     * \param data     A vector of vectors of strings to write the data into
     * \param comment  A vector of strings to write the comment (names of the fields) into
     * \return boolean If process was successful
     */
    static bool readFile ( const std::string& filePath, std::vector<std::vector<std::string>>& data, std::vector<std::string>& comment );

    /**
     * \brief Function to write 'data' and 'comments' into a file
     * \param filePath The file to write into
     * \param data     The vector of vectors of strings to read the data from
     * \param comment  The vector of strings to read the comments from
     * \return boolean If process was successful
     */
    static bool writeFile ( const std::string& filePath, std::vector<std::vector<std::string>>& data, std::vector<std::string>& comment );
};


#endif //P2_2_IO_H
