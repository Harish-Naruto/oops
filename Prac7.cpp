#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map to store state populations
    map<string, float> statePopulation;
    
    // Add some states and their populations (in millions)
    statePopulation["Maharashtra"] = 125;
    statePopulation["Uttar Pradesh"] = 225;
    statePopulation["Bihar"] = 120;
    statePopulation["West Bengal"] = 100;
    statePopulation["Tamil Nadu"] = 80;
    statePopulation["Karnataka"] = 68;
    statePopulation["Gujarat"] = 70;
    statePopulation["Punjab"] = 31;
    statePopulation["Kerala"] = 38;
    statePopulation["Delhi"] = 19;

    int choice;
    do {
        cout << "\n=== Indian States Population Database ===";
        cout << "\n1. Display all states population";
        cout << "\n2. Search state population";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                // Display all states and their populations
                cout << "\nPopulation of all states:\n";
                for(auto state : statePopulation) {
                    cout << state.first << ": " << state.second << " million\n";
                }
                break;

            case 2:
                // Search for a specific state
                {
                    string stateName;
                    cout << "\nEnter state name: ";
                    cin >> stateName;

                    auto it = statePopulation.find(stateName);
                    if(it != statePopulation.end()) {
                        cout << stateName << "'s population is " << it->second << " million\n";
                    } else {
                        cout << "State not found in database!\n";
                    }
                }
                break;

            case 3:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 3);

    return 0;
}