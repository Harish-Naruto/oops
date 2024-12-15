#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
    string Name;
    int ID;
    double salary;
public:
    void accept() {
        cout << "\nName: ";
        cin.ignore();
        getline(cin, Name);
        cout << "ID: ";
        cin >> ID;
        cout << "Salary: ";
        cin >> salary;
    }

    // Write data to file directly as text
    void writeToFile(ofstream& file) {
        file << Name << endl;
        file << ID << endl;
        file << salary << endl;
    }

    // Read data from file
    void readFromFile(ifstream& file) {
        getline(file, Name);
        file >> ID;
        file >> salary;
        file.ignore(); 
    }

    void display() {
        cout << "\nName: " << Name;
        cout << "\nID: " << ID;
        cout << "\nSalary: " << salary << endl;
    }
};

int main() {
    Employee emp;
    int n, i;

    
    cout << "Enter number of employees: ";
    cin >> n;

   
    ofstream outFile("employees.txt");
    
    
    outFile << n << endl;
    
    for(i = 0; i < n; i++) {
        cout << "\nEnter details of Employee " << i+1;
        emp.accept();
        emp.writeToFile(outFile);
    }
    outFile.close();

    
    ifstream inFile("employees.txt");
    int total;
    inFile >> total; 
    inFile.ignore();  

    cout << "\nEmployee Information from file:\n";
    for(i = 0; i < total; i++) {
        Employee e;
        e.readFromFile(inFile);
        cout << "\nEmployee " << i+1;
        e.display();
    }
    inFile.close();

    return 0;
}