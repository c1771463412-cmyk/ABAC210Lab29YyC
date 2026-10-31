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
void loadTraffic();
void displayTraffic();
void simulateTraffic();

int main() {
    srand(time(0));

    // Create a map to store traffic data for each road
    // Each road contains three lists: cars, trucks, and buses

    // Open traffic.txt and read the initial vehicle data

    // Store each vehicle in the correct road and vehicle list

    // Display the initial traffic conditions

    // Run the traffic simulation for 30 time periods
    // During each period, vehicles may enter or leave roads

    // Display the updated traffic conditions after each period

    // Display the final traffic conditions

    return 0;
}

// loadTraffic() loads the initial traffic data from a file
// arguments: none for now
// returns: nothing
void loadTraffic() {
    // Open traffic.txt using ifstream

    // Check if the file opened successfully

    // Read the road name, vehicle type, and vehicle ID

    // Store the vehicle in the correct list

    // Continue reading until the end of the file

    // Close the file
}

// displayTraffic() displays the current traffic conditions
// arguments: none for now
// returns: nothing
void displayTraffic() {
    // Go through each road in the map

    // Display the road name

    // Count the cars, trucks, and buses

    // Display the number of vehicles in each category

    // Display the total number of vehicles
}

// simulateTraffic() simulates vehicles entering and leaving roads
// arguments: none for now
// returns: nothing
void simulateTraffic() {
    // Repeat the simulation for 30 time periods

    // Go through each road

    // Randomly decide whether a vehicle enters or leaves

    // If a vehicle enters, add it to the correct list

    // If a vehicle leaves, remove it from the correct list

    // Check that a list is not empty before removing a vehicle

    // Display the updated traffic conditions
}
