#include "baseballMain.h"
// MIKE TROUT STATS:  http://www.baseball-reference.com/players/gl.cgi?id=troutmi01&t=b&year=2014

using namespace std;

/*********************************************************************
                          batterInput                               
Reads stats inputted by a user, calculates other stats, and displays
the stats in a table to both the console and a file.
*********************************************************************/

void batterInput()
{
     int games;
     string name;
     
     double input;
     Batter batter1;
     
     batter1.setAtBatsTotal(0);
     batter1.setHitByPitchTotal(0);
     batter1.setHitsTotal(0);
     batter1.setSacFliesTotal(0);
     batter1.setWalksTotal(0);
     
     cout << " What is the name of the player? ";
     cin.ignore(1000, '\n');
     getline(cin, name);
     cout << " How many games of stats do you have? ";
     cin >> games;
     
     double ab[games], h[games], bb[games], hitByPitch[games], sf[games],
            average[games], onBasePer[games], aveTotal[games], obpTotal[games];
     
     ofstream outputFile;
     outputFile.open("statsOutput.txt");
     for (int i=0; i < games; i++)
     {
         cout << " For game " << i+1 << ", how many official at-bats did they have? ";
         cin >> input;
         input = batterValidate(input, 15);  // Record for at-bats in a single game is 11
         batter1.setAtBats(input);
         ab[i] = batter1.getAtBats();
         batter1.setAtBatsTotal(batter1.getAtBats());
         
         cout << " How many hits did they get? ";
         cin >> input;
         input = batterValidate(input, batter1.getAtBats());
         batter1.setHits(input);
         h[i] = batter1.getHits();
         batter1.setHitsTotal(batter1.getHits());
         
         cout << " How many walks did they get? ";
         cin >> input;
         input = batterValidate(input, 9);  // Record for walks in a single game is 6
         batter1.setWalks(input);
         bb[i] = batter1.getWalks();
         batter1.setWalksTotal(batter1.getWalks());
         
         cout << " How many times were they hit by a pitch? ";
         cin >> input;
         input = batterValidate(input, 9);  // Record for hbp in a single game is 6
         batter1.setHitByPitch(input);
         hitByPitch[i] = batter1.getHitByPitch();
         batter1.setHitByPitchTotal(batter1.getHitByPitch());
         
         cout << " How many sac flies did they hit? ";
         cin >> input;
         input = batterValidate(input, 5);  // Record for sac flies in a single game is 3
         batter1.setSacFlies(input);
         sf[i] = batter1.getSacFlies();
         batter1.setSacFliesTotal(batter1.getSacFlies());
         cout << endl;

         average[i] = batter1.getAvg();
         onBasePer[i] = batter1.getOnBasePer();
         aveTotal[i] = batter1.getAvgTotal();
         obpTotal[i] = batter1.getOnBasePerTotal();
     }
     cout << " " << left << name << endl;
     cout << " ____________________________________________________________________________" << endl;
     cout << right << " " << setw(8) << " | " << setw(6) << " | " << setw(7) << " | " << setw(8) << " | " << setw(6) << " | " << setw(11) <<
             " |" << setw(6) << "Game " << " |" << setw(6) << "Game " << " |" << setw(6) << "Season" << " |" << setw(6) << "Season" << endl;
     cout << right << " Games" << " | " << " AB" << " | " << "Hits" << " | " << "Walks" << " | " << "HBP" << " | " <<
              "Sac Flies" << " |" << setw(6) << "AVG " << " |" << setw(6) << "OBP " << " |" << setw(6) << "AVG " << " |" << setw(6)
          << "OBP " << endl;
     outputFile << " " << left << name << endl;
     outputFile << " ____________________________________________________________________________" << endl;
     outputFile << right << " " << setw(8) << " | " << setw(6) << " | " << setw(7) << " | " << setw(8) << " | " << setw(6) << " | " << setw(11) <<
                   " |" << setw(6) << "Game " << " |" << setw(6) << "Game " << " |" << setw(6) << "Season" << " |" << setw(6) << "Season" << endl;
     outputFile << right << " Games" << " | " << " AB" << " | " << "Hits" << " | " << "Walks" << " | " << "HBP" << " | " <<
                   "Sac Flies" << " |" << setw(6) << "AVG " << " |" << setw(6) << "OBP " << " |" << setw(6) << "AVG " << " |" << setw(6)
                << "OBP " << endl;
     for (int i=0; i < games; i++)
     {
         cout << setw(6) << i + 1  << " |" << setw(4) << setprecision(0) << ab[i] << " | " << setw(4)
              << h[i] << " | " << setw(5) << bb[i] << " | " << setw(3) << hitByPitch[i] <<  " | "
              << setw(6) << sf[i] << "    |" << fixed << setprecision(3) << setw(6) << average[i] << " |" << setw(6)
              << onBasePer[i] << " |" << setw(6) << aveTotal[i] << " |" << setw(6) << obpTotal[i] << endl;
                 
         outputFile << setw(6) << i + 1  << " |" << setw(4) << setprecision(0) << ab[i] << " | " << setw(4)
                    << h[i] << " | " << setw(5) << bb[i] << " | " << setw(3) << hitByPitch[i] <<  " | "
                    << setw(6) << sf[i] << "    |" << fixed << setprecision(3) << setw(6) << average[i] << " |" << setw(6)
                    << onBasePer[i] << " |" << setw(6) << aveTotal[i] << " |" << setw(6) << obpTotal[i] << endl;
         Sleep(200);   
     }
     cout << " ----------------------------------------------------------------------------" << endl;
     cout << setw(6) << games  << " |" << setw(4) << setprecision(0) << batter1.getAtBatsTotal() << " | " << setw(4);
     cout << batter1.getHitsTotal() << " | " << setw(5) << batter1.getWalksTotal()<< " | " << setw(3);
     cout << batter1.getHitByPitchTotal() <<  " | " << setw(6) << batter1.getSacFliesTotal() << "    |";
     cout << setprecision(3) << setw(6) << "NA " << " |" << setw(6) << "NA " << " |";
     cout << setw(6) << batter1.getAvgTotal() << " |" << setw(6) << batter1.getOnBasePerTotal() << endl << endl;
     
     outputFile << " ---------------------------------------------------------------------------" << endl;
     outputFile << setw(6) << games  << " |" << setw(4) << setprecision(0) << batter1.getAtBatsTotal() << " | " << setw(4);
     outputFile << batter1.getHitsTotal() << " | " << setw(5) << batter1.getWalksTotal()<< " | " << setw(3);
     outputFile << batter1.getHitByPitchTotal() <<  " | " << setw(6) << batter1.getSacFliesTotal() << "    |";
     outputFile << setprecision(3) << setw(6) << "NA " << " |" << setw(6) << "NA " << " |";
     outputFile << setw(6) << batter1.getAvgTotal() << " |" << setw(6) << batter1.getOnBasePerTotal() << endl << endl;
     
     cout << " See statsOutput.txt file for printable stats." << endl << endl;
     outputFile.close();
}

/*********************************************************************
                          batterFile                               
Reads stats from a file, calculates other stats, and displays
the stats in a table to both the console and a file.
*********************************************************************/

void batterFile(char fileName[25], string name, int games)
{
    int gamesTotal;
    double input;
    string junk;
    
    Batter batter1;
    
    batter1.setAtBatsTotal(0);
    batter1.setHitByPitchTotal(0);
    batter1.setHitsTotal(0);
    batter1.setSacFliesTotal(0);
    batter1.setWalksTotal(0);
    
    double ab[games], h[games], bb[games], hitByPitch[games], sf[games],
            average[games], onBasePer[games];
    
    ofstream outputFile;
    outputFile.open("statsOutput.txt");
    ifstream inputFile;
    inputFile.open(fileName);
    cin.ignore(1000, '\n');
    if(!inputFile) 
    { 
          cout << "<ERROR> Could not open file." << endl; 
    }
    else 
    { 
          while(inputFile >> junk) //read input 
          { 
                inputFile >> junk >> junk >> junk >> junk >> junk >> junk;
                cout << " " << left << name << endl;
                cout << " ____________________________________________________________________________" << endl;
                cout << right << " " << setw(8) << " | " << setw(6) << " | " << setw(7) << " | " << setw(8) << " | " << setw(6) << " | " << setw(11) <<
                     " |" << setw(6) << "Game " << " |" << setw(6) << "Game " << " |" << setw(6) << "Season" << " |" << setw(6) << "Season" << endl;
                cout << right << " Games" << " | " << " AB" << " | " << "Hits" << " | " << "Walks" << " | " << "HBP" << " | " <<
                     "Sac Flies" << " |" << setw(6) << "AVG " << " |" << setw(6) << "OBP " << " |" << setw(6) << "AVG " << " |" << setw(6)
                     << "OBP " << endl;
                outputFile << " " << left << name << endl;
                outputFile << " ____________________________________________________________________________" << endl;
                outputFile << right << " " << setw(8) << " | " << setw(6) << " | " << setw(7) << " | " << setw(8) << " | " << setw(6) << " | " << setw(11) <<
                           " |" << setw(6) << "Game " << " |" << setw(6) << "Game " << " |" << setw(6) << "Season" << " |" << setw(6) << "Season" << endl;
                outputFile << right << " Games" << " | " << " AB" << " | " << "Hits" << " | " << "Walks" << " | " << "HBP" << " | " <<
                           "Sac Flies" << " |" << setw(6) << "AVG " << " |" << setw(6) << "OBP " << " |" << setw(6) << "AVG " << " |" << setw(6)
                           << "OBP " << endl;
                for (int i=0; i < games; i++)
                {
                    inputFile >> input;
                    input = batterValidate(input, 15);  // Record for at-bats in a single game is 11
                    batter1.setAtBats(input);
                    ab[i] = batter1.getAtBats();
                    batter1.setAtBatsTotal(batter1.getAtBats());
         
                    inputFile >> input;
                    input = batterValidate(input, batter1.getAtBats());
                    batter1.setHits(input);
                    h[i] = batter1.getHits();
                    batter1.setHitsTotal(batter1.getHits());
         
                    inputFile >> input;
                    input = batterValidate(input, 9);  // Record for walks in a single game is 6
                    batter1.setWalks(input);
                    bb[i] = batter1.getWalks();
                    batter1.setWalksTotal(batter1.getWalks());
         
                    inputFile >> input;
                    input = batterValidate(input, 9);  // Record for hbp in a single game is 6
                    batter1.setHitByPitch(input);
                    hitByPitch[i] = batter1.getHitByPitch();
                    batter1.setHitByPitchTotal(batter1.getHitByPitch());
         
                    inputFile >> input;
                    input = batterValidate(input, 5);  // Record for sac flies in a single game is 3
                    batter1.setSacFlies(input);
                    sf[i] = batter1.getSacFlies();
                    batter1.setSacFliesTotal(batter1.getSacFlies());
                    inputFile >> input;
         
                    average[i] = batter1.getAvg();
                    onBasePer[i] = batter1.getOnBasePer();
                    
                    cout << setw(6) << i + 1  << " |" << setw(4) << setprecision(0) << ab[i] << " | " << setw(4)
                          << h[i] << " | " << setw(5) << bb[i] << " | " << setw(3) << hitByPitch[i] <<  " | "
                          << setw(6) << sf[i] << "    |" << fixed << setprecision(3) << setw(6) << average[i] << " |" << setw(6)
                          << onBasePer[i] << " |" << setw(6) << batter1.getAvgTotal() << " |" << setw(6) << batter1.getOnBasePerTotal() << endl;
                 
                     outputFile << setw(6) << i + 1  << " |" << setw(4) << setprecision(0) << ab[i] << " | " << setw(4)
                                << h[i] << " | " << setw(5) << bb[i] << " | " << setw(3) << hitByPitch[i] <<  " | "
                                << setw(6) << sf[i] << "    |" << fixed << setprecision(3) << setw(6) << average[i] << " |" << setw(6)
                                << onBasePer[i] << " |" << setw(6) << batter1.getAvgTotal() << " |" << setw(6) << batter1.getOnBasePerTotal() << endl;     
                     Sleep(200);
                }
                cout << " ----------------------------------------------------------------------------" << endl;
                cout << setw(6) << games  << " |" << setw(4) << setprecision(0) << batter1.getAtBatsTotal() << " | " << setw(4);
                cout << batter1.getHitsTotal() << " | " << setw(5) << batter1.getWalksTotal()<< " | " << setw(3);
                cout << batter1.getHitByPitchTotal() <<  " | " << setw(6) << batter1.getSacFliesTotal() << "    |";
                cout << setprecision(3) << setw(6) << "NA " << " |" << setw(6) << "NA " << " |";
                cout << setw(6) << batter1.getAvgTotal() << " |" << setw(6) << batter1.getOnBasePerTotal() << endl << endl;
                outputFile << " ---------------------------------------------------------------------------" << endl;
                outputFile << setw(6) << games  << " |" << setw(4) << setprecision(0) << batter1.getAtBatsTotal() << " | " << setw(4);
                outputFile << batter1.getHitsTotal() << " | " << setw(5) << batter1.getWalksTotal()<< " | " << setw(3);
                outputFile << batter1.getHitByPitchTotal() <<  " | " << setw(6) << batter1.getSacFliesTotal() << "    |";
                outputFile << setprecision(3) << setw(6) << "NA " << " |" << setw(6) << "NA " << " |";
                outputFile << setw(6) << batter1.getAvgTotal() << " |" << setw(6) << batter1.getOnBasePerTotal() << endl << endl;
             
                 cout << " See statsOutput.txt file for printable stats." << endl << endl;
                 outputFile.close();
          }
          inputFile.close();
          outputFile.close(); 
          cout << endl;
    }
}

/*********************************************************************
                          batterValidate                               
Checks to make sure inputted stats falls within an acceptable range.
*********************************************************************/

double batterValidate(double input, double upperBound)
{
     const int lowerBound = 0;
     int check = static_cast<int>(input);
     do
     {
          int check = static_cast<int>(input);
          if (input < lowerBound || input > upperBound || input != check)
          {
              cout << fixed << setprecision(0);
              cout << endl << " <ERROR> Must be between " << lowerBound << " and " << upperBound;
              cout << " and must be a whole number. <ERROR>" << endl;
              cout << " Please try again: ";
              cin.ignore(1000, '\n');
              cin >> input;
              cout << endl;
          }
     }while (input < lowerBound || input > upperBound || input != check);
     return input;
}

