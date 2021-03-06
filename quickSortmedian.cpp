#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;
class QuickSort
{
 private: 
   long array[10000];
   long lb;
   long ub;
 public:
static long numComparisons;
 QuickSort(long num[], long n)
 {
  for (long index = 0 ; index < n ; index++)
  {
    array[index] = num[index];
  }
  lb = 0;
  ub =  n-1;
 }
 
 void quicksort(long a[], int llb, int lub)
 {
   if(llb < lub)
   {
   	long partitionIndex =  partition(a, llb , lub);
//        cout << "partitionIndex = " << partitionIndex;
//        getchar();
        numComparisons = numComparisons + (lub - llb);
        if(partitionIndex > llb)
   	  quicksort(a, llb, partitionIndex - 1);
        if(partitionIndex < lub)
   	 quicksort(a, partitionIndex + 1, lub);
   }
 } 
 void sort()
 {
  quicksort(array,lb, ub);
 }
 static void swap(long *a, long *b)
 {
  long temp = *a;
  *a = *b;
  *b = temp;
  return;
 }
 long findMedianIndex(long a[], long llb, long lmb, long lub)
 {
   if ((a[llb] < a[lmb] && a[lmb] < a[lub]) ||
        (a[lub] < a[lmb] && a[lmb] < a[llb]))
   {
     return lmb;
   }
   else if((a[lmb] < a[lub] && a[lub] < a[llb]) ||
           (a[llb] < a[lub] && a[lub] < a[lmb]))
         return lub;
    else if ((a[lmb] < a[llb] && a[llb] < a[lub]) || (a[lub] < a[llb] && a[llb] < a[lmb]))
         return llb;
   return llb;
 
 }
 virtual long partition(long a[], long llb, long lub)
 {
   long numElem = (lub - llb)+1;
   long midElemIndex = 0;
   if( numElem%2 == 0 )
   {
     midElemIndex = numElem/2 -1;
   }
   else
   {
     midElemIndex = numElem/2;
   }
   long medianIndex = findMedianIndex(a, llb, llb+midElemIndex, lub);
   swap(&a[llb], &a[medianIndex]);
   long pivot = llb;
   long i = pivot + 1;
   long j = pivot + 1;
   for( ; i <= lub && j <= lub; j++ )
   {
     if( a[j] < a[pivot])
     {
        swap(&a[j], &a[i]);
        i++;
     }
   }
   swap(&a[pivot], &a[i-1]);
   return i-1;
 }
 void display()
 {
  for(long i=lb; i <= ub; i++)
  {
   cout << array[i] << endl;
  }
 }
};
long QuickSort::numComparisons = 0;
int main()
{
 ifstream fileIn("QuickSortI.txt", ios::in);
 char numStr[6]={0};
 long array[10000]={0};
 long index = 0;
 while (!fileIn.eof())
 {
  
   fileIn.getline(numStr,6);
   cout << numStr << endl;
   array[index++] = atol(numStr);
 }
 fileIn.close();
 QuickSort qSort(array, 10000);
 qSort.sort();
 cout << endl << "After Sorting:" << endl;
 qSort.display();
 cout << "Number of comparisons = " << QuickSort::numComparisons << endl;
 std::cout << "Hello" << std::endl;
}
