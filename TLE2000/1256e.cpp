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

PII v[ 2*N5 ];
LL DP[ 2*N5 ][ 7 ];

int team[ 2*N5 ];
int ans[ 2*N5 ];

LL solve(){
    cin >> n;

    R(i, n) {
        cin >> v[ i ].F;
        v[ i ].S = i;
    }

    sort(v, v + n);

    R(i, n) R(j, 7) DP[ i ][ j ] = MOD;

    LL tmp;
    for( int i = n - 1; i >= 0; i-- ){
        for( int k = min(5, i + 1); k >= 1; k-- ){
            if( i == n - 1 and k < 3 ){
                DP[ i ][ k ] = MOD;
                continue;
            }
            DP[ i ][ k ] = v[ i ].F - v[ i - k + 1 ].F;
            if( i == n - 1 ) continue;
            if( k < 3 ) {
                DP[ i ][ k ] = DP[ i + 1 ][ k + 1 ];
                continue;
            }
            DP[ i ][ k ] += DP[ i + 1 ][ 1 ];
            if( k == 5 ){
                tmp = v[ i - 2 ].F - v[ i - 4 ].F + DP[ i + 1 ][ 3 ];
                DP[ i ][ k ] = min( tmp, DP[ i ][ k ] );
                continue;
            }
            DP[ i ][ k ] = min( DP[ i ][ k ], DP[ i + 1 ][ k + 1 ] );
        }
    }

    cout << DP[ 0 ][ 1 ] << " ";

    int i = 0, k = 1, eq = 1, lft, rgt;
    while( i < n - 1 ){

        team[ i ] = eq;

        if( k < 3 ) {
            i++, k++;
            continue;
        }

        lft = v[ i ].F - v[ i - k + 1 ].F + DP[ i + 1 ][ 1 ];
        rgt = DP[ i + 1 ][ k + 1 ];

        if( lft <= rgt ){
            i ++, eq++;
            k = 1;
        } else{
            i++, k++;
        }

    }

    team[ i ] = eq;

    cout << eq << endl;

    R(i, n)
        ans[ v[ i ].S ] = team[ i ];

    R(i, n) cout << ans[ i ] << " "; cout << endl;

    return 0;
}

int main(){

    //cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();

}
