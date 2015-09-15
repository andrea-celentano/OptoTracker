#ifndef COMMONSTRUCT_HG
#define COMMONSTRUCT_HG

#include <string>
#include <vector>

using namespace std;

typedef struct driver{
	string name;
	string className;
	vector < string > methodName;
	vector < string > methodParam;
} driver_struct;

typedef struct reconControl{
	int dryRun;
	int skipEvents;
	int numberOfEventsTBP;
	int verboseLevel;
	int doProof;
	int doProofDiag;
	int numberOfWorkers;
	int numberOfIterations;
} reconControl_struct;

#endif
