#include<bits/stdc++.h>

#define LL long long
#define N5 100005

#define MOD 1000000007

using namespace std;

LL binpow( LL a, LL e ){
  LL ans = 1;
  while( e ){
    if( e & 1 ) ans = ans * a % MOD;
    a = a * a % MOD; e >>= 1;
  }
  return ans;
}

int main(){
  cout << binpow( 2LL, 3LL ) << endl;
}
