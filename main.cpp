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

// loadTraffic() loads the initial traffic data
// arguments: a map containing traffic data for each road
// returns: nothing
void loadTraffic(
    map<string, array<list<string>, VEHICLE_TYPES>>& traffic) {
    // Open traffic.txt using ifstream

    // Check if the file opened successfully

    // Read the road name, vehicle type, and vehicle ID

    // Mockup: add one test vehicle instead of reading a file
    traffic["Main Street"][CAR].push_back("CAR001");

    // Continue reading until the end of the file

    // Close the file

    cout << "Test traffic data loaded." << endl;
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

    // Repeat the simulation for 30 time periods

    // Go through each road

    // Randomly decide whether a vehicle enters or leaves

    // Mockup: simulate one truck entering Main Street
    traffic["Main Street"][TRUCK].push_back("TRUCK001");

    // If a vehicle leaves, remove it from the correct list

    // Check that a list is not empty before removing a vehicle

    // Display the updated traffic conditions
    cout << "Test traffic simulation completed." << endl;
}
