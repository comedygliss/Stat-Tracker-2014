#include "baseballMain.h"

using namespace std;

/************ SET SINGLE VARIABLES ************/
void Batter::setAtBats(double ab)
{
     atBats = ab;
}
void Batter::setHits(double h)
{
     hits = h;
}
void Batter::setWalks(double bb)
{
     walks = bb;
}
void Batter::setHitByPitch(double hitByPitch)
{
     hbp = hitByPitch;
}
void Batter::setSacFlies(double sf)
{
     sacFly = sf;
}

/************ SET TOTAL VARIABLES ************/
void Batter::setAtBatsTotal(double ab)
{
     atBatsTotal += ab;
}
void Batter::setHitsTotal(double h)
{
     hitsTotal += h;
}
void Batter::setWalksTotal(double bb)
{
     walksTotal += bb;
}
void Batter::setHitByPitchTotal(double hitByPitch)
{
     hbpTotal += hitByPitch;
}
void Batter::setSacFliesTotal(double sf)
{
     sacFlyTotal += sf;
}

/************ GET SINGLE VARIABLES ************/
double Batter::getAtBats()
{
     return atBats;
}
double Batter::getHits()
{
     return hits;
}
double Batter::getWalks()
{
     return walks;
}
double Batter::getHitByPitch()
{
     return hbp;
}
double Batter::getSacFlies()
{
     return sacFly;
}

/************ GET TOTAL VARIABLES ************/
double Batter::getAtBatsTotal()
{
     return atBatsTotal;
}
double Batter::getHitsTotal()
{
     return hitsTotal;
}
double Batter::getWalksTotal()
{
     return walksTotal;
}
double Batter::getHitByPitchTotal()
{
     return hbpTotal;
}
double Batter::getSacFliesTotal()
{
     return sacFlyTotal;
}

/************ GET CALCULATIONS ************/
double Batter::getAvg()
{
     return (hits / atBats);
}
double Batter::getAvgTotal()
{
     return (hitsTotal / atBatsTotal);
}
double Batter::getOnBasePer()
{
     return ((hits + walks + hbp) / (atBats + walks + hbp + sacFly));
}
double Batter::getOnBasePerTotal()
{
     return ((hitsTotal + walksTotal + hbpTotal) / (atBatsTotal + walksTotal + hbpTotal + sacFlyTotal));
}
