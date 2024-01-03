import java.util.Scanner;
import java.math.BigInteger;

public class rsa {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter prime number p: ");
        BigInteger p = new BigInteger(scanner.nextLine());

        System.out.print("Enter prime number q: ");
        BigInteger q = new BigInteger(scanner.nextLine());

        BigInteger n = p.multiply(q);
        BigInteger phiN = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));

        BigInteger e;
        do {
            System.out.print("Enter public exponent e : ");
            e = new BigInteger(scanner.nextLine());
        } while (!e.gcd(phiN).equals(BigInteger.ONE));

        BigInteger d = e.modInverse(phiN);

        System.out.println("Public Key (PU): {" + e + ", " + n + "}");
        System.out.println("Private Key (PR): {" + d + ", " + n + "}");

        System.out.println("Text: ");
        String inputText = scanner.nextLine();

        BigInteger[] numericMessage = stringToNumeric(inputText);

        BigInteger[] encryptedMessage = new BigInteger[numericMessage.length];
        for (int i = 0; i < numericMessage.length; i++) {
            encryptedMessage[i] = numericMessage[i].modPow(e, n);
        }

        System.out.print("Encrypted Message: ");
        for (BigInteger value : encryptedMessage) {
            System.out.print(value + " ");
        }
        System.out.println();

        BigInteger[] decryptedMessage = new BigInteger[encryptedMessage.length];
        for (int i = 0; i < encryptedMessage.length; i++) {
            decryptedMessage[i] = encryptedMessage[i].modPow(d, n);
            System.out.println(encryptedMessage[i] + " " );
        }

        String decryptedText = numericToString(decryptedMessage);
        System.out.println("Decrypted Message: " + decryptedText);

        scanner.close();
    }

    private static BigInteger[] stringToNumeric(String input) {
        BigInteger[] numericValues = new BigInteger[input.length()];
        for (int i = 0; i < input.length(); i++) {
            numericValues[i] = BigInteger.valueOf(input.charAt(i));
        }
        return numericValues;
    }

    private static String numericToString(BigInteger[] numericValues) {
        StringBuilder result = new StringBuilder();
        for (BigInteger value : numericValues) {
            result.append((char) value.intValue());
        }
        return result.toString();
    }
}
 