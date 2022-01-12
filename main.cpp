#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
using namespace std;

string generateRandomQuestion()
{
  srand((unsigned)time(0));
  int result = 1 + (rand() % 20);
  usleep(1000);
  stringstream ss;
  ss << result;
  string str = ss.str();
  return str + ".txt";
}
void Rules()
{
  // function to read out all of the rules, spaced out by pauses to prevent users from being overwhelmed by a block of text
  cout << endl;
  cout << "\033[47;30m Here's how to play!" << endl;
  usleep(1500000);
  cout << "To start, select a difficulty level." << endl;
  usleep(2350000);
  cout << "Easy level starts with $100 000 and 60 percent emmisions" << endl;
  usleep(4000000);
  cout << "Medium level starts with $80 000 and 70 percent emmisions" << endl;
  usleep(4000000);
  cout << "Hard level starts with $50 000 and 80 percent emmisions" << endl;
  usleep(4000000);
  cout << "Then, you will be asked questions to test your skill at city planning" << endl;
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
  cout << "Tremendous Resposibility...                                  " << endl;
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

int main()
{
  //Variables used to take input of whether the user would like to play, or hear the rules
  string running;
  string rules;
  //Variables to keep track of game ending conditions and the selected user difficulty
  int cash;
  int emissions;
  int difficulty;
  //Starting the game if the user is ready 
  cout << "\033[47;30m Good Day! Welcome to the Urban City Planner!\n In this game you will act as a City Planner and be faced with many situations and dillemas which you must solve!\n Are you ready for the responsibility of a whole city? [yes/no]\033[0m" << endl;
  cin >> running;
  if ((running == "yes") || (running == "Yes"))
  {
    // Asking the players if they want to read the rules and calling the Rules function if they do 
    cout << "\033[47;30m Would you like to hear the rules? [yes/no]\033[0m" << endl;
    cin >> rules;
    if ((rules == "yes") || (rules == "Yes"))
    {
      Rules();
    }
    //Having the user select a difficulty level and adjusting the cash and emmisions values accordingly 
    cout << "\033[47;30m What difficulty level would you like to start with? Easy = 1, Medium = 2, Hard = 3\033[0m" << endl;
    cin >> difficulty;
    switch (difficulty)
    {
    case 1:
      cash = 100000;
      emissions = 60;
      cout << "Starting Cash value: $100 000, Emissions 60%" << endl;
      break;
    case 2:
      cash = 80000;
      emissions = 70;
      cout << "Starting Cash value: $85 000, Emissions 70%" << endl;
      break;
    case 3:
      cash = 50000;
      emissions = 80;
      cout << "Starting Cash value: $50 000, Emissions 80%" << endl;
      break;
    }
    //printing out current emmissions and cash
    usleep(1000000);
    system("clear");
    usleep(1000000);
    cout << "\033[47;30m Current Emmisions: " << emissions << "%" << endl;
    usleep(1000000);
    cout << "Current Cash: $" << cash << endl;
    usleep(1000000);

    //Variables to store the change in emmisions of each option for every question
    int aemissions;
    int acost;
    int bemissions;
    int bcost;
    int cemissions;
    int ccost;
    int demissions;
    int dcost;
    //Variable to keep track of how many rounds have completed
    int round = 0;
    // Boolean used to keep track of if a question hasn't been found yet
    bool questionNotFound = true;
    // String to keep track of the file name selected by the random function
    string filename;
    // List which keeps track of all the unopened files and has elements which are removed when files are found
    string unopenedFiles[20] = {
        "1.txt",
        "2.txt",
        "3.txt",
        "4.txt",
        "5.txt",
        "6.txt",
        "7.txt",
        "8.txt",
        "9.txt",
        "10.txt",
        "11.txt",
        "12.txt",
        "13.txt",
        "14.txt",
        "15.txt",
        "16.txt",
        "17.txt",
        "18.txt",
        "19.txt",
        "20.txt",
    };
    while ((emissions < 100) && (cash > 0) && (round!=20))
    {

      questionNotFound = true;
      cout << "Round #" << round <<endl;
      aemissions = 0;
      acost = 0;
      bemissions = 0;
      bcost = 0;
      cemissions = 0;
      ccost = 0;
      demissions = 0;
      dcost = 0;

      while (questionNotFound)
      {
        filename = generateRandomQuestion();
        for (int i = 0; i < 20; i++)
        {
          if (unopenedFiles[i] == filename)
          {
            unopenedFiles[i] = " ";
            questionNotFound = false;
          }
        }
      }

      string line;
      fstream currentfile;
      currentfile.open("data/"+filename);
      if (currentfile.is_open())
      {
        int counter = 0;
        while (getline(currentfile, line))
        {
          if (counter <= 4)
          {
            cout << line << '\n';
            usleep(3000000);
          }
          else if (counter == 6)
          {
            aemissions = stoi(line);
          }
          else if (counter == 7)
          {
            acost = stoi(line);
          }
          else if (counter == 8)
          {
            bemissions = stoi(line);
          }
          else if (counter == 9)
          {
            bcost = stoi(line);
          }
          else if (counter == 10)
          {
            cemissions = stoi(line);
          }
          else if (counter == 11)
          {
            ccost = stoi(line);
          }
          else if (counter == 12)
          {
            demissions = stoi(line);
          }
          else if (counter == 13)
          {
            dcost = stoi(line);
          }
          counter++;
        }
        char choice;
        cout << "What will you do?\033[0m" << endl;
        cin >> choice;
        while((choice!='a') && (choice!='b') &&(choice!='c') && (choice!='d')){
          cout << "Invalid! please select a valid option\033[0m" << endl;
          cin >> choice;
        }
        switch (choice)
        {
        case 'a':
          emissions += aemissions;
          cash += acost;
          break;
        case 'b':
          emissions += bemissions;
          cash += bcost;
          break;
        case 'c':
          emissions += cemissions;
          cash += ccost;
          break;
        case 'd':
          emissions += demissions;
          cash += dcost;
        }
        system("clear");

        if (emissions < 0)
        {
          emissions = 0;
        }
        if (cash < 0)
        {
          cash = 0;
        }
        round++;
        usleep(1000000);
        cout << "\033[47;30m Current Emmisions: " << emissions << "%" << endl;
        usleep(1000000);
        cout << "Current Cash: $" << cash << endl;
        usleep(1000000);
        currentfile.close();
       
      }

    }
    if(round == 20){
      cout << "Congratulations, you defeated all of this game's challenges while keeping emissions down and still having money leftover." << endl;
      usleep(4000000);
      cout << "Thanks for playing" <<endl;
      system("clear");
      rollCredits();
    }else{
      cout << "You failed to save the city." <<endl;
      usleep(4000000);
      cout << "Thanks for playing" <<endl;
      system("clear");
      rollCredits();
    }

 
  }
  return 0;
}
 
