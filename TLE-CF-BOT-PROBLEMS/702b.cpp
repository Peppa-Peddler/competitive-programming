#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

  int vals[100005];
  int frec[100005];
  vector<int>v;
  int n;

  cin >> n;
  for(int i=0;i<n;i++) cin >> vals[i];
  sort(vals, vals + n);

  int r = -1;

  for(int i=0;i<n;i++){
    if(i==0 or vals[i-1]!=vals[i]) {
      frec[++r] = 1;
      v.push_back(vals[i]);
    }
    else frec[r] += 1;
  }

  long long exps[33];
  exps[0] = 1;
  for(int i=1; i < 33; i++ ){
    exps[i] = exps[i-1]*2;
  }

  long long ans = 0;

  for(int i = 0; i < v.size(); i++){
    for(int j=1; j < 33; j++ ){
      long long value = exps[j] - v[i];
      int l = 0, r = v.size(), mid;
      while( r - l > 1 ){
	mid = (l + r )/ 2;
	if(v[mid] <= value) l = mid;
	else r = mid;
      }
      if( v[l] != value ) continue;

      ans +=(1LL*frec[i])*(1LL*frec[l] - (value == v[i]));

    }
  }

  cout << ans / 2 << endl;
}
