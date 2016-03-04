//
// Created by Ennis Massey on 4/03/16.
//
#include "UmbrellaOrder.h"
// Namespace to store number of order and whats been previously ordered.
namespace {
    std::map<char*, int, int> orderSt;
    int orderNum;
    void incrNum () {
            orderNum += 1;
    };
}
// Functions that main will call
// Confirms Order
void confirmOrder() {

}
// Passes orders to a list
void orderToList() {

}
// Takes user input
void userInput() {

}

// Main Function
int main(int argc, char *argv[], char *envp[]) {
    // Greeting
    // Debugging fo now
    for (int i = 0; i < sizeof(*envp); i++) {
        // Store regexx for matching
        std::regex userMatch("USER=");
        // Check if it's the USER entry of path
        if (std::regex_search(envp[i], userMatch) == true) {
            // Store the regex cause otherwise it breaks
            std::regex notNAME("[^USER=].+");
            /* Debug Stuff
            std::cout << envp[i] << std::endl;
            auto* test = envp;
            std::cout << typeid(test).name() << std::endl;
            std::cout << test << std::endl;
            */
            // Filter out the user's name and store it
            // Assign the correct envp index to a char cause otherwise I get errors
            char *envUserName{envp[i]};
            // Create literal match results holder
            std::cmatch match;
            // Find everything proceeded by USER= and then return it excluding USER=
            std::regex_search(envUserName, match, notNAME);
            // Assign matches string result to another char for same reason as above
            char *fetchedName;
            strcpy(fetchedName, match.str().data());
            char *firstLetter;
            strcpy(firstLetter, fetchedName);
            // Capitalize first letter - Here we have to write to a new char to prevent breakage
            char usersName[sizeof(*fetchedName)];
            strcpy(usersName, std::toupper(firstLetter));

            std::cout << usersName[1] << std::endl;
            std::cout << "Welcome to UmbrellaOrder " << std::endl;
        }
    }
}