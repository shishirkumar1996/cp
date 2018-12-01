#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int first[] = {1,1,1,0,0,0,-1,-1,-1};
  int second[] = {1,0,-1,1,0,-1,1,0,-1};

  int n;
  cin>>n;
  
  vi input(n);
  for(int i=0;i<n;i++) cin>>input[i];
  
  int change;
  int ans = INT_MAX;
  for(int i = 0;i<9;i++){
    lld diff = (input[0]+first[i]-(input[1]+second[i]));
    lld temp = input[i]+second[i];
    if(abs(first[i])==1 && abs(second[i])==1) change = 2;
    else if(abs(first[i])==1 || abs(second[i])==1) change = 1;
    else change = 0;

    temp = input[1]+second[i];
//    cout<<diff<<endl;
    int flag = 1;
    for(int j=2;j<n;j++){
      if(input[j]+1 == temp-diff || input[j]-1 == temp-diff){
        change ++;
        if(input[j]+1 == temp-diff) temp = input[j]+1;
        else temp = input[j]-1;
      }else if(input[j] == temp-diff){  temp = input[j];}
      else {flag = 0;break;}
//      cout<<j<<" "<<temp<<endl;
    }
    if(flag) ans = min(ans,change);
  }
  if(ans==INT_MAX) cout<<-1<<endl; else cout<<ans<<endl;
}
