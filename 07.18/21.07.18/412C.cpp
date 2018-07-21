#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >

using namespace std;


int main(){

  int n;
  cin>>n;
  
  vs input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  string output ="";
  
  for(int j=0;j<input[0].length();j++){
    int flag = 1;
    char x=' ';
    for(int i=0;i<n;i++){
      if(input[i][j] == '?') continue;
      if(x>='a' && x<='z'){
        if(x!=input[i][j]){
          output += "?";
          flag = 0;
          break;
        }
      } else x = input[i][j];
      
    }if(flag){
      if(!(x>='a' && x<='z')) x = 'a'; 
      string s(1,x);
      output += s;  
    }
  }
  cout<<output<<endl;

}
