// library which allows to take input from and output into the console
#include <iostream>
//Library which instructs the program to wait for a little before executing the next command
#include <unistd.h>
// namespace which allows for things like cout and string to be written without adding std:: in front of them each time
using namespace std;
void Rules()
{
  // function to read out all of the rules, spaced out by pauses to prevent users from being overwhelmed by a block of text
  cout << endl;
  cout << "\033[47;30mHere's how to play!" << endl;
  usleep(1500000);
  cout << "To start, select a difficulty level." << endl;
  usleep(2350000);
  cout << "Easy level starts with $100 000 and 60 percent emmisions" << endl;
  usleep(4000000);
  cout << "Medium level starts with $80 000 and 70 percent emmisions" << endl;
  usleep(4000000);
  cout << "Hard level starts with $50 000 and 80 percent emmisions" << endl;
  usleep(4000000);
  cout << "For further customization, you can choose your own difficulty level and enter starting cash and emissions values yourself" << endl;
  usleep(4000000);
  cout << "Then, you will be asked questions to test your skill at city planning. type a, b, c or d to select one of the four options" << endl;
  usleep(4000000);
  cout << "Each answer will affect your total emissions and money earned, and if you run out of money or emissions reaches 100% you will lose!" << endl;
  usleep(8000000);
  cout << "Without further ado, lets begin!\033[0m" << endl;
  usleep(3500000);
  cout << endl;
}

void rollCredits(){
  // Function which prints out a thank you and reflection piece at the end of the playthrough, along with a text based tree based off of our early lessons.
  cout << "This project was created to test the limits of your abilities" << endl;
  usleep(3150000);
  cout << "The task of taking control of the future is quite difficult  " << endl;
  usleep(4000000);
  cout << "No matter how you did, I'm proud of you for taking that      " << endl;
  usleep(3500000);
  cout << "Tremendous Responsibility...                                  " << endl;
  usleep(3000000);
  cout << "Take some time to reflect on your successes and failures     " << endl;
  usleep(4000000);
  cout << "The game keeps track of both money and greenhouse emmisions  " << endl;
  usleep(4000000);
  cout << "But it does not keep track of your own opinions and morals   " << endl;
  usleep(4500000);
  cout << "Feel free to play again any time :)                          " << endl;
  usleep(3000000);
  cout << "                             *                               " << endl;
  usleep(500000);
  cout << "                            /|\\                              " << endl;               
  usleep(500000);
  cout << "                           /*|O\\                             " << endl;
  usleep(500000);
  cout << "                          /*/|\\*\\                            " << endl;
  usleep(500000);
  cout << "                         /X/O|*\\X\\                           " << endl;
  usleep(500000);
  cout << "                        /*/X/|\\X\\*\\                          " << endl;
  usleep(500000);
  cout << "                       /O/*/X|*\\O\\X\\                         " << endl;
  usleep(500000);
  cout << "                      /*/O/X/|\\X\\O\\*\\                        " << endl;
  usleep(500000);
  cout << "                     /X/O/*/X|O\\X\\*\\O\\                       " << endl;
  usleep(500000);
  cout << "                    /O/X/*/O/|\\X\\*\\O\\X\\                      " << endl;
  usleep(500000);
  cout << "                            |X|                              " << endl;
  usleep(500000);
  cout << "                            |X|                              " << endl;
  usleep(500000);
  cout << "                   A Game by Lavan Surendra                  \033[0m" << endl;
// slowly scrolling credits away before clearing the console
  usleep(3000000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  usleep(500000);
  cout << endl;
  system("clear");
}
