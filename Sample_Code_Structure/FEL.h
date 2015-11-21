#ifndef FEL_INCLUDED
#define FEL_INCLUDED 

typedef struct FEL_st FEL;

#include "Event.h"
#include "Queue.h"
#include "SimulationData.h"
#include "ListNode.h"
#include "Server.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SUBTASKS 32

struct FEL_st{
  //The number of people that have arrived in each priority queue
  int* NumberArrivals;

  //The variables used in the exponential distribution functions
  float* Lambda;
  float Mu;

  //The list of events, ordered by time, of events that will occur in the future
  ListNode* EventList;

  //
  float LBF; //The average load balancing factor
};

//Create an FEL structure with the given values
FEL* FEL_Create(int arrivals0, int arrivals1, float mu, float lambda0, float lambda1);

//Destroy the FEL structure
void FEL_Destroy(FEL* FutureEvents);


//Randomly generate the arrival of a new subtask.  Its task will be NULL.
ListNode* FEL_GenerateRandomSubTask(FEL* futureEvents, int  priority, int arrivalTime);

//Generate a list of subtasks of random length and random durations
ListNode* FEL_GenerateRandomTask(FEL* fel, int priority, int previousTime);

//Generate a new departute event based off of a given arrival event
Event* FEL_GenerateDeparture(Event* arrival, int currentTime);

//Generate and add to the FEL the departures corresponding to the given
//list of subtasks
void FEL_GenerateAndAddDepartures(FEL* fel, ListNode* subTasks, int currentTime);

//Add an event that already exists to the FEL strucure
void FEL_AddEvent(FEL* futureEvents, Event* event);

//Appends a list node to the end of FEL.  Should only be used if it is known
//That all events are sorted and the FEL is empty
void FEL_Append(FEL* futureEvents, ListNode* node);

//Returns a 1 if there are not more events on the queue
int FEL_IsEmpty(FEL* futureEvents);

//Return the first event from the FEL and remove it from the FEL list
Event* FEL_PopEvent(FEL* futureEvents);

//A more generic version of FEL_PopEvent: returns either a list of
//subtask arrivals (to represent a task) or a departure wrapped in a
//list node
ListNode* FEL_Pop(FEL* fel);

// A function to test the average event time within a given FEL list.
float FEL_AverageEventDuration(FEL* futureEvents);

// A function to print the FEL to a test file for testing purposes. Since
// the function changes the original FEL, a copy is passed as output.
FEL* FEL_PrintPartBTestFile(FEL* fel, const char* testFileName);

#endif /* FEL_INCLUDED */