#include "enigmacomplet.h"

EnigmaComplet::EnigmaComplet() : Encryptage() {

}

EnigmaComplet::EnigmaComplet(std::vector<std::string> listeClesEnigma, std::vector<int> listePositionsClesEnigma) : Encryptage() {
    this->listeClesEnigma = listeClesEnigma;
    this->listePositionsClesEnigma = listePositionsClesEnigma;
    // On rétablit les positions si la valeur est supérieur à la taille de l'alhapabet.
    for (int i = 0; i < this->listePositionsClesEnigma.size(); i++) {
        if (this->listePositionsClesEnigma.at(i) < 0) {
            this->listePositionsClesEnigma.at(i) = 95 - (-this->listePositionsClesEnigma.at(i) % 95);
        }
        else {
            this->listePositionsClesEnigma.at(i) %= 95;
        }
    }
}

EnigmaComplet::~EnigmaComplet() {

}

std::string EnigmaComplet::encoderMessage() {
    int caractereAscii = 0;
    int caractereNonChiffre = 0;
    int caractereChiffre = 0;
    this->messageChiffre = "";
    for (int i = 0; i < this->messageNonChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageNonChiffre.at(i));
        if ((caractereAscii > 31) && (caractereAscii < 127)) {
            caractereChiffre = caractereAscii;
            for (int j = 0; j < this->listeClesEnigma.size(); j++) {
                caractereNonChiffre = caractereChiffre - 32;
                caractereChiffre = this->listeClesEnigma.at(j).at((caractereNonChiffre + this->listePositionsClesEnigma.at(j)) % 95);
                if (j == 0) {
                    if (this->listePositionsClesEnigma.at(j) >= 94) {
                        this->listePositionsClesEnigma.at(j) = 1;
                    }
                    else {
                        this->listePositionsClesEnigma.at(j)++;
                    }
                }
                else {
                    if ((i % static_cast<int>(std::pow(95, j)) == 0) && (this->messageChiffre.size() != 0)) {
                        if (this->listePositionsClesEnigma.at(j) >= 94) {
                            this->listePositionsClesEnigma.at(j) = 1;
                        }
                        else {
                            this->listePositionsClesEnigma.at(j)++;
                        }
                    }
                }
            }
            this->messageChiffre += this->getCharAvecCodeCasii(caractereChiffre);
        }
    }
    return this->messageChiffre;
}

std::string EnigmaComplet::decoderMessage() {
    int caractereAscii = 0;
    int caractereNonChiffre = 0;
    int caractereChiffre = 0;
    this->messageNonChiffre = "";
    for (int i = 0; i < this->messageChiffre.size(); i++) {
        caractereAscii = this->getCodeAsciiChar(this->messageChiffre.at(i));
        if ((caractereAscii > 31) && (caractereAscii < 127)) {
            caractereNonChiffre = caractereAscii;
            for (int j = this->listeClesEnigma.size() - 1; j >= 0; j--) {
                caractereChiffre = (caractereNonChiffre - 32 + 95) % 95 + 32;
                caractereNonChiffre = (this->listeClesEnigma.at(j).find(this->getCharAvecCodeCasii(caractereChiffre)) - this->listePositionsClesEnigma.at(j) + 95) % 95 + 32;
                if (j == 0) {
                    if (this->listePositionsClesEnigma.at(j) >= 94) {
                        this->listePositionsClesEnigma.at(j) = 1;
                    }
                    else {
                        this->listePositionsClesEnigma.at(j)++;
                    }
                }
                else {
                    if ((i % static_cast<int>(std::pow(95, j)) == 0) && (this->messageNonChiffre.size() != 0)) {
                        if (this->listePositionsClesEnigma.at(j) >= 94) {
                            this->listePositionsClesEnigma.at(j) = 1;
                        }
                        else {
                            this->listePositionsClesEnigma.at(j)++;
                        }
                    }
                }
            }
            this->messageNonChiffre += this->getCharAvecCodeCasii(caractereNonChiffre);
        }
    }
    return this->messageNonChiffre;}
