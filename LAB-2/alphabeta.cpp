#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

using namespace std;

int getHeight(int n) {
 return (n == 1) ? 0 : 1 + log2(n / 2);
}

int alphabeta(int height, int depth, int nodeIndex,bool maxPlayer, int values[],int alpha,int beta){
    if (depth == height){
      return values[nodeIndex];
    }
    if (maxPlayer){
      int bestValue = INT_MIN;
      cout<<"\nAlpha before calling alphabeta(): "<<alpha;
      cout<<"\nBeta before calling alphabeta(): "<<beta;
      for (int i = 0; i < height - 1; i++){
          int val = alphabeta(height, depth + 1, nodeIndex * 2 + i, false, values, alpha, beta);
          bestValue = max(bestValue, val);
          alpha = max(alpha, bestValue);
          cout<<"\nAlpha while returning: "<<alpha; 
          cout<<"\nBeta while returning: "<<beta;
          cout<<"\nvalue of bestValue: "<<bestValue;      
          if (beta <= alpha)
            break;
    }
      return bestValue;
    }
  else {
    int bestValue = INT_MAX;
    cout<<"\nAlpha before calling alphabeta(): "<<alpha;
    cout<<"\nBeta before calling alphabeta(): "<<beta;
    for (int i = 0; i < height - 1; i++){
        int val = alphabeta(height, depth + 1, nodeIndex * 2 + i, true, values, alpha, beta);
        bestValue = min(bestValue, val);
        beta = min(beta, bestValue);
        cout<<"\nAlpha while returning: "<<alpha;
        cout<<"\nBeta while returning: "<<beta; 
        cout<<"\nvalue of bestValue: "<<bestValue; 
        if (beta <= alpha)
          break;
    }
      return bestValue;
  }
}

//driver function
int main() {
 int values1[] = {1,2,3,4,5,6,7,8,9};
 int height1 = getHeight(SIZE(values1));
 int result1 = alphabeta(height1, 0, 0, true, values1, INT_MIN, INT_MAX);
 cout <<"\nResult (value of alpha) for array values1 : " << result1 << "\n\n";

 int values2[] = {-3,7,4,-99,4,6,78,32,-10,11,49,12, 57,700,15,-16,17};
 int height2 = getHeight(SIZE(values2));
 int result2 = alphabeta(height2, 0, 0, true, values2, INT_MIN, INT_MAX);
 cout <<"\nResult (value of alpha) for array values2 : " << result2 << "\n";
 return 0;
}

/*
output for the following two binary game trees is as follows:

FOR THE BINARY TREE IN ARRAY VALUES1={1,2,3,4,5,6,7,8,9}

Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2147483647
Alpha while returning: 1
Beta while returning: 2147483647
value of bestValue: 1
Alpha while returning: 2
Beta while returning: 2147483647
value of bestValue: 2
Alpha while returning: -2147483648
Beta while returning: 2
value of bestValue: 2
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2
Alpha while returning: 3
Beta while returning: 2
value of bestValue: 3
Alpha while returning: -2147483648
Beta while returning: 2
value of bestValue: 2
Alpha while returning: 2
Beta while returning: 2147483647
value of bestValue: 2
Alpha before calling alphabeta(): 2
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): 2
Beta before calling alphabeta(): 2147483647
Alpha while returning: 5
Beta while returning: 2147483647
value of bestValue: 5
Alpha while returning: 6
Beta while returning: 2147483647
value of bestValue: 6
Alpha while returning: 2
Beta while returning: 6
value of bestValue: 6
Alpha before calling alphabeta(): 2
Beta before calling alphabeta(): 6
Alpha while returning: 7
Beta while returning: 6
value of bestValue: 7
Alpha while returning: 2
Beta while returning: 6
value of bestValue: 6
Alpha while returning: 6
Beta while returning: 2147483647
value of bestValue: 6
Result (value of alpha) for array values1 : 6

FOR THE BINARY TREE IN ARRAY VALUES2={-3,7,4,-99,4,6,78,32,-10,11,49,12, 57,700,15,-16,17}

Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 2147483647
Alpha while returning: -2147483648
Beta while returning: -3
value of bestValue: -3
Alpha while returning: -2147483648
Beta while returning: -3
value of bestValue: -3
Alpha while returning: -2147483648
Beta while returning: -3
value of bestValue: -3
Alpha while returning: -3
Beta while returning: 2147483647
value of bestValue: -3
Alpha before calling alphabeta(): -3
Beta before calling alphabeta(): 2147483647
Alpha while returning: -3
Beta while returning: 4
value of bestValue: 4
Alpha while returning: -3
Beta while returning: -99
value of bestValue: -99
Alpha while returning: -3
Beta while returning: 2147483647
value of bestValue: -3
Alpha before calling alphabeta(): -3
Beta before calling alphabeta(): 2147483647
Alpha while returning: -3
Beta while returning: 4
value of bestValue: 4
Alpha while returning: -3
Beta while returning: 4
value of bestValue: 4
Alpha while returning: -3
Beta while returning: 4
value of bestValue: 4
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: 4
Alpha while returning: -2147483648
Beta while returning: 4
value of bestValue: 4
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 4
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 4
Alpha while returning: -2147483648
Beta while returning: 4
value of bestValue: 4
Alpha while returning: -2147483648
Beta while returning: 4
value of bestValue: 4
Alpha while returning: -2147483648
Beta while returning: 4
value of bestValue: 4
Alpha while returning: 4
Beta while returning: 4
value of bestValue: 4
Alpha while returning: -2147483648
Beta while returning: 4
value of bestValue: 4
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 4
Alpha before calling alphabeta(): -2147483648
Beta before calling alphabeta(): 4
Alpha while returning: -2147483648
Beta while returning: -10
value of bestValue: -10
Alpha while returning: -2147483648
Beta while returning: -10
value of bestValue: -10
Alpha while returning: -2147483648
Beta while returning: -10
value of bestValue: -10
Alpha while returning: -10
Beta while returning: 4
value of bestValue: -10
Alpha before calling alphabeta(): -10
Beta before calling alphabeta(): 4
Alpha while returning: -10
Beta while returning: 4
value of bestValue: 49
Alpha while returning: -10
Beta while returning: 4
value of bestValue: 12
Alpha while returning: -10
Beta while returning: 4
value of bestValue: 12
Alpha while returning: 12
Beta while returning: 4
value of bestValue: 12
Alpha while returning: -2147483648
Beta while returning: 4
value of bestValue: 4
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: 4
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha while returning: 4
Beta while returning: -10
value of bestValue: -10
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: -10
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha while returning: 4
Beta while returning: 49
value of bestValue: 49
Alpha while returning: 4
Beta while returning: 12
value of bestValue: 12
Alpha while returning: 4
Beta while returning: 12
value of bestValue: 12
Alpha while returning: 12
Beta while returning: 2147483647
value of bestValue: 12
Alpha before calling alphabeta(): 12
Beta before calling alphabeta(): 2147483647
Alpha while returning: 12
Beta while returning: 57
value of bestValue: 57
Alpha while returning: 12
Beta while returning: 57
value of bestValue: 57
Alpha while returning: 12
Beta while returning: 15
value of bestValue: 15
Alpha while returning: 15
Beta while returning: 2147483647
value of bestValue: 15
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 15
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 15
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 15
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 57
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 57
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 15
Alpha while returning: 15
Beta while returning: 15
value of bestValue: 15
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 15
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 15
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 15
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 17
Alpha while returning: 4
Beta while returning: 0
value of bestValue: 0
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 0
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 15
Alpha while returning: 4
Beta while returning: 6
value of bestValue: 6
Alpha while returning: 4
Beta while returning: 3
value of bestValue: 3
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 3
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 15
Alpha while returning: 4
Beta while returning: 1
value of bestValue: 1
Alpha while returning: 4
Beta while returning: 15
value of bestValue: 3
Alpha while returning: 4
Beta while returning: 3
value of bestValue: 3
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: 4
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha while returning: 4
Beta while returning: 17
value of bestValue: 17
Alpha while returning: 4
Beta while returning: 0
value of bestValue: 0
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: 0
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha while returning: 4
Beta while returning: 6
value of bestValue: 6
Alpha while returning: 4
Beta while returning: 3
value of bestValue: 3
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: 3
Alpha before calling alphabeta(): 4
Beta before calling alphabeta(): 2147483647
Alpha while returning: 4
Beta while returning: 1
value of bestValue: 1
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: 3
Alpha while returning: 4
Beta while returning: 3
value of bestValue: 3
Alpha while returning: 4
Beta while returning: 2147483647
value of bestValue: 4
Result (value of alpha) for array values2 : 4

*/
