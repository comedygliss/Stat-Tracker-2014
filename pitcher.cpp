#include "baseballMain.h"

using namespace std;

/*********************************************************************
                          pitcherInput                               
Reads stats inputted by a user, calculates other stats, and displays
the stats in a table to both the console and a file.
*********************************************************************/

void pitcherInput()
{
     int games, intInnings;
     double input;
     string name;

     Pitcher pitcher1;
     
     pitcher1.setInningsTotal(0);
     pitcher1.setHitsTotal(0);
     pitcher1.setWalksTotal(0);
     pitcher1.setRunsTotal(0);
     pitcher1.setOutsTotal(0);
     
     cout << " What is the name of the player? ";
     cin.ignore(1000, '\n');
     getline(cin, name);
     cout << " How many games of stats do you have? ";
     cin >> games;
     cout << endl;
     
     double ip[games], h[games], bb[games], runs[games], era[games], whip[games], eraTotal[games], whipTotal[games];
     
     ofstream outputFile;
     outputFile.open("statsOutput.txt");

     for (int i=0; i < games; i++)
     {
         cout << " For game " << i + 1 << ", how many innings did they pitch? ";
         cin >> input;
         input = pitcherValidate(input, 26);  // Record for innings pitched in a single game is 26
         pitcher1.setInnings(input);
         pitcher1.setIntInnings(input);
         pitcher1.setInningsTotal(pitcher1.getInnings());
         ip[i] = pitcher1.getInnings();
         pitcher1.setOuts(input, pitcher1.getIntInnings());
         pitcher1.setOutsTotal(pitcher1.getOuts());
         
         cout << " How many hits did they allow? ";
         cin >> input;
         input = pitcherValidate(input, 26);  // Record for hits allowed in a single game is 26
         pitcher1.setHits(input);
         pitcher1.setHitsTotal(pitcher1.getHits());
         h[i] = pitcher1.getHits();
         
         cout << " How many walks did they allow? ";
         cin >> input;
         input = pitcherValidate(input, 16);  // Record for walks allowed in a single game is 16
         pitcher1.setWalks(input);
         pitcher1.setWalksTotal(pitcher1.getWalks());
         bb[i] = pitcher1.getWalks();
         
         cout << " How many earned runs did they allow? ";
         cin >> input;
         input = pitcherValidate(input, 17);  // Record for runs allowed in a single game is 17
         pitcher1.setRuns(input);
         pitcher1.setRunsTotal(pitcher1.getRuns());
         runs[i] = pitcher1.getRuns();
         cout << endl;
         
         era[i] = pitcher1.getERA();
         whip[i] = pitcher1.getWHIP();
         eraTotal[i] = pitcher1.getERATotal();
         whipTotal[i] = pitcher1.getWHIPTotal();
     }
     
     cout << " " << left << name << endl
          << " ___________________________________________________________________" << endl
          << right << setw(9) << "| " << setw(8) << "| " << setw(7) << "| " << setw(8) << "| " << setw(7)
          << "| " << setw(5) << "Game" << " |" << setw(6) << "Game" << " | " << setw(5) << "SEAS" << " |"
          << setw(6) << "SEAS" << endl
          << right << " Games" << " | " << "   IP" << " | " << "Hits" << " | " << "Walks" << " | "
          << "Runs" << " | " << setw(5) << "ERA" << " |" << setw(6) << "WHIP" << " | " << setw(5) << "ERA"
          << " |" << setw(6) << "WHIP" << endl;
     outputFile << " " << left << name << endl
                << " __________________________________________________________________" << endl
                << right << setw(9) << "| " << setw(8) << "| " << setw(7) << "| " << setw(8) << "| " << setw(7)
                << "| " << setw(5) << "Game" << " |" << setw(6) << "Game" << " | " << setw(5) << "SEAS" << " |"
                << setw(6) << "SEAS" << endl
                << right << " Games" << " | " << "   IP" << " | " << "Hits" << " | " << "Walks" << " | "
                << "Runs" << " | " << setw(5) << "ERA" << " |" << setw(6) << "WHIP" << " | " << setw(5) << "ERA"
                << " |" << setw(6) << "WHIP" << endl;
     
     for (int i=0; i < games; i++)
     {
         cout << fixed << right << setw(6) << i + 1 << " | " << setw(5) << setprecision(1) << ip[i] << " | " << setw(4)
              << setprecision(0) << h[i] << " | " << setw(5) << bb[i] << " | " << setw(4) << runs[i] << " | " << setw(5)
              << fixed << setprecision(2) << era[i] << " | " << setw(5) << whip[i] << " | " << setw(5) << eraTotal[i]
              << " | " << setw(5) << whipTotal[i] << endl;
                    
         outputFile << fixed << right << setw(6) << i + 1 << " | " << setw(5) << setprecision(1) << ip[i] << " | " << setw(4)
                    << setprecision(0) << h[i] << " | " << setw(5) << bb[i] << " | " << setw(4) << runs[i] << " | " << setw(5)
                    << fixed << setprecision(2) << era[i] << " | " << setw(5) << whip[i] << " | " << setw(5) << eraTotal[i]
                    << " | " << setw(5) << whipTotal[i] << endl;
         Sleep(200);
     }
     cout << " -------------------------------------------------------------------" << endl
          << setw(6) << games  << " | " << setw(5) << setprecision(1) << inningChange((pitcher1.getOutsTotal()/3)) << " | " << setw(4)
          << setprecision(0) << pitcher1.getHitsTotal() << " | " << setw(5) << pitcher1.getWalksTotal() << " | " << setw(4)
          << pitcher1.getRunsTotal() <<  " | " << setw(5) << "NA " << " |" << setw(6) << "NA " <<  " | " << setprecision(2)
          << setw(5) << pitcher1.getERATotal() << " |" << setw(6) << pitcher1.getWHIPTotal() << endl << endl
          << " See statsOutput.txt file for printable stats." << endl << endl;
                
     outputFile << " -------------------------------------------------------------------" << endl
                << setw(6) << games  << " | " << setw(5) << setprecision(1) << inningChange((pitcher1.getOutsTotal()/3)) << " | " << setw(4)
                << setprecision(0) << pitcher1.getHitsTotal() << " | " << setw(5) << pitcher1.getWalksTotal() << " | " << setw(4)
                << pitcher1.getRunsTotal() <<  " | " << setw(5) << "NA " << " |" << setw(6) << "NA " <<  " | " << setprecision(2)
                << setw(5) << pitcher1.getERATotal() << " |" << setw(6) << pitcher1.getWHIPTotal() << endl << endl;
     
     outputFile.close();
}

/*********************************************************************
                          pitcherFile                               
Reads stats from a file, calculates other stats, and displays
the stats in a table to both the console and a file.
*********************************************************************/

void pitcherFile(char fileName[25], string name, int games)
{
    int intInnings;
    double input;
    string file, junk;
    
    Pitcher pitcher1;
     
    pitcher1.setInningsTotal(0);
    pitcher1.setHitsTotal(0);
    pitcher1.setWalksTotal(0);
    pitcher1.setRunsTotal(0);
    pitcher1.setOutsTotal(0);
    
    double ip[games], h[games], bb[games], runs[games], era[games], whip[games];
    
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
                inputFile >> junk >> junk >> junk >> junk >> junk;
                
                cout << " " << left << name << endl
                     << " ___________________________________________________________________" << endl
                     << right << setw(9) << "| " << setw(8) << "| " << setw(7) << "| " << setw(8) << "| " << setw(7)
                     << "| " << setw(5) << "Game" << " |" << setw(6) << "Game" << " | " << setw(5) << "SEAS" << " |"
                     << setw(6) << "SEAS" << endl
                     << right << " Games" << " | " << "   IP" << " | " << "Hits" << " | " << "Walks" << " | "
                     << "Runs" << " | " << setw(5) << "ERA" << " |" << setw(6) << "WHIP" << " | " << setw(5) << "ERA"
                     << " |" << setw(6) << "WHIP" << endl;
                outputFile << " " << left << name << endl
                           << " __________________________________________________________________" << endl
                           << right << setw(9) << "| " << setw(8) << "| " << setw(7) << "| " << setw(8) << "| " << setw(7)
                           << "| " << setw(5) << "Game" << " |" << setw(6) << "Game" << " | " << setw(5) << "SEAS" << " |"
                           << setw(6) << "SEAS" << endl
                           << right << " Games" << " | " << "   IP" << " | " << "Hits" << " | " << "Walks" << " | "
                           << "Runs" << " | " << setw(5) << "ERA" << " |" << setw(6) << "WHIP" << " | " << setw(5) << "ERA"
                           << " |" << setw(6) << "WHIP" << endl;
                for (int i=0; i < games; i++)
                {
                    inputFile >> input;
                    input = pitcherValidate(input, 26);  // Record for innings pitched in a single game is 26
                    pitcher1.setInnings(input);
                    pitcher1.setIntInnings(input);
                    pitcher1.setInningsTotal(pitcher1.getInnings());
                    ip[i] = pitcher1.getInnings();
                    pitcher1.setOuts(input, pitcher1.getIntInnings());
                    pitcher1.setOutsTotal(pitcher1.getOuts());
                    
                    inputFile >> input;
                    input = pitcherValidate(input, 26);  // Record for hits allowed in a single game is 26
                    pitcher1.setHits(input);
                    pitcher1.setHitsTotal(pitcher1.getHits());
                    h[i] = pitcher1.getHits();
         
                    inputFile >> input;
                    input = pitcherValidate(input, 16);  // Record for walks allowed in a single game is 16
                    pitcher1.setWalks(input);
                    pitcher1.setWalksTotal(pitcher1.getWalks());
                    bb[i] = pitcher1.getWalks();
         
                    inputFile >> input;
                    input = pitcherValidate(input, 17);  // Record for runs allowed in a single game is 17
                    pitcher1.setRuns(input);
                    pitcher1.setRunsTotal(pitcher1.getRuns());
                    runs[i] = pitcher1.getRuns();
                    inputFile >> input;
         
                    era[i] = pitcher1.getERA();
                    whip[i] = pitcher1.getWHIP();
                    
                    cout << fixed << right << setw(6) << i + 1 << " | " << setw(5) << setprecision(1) << ip[i] << " | " << setw(4)
                         << setprecision(0) << h[i] << " | " << setw(5) << bb[i] << " | " << setw(4) << runs[i] << " | " << setw(5)
                         << fixed << setprecision(2) << era[i] << " | " << setw(5) << whip[i] << " | " << setw(5)
                         << pitcher1.getERATotal()
                         << " | " << setw(5) << pitcher1.getWHIPTotal() << endl;
                    
                    outputFile << fixed << right << setw(6) << i + 1 << " | " << setw(5) << setprecision(1) << ip[i] << " | " << setw(4)
                               << setprecision(0) << h[i] << " | " << setw(5) << bb[i] << " | " << setw(4) << runs[i] << " | " << setw(5)
                               << fixed << setprecision(2) << era[i] << " | " << setw(5) << whip[i] << " | " << setw(5)
                               << pitcher1.getERATotal()
                               << " | " << setw(5) << pitcher1.getWHIPTotal() << endl;
                    Sleep(200);
                }
                cout << " -------------------------------------------------------------------" << endl
                     << setw(6) << games  << " | " << setw(5) << setprecision(1) << inningChange((pitcher1.getOutsTotal()/3)) << " | " << setw(4)
                     << setprecision(0) << pitcher1.getHitsTotal() << " | " << setw(5) << pitcher1.getWalksTotal() << " | " << setw(4)
                     << pitcher1.getRunsTotal() <<  " | " << setw(5) << "NA " << " |" << setw(6) << "NA " <<  " | " << setprecision(2)
                     << setw(5) << pitcher1.getERATotal() << " |" << setw(6) << pitcher1.getWHIPTotal() << endl << endl
                     << " See statsOutput.txt file for printable stats." << endl << endl;
                
                outputFile << " -------------------------------------------------------------------" << endl
                           << setw(6) << games  << " | " << setw(5) << setprecision(1) << inningChange((pitcher1.getOutsTotal()/3)) << " | " << setw(4)
                           << setprecision(0) << pitcher1.getHitsTotal() << " | " << setw(5) << pitcher1.getWalksTotal() << " | " << setw(4)
                           << pitcher1.getRunsTotal() <<  " | " << setw(5) << "NA " << " |" << setw(6) << "NA " <<  " | " << setprecision(2)
                           << setw(5) << pitcher1.getERATotal() << " |" << setw(6) << pitcher1.getWHIPTotal() << endl << endl;
                
                outputFile.close();
                inputFile.close();
          }
    }
}

/*********************************************************************
                          inningChange                               
Changes parts of innings from thirds (.3 or .7) to accepted values of
.1 for one out and .2 for two outs.
*********************************************************************/

double inningChange(double outsTotal)
{
     int outs1;
     double outs2, outsDecimal;
     
     outs2 = outsTotal;
     outs1 = static_cast<int>(outs2);
     outsDecimal = outs2 - outs1;
     if (outsDecimal < .2)
     {
           outsTotal = outsTotal;
     }
     else if (outsDecimal < .4)
     {
           outsTotal = outs1 + .1;
     }
     else if (outsDecimal < .8)
     {
           outsTotal = outs1 + .2;
     }
     return outsTotal;
}

/*********************************************************************
                          pitcherValidate                               
Checks to make sure inputted stats falls within an acceptable range.
*********************************************************************/

double pitcherValidate(double input, double upperBound)
{
     const int lowerBound = 0;
     do
     {
          if (input < lowerBound || input > upperBound)
          {
              cout << endl << " <ERROR> Must be between " << lowerBound << " and " << upperBound << " <ERROR>" << endl;
              cout << " Please try again: ";
              cin >> input;
              cout << endl;
          }
     }while (input < 0 || input > upperBound);
     return input;
}
