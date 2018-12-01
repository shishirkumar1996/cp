#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  faster
  int n,m,p;
  cin>>n>>m>>p;

  lld a[n],b[m];
  int ans=0;
  vi output;
  map< lld,int > process;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++){ cin>>b[i];process[b[i]]++; }
  
  for(int i=0;i<p;i++){
    int tot=0;
    if(i+(m-1)*p>=n) break;
    for(int j=i;j<n+m*p;j+=p){
      if(j<n){
        process[a[j]]--;
        if(process[a[j]]>=0)tot++;
      }
      if(j-m*p>=0){
        process[a[j-m*p]]++;
        if(process[a[j-m*p]]>0)tot--;
      }
      if(tot==m){
        ans++;
        output.push_back(j-(m-1)*p);
      }
    }
  }
  sort(output.begin(),output.end());
  cout<<ans<<endl;
  for(int i=0;i<output.size();i++)cout<<output[i]+1<<" ";
  cout<<endl;
}
