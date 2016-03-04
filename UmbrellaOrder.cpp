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
            // Filter out the user's name and store it
            std::cout << envp[i] << std::endl;
            auto* test = envp;
            std::cout << typeid(test).name() << std::endl;
            std::cout << test << std::endl;
            const char *envUserName{envp[i]};
            std::match_results<const char*> match;
            std::regex_search(envUserName, match, notNAME);
            std::cout << match.str() << std::endl;
        }
    }
}