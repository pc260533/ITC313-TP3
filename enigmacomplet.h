#ifndef ENIGMACOMPLET_H
#define ENIGMACOMPLET_H

#include "encryptage.h"
#include <algorithm>
#include <vector>
#include <cmath>



class EnigmaComplet : public Encryptage {

private:
    std::vector<std::string> listeClesEnigma;
    std::vector<int> listePositionsClesEnigma;

public:
    EnigmaComplet();
    EnigmaComplet(std::vector<std::string> listeClesEnigma, std::vector<int> listePositionsClesEnigma);
    ~EnigmaComplet();

    // Encryptage interface
public:
    std::string encoderMessage() override;
    std::string decoderMessage() override;

};

#endif // ENIGMACOMPLET_H
