#include "enigma.h"

Enigma::Enigma() : Encryptage() {
    this->cleEnigma1 = "";
    this->cleEnigma2 = "";
    this->positionCleEnigma1 = 0;
    this->positionCleEnigma2 = 0;
}

Enigma::Enigma(std::string cleEnigma1, int positionCleEnigma1) : Encryptage() {
    this->cleEnigma1 = cleEnigma1;
    this->cleEnigma2 = "";
    this->positionCleEnigma1 = positionCleEnigma1;
    this->positionCleEnigma2 = 0;
}

Enigma::Enigma(std::string cleEnigma1, int positionCleEnigma1, std::string cleEnigma2, int positionCleEnigma2) : Encryptage() {
    this->cleEnigma1 = cleEnigma1;
    this->cleEnigma2 = cleEnigma2;
    this->positionCleEnigma1 = positionCleEnigma1;
    this->positionCleEnigma2 = positionCleEnigma2;
    // On rétablit les positions si la valeur est supérieur à la taille de l'alhapabet.
    if (this->positionCleEnigma1 < 0) {
        this->positionCleEnigma1 = 26 - (-this->positionCleEnigma1 % 26);
    }
    else {
        this->positionCleEnigma1 %= 26;
    }
    if (this->positionCleEnigma2 < 0) {
        this->positionCleEnigma2 = 26 - (-this->positionCleEnigma2 % 26);
    }
    else {
        this->positionCleEnigma2 %= 26;
    }
}

Enigma::~Enigma() {

}

std::string Enigma::encoderMessage() {
    int caractereNonChiffre = 0;
    int caractereChiffre = 0;
    this->messageChiffre = "";
    int tailleMessage = 0;
    std::transform(this->messageNonChiffre.begin(), this->messageNonChiffre.end(),this->messageNonChiffre.begin(), ::toupper);
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        if ((this->messageNonChiffre.at(i) >= 'A') && (this->messageNonChiffre.at(i) <= 'Z')) {
            tailleMessage++;
            caractereNonChiffre = this->getCodeAsciiChar(this->messageNonChiffre.at(i)) - 65;
            caractereChiffre = this->cleEnigma1.at((caractereNonChiffre + this->positionCleEnigma1) % 26);

            caractereNonChiffre = caractereChiffre - 65;
            caractereChiffre = this->cleEnigma2.at((caractereNonChiffre + this->positionCleEnigma2) % 26);

            if (this->positionCleEnigma1 == 25) {
                this->positionCleEnigma1 = 1;
            }
            else {
                this->positionCleEnigma1++;
            }
            if ((tailleMessage % 26 == 0) && (tailleMessage != 0)) {
                if (this->positionCleEnigma2 == 25) {
                    this->positionCleEnigma2 = 1;
                }
                else {
                    this->positionCleEnigma2++;
                }
            }

            this->messageChiffre += this->getCharAvecCodeCasii(caractereChiffre);
        }
        else {
            this->messageChiffre += this->messageNonChiffre.at(i);
        }
    }
    return this->messageChiffre;
}

std::string Enigma::decoderMessage() {
    int caractereNonChiffre = 0;
    int caractereChiffre = 0;
    this->messageNonChiffre = "";
    int tailleMessage = 0;
    for (int i = 0; i < this->messageChiffre.size(); i++) {
        if ((this->messageChiffre.at(i) >= 'A') && (this->messageChiffre.at(i) <= 'Z')) {
            tailleMessage++;
            caractereChiffre = this->getCodeAsciiChar(this->messageChiffre.at(i)) - 65;
            caractereNonChiffre = this->cleEnigma2.find(this->getCharAvecCodeCasii(caractereChiffre + 65));

            caractereChiffre = (caractereNonChiffre - this->positionCleEnigma2 + 26) % 26 + 65;
            caractereNonChiffre = (this->cleEnigma1.find(this->getCharAvecCodeCasii(caractereChiffre)) - this->positionCleEnigma1 + 26) % 26 + 65;

            if ((tailleMessage % 26 == 0) && (tailleMessage != 0)) {
                if (this->positionCleEnigma2 == 25) {
                    this->positionCleEnigma2 = 1;
                }
                else {
                    this->positionCleEnigma2++;
                }
            }
            if (this->positionCleEnigma1 == 25) {
                this->positionCleEnigma1 = 1;
            }
            else {
                this->positionCleEnigma1++;
            }

            this->messageNonChiffre += this->getCharAvecCodeCasii(caractereNonChiffre);
        }
        else {
            this->messageNonChiffre += this->messageChiffre.at(i);
        }
    }
    return this->messageNonChiffre;
}
