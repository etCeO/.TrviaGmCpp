#ifndef TRIVIAGAME_H // checks to see if TriviaGame is a defined class
#define TRIVIAGAME_H // defines class TriviaGame

#include "Player.h" // connects Player class and headers
#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <vector> // includes std::vector

class TriviaGame { // body of TriviaGame class is constructed

    private: // private variables and methods
        std::vector<std::string> questions; // vector of strings that stores Trivia questions
        std::vector<std::string> pastQuestions; // vector of strings that tracks Trivia questions that were already asked
        std::vector<std::string> answers; // vector of strings that stores Trivia answers
        std::vector<std::string> pastAnswers; // vector of strings that tracks Trivia answers from pastQuestions
        Player player1; // first Player stored in variable player1
        Player player2; // second Player stored in variable player2
        void buildQuestions(); // void method that creates the string vector of questions
        void buildAnswers(); // void method that creates the string vector of answers
        bool checkQuestion(std::string s); // method that returns type bool if a question in string s has already been asked

    public: // public methods and constructors
        
        TriviaGame(Player p1, Player p2); // OVERLOADED CONSTRUCTOR
        // takes in two Player objects and assigns them to the game's formatted variables 

        void startGame(); // public void method that handles the loop of the game
        // allows both players to take turns answering their questions
        // game ends when 3 questions have been asked to each player

        void askQuestion(Player&); // public void method that handles the process for asking and answering questions
        // parameter is in form Player& to modify current Player variables that are passed into askQuestion()
        // a random question and its corresponding answer are pulled from the list of questions
        // these are stored in pastQuestions and pastAnswers to ensure no questions are repeated
        // a player is given three chances to answer a question timed in under 1 minute
        // points are given from Player's incrementScore() function if answered correctly
        // messages print the correct answer when a Player either runs out of time or maxes out their chances

        void displayResults(); // public void method that prints the final results of both Player's scores
        // declares the winner of the game and prints a goodbye message to the audience

        ~TriviaGame(); // TriviaGame destructor

        // ACCESSORS

        std::vector<std::string> getQuestions(); // returns all questions asked during the game (pastQuestions)
        
        std::vector<std::string> getAnswers(); // returns corresponding answers for questions asked during the game (pastAnswers)

        Player getPlayer1(); // returns player1

        Player getPlayer2(); // returns player2

        friend std::ostream& operator<<(std::ostream& os, const TriviaGame& game);
        // operator for game using ostream
        // friend connects the header declaration with the cpp file

};

#endif // marks the end of definition
