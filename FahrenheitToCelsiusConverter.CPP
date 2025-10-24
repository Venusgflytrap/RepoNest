/*
 * Program: FahrenheitToCelsiusConverter.cpp
 * Author: Lavone Frazier
 * Date: October 24, 2025
 * Course: CS210
 *
 * Purpose:
 *   Read city-temperature data from FahrenheitTemperature.txt,
 *   convert the temperature to Celsius, and write the results
 *   (city name + Celsius temperature) to CelsiusTemperature.txt.
 *   Demonstrates file input/output, string/integer handling,
 *   and best commenting/naming practices in C++.
 */

#include <iostream>    // For input/output
#include <fstream>     // For file handling
#include <string>      // To work with string variables
#include <iomanip>     // For output formatting

using namespace std;

int main() {
    // Input and output streams
    ifstream inFile("FahrenheitTemperature.txt");   // Input file stream (reading)
    ofstream outFile("CelsiusTemperature.txt");     // Output file stream (writing)

    // Check if input file is open/exists
    if (!inFile.is_open()) {
        cerr << "Error: Could not open FahrenheitTemperature.txt for reading." << endl;
        return 1;
    }

    // Check if output file can be created
    if (!outFile.is_open()) {
        cerr << "Error: Could not create CelsiusTemperature.txt for writing." << endl;
        inFile.close();
        return 1;
    }

    string city;
    int fahrenheit;
    double celsius;

    // Write a header to the output file (optional)
    // outFile << "City CelsiusTemperature" << endl;

    // Read from the file until end-of-file is reached
    while (inFile >> city >> fahrenheit) {
        // Convert to Celsius using formula: (°F − 32) × 5 ÷ 9 = °C
        celsius = (fahrenheit - 32) * 5.0 / 9.0;
        
        // Write city and Celsius temperature to output file
        // Set fixed-point notation and 2 decimal places for output
        outFile << city << ' ' << fixed << setprecision(2) << celsius << endl;
    }

    // Close BOTH files to release resources
    inFile.close();
    outFile.close();

    // Inform user that conversion is complete
    cout << "Conversion completed! Data written to CelsiusTemperature.txt" << endl;

    return 0; // Indicate success
}
