#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define VI vector<int>
#define N 10005
#define GRAPH(g) VI g[N]
#define PII pair<int, int>
#define MP make_pair
#define X first
#define Y second

using namespace std;

GRAPH(v);
GRAPH(e);

int vis[N];

void dijkstra(int source){
  memset(vis, -1, sizeof(vis));
  priority_queue<PII>PQ;
  PQ.push(MP(0, source));
  int curr, dist, edge;
  while(!PQ.empty()){
    curr = PQ.top().Y;
    dist = PQ.top().X;
    PQ.pop();
    if( vis[curr] != -1 ) continue;
    vis[curr] = -dist;
    for(int i = 0; i < v[curr].size(); i++){
      edge = -e[curr][i] + dist;
      PQ.push(MP(edge, v[curr][i]));
    }
  }
}

int main(){

  int n, m;
  int a,b,d;

  cin >> n >> m;

  for(int i = 0; i < m; i++){
    cin >> a >> b >> d;
    v[a].push_back(b);
    v[b].push_back(a);
    e[a].push_back(d);
    e[b].push_back(d);
  }

  dijkstra(0);

  for(int i = 0; i < n; i++){
    cout << vis[i] << endl;
  }

}
