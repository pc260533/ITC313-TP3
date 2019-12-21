#include "vigenere.h"

Vigenere::Vigenere() : Encryptage() {
    this->cleVigenere = "";
}

Vigenere::Vigenere(std::string cleVigenere) : Encryptage() {
    this->cleVigenere = cleVigenere;
    std::transform(this->messageNonChiffre.begin(), this->messageNonChiffre.end(),this->messageNonChiffre.begin(), ::toupper);
}

Vigenere::~Vigenere() {

}

std::string Vigenere::encoderMessage() {
    int caractereAscii = 0;
    int decalageCle = 0;
    this->messageChiffre = "";
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        if ((this->messageNonChiffre.at(i) >= 'A') && (this->messageNonChiffre.at(i) <= 'Z')) {
            decalageCle = this->getCodeAsciiChar(this->cleVigenere.at(i % this->cleVigenere.size()) - 65);
            caractereAscii = (this->getCodeAsciiChar(this->messageNonChiffre.at(i)) - 65 + decalageCle) % 26 + 65;
            this->messageChiffre += this->getCharAvecCodeCasii(caractereAscii);
        }
        else {
            this->messageChiffre += this->messageNonChiffre.at(i);
        }
    }
    return this->messageChiffre;
}

std::string Vigenere::decoderMessage() {
    int caractereAscii = 0;
    int decalageCle = 0;
    this->messageNonChiffre = "";
    for (int i = 0; i < this->messageChiffre.size(); i++) {
        if ((this->messageChiffre.at(i) >= 'A') && (this->messageChiffre.at(i) <= 'Z')) {
            decalageCle = this->getCodeAsciiChar(this->cleVigenere.at(i % this->cleVigenere.size()) - 65);
            caractereAscii = (this->getCodeAsciiChar(this->messageChiffre.at(i)) - 65 - decalageCle + 26) % 26 + 65;
            this->messageNonChiffre += this->getCharAvecCodeCasii(caractereAscii);
        }
        else {
            this->messageNonChiffre += this->messageChiffre.at(i);
        }
    }
    return this->messageNonChiffre;
}
