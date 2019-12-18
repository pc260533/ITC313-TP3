#ifndef ENIGMA_H
#define ENIGMA_H

#include "encryptage.h"
#include <algorithm>
#include <string>



class Enigma : public Encryptage {

private:
    std::string cleEnigma1;
    std::string cleEnigma2;
    std::string cleEnigma3;
    int positionCleEnigma1;
    int positionCleEnigma2;
    int positionCleEnigma3;

public:
    Enigma();
    Enigma(std::string cleEnigma1, int positionCleEnigma1);
    Enigma(std::string cleEnigma1, int positionCleEnigma1, std::string cleEnigma2, int positionCleEnigma2);
    ~Enigma();

    // Encryptage interface
public:
    std::string encoderMessage() override;
    std::string decoderMessage() override;

};

#endif // ENIGMA_H
