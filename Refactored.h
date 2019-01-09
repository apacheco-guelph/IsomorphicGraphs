#ifndef REFACTORED_H_
#define REFACTROED_H_

typedef struct points
{
  int pointName;
  int* connectedNums;
  points* next;
}points;

int length;
static int cmp(const void *p1, const void *p2);
int testDegree(int degreeList1[length], int degreeList2[length]);
void addToMatrix(FILE *fp,int matrix[length][length]);
void createDegreeList(int matrix[length][length], int degreeList[length]);
void printDegreeList(int degreeList1[length], int num);
int readMatrix();

#endif //REFACTORED_H_
