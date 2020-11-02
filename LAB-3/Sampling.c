//C program to generate random numbers according to given frequency distribution
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Utility function to find ceiling of r in arr[l..h]
int findCeil(int arr[], int r, int l, int h)
{
  int mid;
  while (l < h){
    mid = l + ((h - l) >> 1); // Same as mid = (l+h)/2
    (r > arr[mid]) ? (l = mid + 1) : (h = mid);
  }
  return (arr[l] >= r) ? l : -1;
}

// The main function that returns a random number from arr[] according to
// distribution array defined by freq[]. n is size of arrays.
int myRand(int arr[], int freq[], int n)
{
  // Create and fill prefix array
  int prefix[n], i;
  prefix[0] = freq[0];
  for (i = 1; i < n; ++i)
    prefix[i] = prefix[i - 1] + freq[i];
    
  // prefix[n-1] is sum of all frequencies. Generate a random number with value from 1 to this sum
  int r = (rand() % prefix[n - 1]) + 1;

  // Find index of ceiling of r in prefix arrat
  int indexc = findCeil(prefix, r, 0, n - 1);

  return arr[indexc];
}

// Driver program to test above functions
int main()
{
  int i,n;
  printf("Enter the size of the array: ");
  scanf("%d" , &n);
  int arr[n], freq[n];
  for (i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++){
   scanf("%d", &freq[i]);
  }
  
  // Use a different seed value for every run.
  srand(time(NULL));

  // Let us generate 10 random numbers accroding to given distribution
  for (i = 0; i < 10; i++)
    printf("%d\n", myRand(arr, freq, n));

  return 0;
}
/*
INPUT AND OUTPUT

Example 1:
Enter the size of the array: 5
1 2 3 4 5
10 5 12 3 60
2
3
5
5
5
5
5
5
3
5

Example 2:
Enter the size of the array: 9
2 3 4 1 6 23 9 8 21
12 3 45 21 89 90 1 78 69
21
8
23
6
6
23
8
21
4
2
*/
