#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n,k;
  string input;
  cin>>n>>k>>input;
  
  vi num(n+1);
  num[0] = 0;
  for(int i=0;i<n;i++)num[i+1] = num[i]+(input[i]=='0'?1:0);
  
  int ans = INT_MAX;
  for(int i=0;i<n;i++){
    int index = lower_bound(num.begin(),num.end(),num[i]+k+1)-num.begin();
    int index1 = lower_bound(num.begin(),num.end(),num[i]+(k+3)/2)-num.begin();
    int index2 = lower_bound(num.begin(),num.end(),num[i]+(k+1)/2)-num.begin();
    if(index==n+1)break;
    int num1 = max(index1-i-1,index-index1);
    ans = min(ans,num1);
    int num2 = max(index2-i-1,index-index2);
    ans = min(ans,num2);
    cout<<i<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
}
