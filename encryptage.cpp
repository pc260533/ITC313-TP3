#include "encryptage.h"

std::string Encryptage::getMessageNonChiffre() const {
    return this->messageNonChiffre;
}

void Encryptage::setMessageNonChiffre(std::string messageNonChiffre) {
    this->messageNonChiffre = messageNonChiffre;
}

std::string Encryptage::getMessageChiffre() const {
    return this->messageChiffre;
}

void Encryptage::setMessageChiffre(std::string messageChiffre) {
    this->messageChiffre = messageChiffre;
}

Encryptage::Encryptage() {

}

std::string Encryptage::encoderMessage() {
    this->messageChiffre = this->messageNonChiffre;
    return this->messageChiffre;
}

std::string Encryptage::decoderMessage() {
    this->messageNonChiffre = this->messageChiffre;
    return this->messageNonChiffre;
}

void Encryptage::sauvegarderMessage(std::string message, std::string cheminFichier) {
    std::ofstream fichierSauvegardeStream(cheminFichier);
    if (fichierSauvegardeStream) {
        fichierSauvegardeStream << message;
    }
    fichierSauvegardeStream.close();
}

std::string Encryptage::lireMessage(std::string cheminFichier) {
    std::string message = "";
    std::ifstream fichierSauvegardeStream(cheminFichier);
    if (fichierSauvegardeStream) {
        fichierSauvegardeStream >> message;
    }
    fichierSauvegardeStream.close();
    return message;
}
