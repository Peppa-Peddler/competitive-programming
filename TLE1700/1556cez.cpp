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
pair<LL, LL> dp[ N3 ][ N3 ];

LL solve(){

  int c[N3];
  cin >> n;
  R(i, n) cin >> c[ i ];

  LL l, r;

  for( int i = 0; i < n; i++ ){
    l = r = 0;
    if( i % 2 ) r = c[ i ];
    else l = c[ i ];
    for( int j = i + 1; j < n; j++ ){
      if( j % 2 == 0 ) l += c[ j ];
      else {
        l -= c[ j ];
        if( l < 0 ) {
          r += -l;
          l = 0;
        }
      }
      dp[ i ][ j ] = MP(l, r);
    }
  }

  LL ans = 0;

  for( int i = 0; i < n; i += 2 ){
    ans += min( c[i], c[ i + 1 ] );
    for( int j = i + 3; j < n; j += 2 ){
      l = dp[ i + 1 ][ j - 1 ].F;
      r = dp[ i + 1 ][ j - 1 ].S;
      if( c[ i ] >= r and c[ j ] >= l ){
        ans += min( c[ i ] - r, c[ j ] - l ) + 1;
      }
    }
  }

  return ans;
}

int main(){

    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
