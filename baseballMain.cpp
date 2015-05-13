/******************************************** 
 * AUTHOR: Alex Greenbaum
 * COURSE: CS 150 C++ Programming 
 * SECTION: MW 3:30 - 5:20pm
 * HOMEWORK #: FINAL PROJECT
 * LAST MODIFIED: December 2, 2014
 ********************************************/
 
/***************************************************************************** 
 * 2014 STAT TRACKER
 ***************************************************************************** 
 * PROGRAM DESCRIPTION: 
 * Allows user to search for a specific player's stats in the database or
 * enter outside stats to calculate other stats.
 ***************************************************************************** 
 * ALGORITHM: 
 * CREATE constant array size
 * CREATE identifiers for repeat, check, results, view, and input
 * CREATE names array of size 21
 * CALL FUNCTION selectionSort
 * WHILE repeat = 1
   // CLEAR screen
   // CALL FUNCTIONS printHeader and baseballMainDisplay
   // DO
      >> PROMPT FOR AND READ check
      >> IF check != 1 && check != 2
         -- DISPLAY error message
   // WHILE repeat != 1 && repeat != 2
      >> END do while
   // IF check == 1
      >> PROMPT FOR AND READ name
      >> CALL FUNCTION binarySearch and set equal to results
      -- IF results == -1
         ** DISPLAY error message
         ** DO
            // PROMPT FOR AND READ view
            // IF view != 1 && view != 2
               >> DISPLAY error message
         ** WHILE view != 1 && view != 2
            // END do while
         ** IF view == 1
            // CALL FUNCTION printArray
      -- ELSE
         ** DISPLAY name
         ** CALL FUNCTION batterPitcherStats
   // ELSE IF check == 2
      -- CALL FUNCTION batterOrPitcher
      -- DO
         ** PROMPT FOR AND READ repeat
         ** IF repeat != 1 && repeat != 2
            // DISPLAY error message
      -- WHILE repeat != 1 && repeat != 2
         ** END do while
 * DISPLAY exit message
 *****************************************************************************
 * ALL INCLUDED FILES NEEDED AND PURPOSE: 
 * iostream = used for console input 
 * iomanip = used for formatting programs
 *****************************************************************************/
#include "baseballMain.h"

using namespace std;

const int ARRAY_SIZE = 21;

int main()
{    
    int repeat, check, results, view;
    repeat = 1;
    string input;
        
    string names[ARRAY_SIZE] = {"Altuve, Jose",      "Martinez, Victor",   "Beltre, Adrian",   "Morneau, Justin",
                                "McCutchen, Andrew", "Jeter, Derek",       "Ortiz, David",     "Trout, Mike", "Darvish, Yu",
                                "Cruz, Nelson",      "Stanton, Giancarlo", "Cabrera, Miguel",  "Gonzalez, Adrian",
                                "Scherzer, Max",     "Lester, Jon",        "Kershaw, Clayton", "Bumgarner, Madison",
                                "Hernandez, Felix",  "Hamels, Cole",       "Kluber, Corey",    "Wainwright, Adam"};
    selectionSort(names, ARRAY_SIZE);
    while (repeat == 1)
    {
          system("cls");
          printHeader("December 2, 2014");
          baseballMainDisplay();
          do
          {
               cout << " Would you like to:" << endl;
               cout << " 1) See if a player's stats are included in our database, or" << endl;
               cout << " 2) Enter a player's stats, either manually or through a file? " << endl << " ";
               cin >> check;
               cout << endl;
               if (check != 1 && check != 2)
               {
                    cout << " <ERROR> Input must be 1 or 2.  Please try again. <ERROR>" << endl << endl;
               }
          }while (check != 1 && check != 2);
          if (check == 1)
          {
                   cout << " Enter the player's name (LastName, FirstName):" << endl << " ";
                   cin.ignore(1000, '\n');
                   getline(cin, input);
                   cout << endl << " Searching for name " << input << " . . . ";
                   Sleep(1500);
                   cout << endl;
                   results = binarySearch(names, ARRAY_SIZE, input);
                   if (results == -1)
                   {
                        cout << " There is no one listed by that name.  Please try again" << endl;
                        do
                        {
                              cout << endl << " Would you like to view the list of names?" << endl;
                              cout << " (1 for YES, 2 for NO.) ";
                              cin >> view;
                              cout << endl;
                              if (view != 1 && view != 2)
                              {
                              cout << " <ERROR> Input must be 1 or 2.  Please try again. <ERROR>" << endl << endl;
                              }
                        }while (view != 1 && view != 2);
                        if (view == 1)
                        {
                              cin.ignore(1000, '\n');
                              printArray(names, ARRAY_SIZE);
                              cout << " Press <ENTER> to return to Main Menu . . . ";
                              cin.ignore(1000, '\n');
                        }
                   }
                   else
                   {
                        cout << " Name found." << endl;
                        cout << " The position of the name in our database is #" << results + 1 << "." << endl << endl;
                        cout << " Press <ENTER> to see the player's stats: " << endl;
                        batterPitcherStats(input);
                        cout << " Press <ENTER> to return to Main Menu . . . ";
                        cin.ignore(1000, '\n');
                   }
          }
          else if (check == 2)
          {
                  batterOrPitcher();
        
                  do
                  {
                          cout << " Would you like to calculate the stats for another player?" << endl;
                          cout << " (1 for YES, 2 for NO.) ";
                          cin >> repeat;
                          cout << endl;
                          if (repeat != 1 && repeat != 2)
                          {
                                 cout << " <ERROR> Input must be 1 or 2.  Please try again. <ERROR>" << endl << endl;
                          }
                   }while (repeat != 1 && repeat != 2);
             }
        }
    cin.ignore(1000, '\n');
    cout << " Press <ENTER> to EXIT ...";	
    cin.ignore(1000, '\n');
    exit(0);
}

/*********************************************************************
                          printHeader                               
Displays the header for the program with info about the author.
*********************************************************************/

void printHeader(string lastModified)
{
    /****** OUTPUT ******/
    cout << endl << setw(38) << right << "FINAL PROJECT" << endl << endl;
    cout << setw(28) << right << "AUTHOR: " << setw(23) << left << "Alex Greenbaum" << endl;
    cout << setw(28) << right << "COURSE: " << setw(23) << left << "CS 150 C++ Programming" << endl;
    cout << setw(28) << right << "SECTION: " << setw(23) << left << "MW 3:30 - 5:20pm" << endl;
    cout << setw(28) << right << "LAST MODIFIED: " << setw(23) << left << lastModified << endl << endl;
}

/*********************************************************************
                          baseballMainDisplay                               
Displays the Main Menu for the 2014 Stat Tracker program.
*********************************************************************/

void baseballMainDisplay()
{
     cout << " --------------------------------------------------------------" << endl << endl;
     cout << right << setw(42) << "MAJOR LEAGUE BASEBALL" << endl;
     cout << setw(40) << "2014 STAT Tracker" << endl << endl;
}

/*********************************************************************
                          batterOrPitcher                               
Allows user to choose whether they want to input info for a 
batter or a pitcher.
*********************************************************************/

void batterOrPitcher()
{
     int choice;
     
     cout << " Please select one of the following:" << endl << endl;
     do
     {
          cout << " 1) Calculate statistics for a batter." << endl;
          cout << " 2) Calculate statistics for a pitcher." << endl;
          cout << " What would you like to do? ";
          cin >> choice;
          cout << endl;
          if (choice != 1 && choice !=2)
          {
             cout << " <ERROR> Input must be 1 or 2.  Please try again. <ERROR>" << endl << endl;
          }
     }while (choice != 1 && choice !=2);
     switch (choice)
     {
            case 1:
                 batterInputOrFile();
                 break;
            
            case 2:
                 pitcherInputOrFile();
                 break;
     }
}

/*********************************************************************
                          batterInputOrFile                               
Allows user to choose in input info manually or through a file to
calculate statistics for a batter.
*********************************************************************/

void batterInputOrFile()
{
     int choice, games;
     string name;
     
     cout << " Please select one of the following:" << endl << endl;
     do
     {
          cout << " 1) Input information manually." << endl;
          cout << " 2) Upload information from a file." << endl;
          cout << " What would you like to do? ";
          cin >> choice;
          cout << endl;
          if (choice != 1 && choice !=2)
          {
             cout << " <ERROR> Input must be 1 or 2.  Please try again. <ERROR>" << endl << endl;
          }
     }while (choice != 1 && choice !=2);
     switch (choice)
     {
            case 1:
                 batterInput();
                 break;
            
            case 2:
                 cout << " Enter stats into file: batterStats.txt" << endl;
                 cout << " What is the name of the player? ";
                 cin.ignore(1000, '\n');
                 getline(cin, name);
                 cout << " How many games of stats do you have? ";
                 cin >> games;
                 cout << endl;
                 char fileName[25] = "batterStats.txt";
                 batterFile(fileName, name, games);
                 break;
     }
}

/*********************************************************************
                          pitcherInputOrFile                               
Allows user to choose in input info manually or through a file to
calculate statistics for a pitcher.
*********************************************************************/

void pitcherInputOrFile()
{
     int choice, games;
     string name;
     
     cout << " Please select one of the following:" << endl << endl;
     do
     {
          cout << " 1) Input information manually." << endl;
          cout << " 2) Upload information from a file." << endl;
          cout << " What would you like to do? ";
          cin >> choice;
          cout << endl;
          if (choice != 1 && choice !=2)
          {
             cout << " <ERROR> Input must be 1 or 2.  Please try again. <ERROR>" << endl << endl;
          }
     }while (choice != 1 && choice !=2);
     switch (choice)
     {
            case 1:
                 pitcherInput();
                 break;
            
            case 2:
                 cout << " Enter stats into file: pitcherStats.txt" << endl;
                 cout << " What is the name of the player? ";
                 cin.ignore(1000, '\n');
                 getline(cin, name);
                 cout << " How many games of stats do you have? ";
                 cin >> games;
                 cout << endl;
                 char fileName[25] = "pitcherStats.txt";
                 pitcherFile(fileName, name, games);
                 break;
     }
}
