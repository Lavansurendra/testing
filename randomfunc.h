//library which takes input and puts output into the consoler
#include <iostream>
//Library which allows for the use of string variables
#include <string>
//Library for converting integers to string
#include <sstream>
//library which causes a pause before the next line is printed
#include <unistd.h>
//namespace which allows for functions like cout and string to be written without having to add std:: each time 
using namespace std;
// function which selects a random number from 1 to 20 and converts it to a string, then it adds .txt to the end which creates an end product of selecting a text file at random
string generateRandomQuestion()
{
// randomly selecting a number from one to twenty
  srand((unsigned)time(0));
  int result = 1 + (rand() % 20);
  usleep(1000);
// converting number to string
  stringstream ss;
  ss << result;
  string str = ss.str();
// returning file name in string format
  return str + ".txt";
}