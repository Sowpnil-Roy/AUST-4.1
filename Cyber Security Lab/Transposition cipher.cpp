#include <iostream>
#include <string>
#include <vector>

//For encrypt
std::string encrypt(const std::string& plaintext, const std::string& key) {
//calculate the number of columns & Rows
    int cols = key.length();
    int rows = (plaintext.length() + cols - 1) / cols;

    // Create a 2D vector to represent the matrix
    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols, 'x'));

    // Fill the matrix with the plaintext row by row
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (index < plaintext.length()) {
                matrix[i][j] = plaintext[index++];
            }
        }
    }

    // Encrypt the matrix based on the key
    std::string encrypted;
    for (char c : key) {
        int col = c - '0' - 1;
        for (int i = 0; i < rows; ++i) {
            if (isalpha(matrix[i][col]) || matrix[i][col] == ' ') {
                encrypted += matrix[i][col];
            }
        }
    }
    return encrypted;
}
//For decrypt
std::string decrypt(const std::string& ciphertext, const std::string& key) {
    int cols = key.length();
    int rows = (ciphertext.length() + cols - 1) / cols;

    // Create a 2D vector to represent the matrix
    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols, 'x'));

    // Fill the matrix with the ciphertext based on the key
    int index = 0;
    for (char c : key) {
        int col = c - '0' - 1;
        for (int i = 0; i < rows; ++i) {
            matrix[i][col] = ciphertext[index++];
        }
    }

    // Decrypt the matrix
    std::string decrypted;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ') {
                decrypted += matrix[i][j];
            }
        }
    }
    return decrypted;
}

int main() {
    std::string key = "41532";
    std::string plaintext = "the simplest possible transpositions";

    // Encrypt the plaintext
    std::string encrypted = encrypt(plaintext, key);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    // Decrypt the ciphertext
    std::string decrypted = decrypt(encrypted, key);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}
