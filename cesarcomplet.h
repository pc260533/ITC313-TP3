#ifndef CESARCOMPLET_H
#define CESARCOMPLET_H

#include "encryptage.h"



class CesarComplet : public Encryptage {

private:
    std::string valeurDecalage;

public:
    CesarComplet();
    CesarComplet(std::string valeurDecalage);
    virtual ~CesarComplet();

    // Encryptage interface
public:
    virtual std::string encoderMessage() override;
    virtual std::string decoderMessage() override;


};

#endif // CESARCOMPLET_H
