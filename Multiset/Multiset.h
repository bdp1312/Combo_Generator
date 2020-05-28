

typedef struct charElement{
  char value;
  int count;
} charElement;

typedef struct charElemColection{
  charElement *elements;
  int numElements;
} charElemColection;

typedef charElemColection *charSet;

//creates char set elements
charElement makeCharElement(char val, int count);

//creates charSet out of array of elements and a corresponding array of counts
charSet makeCharSet(int numUniqueElements, int *counts, char *elements);

//print out all elements in set and their respective quantities
void printCharSet(charSet myCharSet, FILE *fp);

//return sum of the counts of set elements
int getSize(charSet mySet);

//makes new copy of mySet
charSet copySet(charSet mySet);



//constructs all subsets of "mySet" that are of size "size"
int makeAllSubsets(charSet mySet, int size, bool trackFrequency);
