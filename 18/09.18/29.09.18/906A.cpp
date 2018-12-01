#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int n;
  cin>>n;
  
  int possible[26];
  for( int i=0;i<26;i++) possible[i] = 1;
  
  int num_possible = 26;
  int ans = 0;
  for(int i=1;i<n;i++){
    char c;
    string temp;
    cin>>c>>temp;
    if(c=='.'){
      for(int j=0;j<temp.size();j++){
        if(possible[temp[j]-'a']) num_possible--;
        possible[temp[j]-'a'] = 0;
      } 
    } else if(c=='!'){
      if(num_possible==1){ ans++;continue; }
        for(int j=0;j<26;j++){
          int flag = 0;
          for(int k=0;k<temp.size();k++)if(j==temp[k]-'a'){ flag = 1;break; }
          if(!flag){
            if(possible[j]) num_possible--;
            possible[j] = 0;
          }
        }
    } else if(c=='?'){
      if(num_possible==1) ans++;
      else{
        if(possible[temp[0]-'a']) num_possible--;
        possible[temp[0]-'a'] = 0;
      }
    }
  }
  char c;
  string temp;
  cin>>c>>temp;
  cout<<ans<<endl;
  
}
