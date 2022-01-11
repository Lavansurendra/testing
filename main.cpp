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
  // function to read out all of the rules
  cout << endl;
  cout << "\033[47;30m Here's how to play!" << endl;
  usleep(1050000);
  cout << "To start, select a difficulty level." << endl;
  usleep(1050000);
  cout << "Easy level starts with $50 000 and 60 percent emmisions" << endl;
  usleep(1050000);
  cout << "Medium level starts with $25 000 and 70 percent emmisions" << endl;
  usleep(1050000);
  cout << "Hard level starts with $10 000 and 80 percent emmisions" << endl;
  usleep(1050000);
  cout << "Then, you will be asked questions to test your skill at city planning" << endl;
  usleep(1050000);
  cout << "Each answer will affect your total emissions and money earned, and if you run out of money or emissions reaches 100 you will lose!" << endl;
  usleep(1050000);
  cout << "Without further ado, lets begin!\033[0m" << endl;
  usleep(1050000);
  cout << endl;
}
int main()
{
  string running;
  string rules;
  int cash;
  int emissions;
  int difficulty;
  cout << "\033[47;30m Good Day! Welcome to the Urban City Planner!\n In this game you will act as a City Planner and be faced with many situations and dillemas which you must solve!\n Are you ready for the responsibility of a whole city? [yes/no]\033[0m" << endl;
  cin >> running;
  if ((running == "yes") || (running == "Yes"))
  {
    cout << "\033[47;30m Would you like to hear the rules? [yes/no]\033[0m" << endl;
    cin >> rules;
    if ((rules == "yes") || (rules == "Yes"))
    {
      Rules();
    }
    cout << "\033[47;30m What difficulty level would you like to start with? Easy = 1, Medium = 2, Hard = 3\033[0m" << endl;
    cin >> difficulty;
    switch (difficulty)
    {
    case 1:
      cash = 50000;
      emissions = 60;
      cout << "Starting Cash value: $200 000, Emissions 10%" << endl;
      break;
    case 2:
      cash = 25000;
      emissions = 70;
      cout << "Starting Cash value: $100 000, Emissions 20%" << endl;
      break;
    case 3:
      cash = 10000;
      emissions = 80;
      cout << "Starting Cash value: $50 000, Emissions 30%" << endl;
      break;
    }
    system("clear");
    usleep(1050000);
    cout << "\033[47;30m Current Emmisions: " << emissions << "%" << endl;
    usleep(1050000);
    cout << "Current Cash: $" << cash << endl;
    usleep(1050000);

    int aemissions;
    int acost;
    int bemissions;
    int bcost;
    int cemissions;
    int ccost;
    int demissions;
    int dcost;
    int round = 0;
    bool questionNotFound = true;
    string filename;
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
    while ((emissions < 100) && (cash > 0))
    {

      questionNotFound = true;
      round++;
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
         if (round == 20)
        {
          break;
        }
        usleep(1050000);
        cout << "\033[47;30m Current Emmisions: " << emissions << "%" << endl;
        usleep(1050000);
        cout << "Current Cash: $" << cash << endl;
        usleep(1050000);
        currentfile.close();
       
      }

    }
    if(round == 20){
      cout << "Congratulations, you defeated all of this game's challenges while keeping emissions down and still having money leftover." << endl;
      usleep(1050000);
      cout << "Thanks for playing" <<endl;
    }else{
      cout << "You failed to save the city." <<endl;
      usleep(1050000);
      cout << "Thanks for playing" <<endl;
    }

 
  }
  return 0;
}
 
