#include<bits/stdc++.h>
#define LL long long

using namespace std;

void criba(bool *prime, int len){
  for(int i = 0; i < len; i++) prime[i] = true;
  prime[0] = prime[1] = false;
  for(int i = 4; i < len; i+=2) prime[i] = false;
  for(LL i = 3; i*i < len; i+=2)
      for(LL j = i*i; prime[i] and j < len; j+=2*i)
	prime[j] =false;
}

int main(){
  bool primes[100000];
  int n = 1000;
  criba(primes, n);
  for(int i = 0; i < 100; i++)
    if(primes[i])
      cout << i << " ";
  cout << endl;
}
