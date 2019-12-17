#include "cesarcomplet.h"

CesarComplet::CesarComplet() : Encryptage() {
    this->valeurDecalage = "3";
}

CesarComplet::CesarComplet(std::string valeurDecalage) : Encryptage() {
    this->valeurDecalage = valeurDecalage;
}

CesarComplet::~CesarComplet() {

}

std::string CesarComplet::encoderMessage() {
    int caractereAscii = 0;
    int decalage = std::stoi(this->valeurDecalage);
    this->messageChiffre = "";
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageNonChiffre.at(i));
        if ((caractereAscii > 31) && (caractereAscii < 127)) {
            caractereAscii = (caractereAscii - 32 + decalage) % 95 + 32;
        }
        this->messageChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
    return this->messageChiffre;
}

std::string CesarComplet::decoderMessage() {
    int caractereAscii = 0;
    int decalage = std::stoi(this->valeurDecalage);
    this->messageNonChiffre = "";
    for (int i = 0; i < this->messageChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageChiffre.at(i));
        if ((caractereAscii > 31) && (caractereAscii < 127)) {
            caractereAscii = (caractereAscii - 32 - decalage + 95) % 95 + 32;
        }
        this->messageNonChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
    return this->messageNonChiffre;
}
