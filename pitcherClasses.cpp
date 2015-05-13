#include "baseballMain.h"

using namespace std;

/************ SET SINGLE VARIABLES ************/
void Pitcher::setInnings(double ip)
{
     innings = ip;
}
void Pitcher::setHits(double h)
{
     hits = h;
}
void Pitcher::setWalks(double bb)
{
     walks = bb;
}
void Pitcher::setOuts(double ip, int intIP)
{
     outs = ((intIP * 3) + ((ip - intIP)*10));
}
void Pitcher::setRuns(double r)
{
     runs = r;
}
void Pitcher::setIntInnings(double ip)
{
     intInnings = static_cast<int>(ip);
}

/************ SET TOTAL VARIABLES ************/
void Pitcher::setInningsTotal(double ip)
{
     inningsTotal += ip;
}
void Pitcher::setHitsTotal(double h)
{
     hitsTotal += h;
}
void Pitcher::setWalksTotal(double bb)
{
     walksTotal += bb;
}
void Pitcher::setOutsTotal(double out)
{
     outsTotal += out;
}
void Pitcher::setRunsTotal(double r)
{
     runsTotal += r;
}

/************ GET SINGLE VARIABLES ************/
double Pitcher::getInnings()
{
     return innings;
}
double Pitcher::getHits()
{
     return hits;
}
double Pitcher::getWalks()
{
     return walks;
}
double Pitcher::getOuts()
{
     return outs;
}
double Pitcher::getRuns()
{
     return runs;
}
int Pitcher::getIntInnings()
{
    return intInnings;
}

/************ GET TOTAL VARIABLES ************/
double Pitcher::getInningsTotal()
{
     return inningsTotal;
}
double Pitcher::getHitsTotal()
{
     return hitsTotal;
}
double Pitcher::getWalksTotal()
{
     return walksTotal;
}
double Pitcher::getOutsTotal()
{
     return outsTotal;
}
double Pitcher::getRunsTotal()
{
     return runsTotal;
}

/************ GET CALCULATIONS ************/
double Pitcher::getERA()
{
     return ((runs * 27) / outs);
}
double Pitcher::getERATotal()
{
     return ((runsTotal * 27) / outsTotal);
}
double Pitcher::getWHIP()
{
     return ((hits + walks) / (outs/3));
}
double Pitcher::getWHIPTotal()
{
     return ((hitsTotal + walksTotal) / (outsTotal/3));
}
