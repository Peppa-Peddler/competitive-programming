#include<bits/stdc++.h>

#define LL long long
#define N5 100005

#define MOD 1000000007

using namespace std;

int INV[ N5 ];
LL F[ N5 ];
LL FI[ N5 ];

void prefac(int Nmax, int mod){
  INV[ 1 ] = 1;
  for( LL i = 2; i < Nmax ; i++ )
    INV[ i ] = mod - (LL)( mod / i ) * INV[ mod % i ] % mod;

  F[ 0 ] = 1;
  for( LL i = 1 ; i < Nmax ; i++ )
    F[ i ] = F[ i - 1 ]*i % mod;

  FI[ 0 ] = 1;
  for( LL i = 1 ; i < Nmax ; i++ )
    FI[ i ] = FI[ i - 1 ]*INV[ i ] % mod;
}

LL C( LL n, LL k, int mod ){
  if( n < k ) return 0;
  return F[ n ] * FI[ k ] % mod * FI[ n - k ] % mod;
}

int main(){
  prefac(N5, 31);
  for(int i = 1; i <= 10; i++){
    cout << F[ i ] << " " <<  INV[ i ] << endl;
  }
  cout << C(6, 2, 31) << endl;
}
