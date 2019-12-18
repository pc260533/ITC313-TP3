#include "cesar.h"
#include "cesarcomplet.h"
#include "encryptage.h"
#include "enigma.h"
#include "vigenere.h"

#include <iostream>



int main() {
    /* Question 1
    std::string cheminFichierSauvegardeNonChiffre = "sauvegardeNonChiffre.txt";
    std::string cheminFichierSauvegardeChiffre = "sauvegardeChiffre.txt";
    std::string messageNonChiffre = "";
    std::string messageChiffre = "";
    Encryptage encryptage;

    messageNonChiffre = encryptage.lireMessage(cheminFichierSauvegardeNonChiffre);
    encryptage.setMessageNonChiffre(messageNonChiffre);
    messageChiffre = encryptage.encoderMessage();
    encryptage.sauvegarderMessage(messageChiffre, cheminFichierSauvegardeChiffre);

    messageChiffre = encryptage.lireMessage(cheminFichierSauvegardeChiffre);
    encryptage.setMessageChiffre(messageNonChiffre);
    messageNonChiffre = encryptage.decoderMessage();
    encryptage.sauvegarderMessage(messageNonChiffre, cheminFichierSauvegardeNonChiffre);
    */

    /* Question 2
    std::string cheminFichierSauvegardeNonChiffre = "sauvegardeNonChiffre.txt";
    std::string cheminFichierSauvegardeChiffre = "sauvegardeChiffre.txt";
    std::string messageNonChiffre = "";
    std::string messageChiffre = "";
    Cesar cesar("27");

    messageNonChiffre = cesar.lireMessage(cheminFichierSauvegardeNonChiffre);
    cesar.setMessageNonChiffre(messageNonChiffre);
    messageChiffre = cesar.encoderMessage();
    cesar.sauvegarderMessage(messageChiffre, cheminFichierSauvegardeChiffre);

    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    std::cout << "Message chiffre : " << messageChiffre << std::endl;

    messageChiffre = cesar.lireMessage(cheminFichierSauvegardeChiffre);
    cesar.setMessageChiffre(messageChiffre);
    messageNonChiffre = cesar.decoderMessage();
    cesar.sauvegarderMessage(messageNonChiffre, cheminFichierSauvegardeNonChiffre);

    std::cout << "Message chiffre : " << messageChiffre << std::endl;
    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    */

    /* Question 3
    std::string cheminFichierSauvegardeNonChiffre = "sauvegardeNonChiffre.txt";
    std::string cheminFichierSauvegardeChiffre = "sauvegardeChiffre.txt";
    std::string messageNonChiffre = "";
    std::string messageChiffre = "";
    CesarComplet cesarComplet("2");

    messageNonChiffre = cesarComplet.lireMessage(cheminFichierSauvegardeNonChiffre);
    cesarComplet.setMessageNonChiffre(messageNonChiffre);
    messageChiffre = cesarComplet.encoderMessage();
    cesarComplet.sauvegarderMessage(messageChiffre, cheminFichierSauvegardeChiffre);

    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    std::cout << "Message chiffre : " << messageChiffre << std::endl;

    messageChiffre = cesarComplet.lireMessage(cheminFichierSauvegardeChiffre);
    cesarComplet.setMessageChiffre(messageChiffre);
    messageNonChiffre = cesarComplet.decoderMessage();
    cesarComplet.sauvegarderMessage(messageNonChiffre, cheminFichierSauvegardeNonChiffre);

    std::cout << "Message chiffre : " << messageChiffre << std::endl;
    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    */

    /* Question 4
    std::string cheminFichierSauvegardeNonChiffre = "sauvegardeNonChiffre.txt";
    std::string cheminFichierSauvegardeChiffre = "sauvegardeChiffre.txt";
    std::string messageNonChiffre = "";
    std::string messageChiffre = "";
    Vigenere vigenere("cle");

    messageNonChiffre = vigenere.lireMessage(cheminFichierSauvegardeNonChiffre);
    vigenere.setMessageNonChiffre(messageNonChiffre);
    messageChiffre = vigenere.encoderMessage();
    vigenere.sauvegarderMessage(messageChiffre, cheminFichierSauvegardeChiffre);

    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    std::cout << "Message chiffre : " << messageChiffre << std::endl;

    messageChiffre = vigenere.lireMessage(cheminFichierSauvegardeChiffre);
    vigenere.setMessageChiffre(messageChiffre);
    messageNonChiffre = vigenere.decoderMessage();
    vigenere.sauvegarderMessage(messageNonChiffre, cheminFichierSauvegardeNonChiffre);

    std::cout << "Message chiffre : " << messageChiffre << std::endl;
    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    */

    /* Question 5 */
    std::string cheminFichierSauvegardeNonChiffre = "sauvegardeNonChiffre.txt";
    std::string cheminFichierSauvegardeChiffre = "sauvegardeChiffre.txt";
    std::string messageNonChiffre = "";
    std::string messageChiffre = "";
    Enigma enigmaChiffrement("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 0, "ZABCDEFGHIJKLMNOPQRSTUVWXY", 0);
    Enigma enigmaDechiffrement("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 0, "ZABCDEFGHIJKLMNOPQRSTUVWXY", 0);


    messageNonChiffre = enigmaChiffrement.lireMessage(cheminFichierSauvegardeNonChiffre);
    enigmaChiffrement.setMessageNonChiffre(messageNonChiffre);
    messageChiffre = enigmaChiffrement.encoderMessage();
    enigmaChiffrement.sauvegarderMessage(messageChiffre, cheminFichierSauvegardeChiffre);

    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    std::cout << "Message chiffre : " << messageChiffre << std::endl;

    messageChiffre = enigmaDechiffrement.lireMessage(cheminFichierSauvegardeChiffre);
    enigmaDechiffrement.setMessageChiffre(messageChiffre);
    messageNonChiffre = enigmaDechiffrement.decoderMessage();
    enigmaDechiffrement.sauvegarderMessage(messageNonChiffre, cheminFichierSauvegardeNonChiffre);

    std::cout << "Message chiffre : " << messageChiffre << std::endl;
    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;

    return 0;
}
