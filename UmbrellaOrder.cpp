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
    for (int i = 0; i < sizeof(envp); i++) {
        // Store regexx for matching
        std::regex userMatch("USER=");
        // Check if it's the USER entry of path
        if (std::regex_search(envp[i], userMatch)) {
            std::cout << envp[i] << std::endl;
        }
    }
}