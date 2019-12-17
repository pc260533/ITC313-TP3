#ifndef CESAR_H
#define CESAR_H

#include "encryptage.h"



class Cesar : public Encryptage {

private:
    std::string valeurDecalage;

private:
    int getCodeAsciiChar(char caractere);
    char getCharAvecCodeCasii(int codeAscii);

public:
    Cesar();
    std::string getValeurDecalage() const;
    void setValeurDecalage(std::string valeurDecalage);

    // Encryptage interface
public:
    virtual std::string encoderMessage() override;
    virtual std::string decoderMessage() override;


};

#endif // CESAR_H
