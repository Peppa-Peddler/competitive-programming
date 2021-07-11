#include<iostream>
#include<vector>

using namespace std;

#define N 200005

vector<int>adj[N];
vector<int>group[N];
int head[N];

void dfs(int cur, int root){
  if(head[cur] != -1) return;
  head[cur] = root;
  group[root].push_back(cur);
  for(int i = 0; i < adj[cur].size(); i++)
    dfs(adj[cur][i], root);
}

string solve(){
  int n, m, a, b, amount;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  for(int i = 0; i < n; i++) head[i] = -1;
  for(int i = 0; i < n; i++){
    if(head[i] != -1) continue;
    dfs(i, i);
    amount = group[i].size();
    for(int j = 0; j < amount; j++)
      if(adj[group[i][j]].size() != amount - 1) return "NO";
  }
  return "YES";
}

int main(){
  cout << solve() << endl;
}
