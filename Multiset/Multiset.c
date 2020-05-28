#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#include "Multiset.h"

//creates char set elements
charElement makeCharElement(char val, int count)
{
  charElement myElem;
  myElem.value = val;
  myElem.count = count;
  return myElem;
}

//creates charSet out of array of elements and a corresponding array of counts
charSet makeCharSet(int numUniqueElements, int *counts, char *elements)
{
    int i;
    charSet myCharSet = (charSet) malloc(sizeof(charElemColection));
    myCharSet->elements= (charElement*) malloc(sizeof(charElement)*numUniqueElements);
    for(i = 0; i < numUniqueElements; ++i){
      if(&(counts[i])==NULL || &(elements[i])==NULL){
        free(myCharSet->elements);
        return NULL;
      }
      myCharSet->elements[i] = makeCharElement(elements[i], counts[i]);
    }
    myCharSet->numElements=numUniqueElements;
    return myCharSet;
}


//print out all elements in set and their respective quantities
//
void printCharSet(charSet myCharSet, FILE *fp)
{
  int i;
  if(myCharSet!=NULL){
      if(fp == NULL){
        printf("%d\n", myCharSet->numElements);
        for(i=0; i<myCharSet->numElements;i++){
          printf("%c * %d\n", myCharSet->elements[i].value, myCharSet->elements[i].count);
        }
      } else {
        fprintf(fp, "%d\n", myCharSet->numElements);
        for(i=0; i<myCharSet->numElements;i++){
          fprintf(fp, "%c, %d\n", myCharSet->elements[i].value, myCharSet->elements[i].count);
        }
      }
  } else {
    printf("Set pointer equals NULL\n");
  }
}

//return sum of the counts of set elements
int getSize(charSet mySet){
  int setSize = 0;
  int i;
  if(mySet!=NULL){
    for(i = 0; i<mySet->numElements; ++i){
      setSize+=mySet->elements[i].count;
    }
  }
  return setSize;
}
//copies the data myElem into duplicate, returns duplicate
charElement copyCharElement(charElement myElem){
  charElement duplicite;
  duplicite.value = myElem.value;
  duplicite.count = myElem.count;
  return duplicite;
}

//creates charElemColection cloneSet, fills with data of mySet, returns cloneSet
charSet copySet(charSet mySet){
  int i;
  charSet cloneSet = (charElemColection *) malloc(sizeof(charElemColection));
  cloneSet->elements = (charElement *) malloc(sizeof(charElement)*(mySet->numElements));
  cloneSet->numElements = mySet->numElements;
  for(i=0; i<mySet->numElements; ++i){
    cloneSet->elements[i] = copyCharElement(mySet->elements[i]);
  }
  return cloneSet;
}




int main()
{
  int counts[]  = {1, 2, 3};
  char vals[] = {'A', 'B', 'C'};
  charSet myFirstSet = makeCharSet(3, counts, vals);

  printCharSet(myFirstSet, NULL);

  FILE *fp=fopen("output.txt", "w");
  printf("myFirstSet\n");
  printCharSet(myFirstSet, fp);
  fclose(fp);

  printf("number of elements: %d\n", getSize(myFirstSet));

  charSet mySecondSet = copySet(myFirstSet);

  printCharSet(mySecondSet, NULL);

  FILE *fp1=fopen("output.txt", "a");
  printf("mySecondSet\n");
  printCharSet(mySecondSet, fp1);
  fclose(fp1);

  printf("number of elements: %d\n", getSize(myFirstSet));

  return 0;
}
