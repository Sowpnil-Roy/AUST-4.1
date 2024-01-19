#include <bits/stdc++.h>
using namespace std;

// Function to generate a random cipher key
map<char, char> generateCipherKey() {
    string naturalAlphabet = "abcdefghijklmnopqrstuvwxyz";//naturalAlphabet
    string changedAlphabet = naturalAlphabet;//changedAlphabet
    random_device rd;
    mt19937 g(rd());//Mersenne Twister pseudo-random number generator.
    shuffle(changedAlphabet.begin(), changedAlphabet.end(), g);//shuffles the characters

    map<char, char> cipherKey;
    for (size_t i = 0; i < naturalAlphabet.length(); ++i) {
        cipherKey[naturalAlphabet[i]] = changedAlphabet[i];
    }
    return cipherKey;
}

// Function to encrypt a message using the cipher key
string encryptMessage(const string& message, const map<char, char>& cipherKey) {
    string encryptedMessage;
    for (char c : message) {
        if (isalpha(c)) {
            char encryptedChar = cipherKey.at(tolower(c));//uppercase and lowercase characters
            if (isupper(c)) {
                encryptedChar = toupper(encryptedChar);
            }
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Function to decrypt an encrypted message using the cipher key
string decryptMessage(const string& encryptedMessage, const map<char, char>& cipherKey) {
    map<char, char> decryptionKey;
    for (const auto& pair : cipherKey) {
        decryptionKey[pair.second] = pair.first;
    }

    string decryptedMessage;
    for (char c : encryptedMessage) {
        if (isalpha(c)) {
            char decryptedChar = decryptionKey.at(tolower(c));
            if (isupper(c)) {
                decryptedChar = toupper(decryptedChar);
            }
            decryptedMessage += decryptedChar;
        } else {
            decryptedMessage += c;
        }
    }
    return decryptedMessage;
}

int main() {
    string inputMessage;
    cout << "Enter a message: ";
    getline(cin, inputMessage);

    map<char, char> cipherKey = generateCipherKey();//random mapping between characters

    string encryptedMessage = encryptMessage(inputMessage, cipherKey);
    cout << "Encrypted: " << encryptedMessage << endl;

    string decryptedMessage = decryptMessage(encryptedMessage, cipherKey);
    cout << "Decrypted: " << decryptedMessage << endl;

    return 0;
}
