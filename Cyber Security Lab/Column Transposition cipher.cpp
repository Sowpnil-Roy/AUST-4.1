#include <iostream>
#include <string>
#include <vector>

std::string encrypt(const std::string& plaintext, const std::string& key) {
    int keyLength = key.size();
    std::vector<std::string> columns(keyLength, "");

    // Distribute characters of plaintext into columns based on the key
    for (int i = 0; i < plaintext.size(); ++i) {
        columns[i % keyLength] += plaintext[i];
    }

    // Concatenate the columns to get the ciphertext
    std::string ciphertext;
    for (const std::string& column : columns) {//connecting final ciphertext
        ciphertext += column;
    }

    return ciphertext;
}

std::string decrypt(const std::string& ciphertext, const std::string& key) {
    int keyLength = key.size();
    int columnSize = ciphertext.size() / keyLength;
    int extraChars = ciphertext.size() % keyLength;

    std::vector<std::string> columns(keyLength, "");
    int index = 0;

    // Distribute characters of ciphertext into columns based on the key
    for (int i = 0; i < keyLength; ++i) {
        int charsInColumn = columnSize + (i < extraChars ? 1 : 0);
        columns[i] = ciphertext.substr(index, charsInColumn);
        index += charsInColumn;
    }

    // Concatenate the columns to get the plaintext
    std::string plaintext;
    for (int i = 0; i < columnSize + extraChars; ++i) {
        for (int j = 0; j < keyLength; ++j) {
            if (i < columns[j].size()) {
                plaintext += columns[j][i];
            }
        }
    }

    return plaintext;
}


int main() {
    std::string plaintext = "stopfinishtheware";
    std::string key = "WARE";

    std::string encrypted = encrypt(plaintext, key);
    std::cout << "Encrypted: " << encrypted << std::endl;

    std::string decrypted = decrypt(encrypted, key);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
