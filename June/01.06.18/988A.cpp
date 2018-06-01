#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  faster
  int n,k;
  cin>>n>>k;
  
  vi input(n);
  map< int,int > present;
  vi ans;
  for(int i = 0;i<n;i++){ 
    cin>>input[i];
    if(!present[input[i]]){ans.push_back(i+1); present[input[i]]=1;}
  }

  if(ans.size()<k) cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    for(int i = 0;i<k;i++)cout<<ans[i]<<" ";
    cout<<endl;
  }

}
