#ifndef CAESAR_CIPHER_CIPHER_H
#define CAESAR_CIPHER_CIPHER_H

#include <string>

class Cipher
{
public:
    Cipher ( const int k ) : key ( k % 26 ) {}
    std::string shiftMessage ( const std::string& origMsg ) const;

private:
    const int key;
};


#endif //CAESAR_CIPHER_CIPHER_H
