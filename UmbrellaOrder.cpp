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
    const std::locale loc;
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
            string fetchedName = match.str().data();
            // Capitalize first letter - Here we have to write to a new char to prevent breakage
            string usersName;
            usersName = fetchedName[0];
            usersName = toupper(usersName[0], loc);
            for (auto j = 1; j <= fetchedName.size()-1; j++) {
                // TMP storage otherwise it craps itself
                auto tmp = fetchedName[j];
                usersName.push_back(tmp);
            }
            std::cout << usersName << std::endl;
            std::cout << "Welcome to UmbrellaOrder " << std::endl;
        }
    }
}