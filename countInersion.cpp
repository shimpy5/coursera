#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class CountInversion
{

private:
 long numArray[100001];
 long size;
 long countInv;
 long countSplitInversionImpl(int lb, int mid, int ub)
 {
   long i = lb;
   long j = mid+1;
   long splitInvCount = 0;
   long bArray[100001];
   long k = 0;
   
   for ( ; i <= mid && j <=ub; )
   {
     if(numArray[i] > numArray[j])
     {
       splitInvCount = splitInvCount + (mid - i) +1;
       bArray[k++] = numArray[j++];
     }
     else
     {
       bArray[k++]= numArray[i++];
     }
   }
   while (i <=mid)
     bArray[k++] = numArray[i++];
   
   while (j <= ub)
     bArray[k++] = numArray[j++];
   for(long z=lb, x=0; z<= ub; )
   {
      numArray[z++] = bArray[x++]; 
   }
   return splitInvCount;
 }
 long countInversionImpl(int lb, int ub)
 {
    if (lb < ub)
    {
       long count1 = 0;
       long count2 = 0;
       long count3 = 0;
       long mid = lb + (ub-lb)/2;
       cout << "Lower Bound is :" << lb << endl;
       cout << "Mid Element is :" << mid << endl;
       cout << "Upper bound is :" << ub << endl;
       ///getchar();
       count1 = countInversionImpl(lb, mid);
       cout << "Count1 is :" << count1 << endl;
       count2 = countInversionImpl(mid+1, ub);
       cout << "Count2 is :" << count2 << endl;
       count3 = countSplitInversionImpl(lb,mid,ub);
       cout << "Count3 is :" << count3 << endl;
       return (count1 + count2 + count3);
       cout <<"Count INv is :" << countInv << endl;
//       getchar();
   // cout << "Array after merge is :" << endl;
//       display();
       
      
    }
    return 0;
 }
public:
 CountInversion(long arr[], int size)
 {
  for(long i=0; i < size; i++)
  {
    numArray[i] = arr[i];
    countInv = 0;
  }
  this->size = size;
  cout << "Size is " << size << endl;
 }
 long count()
 {
    long totalCountInv = countInversionImpl(0, size -1);
    return totalCountInv;
 }
 void display()
 {
  for(int l = 0; l < size; l++)
  {
     cout << numArray[l] << endl;
  }
  
 }

};

//long CountInversion::countInv = 0;


int main()
{
  char numStr[7]={0};
  long numArr[100001]={0};
  ifstream file("IntegerArray.txt", ios::in);
  long index = 0;
  while (!file.eof())
  {
    file.getline(numStr,7);
    cout << numStr << endl;
    numArr[index++] = atol(numStr);
    //cout << numArr[index - 1];
  }
  
  CountInversion cI(numArr, index-1);
  long tc = cI.count();
  cI.display();
  cout << endl << "Size of long is " << sizeof(long) <<endl;
  cout << endl << "Total Count is "  << tc << endl;
}
