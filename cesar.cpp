#include "cesar.h"

std::string Cesar::getValeurDecalage() const {
    return this->valeurDecalage;
}

void Cesar::setValeurDecalage(std::string valeurDecalage) {
    this->valeurDecalage = valeurDecalage;
}

int Cesar::getCodeAsciiChar(char caractere) {
    return (int)caractere;
}

char Cesar::getCharAvecCodeCasii(int codeAscii) {
    return (char)codeAscii;
}

Cesar::Cesar() : Encryptage() {

}

std::string Cesar::encoderMessage() {
    int caractereAscii = 0;
    int decalage = std::stoi(this->valeurDecalage);
    this->messageChiffre = "";
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageChiffre.at(i));
        if ((caractereAscii > 96) && (caractereAscii < 123)) {
            caractereAscii = (caractereAscii - 97 + decalage) % 26 + 97;
        }
        this->messageChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
}

std::string Cesar::decoderMessage() {
    int caractereAscii = 0;
    int decalage = std::stoi(this->valeurDecalage);
    this->messageNonChiffre = "";
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageNonChiffre.at(i));
        if ((caractereAscii > 96) && (caractereAscii < 123)) {
            caractereAscii = (caractereAscii - 97 - decalage) % 26 + 97;
        }
        this->messageNonChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
}
