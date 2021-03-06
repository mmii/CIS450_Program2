#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Job.h"
#include "AdmissionScheduler.h"
#include "CPUScheduler.h"

using namespace std;

///
//Main program source file.
///
int main(int argc, char **argv)
{
	int memoryAlgorithm = 0;
	char* inputFile;
	AdmissionScheduler adminScheduler;
	CPUScheduler *cpu = new CPUScheduler();

	if (argc < 3)
	{
		cout << "Usage: simulation <Memory Algorithm> <Data File>" << endl;
		cout << " e.g.: ./simulation 1 datafile.txt" << endl;
		exit(0);
	}

	memoryAlgorithm = atoi(argv[1]);
	inputFile = argv[2];

	ifstream infile(inputFile);

	int pId;
	int arrivalTime;
	int serviceTime;
	int dataSize;

	cout << "Loading jobs from: " << inputFile << endl;

	while (infile >> pId >> arrivalTime >> serviceTime >> dataSize)
	{
		Job job(pId, arrivalTime, serviceTime, dataSize);
		adminScheduler.addJob(job);
	}

	cout << adminScheduler.queueSize() << " jobs loaded." << endl;
	
	cout << "Running main program loopi." << endl;

	while (adminScheduler.queueSize() > 0)
	{
		cout << "Clock Time: " << cpu->getCurrentClock() << " ";

		vector<Job> readyForWaiting = adminScheduler.checkJobsForAdmission(
				cpu->getCurrentClock()
				);
	
		for(int i = 0; i < readyForWaiting.size(); i++)
		{
			cout << "Process: " << readyForWaiting[i].getProcessId() << " arrived";
		}

		cpu->incrementClock();

		cout << endl;
	}
}
