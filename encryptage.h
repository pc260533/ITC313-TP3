#ifndef ENCRYPTAGE_H
#define ENCRYPTAGE_H

#include <string>
#include <fstream>



class Encryptage {

protected:
    std::string messageNonChiffre;
    std::string messageChiffre;

protected:
    int getCodeAsciiChar(char caractere);
    char getCharAvecCodeCasii(int codeAscii);

public:
    Encryptage();
    std::string getMessageNonChiffre() const;
    void setMessageNonChiffre(std::string messageNonChiffre);
    std::string getMessageChiffre() const;
    void setMessageChiffre(std::string messageChiffre);

    virtual std::string encoderMessage();
    virtual std::string decoderMessage();

    void sauvegarderMessage(std::string message, std::string cheminFichier);
    std::string lireMessage(std::string cheminFichier);

};

#endif // ENCRYPTAGE_H
