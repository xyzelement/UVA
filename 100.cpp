//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
//basic version - works, time is .606
//recursive solution             .605
//unoptimized cache              .309

#include <iostream>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

hash_map<unsigned int, int> cache;


int cycleLengthRecursive(unsigned int n) {

 
  if (n == 1) return 1;
  
  
  if (cache.find(n) != cache.end()) {
    return cache[n];  
  }
  
  
  unsigned int n1;
  if (n % 2 == 1) n1 = (n*3) + 1;  // if n is odd then  n <- 3n + 1
  else            n1 = n/2;        // else n <- n/2

  int out = 1 + cycleLengthRecursive(n1);
  cache[n] = out;
  return out;
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
	
