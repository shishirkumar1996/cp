#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >
#define lld long long int
#define pr pair< int, int >
#define vpr vector< pr >

using namespace std;


int main(){

  int n;
  cin>>n;
  vs input(n);
  for(int i = 0;i<n;i++) cin>>input[i];

  map< pr,int > process;
  vpr temp;
  for(int i = 0;i<n;i++){
    int open = 0,closed = 0;
    stack< char > mid;
    for(int j = 0;j<input[i].size();j++)
      if(input[i][j]=='(') mid.push(input[i][j]);
      else if(input[i][j]==')') {
        if(mid.size()) mid.pop();
        else closed++;
      }
      open = mid.size();
      pr x = make_pair(open,closed);
      process[x]++;
      temp.push_back(x);
  }
  lld ans = 0;
  
  for(int i = 0;i<n;i++){
    pr x = temp[i];
    if(x.first && x.second) continue;
    
    if(!x.second){
      lld num = process[make_pair(x.second,x.first)];
      ans += num;
    }
  }
  cout<<ans<<endl;
}
