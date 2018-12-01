#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  faster
  string input;
  cin>>input;
  int n=input.length();
  vi straight(n,0),opposite(n,0);
  
  for(int i=0;i<n;i++){
    if(i==0) opposite[i] = 1;
    else if(input[i] != input[i-1])opposite[i] = opposite[i-1]+1;
    else opposite[i] = 1;
  }
  
  for(int i=n-1;i>=0;i--){
    if(i==n-1)straight[i] = 1;
    else if(input[i]!=input[i+1])straight[i] = straight[i+1]+1;
    else straight[i] = 1;
  }
  int ans = 0;
  for(int i=0;i<n;i++)ans = max(ans,straight[i]);  
  for(int i=0;i<n-1;i++){
    ans = max(ans,opposite[i]);
    ans = max(ans,straight[i+1]);
    if(input[0]!=input[n-1]){
      int a = min(straight[0],i+1);
      int b = min(opposite[n-1],n-1-i);
      ans = max(ans,a+b);
    }
//    cout<<i<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
}
