//
// Created by Ennis Massey on 4/03/16.
//
#include "UmbrellaOrder.h"
// Namespace to store number of order and whats been previously ordered.
namespace orderNum {
    std::map<string, std::pair<int, int>> ordersMade;
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

// Prototype to prevent breakage
void initPrompt();

// Takes user input
// Now thats done, take the user's desired input
void colInput() {
    std::cout << "Please enter the desired umbrella color" << std::endl;
    std::cout << "Put your color in please: "; // No line end here to make this a prompt
    string usersInput; // String for storing user input
    // Use getline for input extraction
    getline(std::cin, usersInput);
    // Append usersInput to orderNum::ordersMade
    orderNum::ordersMade[usersInput] = std::pair<int, int>(1, 1);
    // Because it's stored as a pair, we have to access it like this
    std::cout << orderNum::ordersMade["yoho"].first; // First of the pair
    std::cout << orderNum::ordersMade["yoho"].second; // Second of the pair
};


// Initial Prompt
void inputPrompt() {
    // Print Order Num
    std::cout << orderNum::orderNum << std::endl;
    colInput();
};
void initPrompt() {
    // Moved here so it only prints once
    std::cout << "Please enter the desired color of your Umbrella" << std::endl;
    std::cout << "You will then be prompted for quantity. To cancel an order, type cancel. To finish an order and  proceed to checkout, type done" << std::endl;
    inputPrompt();
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
        if (std::regex_search(envp[i], userMatch)) {
            // Store the regex cause otherwise it breaks
            std::regex notNAME("[^USER=].+");
            // Filter out the user's name and store it
            // Assign the correct envp index to a char cause otherwise it breaks
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
            std::cout << "Welcome to Umbrella-Order " << usersName << std::endl;
        }
    }
    inputPrompt();
    // Because C++ Sucks
    return 0;
}