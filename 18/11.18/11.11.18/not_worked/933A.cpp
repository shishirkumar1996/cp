#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  faster;
  int n;
  cin>>n;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  vi high(n),low(n),last_high(n);
  
  for(int i=0;i<n;i++)last_high[i] = i;
  for(int i=0;i<n;i++){
    int index = i;
    while(i<n-1 && input[index+1]>=input[index]){
      index++;
      last_high[index] = min(last_high[index],i);
    }
    high[i] = index;
    index = i;
    while(i<n-1 && input[index+1]<=input[index])index++; 
    low[i] = index;
  }
//  for(int i=0;i<n;i++)cout<<high[i]<<" "<<low[i]<<" "<<last_high[i]<<'\n';
  
  int maxm = 0;
  for(int i=0;i<n;i++){
    int l = low[i]-i+1;
    if(i>0 && input[i-1]<=input[low[i]])l += (i-1-last_high[i-1]+1);
    if(low[i]<n-1 && input[i]<=input[low[i]+1]) l+= (high[low[i]+1]-low[i]-1+1);
    maxm = max(maxm,l);
    cout<<i<<" "<<l<<'\n';
  }
  cout<<maxm<<endl;
}
