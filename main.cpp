// COMSC-210-5293 | Lab 29 | Yuyi Chen

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

const int VEHICLE_TYPES = 3;
const int TIME_PERIODS = 30;

const int CAR = 0;
const int TRUCK = 1;
const int BUS = 2;

// Function prototypes
void loadTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic);
void displayTraffic(
    const map<string, array<list<string>, VEHICLE_TYPES>>& traffic);
void simulateTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic);

int main() {
    srand(time(0));

    // Create a map to store traffic data for each road
    // Each road contains three lists: cars, trucks, and buses
    map<string, array<list<string>, VEHICLE_TYPES>> traffic;

    // Load the initial traffic data
    loadTraffic(traffic);

    // Display the initial traffic conditions
    displayTraffic(traffic);

    // Run a test traffic simulation
    simulateTraffic(traffic);

    // Display the updated traffic conditions
    displayTraffic(traffic);

    return 0;
}


 // loadTraffic() loads the initial traffic data from a file
 // arguments: a map containing traffic data for each road
 // returns: nothing
void loadTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic) {

    // Open the input file
    ifstream fin("traffic.txt");

    // Check if the file opened successfully
    if (!fin) {
        cout << "Error opening traffic.txt" << endl;
        return;
    }

    string road, type, id;

    // Read the road name, vehicle type, and vehicle ID
    while (fin >> road >> type >> id) {

        // Store the vehicle in the correct list
        if (type == "CAR") {
            traffic[road][CAR].push_back(id);
        }
        else if (type == "TRUCK") {
            traffic[road][TRUCK].push_back(id);
        }
        else if (type == "BUS") {
            traffic[road][BUS].push_back(id);
        }
    }

    // Close the input file
    fin.close();

    cout << "Traffic data loaded." << endl;
}

// displayTraffic() displays the current traffic conditions
// arguments: a map containing traffic data for each road
// returns: nothing
void displayTraffic(
    const map<string, array<list<string>, VEHICLE_TYPES>>& traffic) {
    // Go through each road in the map
    for (auto it = traffic.begin(); it != traffic.end(); it++) {
        cout << "Road: " << it->first << endl;

        // Count the vehicles in each category
        int cars = it->second[CAR].size();
        int trucks = it->second[TRUCK].size();
        int buses = it->second[BUS].size();

        // Display the number of vehicles
        cout << "Cars: " << cars << endl;
        cout << "Trucks: " << trucks << endl;
        cout << "Buses: " << buses << endl;

        // Display the total number of vehicles
        cout << "Total: " << cars + trucks + buses << endl;
        cout << endl;
    }
}

 // simulateTraffic() simulates vehicles entering and leaving roads
 // arguments: a map containing traffic data for each road
 // returns: nothing
void simulateTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic) {

    // Go through each road in the map
    for (auto it = traffic.begin(); it != traffic.end(); it++) {

        // Randomly choose a vehicle type
        int type = rand() % VEHICLE_TYPES;

        // Randomly decide if a vehicle enters or leaves
        int action = rand() % 2;

        if (action == 0) {

            // Add a new vehicle to the selected list
            string id = "NEW" + to_string(rand() % 1000);

            it->second[type].push_back(id);

            cout << "Added " << id << " to "
                 << it->first << endl;
        }
        else {

            // Check if the selected list is not empty
            if (!it->second[type].empty()) {

                // Remove the first vehicle from the list
                it->second[type].pop_front();

                cout << "Removed a vehicle from "
                     << it->first << endl;
            }
        }
    }

    cout << "Test traffic simulation completed." << endl;
}
