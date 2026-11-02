// COMSC-210-5293 | Lab 29 | Yuyi Chen

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <list>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

const int VEHICLE_TYPES = 3;
const int TIME_PERIODS = 30;

const int CAR = 0;
const int TRUCK = 1;
const int BUS = 2;

// Function prototypes
bool loadTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic);
void displayTraffic(
    const map<string, array<list<string>, VEHICLE_TYPES>>& traffic);
void simulateTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic);
bool validVehicleID(string id, string type);

int main() {
    srand(time(0));

    // Create a map to store traffic data for each road
    // Each road contains three lists: cars, trucks, and buses
    map<string, array<list<string>, VEHICLE_TYPES>> traffic;

    // Load the initial traffic data
    if (!loadTraffic(traffic)) {
        return 1;
    }

    // Display the initial traffic conditions
    cout << "\nInitial Traffic Conditions:" << endl;
    displayTraffic(traffic);

    // Run the traffic simulation for 30 time periods
    simulateTraffic(traffic);

    // Display the final traffic conditions
    cout << "\nFinal Traffic Conditions:" << endl;
    displayTraffic(traffic);

    return 0;
}

// loadTraffic() loads the initial traffic data from a file
// arguments: a map containing traffic data for each road
// returns: true if data was loaded, otherwise false
bool loadTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic) {

    // Open the input file
    ifstream fin("traffic.txt");

    // Check if the file opened successfully
    if (!fin) {
        cout << "Error opening traffic.txt" << endl;
        return false;
    }

    // Count the number of valid vehicles loaded
    int loadedCount = 0;
    string road, type, id;
    // Store vehicle IDs that have already been loaded
    set<string> loadedIDs;

    // Read the road name, vehicle type, and vehicle ID
    while (fin >> road >> type >> id) {

        // Check if the vehicle ID is already in the file
        if (loadedIDs.find(id) != loadedIDs.end()) {

            cout << "Duplicate vehicle ID: " << id << endl;
        }
        else if (type == "CAR" || type == "TRUCK" || type == "BUS") {

            // Check if the vehicle ID matches its type
            if (validVehicleID(id, type)) {

                if (type == "CAR") {
                    traffic[road][CAR].push_back(id);
                }
                else if (type == "TRUCK") {
                    traffic[road][TRUCK].push_back(id);
                }
                else {
                    traffic[road][BUS].push_back(id);
                }

                // Save the ID after the vehicle is accepted
                loadedIDs.insert(id);
                loadedCount++;
            }
            else {
                cout << "Invalid vehicle ID: " << id
                     << " for " << type << endl;
            }
        }
        else {
            cout << "Invalid vehicle type: " << type
                 << " on " << road << endl;
        }
    }

    // Close the input file
    fin.close();

    // Check if any valid vehicles were loaded
    if (loadedCount == 0) {
        cout << "Error: No valid traffic data found." << endl;
        return false;
    }

    cout << "Traffic data loaded." << endl;
    return true;
}

// displayTraffic() displays the current traffic conditions
// arguments: a map containing traffic data for each road
// returns: nothing
void displayTraffic(
    const map<string, array<list<string>, VEHICLE_TYPES>>& traffic) {

    // Store the total number of vehicles on all roads
    int grandTotal = 0;

    cout << left
         << setw(18) << "Road"
         << setw(10) << "Cars"
         << setw(10) << "Trucks"
         << setw(10) << "Buses"
         << setw(10) << "Total" << endl;

    cout << "----------------------------------------------------------"
         << endl;

    // Go through each road in the map
    for (auto it = traffic.begin(); it != traffic.end(); it++) {

        // Count the vehicles in each category
        int cars = it->second[CAR].size();
        int trucks = it->second[TRUCK].size();
        int buses = it->second[BUS].size();

        // Add the vehicles on this road to the total
        grandTotal += cars + trucks + buses;

        // Display the traffic conditions for each road
        cout << setw(18) << it->first
             << setw(10) << cars
             << setw(10) << trucks
             << setw(10) << buses
             << setw(10) << cars + trucks + buses
             << endl;
    }

    cout << "----------------------------------------------------------"
         << endl;
    cout << "Grand Total: " << grandTotal << endl;
    cout << endl;
}

// simulateTraffic() simulates vehicles entering and leaving roads
// arguments: a map containing traffic data for each road
// returns: nothing
void simulateTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic) {

    // Keep track of new vehicle IDs for each type
    int nextID[VEHICLE_TYPES] = {1, 1, 1};

    // Store all vehicle IDs that have been used
    set<string> usedIDs;

    // Save the IDs of all vehicles loaded from the file
    for (auto it = traffic.begin(); it != traffic.end(); it++) {

        for (int type = 0; type < VEHICLE_TYPES; type++) {

            for (auto vehicle = it->second[type].begin();
                vehicle != it->second[type].end(); vehicle++) {

                usedIDs.insert(*vehicle);
            }
        }
    }

    // Repeat the simulation for 30 time periods
    for (int period = 1; period <= TIME_PERIODS; period++) {

        cout << "\nTime Period " << period << endl;
        cout << "------------------------" << endl;

        // Go through each road in the map
        for (auto it = traffic.begin(); it != traffic.end(); it++) {

            // Randomly choose a vehicle type
            int type = rand() % VEHICLE_TYPES;

            // Randomly decide if a vehicle enters or leaves
            int action = rand() % 2;

            if (action == 0) {

                // Add a new vehicle to the selected list
                string id;
                string prefix;

                if (type == CAR) {
                    prefix = "CAR";
                }
                else if (type == TRUCK) {
                    prefix = "TRUCK";
                }
                else {
                    prefix = "BUS";
                }

                // Find a vehicle ID that has not been used
                do {
                    string number = to_string(nextID[type]);

                    // Add leading zeros to make the number three digits
                    if (nextID[type] < 10) {
                        number = "00" + number;
                    }
                    else if (nextID[type] < 100) {
                        number = "0" + number;
                    }

                    id = prefix + number;
                    nextID[type]++;

                } while (usedIDs.find(id) != usedIDs.end());

                // Save the new ID so it cannot be used again
                usedIDs.insert(id);

                it->second[type].push_back(id);

                cout << setw(8) << "Added" << setw(9) << id 
                     << setw(5) << "to" << it->first << endl;
            }
            else {

                // Check if the selected list is not empty
                if (!it->second[type].empty()) {

                    // Get the ID of the first vehicle
                    string id = it->second[type].front();

                    // Remove the first vehicle from the list
                    it->second[type].pop_front();

                    cout << setw(8) << "Removed" << setw(9) << id 
                         << setw(5) << "from" << it->first << endl;
                }
                else {

                    // Display a message when the selected list is empty
                    cout << "No vehicle to remove from "
                         << it->first << endl;
                }
            }
        }

        // Display the updated traffic conditions
        cout << "\nTraffic conditions after period "
             << period << ":" << endl;

        displayTraffic(traffic);
    }

    cout << "Traffic simulation completed." << endl;
}

// validVehicleID() checks the prefix and numbers of a vehicle ID
// arguments: the vehicle ID and its vehicle type
// returns: true if the ID is valid, otherwise false
bool validVehicleID(string id, string type) {

    int start = 0;

    if (type == "CAR" || type == "BUS") {
        start = 3;
    }
    else if (type == "TRUCK") {
        start = 5;
    }
    else {
        return false;
    }

    // Check if the ID starts with the correct vehicle type
    if (id.find(type) != 0) {
        return false;
    }

    // Check if the ID contains at least one number
    if (id.size() <= start) {
        return false;
    }

    // Check if every character after the prefix is a digit
    for (int i = start; i < id.size(); i++) {

        if (id[i] < '0' || id[i] > '9') {
            return false;
        }
    }

    return true;
}
