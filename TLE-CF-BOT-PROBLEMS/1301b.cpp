#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)

vector<int>array;
int n;

int abs(int v){
  return v < 0?-v:v;
}

int validate(int k){
  int maxi = 0;
  REP(i,n){
    if(array[i] == -1){
      if(i) maxi = max(maxi, abs(k - array[i-1]));
      if(i < n-1) maxi = max(maxi, abs(k - array[i+1]));
    }
  }
  return maxi;
}

int solve(){
  cin >> n;
  int val, prev=-2, maxi = 0;
  REP(i,n) {
    cin >> val;
    if(val != -1 or prev != -1){
      array.push_back(val);
    }
    if(prev >= 0 and val >= 0){
      maxi = max(maxi, abs(prev - val));
    }
    prev = val;
  }
  n = array.size();

  int l = 0, r = 1e9+1, m1, m2, f1, f2;
  while( r - l > 2){
    m1 = l + (r - l)/3;
    m2 = r - (r - l)/3;
    f1 = max(validate(m1), maxi);
    f2 = max(validate(m2), maxi);
    if(f1>=f2) l = m1;
    else r = m2;
  }

  int l0 = validate(l);
  int l1 = validate(l+1);
  int l2 = validate(l+2);

  if(l1 == min(l0, min(l1, l2)))
    l = l + 1;

  else if(l2 == min(l0, min(l1, l2)))
    l = l + 2;

  cout << max(maxi,validate(l)) <<" "<< l << endl;
  array.clear();
  return 1;
}

int main(){
  int t;
  cin >> t;
  while(t--)
  solve();
}
