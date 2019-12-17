#include "vigenere.h"

Vigenere::Vigenere() : Encryptage() {
    this->cleVigenere = cleVigenere;
}

Vigenere::Vigenere(std::string cleVigenere) : Encryptage() {
    this->cleVigenere = cleVigenere;
}

Vigenere::~Vigenere() {

}

std::string Vigenere::encoderMessage() {
    int caractereAscii = 0;
    int decalageCle = 0;
    this->messageChiffre = "";
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageNonChiffre.at(i));
        if ((caractereAscii > 31) && (caractereAscii < 127)) {
            decalageCle = this->getCodeAsciiChar(this->cleVigenere.at(i % this->cleVigenere.size()) - 32);
            caractereAscii = (caractereAscii - 32 + decalageCle) % 95 + 32;
        }
        this->messageChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
    return this->messageChiffre;
}

std::string Vigenere::decoderMessage() {
    int caractereAscii = 0;
    int decalageCle = 0;
    this->messageNonChiffre = "";
    for (int i = 0; i < this->messageChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageChiffre.at(i));
        if ((caractereAscii > 31) && (caractereAscii < 127)) {
            decalageCle = this->getCodeAsciiChar(this->cleVigenere.at(i % this->cleVigenere.size()) - 32);
            caractereAscii = (caractereAscii - 32 - decalageCle + 95) % 95 + 32;
        }
        this->messageNonChiffre += this->getCharAvecCodeCasii(caractereAscii);
    }
    return this->messageNonChiffre;
}
