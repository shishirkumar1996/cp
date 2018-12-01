#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n,k;
  cin>>n>>k;
  
  string input;
  cin>>input;
  
  if(k==2){
    int diff1 = 0,diff2= 0;
    string process1="",process2 = "";
    for(int i= 0;i<input.size();i++){
      if(input[i] != ('A'+(i%2))) diff1++;
      if(input[i] != ('A'+((i+1)%2))) diff2++;
      process1 += 'A'+(i%2);
      process2 += 'A'+((i+1)%2);
    }
    if(diff1<diff2)cout<<diff1<<endl<<process1<<endl;
    else cout<<diff2<<endl<<process2<<endl;
  
    return 0;
  }
  
  
  int ans = 0;
  for(int i = 1;i<input.size();i++){
    if(input[i] == input[i-1]){
      int index = 1;
      char col;
      while(index<=k){
        col = index-1+'A';
        if(col==input[i-1]|| (i<input.size()-1 && col==input[i+1]))index++;
        else break;
      }
      ans++;
      input[i] = col; 
    }
  }
  cout<<ans<<endl;
  cout<<input<<endl;

}
