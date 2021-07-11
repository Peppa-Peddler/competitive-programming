#include <iostream>

using namespace std;

int solve(){
  int n;
  int nums[200005];
  cin >> n;
  int eqs = 0;
  for(int i = 0; i < n; i++){
    cin >> nums[i];
    eqs += nums[i] == i + 1;
  }

  if(eqs == n) return 0;
  if(eqs == 0) return 1;

  int left = 0, right = n - 1;
  for(; left < n; left++) if(nums[left] != left+1) break;
  for(; right >= 0; right--) if(nums[right] != right+1) break;
  right = n - 1 - right;
  eqs -= right + left;

  if(eqs == 0) return 1;
  return 2;

}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << solve() <<endl;
  }
}
