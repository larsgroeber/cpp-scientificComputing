#ifndef CAESAR_CIPHER_CIPHER_H
#define CAESAR_CIPHER_CIPHER_H

#include <string>

/**
 * @brief class Cipher, shifts a message by the value of a given key
 */
class Cipher
{
public:
    /**
     * @brief constructor, initialises key
     * @param k the key being used by the class
     */
    Cipher ( const int k ) : key ( k % 26 ) {}

    /**
     * @brief method that shifts a message by key
     * @param origMsg the original message
     * @return the shifted message
     */
    std::string shiftMessage ( const std::string& origMsg ) const;

private:
    /**
     * property holding the cipher key
    */
    const int key;
};


#endif //CAESAR_CIPHER_CIPHER_H
