//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
//basic version - works, time is .606


#include <iostream>
using namespace std;

unsigned int cache[1000001];

int cycleLengthRecursive(unsigned int n) {
 
  if (n == 1) return 1;
  
  if (n % 2 == 1) n = (n*3) + 1;  // if n is odd then  n <- 3n + 1
  else            n = n/2;        // else n <- n/2

  return 1 + cycleLengthRecursive(n);
}

int maxCycleLength(int i, int j) {
  
  if (j<i) { // arange them in min/max order
    int tmp = i;
    i = j;
    j = tmp;
  }

  //loop from min to small and keep track of max
  int max = 0;
  for (int n=i; n<=j; ++n){
    int c = cycleLengthRecursive(n);
    if (c>max) max = c; 
  }

  return max;
}

int main(int argc,char *argv[]) {
    int i, j;
    while (cin >> i && cin >> j) {
      cout << i << " " << j << " " << maxCycleLength(i, j) << endl;
    }
  }
	
