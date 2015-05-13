#include "baseballMain.h"

/***************************************************************************** 
 * BASEBALL CLASSES .h
 *****************************************************************************/
using namespace std;

class Batter
{
      private:
         double atBats, atBatsTotal, hits, hitsTotal, avg, walks, walksTotal;
         double hbp, hbpTotal, sacFly, sacFlyTotal, obp, avgTotal, obpTotal;
         
      public:
         void setAtBats(double ab);
         void setHits(double h);
         void setWalks(double bb);
         void setHitByPitch(double hitByPitch);
         void setSacFlies(double sf);
         
         void setAtBatsTotal(double ab);
         void setHitsTotal(double h);
         void setWalksTotal(double bb);
         void setHitByPitchTotal(double hitByPitch);
         void setSacFliesTotal(double sf);
         
         double getAtBats();
         double getHits();
         double getWalks();
         double getHitByPitch();
         double getSacFlies();
         
         double getAtBatsTotal();
         double getHitsTotal();
         double getWalksTotal();
         double getHitByPitchTotal();
         double getSacFliesTotal();
         
         double getAvg();
         double getAvgTotal();
         double getOnBasePer();
         double getOnBasePerTotal();
         
         Batter()
         {
               atBatsTotal = hitsTotal = walksTotal = hbpTotal
                           = sacFlyTotal = avgTotal = obpTotal = 0;
         }
};

class Pitcher
{
      private:
         int intInnings;
         double innings, inningsTotal, hits, hitsTotal, walks, walksTotal;
         double outs, outsTotal, runs, runsTotal, era, whip, eraTotal, whipTotal;
         
      public:
         void setInnings(double ip);
         void setHits(double h);
         void setWalks(double bb);
         void setOuts(double ip, int intIP);
         void setRuns(double r);
         void setIntInnings(double ip);
         
         void setInningsTotal(double ip);
         void setHitsTotal(double h);
         void setWalksTotal(double bb);
         void setOutsTotal(double out);
         void setRunsTotal(double r);
         
         double getInnings();
         double getHits();
         double getWalks();
         double getOuts();
         double getRuns();
         int getIntInnings();
         
         double getInningsTotal();
         double getHitsTotal();
         double getWalksTotal();
         double getOutsTotal();
         double getRunsTotal();
         
         double getERA();
         double getERATotal();
         double getWHIP();
         double getWHIPTotal();
         
         Pitcher()
         {
               inningsTotal = hitsTotal = walksTotal = outsTotal
                           = runsTotal = eraTotal = whipTotal = 0;
         }
};
