#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >

using namespace std;

int main(){

  int t;
  cin>>t;
  
  for(int x =1;x<=t;x++){
    int n,p;
    cin>>n>>p;
    vs input(p);
    for(int i=0;i<p;i++)cin>>input[i];
    vs process;
    for(int i=0;i<p;i++){
      int flag = 1;
      for(int j=0;j<p;j++){
        if(i==j)continue;
        if(input[i].length()>=input[j].length() && input[i].substr(0,input[j].length())==input[j]){flag = 0;break; }
      }
      if(flag)process.push_back(input[i]);
    }
    lld ans = pow(2,n);
    for(int i=0;i<process.size();i++){
      ans -= pow(2,n-process[i].size());
    }
    cout<<"Case #"<<x<<": "<<ans<<'\n';
  }

}
