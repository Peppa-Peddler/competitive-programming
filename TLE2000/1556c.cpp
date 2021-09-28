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

int c[ N3 ];
pair<LL, LL> dp[ N3 ][ N3 ];

LL solve(){
    cin >> n;

    R(i, n) cin >> c[ i ];

    LL l, r;

    R(i, n - 1){
      if(i % 2){
        dp[ i ][ i + 1 ] = MP(c[i], c[i + 1]);
        continue;
      }
      l = max(0, c[ i + 1 ] - c[ i ] );
      r = max(0, c[ i ] - c[ i + 1 ] );
      dp[ i ][ i + 1 ] = MP(l, r);
    }
    LL ll, rr;
    for( int i = n - 1; i >= 0; i-- ){
      for( int j = i + 3; j < n; j+=2 ){
        l = dp[ i + 1 ][ j - 1 ].F;
        r = dp[ i + 1 ][ j - 1 ].S;
        if( i % 2 ){
          dp[ i ][ j ] = MP( c[ i ] + l, c[ j ] + r );
          continue;
        }
        ll = c[ i ] - l;
        rr = c[ j ] - r;
        if( l > c[ i ] ) ll = 0;
        if( r > c[ j ] ) rr = 0;
        l -= min( l, c[ i ]*1LL);
        r -= min( r, c[ j ]*1LL );

        dp[ i ][ j ] = MP(max(rr - ll, 0LL) + l, max(ll - rr, 0LL )+ r);
      }
    }
    /*
    for( int i = 0; i < n; i+=1 ){
      for( int j = i + 1; j < n; j += 2 ){
        cout << dp[ i ][ j ].F << ":" << dp[ i ][ j ].S << " (" << i <<","<<j<<") - ";
      }
      cout << endl;
    }
    */
    LL ans = 0;

    for(int i = 0; i < n; i+= 2){
      ans += min( c[ i ], c[ i + 1 ] );
      for(int j = i + 3; j < n; j+= 2){
        l = dp[ i + 1 ][ j - 1 ].F;
        r = dp[ i + 1 ][ j - 1 ].S;
        if( l <= c[ i ] and r <= c[ j ] ) {
          ans += min( c[ i ] - l, c[ j ] - r ) + 1;
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
