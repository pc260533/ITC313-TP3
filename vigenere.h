#ifndef VIGENERE_H
#define VIGENERE_H

#include "encryptage.h"
#include <algorithm>
#include <string>



class Vigenere : public Encryptage {

private:
    std::string cleVigenere;

public:
    Vigenere();
    Vigenere(std::string cleVigenere);
    virtual ~Vigenere();


    // Encryptage interface
public:
    virtual std::string encoderMessage() override;
    virtual std::string decoderMessage() override;

};

#endif // VIGENERE_H
