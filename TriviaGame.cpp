#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <vector> // includes std::vector
#include <cstdlib> // includes time from standard library
#include <ctime> // includes tracking of time
#include <chrono> // includes chrono function for time methods during the game
#include "TriviaGame.h" // connects TriviaGame header declarations
#include "Player.h" // connects Player class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl
using std::cin; // shortens input to cin

void TriviaGame::buildQuestions() { // a public void method that generates 11 questions as strings and adds them to the questions vector
// all questions are pulled from Google's web search on lists of random trivia questions
// questions range in a variety of topics from sports to animals to art, science, history, geography, or the solar system
    questions.push_back("What is the only planet in our solar system that rotates on its side?");
    questions.push_back("What is the smallest country in the world by land area?");
    questions.push_back("Which element in the period table has the chemical symbol 'Au' ?");
    questions.push_back("Which famous artist is known for cutting off his own ear?");
    questions.push_back("What is the longest river in the world?");
    questions.push_back("What type of animal is the largest living species of reptile?");
    questions.push_back("Who wrote the famous play, 'Romeo and Juliet' ?");
    questions.push_back("What is the capital city of Japan?");
    questions.push_back("What is the tallest mountain in the world?");
    questions.push_back("In which sport would you compete in the 'Tour de France' ?");
    questions.push_back("Who was the first woman to fly solo across the Atlantic Ocean?");
}

void TriviaGame::buildAnswers() { // a public void method that generates 11 answers as strings and adds them to the answers vector
// all answers are pulled from Google's web search on lists of random trivia questions
    answers.push_back("Uranus");
    answers.push_back("Vatican City");
    answers.push_back("Gold");
    answers.push_back("Vincent Van Gogh");
    answers.push_back("The Nile River");
    answers.push_back("Crocodile");
    answers.push_back("William Shakespeare");
    answers.push_back("Tokyo");
    answers.push_back("Mount Everest");
    answers.push_back("Cycling");
    answers.push_back("Amelia Earhart");
}

bool TriviaGame::checkQuestion(std::string s) { // a private bool method that checks a question to see if it's already been asked
// std::string s is the question that needs to be checked
    bool asked = false; // bool variable asked is false assuming the question hasn't been asked
    for (std::string i : pastQuestions) { // for each question i in the pastQuestions vector
        if (i == s) { // if any match the current question being asked
            asked = true; // assign asked to true since the question was asked
            break; // breaks the loop to no longer evaluate anymore questions
        }
    }
    return asked; // returns the value of the question in bool
}

        
TriviaGame::TriviaGame(Player p1, Player p2) { // OVERLOADED CONSTRUCTOR
// takes in 2 players as parameters and assigns them to the game's variables
    buildQuestions(); // list of questions are formed
    buildAnswers(); // list of answers are formed
    player1 = p1; // first Player is player1
    player2 = p2; // second Player is player2
}

void TriviaGame::startGame() { // public void method that handles the game's overall loop

    int asks = 0; // int asks is assigned with 0 (asks keeps track of the number of questions asked)

    while (asks < 6) { // while the number of questions is "no more than" 6 total

        if (asks % 2 == 0) { // if var asks is an even number
            cout << endl;
            cout << "Player 1 ... 1 minute on the clock" << endl;
            askQuestion(player1); // Player 1 is asked a question
        }
        else { // if var asks is odd
            cout << endl;
            cout << "Player 2, let's try this!" << endl;
            askQuestion(player2); // Player 2 is asked a question
        }
        ++asks; // increments asks by 1 to exchange Player turns and prevent infinite looping
    }
}

void TriviaGame::askQuestion(Player& p) { // public void method that handles each question's timing, pts, and ask
// parameter p is the Player passed in who's being asked the question
// Player& handles modification of private variables in p

    std::string question; // variable for question asked as type string
    std::string answer; // variable for the question's answer as type string

    int tries = 1; // tries of type integer is assigned with 1 to represent each person's first attempt answering a question
    int seconds_taken = 0; // represents the time in seconds each person takes to answer a question
    // at the beginning, this is assigned with 0
    int player_points; // number of points a Player earns when they answer a question correctly (minus bonus pts)
    std::srand(std::time(0)); // seed for time

    int i = rand() % questions.size(); // int i is assigned with a random index from questions
    question = questions[i]; // question stores the string from questions at i
    bool pastQuestion = checkQuestion(question); // boolean pastQuestion is assigned to the result of checkQuestion() on question
    // true if the question has already been asked and false otherwise

    while (pastQuestion) { // while a question has already been asked
        i = rand() % questions.size(); // assign i with another random index
        question = questions[i]; // assign question with that new string in questions
        pastQuestion = checkQuestion(question); // check again to see if the question has been asked
    }
    // this process ensures no repeat questions from the list are asked during the game

    pastQuestions.push_back(question); // once a question has been decided, add this question to pastQuestions to make sure it is not asked again
    answer = answers[i]; // get the question's answer from answers by accessing at same position i
    pastAnswers.push_back(answer); // add answer to pastAnswers to keep track of the game's correct responses

    while (tries < 4 && seconds_taken < 61) { // while a Player tries no more than 3 times and their time is 60 seconds or less

        auto start = std::chrono::steady_clock::now(); // start the clock counting in steady increments of one second

        cout << endl; // newline for neatness

        std::string response; // variable for a player's response as type string
        cout << question << " : "; // asks the question
        std::getline(cin, response); // Player's answer "response" is recorded as input

        if (response == answer) { // if the Player's response is correct

            auto end = std::chrono::steady_clock::now(); // record end time
            seconds_taken += std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
            // add the length between end time to start time to record this as seconds_taken
            // this is the time taken in seconds for the Player to answer the question correctly

            player_points = 60 - seconds_taken; // a Player's points are determined by their quickness in answering the question
            // their remaining time gets assigned as the amount of points they receive
            p.incrementScore(tries, player_points); // Player's incrementScore() takes in player_points and tries accordingly
            // their scores are now increased based on these two criteria
            cout << endl; // newline for neatness
            int totalScore = 0; // totalScore is the combination of both bonus and timing points together
            cout << "CONGRATULATIONS!!! You got it right!" << endl; // informing message printed
            cout << endl;
            if (tries == 1) { // if a Player answers on their first try
                cout << "First Try! :>" << endl;
                totalScore += 10; // tell them so and add 10 bonus points to the overall score
            } 
            else if (tries == 2) { // if a Player answers on their second try
                cout << "Second Try's The Charm! :>" << endl;
                totalScore += 5; // tell them so and add 5 bonus points to the overall score
            }
            totalScore += player_points; // add the remaining points from time
            cout << seconds_taken << " seconds taken!!!" << endl; // print the Player's time
            cout << "+" << totalScore << " pts" << endl; // print how many total points they received for that one question
            cout << "YOUR SCORE SO FAR -> " << p.getScore() << endl; // print their score
            cout << endl;
            cout << "Moving Forward!" << endl;
            break; // end the loop here
        }
        // when a Player doesn't answer correctly
        auto end = std::chrono::steady_clock::now(); // record end time for a single attempt
        seconds_taken += std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
        // add this time to the amount of time they've spent in the round
        ++tries; // increment their tries
        cout << "Wrong!!! Try again! :(" << endl; // print they got the answer wrong
        cout << "Your Time : " << seconds_taken << " seconds" << endl; // record their time spent answering thus far
    }

    if (tries == 4 && seconds_taken < 60) { // if a Player fails because they have no more attempts to answer under 1 minute
        cout << "Sorry " << p.getName() << " :<" << endl; // print their name and a message telling them this happened
        cout << "Looks like you maxed out your guesses..." << endl;
        cout << endl;
        cout << "CORRECT ANSWER : " << answer << endl; // display the correct answer for them to see
        cout << "Moving on!" << endl;
    }
    else if (seconds_taken >= 60) { // if a Player fails because they ran out of time to answer
        cout << "OOH! Tough luck " << p.getName() << " :/" << endl; // print their name and a message telling them this happened
        cout << "Looks like you ran out of time..." << endl;
        cout << endl;
        cout << "CORRECT ANSWER : " << answer << endl; // display the correct answer for them to see
        cout << "Moving on!" << endl;
    }
}

void TriviaGame::displayResults() { // a public void method for displaying the final results of the game
    cout << endl;
    // tell the Players the game has ended
    cout << "END OF GAME!!!!" << endl;
    cout << "_______________" << endl;
    cout << endl;
    cout << "Final Results ->" << endl;
    cout << "PLAYER 1 SCORE: " << player1.getScore() << endl; // print both players' scores
    cout << "PLAYER 2 SCORE: " << player2.getScore() << endl; // access using .getScore() method
    cout << endl;
    if (player1.getScore() > player2.getScore()) { // if Player 1's score is greater than Player 2's score
        cout << "CONGRATS TO PLAYER 1!!!! YOU WON!!" << endl; // print player 1 as the winner
        cout << "The grand prize of $1000 is yours :>" << endl;
    }
    else if (player1.getScore() < player2.getScore()) { // if Player 2's score is greater than Player 1's score
        cout << "CONGRATS TO PLAYER 2!!!! YOU WON!!" << endl; // print player 2 as the winner
        cout << "The grand prize of $1000 is yours :>" << endl;
    }
    else { // in the RARE RARE case that both players end up getting the same score
        cout << "TIE!!!!!!!! CONGRATS TO BOTH PLAYERS!!!!" << endl; // print it's a tie and divide up the prize money
        cout << "The grand prize of $1000 is split into two stashes of $500 for both of you :>" << endl;
    }
}

TriviaGame::~TriviaGame(){}; // empty destructor for TriviaGame

// ACCESSORS

std::vector<std::string> TriviaGame::getQuestions() { // returns pastQuestions
    return pastQuestions;
}

std::vector<std::string> TriviaGame::getAnswers() { // returns pastAnswers
    return pastAnswers;
}

Player TriviaGame::getPlayer1() { // returns Player1
    return player1;
}

Player TriviaGame::getPlayer2() { // returns Player2
    return player2;
}

// OPERATOR
// displays the game's current state including player names and scores

    std::ostream& operator<<(std::ostream& os, const TriviaGame& game) {
        // using ostream, os is the output source and game is the class being implemented
        os << "GAME INFORMATION AND RESULTS" << endl;
        os << "----------------------------" << endl;
        os << endl;
        os << "\t\t\tPLAYER #1" << endl;
        // player 1 info
        os << game.player1 << endl;
        // grabs ostream for player1 to output their name and score
        os << "\t\t\tPLAYER #2" << endl;
        // player 2 info
        os << game.player2 << endl;
        // grabs ostream for player2 to output their name and score
        return os; // returns all output combined together
    }

