#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  faster
  int n,q;
  cin>>n>>q;
  
  int t[q],k[q],d[q];
  
  int busy[n];
  for(int i = 0;i<n;i++) busy[i] = 0;
  
  for(int i = 0;i<q;i++){ 
    cin>>t[i]>>k[i]>>d[i];
    
    int sum = 0;
    for(int j = 0;j<n;j++) if(busy[j]<t[i]) sum++;
    
    if(sum<k[i]){cout<<-1<<endl;continue;}
    
    int ans = 0;sum = 0;
    for(int j = 0;j<n && sum<k[i];j++)if(busy[j]<t[i]){busy[j]=t[i]+d[i]-1,ans += (j+1),sum++;}    
    cout<<ans<<endl;
  }
  
}
