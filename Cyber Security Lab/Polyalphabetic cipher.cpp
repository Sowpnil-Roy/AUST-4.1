#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//generates a key of a specified size based on the provided input key
string generateKey(string key, int size) {
    int keyLength = key.length();
    string generatedKey;
    for (int i = 0; i < size; ++i) {
        generatedKey += key[i % keyLength];
    }
    return generatedKey;
}
//Encryption
string performEncryption(string plaintext, string key) {
    string ciphertext;
    int textLength = plaintext.length();
    key = generateKey(key, textLength);

    for (int i = 0; i < textLength; ++i) {
        char ch = plaintext[i];
        ciphertext += (ch + key[i]) % 128;
    }
    return ciphertext;
}
//decryptedText
string performDecryption(string ciphertext, string key) {
    string decryptedText;
    int textLength = ciphertext.length();
    key = generateKey(key, textLength);

    for (int i = 0; i < textLength; ++i) {
        char ch = ciphertext[i];
        decryptedText += (ch - key[i] + 128) % 128;
    }
    return decryptedText;
}

int main() {

    string userKey, userMessage;
    cout << "Enter the key: ";
    getline(cin, userKey);
    cout << "Enter the message: ";
    getline(cin, userMessage);

    string encryptedMessage = performEncryption(userMessage, userKey);
    string decryptedMessage = performDecryption(encryptedMessage, userKey);

    cout << "Original Message: " << userMessage << endl;
    cout << "Encrypted: " << encryptedMessage << endl;
    cout << "Decrypted: " << decryptedMessage << endl;

    return 0;
}
