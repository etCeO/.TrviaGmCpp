#ifndef PLAYER_H // checks to see if Player is a defined class
#define PLAYER_H // defines class Player

#include <iostream> // includes input and output functions
#include <string> // includes std::string

class Player { // body of Player class is constructed

    private: // private variables
        std::string name; // name of type string stores the Player's name
        int score; // score of type int stores the Player's score

    public: // public methods and constructors

        Player(); // default constructor for proper processing

        Player(std::string n); // overloaded constructor for Player
        // takes in a Player's name as type string and stores their information

        void incrementScore(int tries, int player_points);
        // public method that modifies a player's score
        // added parameters include tries and player_points of type int for more accurate calculations
        // tries -> how many times it took the player to answer
        // player_points -> (60 seconds) - (time it took for the player to form a response)
        // incrementScore is only called when a player answers a question correctly
      
        ~Player(); // destructor for Player

        std::string getName(); // returns the Player's name variable

        int getScore(); // returns the Player's score variable

        friend std::ostream& operator<<(std::ostream& os, const Player& player);
        // operator for player using ostream
        // friend connects the header declaration with the cpp file

};

#endif // marks the end of definition
