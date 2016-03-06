//
// Created by Ennis Massey on 4/03/16.
//
#include "UmbrellaOrder.h"
// Namespace to store number of order and whats been previously ordered.
namespace orderNum {
    int orderNum;
    // Typedef for nested dict
    typedef std::map<string, int> newOrder;
    // Create initial dict
    std::map<int, newOrder> orders;
    void incrNum () {
            orderNum += 1;
    };
}
// Prototypes
void initPrompt();
bool checkColour(string colour);
bool continuePrompt();
// Functions that main will call

// Confirms Order
void confirmOrder() {

}

// Passes orders to a list
void orderToList() {

}

// Prototype to prevent breakage


// Takes user input
// Now thats done, take the user's desired input
void colInput() {
    // This is here so tolower works
    const std::locale loc;
    std::cout << "Please enter the desired umbrella colour" << std::endl;
    std::cout << "Put your colour in please: "; // No line end here to make this a prompt
    string usersInput; // String for storing user input
    // String to store lowercase copy of colour
    string lowerColour;
    int quant; // Store amount ordered
    // Use getline for input extraction
    getline(std::cin, usersInput);
    // Convert colour to lowercase so it's case insensitive
    for (int j = 0; j < usersInput.length(); ++j) {
        string tmp;
        tmp = std::tolower(usersInput.at(j), loc);
        // Debug std::cout << tmp << std::endl;
        lowerColour.append(tmp);
        // Debug std::cout << lowerColour << std::endl;
    }
    // Check the users input to see if it matches a valid colour. If so, ask's for amount
    if (checkColour(lowerColour)) {
        std::cout << std::endl << "Quantity: ";
        std::cin >> quant;
        // Append/Update usersInput to orderNum::ordersMade
        auto mapAccess = orderNum::orders[orderNum::orderNum];
        std::map<string, int> tmpOrderStore;
        tmpOrderStore[lowerColour] = quant;
        orderNum::orders[orderNum::orderNum] = tmpOrderStore;
        // Because it's stored as a pair, we have to access it like this
        std::cout << "Color: " << lowerColour << std::endl;
        std::cout << "Quantity: " << orderNum::orders[orderNum::orderNum][lowerColour] /* First of the pair */ << std::endl;
        std::cout << "Order Num: " << orderNum::orderNum /* Second of the pair */ << std::endl;

    }

    if (checkColour(lowerColour)) { // If it return true
    }

};
bool continuePrompt () {
    std::cout << "Are you sure you wish to continue with this selection" << std::endl;
    std::cout << "Your current order is: " << std::endl;
    // for (auto it = orderNum::ordersMade.begin(); it != orderNum::ordersMade.end(); ++it) {
        // std::cout << orderNum::ordersMade[0].first << std::endl;
    // }
    return true;
}


void inputPrompt() {
    // Print Order Num
    std::cout << orderNum::orderNum << std::endl;
    colInput();
};
// Initial Prompt
void initPrompt() {
    // Moved here so it only prints once
    std::cout << "Please enter the desired colour of your Umbrella" << std::endl;
    std::cout << "You will then be prompted for quantity. To cancel an order, type cancel. To finish an order and  proceed to checkout, type done" << std::endl;
    inputPrompt();
}
// Checks Color
bool checkColour(string colour) {
    // Store valid colours
    std::list<string> validColours = {
            "red",
            "blue",
            "light green",
            "orange",
            "dark grey",
            "clear",
    };
    // Iterate through items in validColours
    for (auto i = validColours.begin(); i != validColours.end(); ++i) {
        if (colour == *i) {
            return true;
        }
        else if (colour == "done") {
            continuePrompt();
        }
    }
    // If loop exits return false
    return false;
}

// Main Function
int main(int argc, char *argv[], char *envp[]) {
    const std::locale loc;
    // Greeting
    for (int i = 0; i < sizeof(*envp); i++) {
        // Store regex for matching
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