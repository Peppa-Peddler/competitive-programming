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

int a[N5];
int b[N5];

LL solve(){
    cin >> n;
    R(i, n) cin >> a[i];
    R(i, n) cin >> b[i];
    set <int> ans;
    LL d = 0;
    LL dmin = LLONG_MAX;
    R(i, n){
      d += a[i] - b[i];
      dmin = min(d, dmin);
    }
    if( dmin == 0 ) ans.insert(0);
    R(i, n - 1){
      dmin -= a[i] - b[i];
      if( dmin == 0 ) ans.insert(i + 1);
    }

    d = 0; dmin = LLONG_MAX;
    R(i, n){
      d += a[(n - i)%n] - b[n - i - 1];
      dmin = min(d, dmin);
    }
    if( dmin == 0 ) ans.insert(0);
    R(i, n - 1){
      dmin -= a[(n - i)%n] - b[n - i - 1];
      if( dmin == 0 ) ans.insert(n - i  - 1);
    }

    cout << len(ans) << endl;

    for(auto it = ans.begin(); it != ans.end() ; it++ )
      cout << *it + 1 << " ";
    cout << endl;

    return 0;

}

int main(){

    //cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();

}
