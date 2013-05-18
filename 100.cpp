//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36

//basic version - works, time is .606
//recursive solution             .605
//unoptimized cache              .309
//optimized cache                .216
//slightly more optimized        .225  (avoids ==1 check)
//avoids any rebucketing         .169

#include <iostream>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

typedef hash_map<unsigned int, short> cache_t;
cache_t cache;

int cycleLengthRecursive(unsigned int n) {
  // base case is handled by cache
  
  cache_t::iterator it = cache.find(n);
  if (it != cache.end()) {
    return it->second;  
  }
  
  int out;
  if (n % 2 == 1) 
    out = 1 + cycleLengthRecursive((n*3) + 1);  // if n is odd then  n <- 3n + 1
  else           
    out = 1 + cycleLengthRecursive(n/2);        // else n <- n/2

  cache[n] = out;
  return out;
}

int maxCycleLength(unsigned int i, unsigned int j) {
  
  if (j<i) { // arange them in min/max order
    int tmp = i;
    i = j;
    j = tmp;
  }

  int max = 0;
  for (int n=i; n<=j; ++n){
    int c = cycleLengthRecursive(n);
    if (c>max) max = c; 
  }

  return max;
}

int main(int argc,char *argv[]) {
    cache.resize(3145739); // avoid any future rebucketing
    cache[1] = 1; // base case, avoids lots of future ==
    unsigned int i, j;
    while (cin >> i && cin >> j) {
      cout << i << " " << j << " " << maxCycleLength(i, j) << endl;
    }
  }
	
