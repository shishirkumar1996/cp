#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  int n;
  cin>>n;
  
  vi input(n);
  map< lld,int > left_sum,right_sum;
  vi left(n),right(n);
  vi process;
  for(int i=0;i<n;i++) cin>>input[i];
  
  for(int i=0;i<n;i++){ left_sum[input[i]]++;left[i] = left_sum[input[i]];}
  
  for(int i=n-1;i>=0;i--) {right_sum[input[i]]++; right[i] = right_sum[input[i]]; }
  
  vi temp = right;
  sort(right.begin(),right.end());
  lld ans = 0;
  for(int i=0;i<n;i++){
    process.push_back(temp[i]);
    sort(process.begin(),process.end());
    int index1 = lower_bound(right.begin(),right.end(),left[i])-right.begin();
    int index2 = lower_bound(process.begin(),process.end(),left[i])-process.begin();
    ans += (index1-index2);
    
  }
  cout<<ans<<endl;
}
