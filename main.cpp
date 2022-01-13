// library which allows for input and output to the console
#include <iostream>
// library which allows for string variables to be made
#include <string>
// library which helps to pause for a certain amount of time before the next command
#include <unistd.h>
// library which allows code to interact with text files
#include <fstream>
#include "textfunc.h"
#include "randomfunc.h"
using namespace std;


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
  while ((running != "yes") && (running != "Yes") && (running != "No") && (running != "no"))
  {
    // This loop asks user to re enter their response incase their response is invalid
    cout << "\033[47;30mInvalid response, please enter either yes or no\033[0m" << endl;
    cin >> running;
  }
  if ((running == "yes") || (running == "Yes"))
  {
    // Asking the players if they want to read the rules and calling the Rules function if they do 
    cout << "\033[47;30m Would you like to hear the rules? [yes/no]\033[0m" << endl;
    cin >> rules;
    while ((rules != "yes")&& (rules!= "Yes")&& (rules!= "No") && (rules!= "no"))
    {
      // This loop asks user to re enter their response incase their response is invalid
      cout << "\033[47;30mInvalid response, please enter either yes or no\033[0m" << endl;
      cin >> rules;
    }
    
    if ((rules == "yes") || (rules == "Yes"))
    {
      Rules();
    }
    //Having the user select a difficulty level and adjusting the cash and emmisions values accordingly 
    cout << "\033[47;30m What difficulty level would you like to start with? Easy = 1, Medium = 2, Hard = 3 Choose your own difficulty = 4 \033[0m" << endl;
    cin >> difficulty;

    while (((difficulty!=1) && (difficulty!=2) && (difficulty!=3) && (difficulty!=4)) || cin.fail())
    {
      //this loop asks the user to re enter a reponse incase they respond with an invalid one
      cout << "\033[47;30mInvalid response, please enter either 1,2,3 or 4 \033[0m" << endl;
      cin.clear();
      cin.ignore(256,'\n');
      cin >> difficulty;
    }
    // Adjusting cash and emissions according to selected difficulty level 
    switch (difficulty)
    {
    case 1:
      cash = 50000;
      emissions = 60;
      cout << "Starting Cash value: $50 000, Emissions 60%" << endl;
      break;
    case 2:
      cash = 25000;
      emissions = 70;
      cout << "Starting Cash value: $25 000, Emissions 70%" << endl;
      break;
    case 3:
      cash = 10000;
      emissions = 80;
      cout << "Starting Cash value: $10 000, Emissions 80%" << endl;
      break;
    case 4:
    // taking input of the users choice of cash and emissions if they select the choose your own option
      cout << "Enter a cash value to start with (must be a number > 0 i.e. (100000)" << endl; 
      cin >> cash;
      // while loop to prompt them to re enter a cash value if their original reponse was invalid
      while ((cash<=0) || (cin.fail()))
      {
        cout << "Please enter a number which is greater than 0" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> cash;
      }
      cout << "Enter a emissions value to start with (must be a number >0 and <100)" << endl;
      cin >> emissions;
      // while loop to prompt them to re enter an emmissions value if their original reponse was invalid
      while ((emissions < 0) || (emissions > 100) || (cin.fail()))
      {
        cout << "Please enter a number which is greater than 0 and less than 100" << endl;  
        cin.clear();
        cin.ignore(256, '\n');
        cin >> emissions; 
      }
      cout <<"Starting Cash value: $" << cash <<", Emissions " << emissions <<"%" << endl;


    }
    //printing out current emmissions and cash
    usleep(3000000);
    system("clear");
    usleep(1000000);
    cout << "\033[47;30m Current Emmisions: " << emissions << "%" << endl;
    usleep(1000000);
    cout << "Current Cash: $" << cash << endl;
    usleep(1000000);

    //Variables to store the change in emmisions and of each option for every question
    int aemissions;
    int acost;
    int bemissions;
    int bcost;
    int cemissions;
    int ccost;
    int demissions;
    int dcost;
    //Variable to keep track of how many rounds have completed
    int round = 1;
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
    // code to ask questions until they run out or the player loses
    while ((emissions < 100) && (cash > 0) && (round!=20))
    {
      // variable which keeps track of if a valid filename is found
      questionNotFound = true;
      // Printing the current round number
      cout << "Round #" << round <<endl;
      // variables to store the emissions and costs
      aemissions = 0;
      acost = 0;
      bemissions = 0;
      bcost = 0;
      cemissions = 0;
      ccost = 0;
      demissions = 0;
      dcost = 0;

      // while loop which generates questions until a question which hasn't been asked yet is found
      while (questionNotFound)
      {
        filename = generateRandomQuestion();
        for (int i = 0; i < 20; i++)
        {
          // use of unopened files list to determine whether a file has been visited before
          if (unopenedFiles[i] == filename)
          {
            unopenedFiles[i] = " ";
            questionNotFound = false;
          }
        }
      }
      // variables for running through lines of a file and for opening files themselves
      string line;
      fstream currentfile;
      // command to open a file and loop through it
      currentfile.open("data/"+filename);
      if (currentfile.is_open())
      {
        int counter = 0;
        while (getline(currentfile, line))
        {
          // Printing out the first four lines of the file (the questions)
          if (counter <= 4)
          {
            cout << line << '\n';
            usleep(3000000);
          }
          // Storing the 6th line as an integer into the emissions change of option a 
          else if (counter == 6)
          {
            aemissions = stoi(line);
          }
          // Storing the 7th line as an integer into the cost change of option a 
          else if (counter == 7)
          {
            acost = stoi(line);
          }
          // Storing the 8th line as an integer into the emissions change of option b 
          else if (counter == 8)
          {
            bemissions = stoi(line);
          }
          // Storing the 9th line as an integer into the cost change of option b 
          else if (counter == 9)
          {
            bcost = stoi(line);
          }
          // Storing the 10th line as an integer into the emissions change of option c
          else if (counter == 10)
          {
            cemissions = stoi(line);
          }
          // Storing the 11th line as an integer into the cost change of option c
          else if (counter == 11)
          {
            ccost = stoi(line);
          }
          // Storing the 12th line as an integer into the emissions change of option d
          else if (counter == 12)
          {
            demissions = stoi(line);
          }
          // Storing the 13th line as an integer into the cost change of option d
          else if (counter == 13)
          {
            dcost = stoi(line);
          }
          // Incrementing the counter to keep track of the movement to the next line
          counter++;
        }
        // Taking input of the users choice and running a loop if it's not a valid choice, so that they can reinput a valid option
        char choice;
        cout << "What will you do?\033[0m" << endl;
        cin >> choice;
        while((choice!='a') && (choice!='b') &&(choice!='c') && (choice!='d')){
          cout << "Invalid! please select a valid option\033[0m" << endl;
          cin >> choice;
        }
        // Taking the users choice and adjusting the game's current emissions and cost accordingly 
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
        // clearing the screen to avoid clutter
        system("clear");
        // Resetting the emissions and cash values to 0 if they go into the negatives 
        if (emissions < 0)
        {
          emissions = 0;
        }
        if (cash < 0)
        {
          cash = 0;
        }
        // Incrementing the current round number and printing out the current emissions and cash before running the loop again
        round++;
        usleep(1000000);
        cout << "\033[47;30m Current Emmisions: " << emissions << "%" << endl;
        usleep(1000000);
        cout << "Current Cash: $" << cash << endl;
        usleep(1000000);
        currentfile.close();
       
      }

    }
    // Congratulating the player if they've succeded or informing them if they've lost. Then calling the function to role credits
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
 
