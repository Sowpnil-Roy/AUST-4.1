#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

// Function to generate key pair
void generateKeyPair(int& e, int& d, int& n, int p, int q) {
    // Calculate n and φ(n)
    n = p * q;
    int phi_n = (p - 1) * (q - 1);

    // Select a random encryption key e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1
    do {
        e = rand() % (phi_n - 2) + 2;
    } while (gcd(e, phi_n) != 1);

    // Calculate the decryption key d
    d = modInverse(e, phi_n);
}

// Function to perform RSA encryption
int encrypt(int plaintext, int e, int n) {
    int result = 1;
    for (int i = 0; i < e; ++i) {
        result = (result * plaintext) % n;
    }
    return result;
}

// Function to perform RSA decryption
int decrypt(int ciphertext, int d, int n) {
    int result = 1;
    for (int i = 0; i < d; ++i) {
        result = (result * ciphertext) % n;
    }
    return result;
}

int main() {
    int p, q;

    cout << "Enter prime number P: ";
    cin >> p;

    // Validate P is prime
    if (!isPrime(p)) {
        cout << "P must be a prime number." << endl;
        return 1;
    }

    cout << "Enter prime number Q: ";
    cin >> q;

    // Validate Q is prime
    if (!isPrime(q)) {
        cout << "Q must be a prime number." << endl;
        return 1;
    }

    int e, d, n;
    generateKeyPair(e, d, n, p, q);

    cout << "Public key (PU): {" << e << ", " << n << "}\n";
    cout << "Private key (PR): {" << d << ", " << n << "}\n";

    cin.ignore(); // Clear newline from the input buffer

    // Note: This example assumes the input is a string
    cout << "Enter the plaintext message: ";
    string text;
    getline(cin, text);

    // Encryption
    int i = 0, k=0;
    int ciphertext[100];
    int decryptedText[100];
    int plaintext;
    cout << "Ciphertext (C): ";
    for (char c : text) {
         plaintext = static_cast<int>(c);
         ciphertext[i] = encrypt(plaintext, e, n);
        cout << ciphertext[i] << " ";
        i++;
    }
    cout << endl;

    // Decryption
    cout << "Decrypted Text (M): ";
    for (char c : text) {
         decryptedText[k] = decrypt(ciphertext[k], d, n);
        cout << decryptedText[k] << " ";
        k++;
    }


    return 0;
}
