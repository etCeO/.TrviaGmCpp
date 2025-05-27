#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include "Player.h" // connects Player header declarations

// FOR READABILITY
using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl
using std::ostream; // shortens stream to ostream

        Player::Player(){name = ""; score = 0;} // Default Constructor for proper processing
        // name is assigned with no value and score is 0

        Player::Player(std::string n) : name(n), score(0) {} // OVERLOADED CONSTRUCTOR
        // takes in string n and stores it as the Player's name
        // all players start with a score of 0 pts

        // METHODS

        void Player::incrementScore(int tries, int player_points) {
            // MUTATOR for score
            // takes in a player's tries and remaining time and computes their score
            score += player_points; // 60 sec. - time is added
            if (tries == 1) { // if the Player answered on their 1st try
                score += 10; // add 10 pts
            }
            else if (tries == 2) { // if the Player answered on their 2nd try
                score += 5; // add 5 pts
            }
        }

        Player::~Player(){}; // empty destructor for Player
        // no additional memory needs to be cleared

        // ACCESSORS

        std::string Player::getName() {
            // Player name is returned
            return name;
        }

        int Player::getScore() {
            // Player score is returned
            return score;
        }

    // OPERATOR
    // displays the player's score
    // I also included their name because why not

    std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Name: " << player.name << endl;
        os << "Score: " << player.score << endl;
        return os;
    }
