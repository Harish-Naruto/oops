#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor with default parameters
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Friend functions for input/output
    friend istream& operator>>(istream& input, Complex& c) {
        input >> c.real >> c.imag;
        return input;
    }

    friend ostream& operator<<(ostream& output, const Complex& c) {
        output << c.real << " + " << c.imag << "i";
        return output;
    }

    // Arithmetic operators
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }
};

class ComplexCalculator {
public:
    static void run() {
        Complex num1, num2;
        char choice;

        do {
            // Input complex numbers
            cout << "\nEnter Real and Imaginary parts of Complex Number 1:\n";
            cin >> num1;
            cout << "Enter Real and Imaginary parts of Complex Number 2:\n";
            cin >> num2;

            // Display entered numbers
            cout << "\nComplex Number 1: " << num1 << endl;
            cout << "Complex Number 2: " << num2 << endl;

            // Menu loop
            bool continueCalculations = true;
            while (continueCalculations) {
                displayMenu();
                int option = getMenuChoice();

                switch (option) {
                    case 1:
                        cout << "Addition: " << (num1 + num2) << endl;
                        break;
                    case 2:
                        cout << "Multiplication: " << (num1 * num2) << endl;
                        break;
                    case 3:
                        return;
                    default:
                        cout << "Invalid option!\n";
                        continue;
                }

                continueCalculations = askToContinue();
            }

            cout << "Do you want to enter new numbers? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        cout << "Thanks for using this program!\n";
    }

private:
    static void displayMenu() {
        cout << "\n********** MENU **********\n"
             << "1. Addition of Complex Numbers\n"
             << "2. Multiplication of Complex Numbers\n"
             << "3. Exit\n";
    }

    static int getMenuChoice() {
        int choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        return choice;
    }

    static bool askToContinue() {
        char response;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> response;
        return (response == 'y' || response == 'Y');
    }
};

int main() {
    ComplexCalculator::run();
    return 0;
}