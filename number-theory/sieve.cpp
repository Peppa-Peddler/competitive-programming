#include<bits/stdc++.h>

#define LL long long
#define N5 100005

using namespace std;

int primes[ N5 ];
void criba(int *prime, int Nmax){
  for(int i = 0; i < Nmax; i++) prime[ i ] = -1;
  for(int i = 4; i < Nmax; i+=2) prime[ i ] = 2;
  for(LL i = 3; i*i < Nmax; i+=2)
    if( prime[ i ] == -1 )
      for(LL j = i*i; j < Nmax; j += 2*i)
        if( prime[ j ] == -1 )
          prime[ j ] = i;
}

//criba(primes, N5);

int main(){
  criba(primes, N5);
  for(int i = 0; i < 100; i++)
    cout << "(" << i << " : " << primes[ i ] << ") ";
  cout << endl;
}
