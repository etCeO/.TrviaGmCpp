#include <iostream> // imports input and output functions
#include <string> // includes std::string
#include <vector> // includes std::vector
#include "Player.h" // connects Player class
#include "TriviaGame.h" // connects TriviaGame class

// FOR READABILITY
using std::cout; // shortens output to cout
using std::cin; // shortens input to cin
using std::endl; // shortens newline to endl

int main() { // main function that runs the driver

    std::srand(time(0)); // Seed for random number generation    

    // INTRO with newlines for neatness

    cout << endl;
    cout << "Welcome Back Ladies And Gentleman To Today's Live Virtual Trivia Game!!!" << endl;
    cout << endl;

    // RULES OF THE TRIVIA GAME
    // two players are each asked three questions with guidelines for points

    cout << "Two players will now take the spotlight to answer 6 random trivia questions!" << endl;
    cout << endl;
    cout << "\t1) Each person will get 3 tries to answer a question correctly in under 1 minute" << endl;
    cout << "\t2) The sooner you answer correct, the more points you receive!" << endl;
    cout << "\t3) Answering correctly the first try will score you an additional 10 pts" << endl;
    cout << "\t4) Answering correctly on the second try will score you an additional 5 pts" << endl;
    cout << endl;
    cout << "Whoever has the most points by the end of the game WINS!!!" << endl;
    cout << endl;

    std::string player1Name, player2Name; // declares strings for Player 1 and Player 2 names
    std::string response; // declares string for a response to initiate the game

    // INTRO FOR PLAYER 1

    cout << "Let's Introduce Player #1!!!" << endl;
    cout << "Your name is? : "; // asks for name input
    std::getline(cin, player1Name); // getLine function reads input from user and stores Player 1's name in variable player1Name
    Player p1(player1Name); // a new player is created with Player 1's name as the parameter
    // all contents for Player 1 are stored in variable p1
    cout << "Nice to have you here today " << player1Name << " :)" << endl;
    cout << endl;

    // INTRO FOR PLAYER 2

    cout << "And next up let's get to your competitor! Player #2, please step forward!!!" << endl;
    cout << "Your name is? : "; // asks for name input
    std::getline(cin, player2Name); // getLine function reads input from user and stores Player 2's name in variable player2Name
    Player p2(player2Name); // a new player is created with Player 2's name as the parameter
    // all contents for Player 2 are stored in variable p2
    cout << "Splendid! " << player1Name << " and " << player2Name << ", I wish you both the best of luck!" << endl;
    cout << "So, without further ado, let's start!" << endl;

    // GAME START

    cout << "Both of you ready? "; // random question to initiate game play
    std::getline(cin, response); // once the user inputs something into the response variable, the game officially commences

    cout << endl;
    cout << "Let's Begin!" << endl;

    TriviaGame game(p1, p2); // a game is created from the TriviaGame class for players 1 and 2
    game.startGame(); // players 1 and 2 compete against each other in the game to answer their questions as quickly as they can and earn as many points as possible
    game.displayResults(); // when the game ends, displayResults() outputs the final scores for both players and declares the winner
    cout << endl; // newline for neatness

    cout << "QUESTIONS ASKED" << endl; // prints all questions asked during the game
    cout << endl;
    for (int i = 0; i < game.getQuestions().size(); i++) { // within the questions vector
        cout << (i+1) << ") " << game.getQuestions().at(i) << endl; // get each index and output the string
        // format #) Question? newline
    }
    cout << endl;

    cout << "ANSWERS" << endl; // prints all answers
    cout << endl;
    for (int j = 0; j < game.getAnswers().size(); j++) { // within the answers vector
        cout << (j+1) << ") " << game.getAnswers().at(j) << endl; // get each index and output the string
        // format #) Question? newline
    }
    cout << endl;

    // OPERATORS!!!!
    // cout << endl;
    // cout << game; // prints the final results
    // commented because I found this kind of redundant in the original program
    // displayResults function already shows player scores and who won

    // FEEL FREE to comment out and test lines 88 and 89 to make sure this works! :)

    cout << "Thank you for playing!!! Goodbye! :)" << endl; // goodbye message
    cout << endl;

    return 0; // reached when the program is officially done running
}
