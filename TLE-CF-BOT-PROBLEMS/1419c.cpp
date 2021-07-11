#include <iostream>

using namespace std;

int solve(){
  int n, x;
  cin >> n >> x;
  x += 0;
  int sum = 0, val, count = 0;
  for( int i = 0; i < n; i ++ ){
    cin >> val;
    sum += val;
    count += val == x;
  }
  if(count == n) return 0;
  if(sum == x*n or count) return 1;
  return 2;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << solve() << endl;
  }
}
