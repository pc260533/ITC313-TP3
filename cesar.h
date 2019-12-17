#ifndef CESAR_H
#define CESAR_H

#include "encryptage.h"



class Cesar : public Encryptage {

private:
    std::string valeurDecalage;

public:
    Cesar();
    Cesar(std::string valeurDecalage);
    virtual ~Cesar();
    std::string getValeurDecalage() const;
    void setValeurDecalage(std::string valeurDecalage);

    // Encryptage interface
public:
    virtual std::string encoderMessage() override;
    virtual std::string decoderMessage() override;


};

#endif // CESAR_H
