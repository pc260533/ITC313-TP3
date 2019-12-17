#include "cesar.h"

std::string Cesar::getValeurDecalage() const {
    return this->valeurDecalage;
}

void Cesar::setValeurDecalage(std::string valeurDecalage) {
    this->valeurDecalage = valeurDecalage;
}

Cesar::Cesar() : Encryptage() {
    this->valeurDecalage = "3";
}

Cesar::Cesar(std::string valeurDecalage) : Encryptage() {
    this->valeurDecalage = valeurDecalage;
}

Cesar::~Cesar() {

}

std::string Cesar::encoderMessage() {
    int caractereAscii = 0;
    int decalage = std::stoi(this->valeurDecalage);
    this->messageChiffre = "";
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageNonChiffre.at(i));
        if ((caractereAscii > 96) && (caractereAscii < 123)) {
            caractereAscii = (caractereAscii - 97 + decalage) % 26 + 97;
        }
        this->messageChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
    return this->messageChiffre;
}

std::string Cesar::decoderMessage() {
    int caractereAscii = 0;
    int decalage = std::stoi(this->valeurDecalage);
    this->messageNonChiffre = "";
    for (int i = 0; i < this->messageChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageChiffre.at(i));
        if ((caractereAscii > 96) && (caractereAscii < 123)) {
            caractereAscii = (caractereAscii - 97 - decalage + 26) % 26 + 97;
        }
        this->messageNonChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
    return this->messageNonChiffre;
}
