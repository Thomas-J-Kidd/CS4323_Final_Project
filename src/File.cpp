/*
Author: Ben Sailor
Name: File
Date written: 04/14/2024
Updated:
    - By: Ben Sailor on 04/14/2024
*/

#include "File.h"

#include <fstream>
#include <iostream>
#include <string>



bool exists(const std::string account_id) { // Function to check if the account exists
    std::ifstream infile("./accounts/" + account_id);   // Open the file
    return infile.good();                   // Return true if the file is open
}

File::File() { }                            // Default constructor

File::File(const std::string& account_id) { // Constructor
    this->fileName = "./users/" + account_id;   // Initialize the file name      
}


void File::create() {                       // Create a file
    std::ofstream outfile(this->fileName); 
}

bool File::write(const double data) {       // Write the balance to the file
    std::string str_data = std::to_string(data);    // Convert the balance to string
    std::ofstream outfile(this->fileName, std::ios::trunc); // Open the file and truncate the content
    if (outfile.is_open()) {                // If the file is open
        outfile << str_data << std::endl;   // Write the balance to the file
        outfile.close();                    // Close the file
        return true;                        // Return true if the balance is written
    }   else {                              // If the file is not open
        return false;                       // Return false if the balance is not written
    }
}

double File::read() {                       // Read the balance from the file
    std::string line;                       // Initialize a string variable
    std::ifstream infile(this->fileName);   // Open the file
    double balance = -1.00;                 // Initialize balance to -1
    if (infile.is_open()) {                 // If the file is open
        getline(infile, line);              // Read the file
        balance = std::stod(line);          // Convert the string to integer
        infile.close();                     // Close the file
    }    else {                             // If the file is not open
        std::cout << "Unable to open file" << std::endl;    // Print an error message
    }
    return balance;                         // Return the balance (-1.00 for error)
}

bool File::deleteFile() {
    if (remove(this->fileName.c_str()) != 0) {
        return false;                       // Return false if the file is not deleted 
    }   
    return true;                            // Return true if the file is deleted
}