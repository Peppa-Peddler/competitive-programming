#include<bits/stdc++.h>

#define LL long long

#define PII pair<int, int>
#define VI vector<int>
#define PB push_back
#define PQ priority_queue

#define MP make_pair
#define F first
#define S second

#define MOD 1000000007
#define N6 1000006
#define N5 100005
#define N4 10004
#define N3 1003

#define PI 3.1415926535897932384626

#define N N5

#define clr(v, a) memset(v, a, sizeof(v))
#define all(x) x.begin(),x.end()
#define R(i, n) for(int i=0; i<n; i++)
#define len(x) ((int)(x).size())

#define bits(x) __builtin_popcount(x)
#define bitsLL(x) __builtin_popcountll(x)

#define zerosl(x) __builtin_clz(x)
#define zerosr(x) __builtin_ctz(x)

/*
⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄
*/

using namespace std;

int n, m, k, t = 1;

string s[ 2*N3 ];

LL DPb[ 2*N3 ][ 2*N3 ];
LL DPr[ 2*N3 ][ 2*N3 ];
LL ab[ 2*N3 ][ 2*N3 ] = {};
LL ar[ 2*N3 ][ 2*N3 ];
int v[ 2*N3 ][ 2*N3 ];
int h[ 2*N3 ][ 2*N3 ];

LL solve(){
  cin >> n >> m;
  R(i, n) cin >> s[ i ];
  R(i, n){
    h[ i ][ m - 1 ] = 0;
    for( int j = m - 2; j >= 0; j-- )
      h[ i ][ j ] = (s[ i ][ j + 1 ] == 'R') + h[ i ][ j + 1 ];
  }
  R(i, m){
    v[ n - 1 ][ i ] = 0;
    for( int j = n - 2; j >= 0; j-- )
      v[ j ][ i ] = (s[ j + 1 ][ i ] == 'R') + v[ j + 1 ][ i ];
  }

  if( n == 1 and m == 1 ) return 1;
  if( s[ n - 1 ][ m - 1 ] == 'R' ) return 0;

  R(j, m){ DPb[ n - 1 ][ j ] = 0; }
  R(i, n){ DPr[ i ][ m - 1 ] = 0; }
  DPb[ n - 1 ][ m - 1 ] = DPr[ n - 1 ][ m - 1 ] = 1;
  ar[ n - 1 ][ m - 1 ] = ab[ n - 1 ][ m - 1 ] = 1;

  LL mov;

  for( int i = n - 2 ; i >= 0 ; i-- ){
    DPb[ i ][ m - 1 ] = DPb[ i + 1 ][ m - 1 ];
    if( s[ i ][ m - 1 ] == 'R' ) DPb[ i ][ m - 1 ] = 0;
    ab[ i ][ m - 1 ] = DPb[ i ][ m - 1 ];
  }

  for( int j = m - 2 ; j >= 0 ; j-- ){
    DPr[ n - 1 ][ j ] = DPr[ n - 1 ][ j + 1 ];
    if( s[ n - 1 ][ j ] == 'R' ) DPr[ n - 1 ][ j ] = 0;
    ar[ n - 1 ][ j ] = DPr[ n - 1 ][ j ];
  }

  for( int i = n - 2; i >= 0; i-- ){
    for( int j = m - 2; j >= 0; j-- ){
      DPr[ i ][ j ] = DPb[ i ][ j ] = 0;
      mov = m - j - 1 - h[ i ][ j ];
      if( mov ){
        DPr[ i ][ j ] = ab[ i ][ j + 1 ];
        if( j + mov + 1 < m ) DPr[ i ][ j ] = (1LL*MOD + DPr[ i ][ j ] - ab[ i ][ j + mov + 1 ])%MOD;
      }
      mov = n - i - 1 - v[ i ][ j ];
      if( mov ){
        DPb[ i ][ j ] = ar[ i + 1 ][ j ];
        if( i + mov + 1 < n ) DPb[ i ][ j ] = (1LL*MOD + DPb[ i ][ j ] - ar[ i + mov + 1 ][ j ])%MOD;
      }
      ab[ i ][ j ] = (1LL*ab[ i ][ j + 1 ] + DPb[ i ][ j ])%MOD;
      ar[ i ][ j ] = (1LL*ar[ i + 1 ][ j ] + DPr[ i ][ j ])%MOD;
    }
  }

  return (0LL + DPr[0][0] + DPb[0][0])%MOD;
}

int main(){

  //cin >> t;
  while(t--) cout << solve() << endl;
  //while(t--) solve();

}
