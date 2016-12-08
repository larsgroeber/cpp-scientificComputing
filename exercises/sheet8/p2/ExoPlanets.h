#ifndef P2_2_IO_H
#define P2_2_IO_H

#include <vector>
#include <string>

class ExoPlanets
{
public:
    static bool readFile ( const std::string& filePath, std::vector<std::vector<std::string>>& data, std::vector<std::string>& comment );

    static bool writeFile ( const std::string& filePath, std::vector<std::vector<std::string>>& data, std::vector<std::string>& comment );
};


#endif //P2_2_IO_H
