#include <iostream>
#include <vector>
using namespace std;

#ifndef STATS_H
#define STATS_H

class Stats
{
	private:

		vector<int> _percentHoleData;       //used to store each hole calculation so an average can be computed at the end

	public:

			void OutputMem(vector<char> memory);       //call this function to print memory statistics
			void MemMap(vector<char> memory);          //prints memory map
			void PercentHoles(vector<char> memory);    //prints percentage of holes in memory map
			void ProcessStates(vector<Job> Jobs);                      //prints out information for each process

			int logHolePercent(int percentHole, vector<int> &_percentHoleData);   //called after every percentHole calculation to store the hole percentages        
			int getAvgHolePercent(vector<int> _percentHoleData);
			int getAvgWaitTime(vector<Job> Jobs);           //call at the

};

#endif /* End STATS_H */
