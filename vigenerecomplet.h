#ifndef VIGENERECOMPLET_H
#define VIGENERECOMPLET_H

#include "encryptage.h"



class VigenereComplet : public Encryptage {

private:
    std::string cleVigenere;

public:
    VigenereComplet();
    VigenereComplet(std::string cleVigenere);
    virtual ~VigenereComplet();


    // Encryptage interface
public:
    virtual std::string encoderMessage() override;
    virtual std::string decoderMessage() override;

};

#endif // VIGENERECOMPLET_H
