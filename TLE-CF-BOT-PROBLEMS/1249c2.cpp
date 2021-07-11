#include<iostream>
#include<vector>

using namespace std;

long long solve(){
  long long n;
  cin >> n;
  long long bit;
  long long c = n;
  bool flg = true;

  vector<int>d;

  while(c){
    bit = (c%3LL);
    d.push_back(bit);
    c /= 3LL;
    if( bit == 2 ) flg = false;
  }
  d.push_back(0);
  if(flg) return n;

  int r = d.size() - 1;

  while(d[r]!=2)r--;
  while(d[r]!=0)r++;

  long long ans = 1;

  for(int i=0; i < r; i++) ans*=3LL;
  long long trit = ans*3LL;
  for(int i=r+1; i < d.size() ; i++, trit*=3LL)
    ans += trit*(1LL*d[i]);

  return ans;

}

int main(){
  int q;
  cin >> q;
  while(q--){
    cout << solve() << endl;
  }
}
