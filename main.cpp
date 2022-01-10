#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
using namespace std;

string generateRandomQuestion(){
    srand((unsigned) time(0));
    int result = 1 + (rand() % 20);
    usleep(1005000);
    stringstream ss;
    ss << result;
    string str = ss.str();
    return str+".txt";
    
}
void Rules()
{
    cout << endl;
    cout << "\033[42;30m Here's how to play!" << endl;
    usleep(1005000);
    cout << "To start, select a difficulty level." << endl;
    usleep(1005000);
    cout << "Easy level starts with $200 000 and 10 percent emmisions" << endl;
    usleep(1005000);
    cout << "Medium level starts with $100 000 and 20 percent emmisions" << endl;
    usleep(1005000);
    cout << "Hard level starts with $50 000 and 30 percent emmisions" << endl;
    usleep(1005000);
    cout << "Then, you will be asked questions to test your skill at city planning" << endl;
    usleep(1005000);
    cout << "Each answer will affect your total emissions and money earned, and if you run out of money or emissions reaches 100 you will lose!" << endl;
    usleep(1005000);
    cout << "Without further ado, lets begin!\033[0m" << endl;
    usleep(1005000);
    cout << endl;
}
int main()
{
    string running;
    string rules;
    int cash;
    int emissions;
    int difficulty;
    cout << "\033[42;30m Good Day! Welcome to the Urban City Planner!\n In this game you will act as a City Planner and be faced with many situations and dillemas which you must solve!\n Are you ready for the responsibility of a whole city? [yes/no]\033[0m" << endl;
    cin >> running;
    if ((running == "yes") || (running == "Yes"))
    {
        cout << "\033[42;30m Would you like to hear the rules? [yes/no]\033[0m" << endl;
        cin >> rules;
        if ((rules == "yes") || (rules == "Yes"))
        {
            Rules();
        }
        cout << "\033[42;30m What difficulty level would you like to start with? Easy = 1, Medium = 2, Hard = 3\033[0m" << endl;
        cin >> difficulty;
        switch (difficulty)
        {
        case 1:
            cash = 200000;
            emissions = 10;
            cout << "Starting Cash value: $200 000, Emissions 10%" << endl;
            break;
        case 2:
            cash = 100000;
            emissions = 20;
            cout << "Starting Cash value: $100 000, Emissions 20%" << endl;
            break;
        case 3:
            cash = 50000;
            emissions = 30;
            cout << "Starting Cash value: $50 000, Emissions 30%" << endl;
            break;
        }
        system("clear");
        usleep(1005000);
        cout << "\033[42;30m Current Emmisions: " << emissions << "%" << endl;
        usleep(1005000);
        cout << "Current Cash: $" << cash << endl;
        usleep(1005000);

        int aemissions;
        int acost;
        int bemissions;
        int bcost;
        int cemissions;
        int ccost;
        int demissions;
        int dcost;

        while((emissions<100)&& (cash>=0)){
          int aemissions =0;
          int acost =0;
          int bemissions=0;
          int bcost =0;
          int cemissions =0;
          int ccost =0;
          int demissions =0;
          int dcost =0;
          string filename =  generateRandomQuestion();
          string line;
          ifstream currentfile;
          currentfile.open(filename);
          if (currentfile.is_open()){
                int  counter = 0;
                while ( getline (currentfile,line)){
                   if(counter<=4){
                    cout << line << '\n';
                   }else if (counter == 6){
                     aemissions = stoi(line);
                   }else if (counter == 7){
                     acost = stoi(line);
                   }else if (counter == 8){
                     bemissions = stoi(line);
                   }else if (counter == 9){
                     bcost = stoi(line);
                   }else if (counter == 10){
                     cemissions = stoi(line);
                   }else if (counter == 11){
                     ccost = stoi(line);
                   }else if (counter == 12){
                     demissions = stoi(line);
                   }else if (counter == 13){
                     dcost = stoi(line);
                   }
                   counter++;
                  }
                char choice;
                cout << "What will you do?\033[0m" << endl;
                cin >> choice;
                switch (choice){
                  case 'a':
                    emissions+=aemissions;
                    cout << cash << endl;
                    cash+=acost;
                    cout << acost << endl;
                    break;
                  case 'b':
                    emissions+=bemissions;
                    cash+=bcost;
                    break;
                  case 'c':
                    emissions+=cemissions;
                    cash+=ccost;
                    break;
                  case 'd':
                    emissions+=demissions;
                    cash+=dcost;
                }
              // system("clear");
              usleep(1005000);
              cout << "\033[42;30m Current Emmisions: " << emissions << "%" << endl;
              usleep(1005000);
              cout << "Current Cash: $" << cash << endl;
              usleep(1005000);

                
          currentfile.close();
          }
        }
       
    }
    return 0;
}