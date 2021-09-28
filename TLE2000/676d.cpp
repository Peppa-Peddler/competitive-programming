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

bool dist[N3][N3][4] = {};
string lab[N3][N3][4];

LL solve(){

  cin >> n >> m;
  string s, val;
  char c;

  R(i, n){
    cin >> s;
    R(j, m){
      c = s[ j ];
      if( c == '+' ){ lab[ i ][ j ][0] = "1111"; }
      else if( c == '-' ){ lab[ i ][ j ][0] = "1010"; }
      else if( c == '|' ){ lab[ i ][ j ][0] = "0101"; }
      else if( c == '^' ){ lab[ i ][ j ][0] = "0100";}
      else if( c == '>' ){ lab[ i ][ j ][0] = "0010"; }
      else if( c == '<' ){ lab[ i ][ j ][0] = "1000"; }
      else if( c == 'v' ){ lab[ i ][ j ][0] = "0001"; }
      else if( c == 'L' ){ lab[ i ][ j ][0] = "0111"; }
      else if( c == 'R' ){ lab[ i ][ j ][0] = "1101"; }
      else if( c == 'U' ){ lab[ i ][ j ][0] = "1011"; }
      else if( c == 'D' ){ lab[ i ][ j ][0] = "1110"; }
      else { lab[ i ][ j ][ 0 ] = "0000"; }
      R(z, 3){
        val = lab[ i ][ j ][ z ];
        rotate( val.rbegin(), val.rbegin() + 1, val.rend() );
        lab[ i ][ j ][ z + 1 ] = val;
      }

    }
  }

  queue <vector<int>> Q;
  int x , y;
  cin >> x >> y;
  x--, y--;
  Q.push(vector<int>({0,0,x,y}));
  int xt, yt;
  cin >> xt >> yt;
  xt--, yt--;
  VI to;
  string Qt, Qn;
  int d, r;
  while( !Q.empty() ){
    to = Q.front();
    Q.pop();
    x = to[ 2 ];
    y = to[ 3 ];
    d = to[ 0 ];
    r = to[ 1 ]%4;
    if( x == xt and y == yt ) return d;
    if( dist[ x ][ y ][ r ] ) continue;
    dist[ x ][ y ][ r ] = true;
    Qt = lab[ x ][ y ][ r ];
    if( x ){
      Qn = lab[ x - 1 ][ y ][ r ];
      if( Qn[ 3 ] == '1' and Qt[ 1 ] == '1')
          Q.push(vector<int>({d + 1, r ,x - 1,y}));
    }
    if( x < n - 1 ){
      Qn = lab[ x + 1 ][ y ][ r ];
      if( Qn[ 1 ] == '1' and Qt[ 3 ] == '1' )
        Q.push(vector<int>({d + 1, r ,x + 1,y}));
    }
    if( y ){
      Qn = lab[ x ][ y - 1 ][ r ];
      if( Qn[ 2 ] == '1' and Qt[ 0 ] == '1' )
        Q.push(vector<int>({d + 1, r , x , y - 1}));
    }
    if( y < m - 1 ){
      Qn = lab[ x ][ y + 1 ][ r ];
      if( Qn[ 0 ] == '1' and Qt[ 2 ] == '1' )
          Q.push(vector<int>({d + 1, r , x , y + 1}));
    }
    Q.push(vector<int>({d + 1, r + 1, x, y}));
  }
  return -1;
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  //cin >> t;
  while(t--) cout << solve() << endl;
  //while(t--) solve();

}
