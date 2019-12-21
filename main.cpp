#include "cesar.h"
#include "cesarcomplet.h"
#include "encryptage.h"
#include "enigma.h"
#include "enigmacomplet.h"
#include "vigenere.h"
#include "vigenerecomplet.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <time.h>



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
    Vigenere vigenere("CLE");

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


    std::string cheminFichierSauvegardeNonChiffre = "sauvegardeNonChiffre.txt";
    std::string cheminFichierSauvegardeChiffre = "sauvegardeChiffre.txt";
    std::string messageNonChiffre = "";
    std::string messageChiffre = "";
    VigenereComplet vigenereComplet("cle");

    messageNonChiffre = vigenereComplet.lireMessage(cheminFichierSauvegardeNonChiffre);
    vigenereComplet.setMessageNonChiffre(messageNonChiffre);
    messageChiffre = vigenereComplet.encoderMessage();
    vigenereComplet.sauvegarderMessage(messageChiffre, cheminFichierSauvegardeChiffre);

    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    std::cout << "Message chiffre : " << messageChiffre << std::endl;

    messageChiffre = vigenereComplet.lireMessage(cheminFichierSauvegardeChiffre);
    vigenereComplet.setMessageChiffre(messageChiffre);
    messageNonChiffre = vigenereComplet.decoderMessage();
    vigenereComplet.sauvegarderMessage(messageNonChiffre, cheminFichierSauvegardeNonChiffre);

    std::cout << "Message chiffre : " << messageChiffre << std::endl;
    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;*/

    /* Question 5
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
    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;*/

    std::string cheminFichierSauvegardeNonChiffre = "sauvegardeNonChiffre.txt";
    std::string cheminFichierSauvegardeChiffre = "sauvegardeChiffre.txt";
    std::string messageNonChiffre = "";
    std::string messageChiffre = "";

    std::string alphabet = "";
    for (int i = 32; i < 127; i++) {
        alphabet += char(i);
    }

    std::map<std::string, int> mapClesPositionsEnigma = {
        {" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", 0},
        {",!)Q ;Zrvz2^@HgS{I~1(O`ba'&l%$mqVCXG9#w0]d.-8W_34[kA5<n/RBDLsFN\\tpY6E7fy?oi|+\"xJ>ThUc=uKjeM:}*P", 0}
    };

    for (int i = 0; i < 1000; i++) {
        std::srand(static_cast<unsigned int>(time(nullptr)));
        std::random_shuffle(alphabet.begin(), alphabet.end());
        mapClesPositionsEnigma.insert(std::pair<std::string, int>(alphabet, std::rand() % 100));
    }

    std::vector<std::string> listeClesEnigma;
    std::vector<int> listePosistionsClesEnigma;
    for (auto &clePositionEnigma : mapClesPositionsEnigma) {
        listeClesEnigma.push_back(clePositionEnigma.first);
        listePosistionsClesEnigma.push_back(clePositionEnigma.second);
    }
    EnigmaComplet enigmaCompletChiffrement(listeClesEnigma, listePosistionsClesEnigma);
    EnigmaComplet enigmaCompletDechiffrement(listeClesEnigma, listePosistionsClesEnigma);


    messageNonChiffre = enigmaCompletChiffrement.lireMessage(cheminFichierSauvegardeNonChiffre);
    enigmaCompletChiffrement.setMessageNonChiffre(messageNonChiffre);
    messageChiffre = enigmaCompletChiffrement.encoderMessage();
    enigmaCompletChiffrement.sauvegarderMessage(messageChiffre, cheminFichierSauvegardeChiffre);

    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;
    std::cout << "Message chiffre : " << messageChiffre << std::endl;

    messageChiffre = enigmaCompletDechiffrement.lireMessage(cheminFichierSauvegardeChiffre);
    enigmaCompletDechiffrement.setMessageChiffre(messageChiffre);
    messageNonChiffre = enigmaCompletDechiffrement.decoderMessage();
    enigmaCompletDechiffrement.sauvegarderMessage(messageNonChiffre, cheminFichierSauvegardeNonChiffre);

    std::cout << "Message chiffre : " << messageChiffre << std::endl;
    std::cout << "Message non chiffre : " << messageNonChiffre << std::endl;

    return 0;
}
