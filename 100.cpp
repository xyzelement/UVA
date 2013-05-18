//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36

#include <iostream>
using namespace std;

int cycleLength(unsigned int n) {
  static int cache[10000000]; //do i need to memset?

  int cycleLen = 1;

  while (n != 1) {
    if (n % 2 == 1) n = (n*3) + 1;  // if n is odd then  n <- 3n + 1
    else            n = n/2;        // else n <- n/2
    
    ++cycleLen;
  }

  return cycleLen;
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
    int c = cycleLength(n);
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
	
