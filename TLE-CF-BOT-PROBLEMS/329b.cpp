#include <iostream>
#include <queue>

using namespace std;

#define PII pair<int, int>
#define REP(i,n) for(int i = 0; i < n; i++)
#define MP(a,b) make_pair(a,b)

#define X first
#define Y second

int main(){
  queue <pair<PII, int>> cola;
  char forest[1003][1003];
  int path[1003][1003];
  int n,m, dis, x, y;
  PII source;
  PII self;
  pair<PII,int> curr;
  cin >> n >> m;
  REP(i,n) REP(j,m) {
    cin >> forest[i][j];
    path[i][j] = -1;
    if(forest[i][j] == 'E') source = MP(i,j);
    if(forest[i][j] == 'S'){
      self = MP(i,j);
      forest[i][j] = '0';
    }
  }

  cola.push(MP(source, 0));

  while(!cola.empty()){
    curr = cola.front();
    cola.pop();
    x = curr.X.X;
    y = curr.X.Y;
    dis = curr.Y;
    if( x < 0 or x == n) continue;
    if( y < 0 or y == m) continue;
    if(path[x][y] != -1) continue;
    if(forest[x][y] == 'T') continue;
    path[x][y] = dis;
    cola.push(MP(MP(x,y+1),dis+1));
    cola.push(MP(MP(x,y-1),dis+1));
    cola.push(MP(MP(x+1,y),dis+1));
    cola.push(MP(MP(x-1,y),dis+1));
  }

  int ans = 0;
  x = self.X;
  y = self.Y;
  int route = path[x][y];

  /*REP(i,n){
    REP(j,m)
      cout << path[i][j];
    cout << endl;
  }*/

  REP(i,n)REP(j,m){
    if(path[i][j] <= route and path[i][j] > 0)
      ans += forest[i][j]-'0';
  }

  cout << ans << endl;


}
