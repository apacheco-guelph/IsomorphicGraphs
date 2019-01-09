/*
Austin Pacheco
apacheco@uoguelph.ca
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Refactored.h"

typedef struct points{
  int pointName;
  int* connectedNums;
  points1* next;
}points;

int length = 0;

/*Qsort comapre function*/
static int cmp(const void *p1, const void *p2){
  return *(int*)p1 > *(int*)p2;
}

/*Tests whetehr or not the degreeLists are the same or not*/
int testDegree(int degreeList1[length], int degreeList2[length]){
  for(int i = 0; i < length; ++i){
    if(degreeList1[i] != degreeList2[i]){
      printf("\nThe graphs do NOT have the same degree sequence");
      return 0;
    }
  }
  printf("\nThe graphs do have the same degree sequence");
  return 0;
}
/*adds to the Matrix*/
void addToMatrix(FILE *fp,int matrix[length][length]){
  for(int j = 0; j< length; ++j){
    for(int i = 0; i< length; ++i){
      fscanf(fp,"%d", &matrix[i][j]);
      
    }
  }
}

/*creates the degreeList by looping thorugh the matrix and creating the Lists*/
void createDegreeList(int matrix[length][length], int degreeList[length]){

  int numName = 1;
  for(int j = 0; j< length; ++j){
    int degree = 0;
    for(int i = 0; i< length; ++i){
      if(matrix[i][j] == 1){
        ++degree;
      }
    }

    degreeList[j] = degree;
  }
}

/*Prints the degreeList*/
void printDegreeList(int degreeList1[length], int num){
  printf("\nDegree seq for G%d:",num);
  for(int i = 0; i < length; ++i){
    printf(" %d", degreeList1[i]);
  }
}

/*The main for reading the matrix*/
int readMatrix(){
  FILE *fp;
  fp = fopen("input.txt","r");

  while(!feof(fp))/*While the file still contains content*/
	{
    fscanf(fp,"%d",&length);
    /*Opens file and prints the size of the matrix*/

    /*Setting sizes for the matrix's and the degreeLists*/
    int degreeList1[length];
    int degreeList2[length];
    int matrix1[length][length];
    int matrix2[length][length];

    /*Reading into matrix*/
    addToMatrix(fp, matrix1);
    fscanf(fp,"%d",&length);
    addToMatrix(fp, matrix2);

    /*Creates the degree Lists*/
    createDegreeList(matrix1,degreeList1);
    createDegreeList(matrix2,degreeList2);

    /*Sorts both degreeLists*/
  	qsort(degreeList1, sizeof(degreeList1)/sizeof(int), sizeof(int), cmp);
    qsort(degreeList2, sizeof(degreeList2)/sizeof(int), sizeof(int), cmp);

    /*prints degreeList*/
    printDegreeList(degreeList1,1);
    printDegreeList(degreeList2,2);

    /*Tests whether or not the matrix has the same degreeList*/
    testDegree(degreeList1,degreeList2);
    printf("\n");
  }
  return 0;
}
