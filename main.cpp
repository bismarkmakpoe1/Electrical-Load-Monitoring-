#include <string>
#include <iostream>
#include <vector>
#include <iomanip> // For better decimal formatting

using namespace std;

class Appliance {
private:
    string name;
    double powerRating;
    double usageHours;

public:
    Appliance(string n, double p, double h) : name(n), powerRating(p), usageHours(h) {}

    string getName() const { return name; }
    double getPower() const { return powerRating; }
    double getHours() const { return usageHours; }

    double calculateEnergy() const {
        return (powerRating * usageHours) / 1000.0;
    }
};

vector<Appliance> appliances;

void registerAppliance() {
    string name;
    double power, hours;

    cout << "\n--- Register New Appliance ---\n";
    cout << "Enter appliance name: ";
    getline(cin, name);

    while (name.empty()) {
        cout << "Name cannot be empty. Enter again: ";
        getline(cin, name);
    }

    cout << "Enter power rating (Watts): ";
    cin >> power;
    while (power <= 0) {
        cout << "Power must be > 0. Enter again: ";
        cin >> power;
    }

    cout << "Enter daily usage hours (0 - 24): ";
    cin >> hours;
    while (hours < 0 || hours > 24) {
        cout << "Hours must be 0-24. Enter again: ";
        cin >> hours;
    }
    cin.ignore(1000, '\n'); // Clear buffer for next menu input

    appliances.push_back(Appliance(name, power, hours));
    cout << "Appliance registered successfully!\n";
}

void viewAppliances() {
    if (appliances.empty()) {
        cout << "\nNo appliances registered yet.\n";
        return;
    }

    double totalEnergy = 0;
    cout << "\n--- Registered Appliances ---\n";
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Watts", "Hours", "kWh/Day");
    cout << "--------------------------------------------------------\n";

   
}



int main() {
    int choice;
    while (true) {
        cout << "\n--- ENERGY TRACKER MENU ---\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Registered Appliances\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n'); // Critical: clears the 'Enter' key from buffer

        switch (choice) {
            case 1: registerAppliance(); break;
            case 2: viewAppliances(); break;
            case 3: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}