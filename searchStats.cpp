#include "baseballMain.h"

using namespace std;

/*********************************************************************
                          selectionSort                               
Sorts the elements of an array of strings into alphabetical order.
*********************************************************************/

void selectionSort(string list[], int size)
{
    int startScan, minIndex;
    string minValue;
    for(startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = list[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (list[index] < minValue)
            {
                minValue = list[index];
                minIndex = index;
            }
        }
        list[minIndex] = list[startScan];
        list[startScan] = minValue;
    }
}

/*********************************************************************
                          printArray                               
Displays all members in an array in a single column.
*********************************************************************/

void printArray(string list[], int size)
{
     for (int index = 0; index < size; index++)
     {
         cout << setw(4) << right << index + 1 << ". " << list[index] << endl;
         Sleep(200);
     }
     cout << endl;
}

/*********************************************************************
                          binarySearch                               
Searches an array for a specified string and, if it finds the string,
returns the string's position, otherwise it returns -1.
*********************************************************************/

int binarySearch(string list[], int size, string value)
{
    int first, last, middle, position;
    bool found = false;

    first = 0;
    last = size - 1;
    position = -1;
    
    while (first <= last && !found)
    {
          middle = (first + last) / 2;
          if (list[middle] == value)
          {
                 found = true;
                 position = middle;
          }
          else if (list[middle] > value)
          {
                 last = middle - 1;
          }
          else
          {
                 first = middle + 1;
          }
    }
    return position;
}

/*********************************************************************
                          batterPitcherStats                               
Assigns a file to a specific player and sets parameters for the
batterFile function.
*********************************************************************/

void batterPitcherStats(string input)
{
       const int games = 20;
       if (input == "Altuve, Jose")
       {
             char fileName[25] = "Files/AltuveStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Martinez, Victor")
       {
             char fileName[25] = "Files/MartinezStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Beltre, Adrian")
       {
             char fileName[25] = "Files/BeltreStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Morneau, Justin")
       {
             char fileName[25] = "Files/MorneauStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "McCutchen, Andrew")
       {
             char fileName[25] = "Files/McCutchenStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Jeter, Derek")
       {
             char fileName[25] = "Files/JeterStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Ortiz, David")
       {
             char fileName[25] = "Files/OrtizStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Trout, Mike")
       {
             char fileName[25] = "Files/TroutStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Cruz, Nelson")
       {
             char fileName[25] = "Files/CruzStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Stanton, Giancarlo")
       {
             char fileName[25] = "Files/StantonStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Cabrera, Miguel")
       {
             char fileName[25] = "Files/CabreraStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Gonzalez, Adrian")
       {
             char fileName[25] = "Files/GonzalezStats.txt";
             batterFile(fileName, input, games);
       }
       else if (input == "Scherzer, Max")
       {
             char fileName[25] = "Files/ScherzerStats.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Lester, Jon")
       {
             char fileName[25] = "Files/LesterStats.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Kershaw, Clayton")
       {
             char fileName[25] = "Files/KershawStats.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Bumgarner, Madison")
       {
             char fileName[25] = "Files/BumgarnerStats.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Hernandez, Felix")
       {
             char fileName[25] = "Files/HernandezStats.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Hamels, Cole")
       {
             char fileName[25] = "Files/HamelsStats.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Kluber, Corey")
       {
             char fileName[25] = "Files/KluberStats.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Wainwright, Adam")
       {
             char fileName[25] = "Files/WainwrightStat.txt";
             pitcherFile(fileName, input, games);
       }
       else if (input == "Darvish, Yu")
       {
             char fileName[25] = "Files/DarvishStats.txt";
             pitcherFile(fileName, input, games);
       }
}
