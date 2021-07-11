#include <iostream>

using namespace std;

string solve(){
  string s, e;
  cin >> s >> e;
  bool a = true, b = true;
  for(int i = 0; i < s.size(); i++)
    if(s[i]=='1') b  = false;
  for(int i = 0; i < e.size(); i++)
    if(e[i]=='1') a = false;
  return a == b and s.size() == e.size() ? "YES":"NO";
}

int main(){
  cout << solve() << endl;
}
