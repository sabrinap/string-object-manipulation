/* Name: Sabrina Pinera
Date: November 20, 2018
Section: 5
Assignment: #6
Due Date: November 20, 2018
About this project: This assignment will involve practice with either C-style
strings or string objects, as well as some of the libraries that involve
manipulations on characters (like cctype) and strings (cstring/string).
Assumptions: User will write a sentence. After the user clicks enter a menu will
show up to give the user options to pick from and depending on the options the
user picks it will display certain outputs.

All work below was performed by Sabrina Pinera */
#include <iostream>
#include <cstdlib> // for srand and rand
#include <ctime>  // for time
#include <cctype> //declares a set of functions to classify & transform individual char
#include <string>
//include other libraries if you need them (you'll need them)

using namespace std;

//Function declaration.
void print(string& s);
void upper(string& s);
void lower(string& s);
void replace(string& s, char replace1, char replace2);
void stats(string& s);
void newS(string& s);
void jazz(string& s);
void menu();


int main()
{
    int choice;
    string s;
    char replace1, replace2;  // replacement inputs for user in case 4
    srand ((unsigned int)time(0)); //seeding function, called only ONCE. @ the beginning

    cout << "To get started, enter anything you'd like, then hit enter:\n";
    getline(cin, s);


	menu();
	do
	{
	    cout << "Selection -----> ";
	    cin >> choice;

	       //error checking menu and loops it till user picks one of the
	       //correct choices.
	       while(choice >= 9 || choice <= -1)
	       {
	           cout << "Invalid Choice.\n\n";
	           cout << "Selection -----> ";
               cin >> choice;
	       }

	    switch(choice)
	    {
	       case 1 : //print the current string
	                print(s);
	       break;
	       case 2 : //Uppercase
                    upper(s);
    	   break;
    	   case 3 : //Lowercase
    	            lower(s);
    	   break;
    	   case 4 : //Replace character
    	            cout << "Replace all of these characters: ";
    	            cin >> replace1;
    	            cout << "To these characters: ";
    	            cin >> replace2;
    	            replace(s, replace1, replace2);
    	   break;
    	   case 5 : //show string statistic
    	            stats(s);
    	   break;
    	   case 6 : //enter a new string
    	            newS(s);
    	   break;
    	   case 7 : //jazz things up
    	            jazz(s);
    	   break;
    	   case 8 : //show the menu
    	            menu();
    	   break;

	    }

	}while(choice != 0);

        cout << "Bye!";

   return 0;
}
//done
void print(string & s)
{
    //prints out the string
    cout << "Current String: " << s << "\n\n";
}
//done
void upper(string& s)
{
    //changes the string to uppercase
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }

}
//done
void lower(string& s)
{
    //changes the string to lowercase
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
}
//done
void replace(string& s, char replace1, char replace2)
{
    //for loop needed
    //replace the letter the user asked to change to the new one the user wants
    int counter = 0;
    for(int i = 0; i < s.length(); i++)
    {
       if(s[i] == replace1)
       {
            ++counter;
            s[i] = replace2;
       }

    }
    cout << counter << " characters replaced.\n\n";
}
//done
void stats(string& s)
{
    //initializing
    int letters = 0, spaces = 0, punct = 0, digits = 0;
    //for loop is needed
    for(int i = 0; i < s.length(); i++)
    {
        if(isalpha(s[i]))
           ++letters;
        else if(ispunct(s[i]))
           ++punct;
        else if(isdigit(s[i]))
           ++digits;
        else if(isspace(s[i]))
           ++spaces;
    }
      //outputs the stats
      cout << "Letters: " << letters << endl;
      cout << "Punctuation: " << punct << endl;
      cout << "Digits: " << digits << endl;
      cout << "Whitespace: " << spaces << "\n\n";

}
//done
void newS(string& s)
{
    //user enters new string
    cout << "Enter a new string:\n";
    cin.ignore();
    getline(cin, s);
    cout << "\n";
}
//done
void jazz(string& s)
{
    /*
    * new string of a random length between 1 and 50.
    * new string is made up of random characters that have ascii values
    * between 32-122.
    */
    int rNum = 1 + (rand() % 50);
        s = "";
   for(int i = 0; i < rNum; ++i)
   {
       s += (char)(32 + (rand()%91));
   }
    cout << "Your string is now: " << s << "\n\n";
}
//done
void menu()
{
    //prints out menu
    cout << "\nString Manipulator Options Menu\n";
    cout << "-------------------------------\n";
    cout << "1 - Print the current string\n";
    cout << "2 - Make the string all Uppercase\n";
    cout << "3 - Make the string all Lowercase\n";
    cout << "4 - Replace a character\n";
    cout << "5 - Show string statistics\n";
    cout << "6 - Enter a new string\n";
    cout << "7 - Jazz things up... (You'll lose your current string!)\n";
    cout << "8 - Show this menu\n";
    cout << "0 - Quit\n";
}
