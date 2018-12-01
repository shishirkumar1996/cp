#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 200007
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  string input;
  cin>>input;
  int length = 0,last_zero = -1;

  vii output(NUM);
  for(int i=0;i<input.length();i++){
    if(input[i]=='0'){
      output[++last_zero].push_back(i+1);
      length = max(length,last_zero+1);
    } else{
      if(last_zero==-1){ cout<<-1<<endl;return 0;}
      output[last_zero--].push_back(i+1);
    }
  }
  if(last_zero != length-1) {cout<<-1<<endl;return 0;}
  
  cout<<length<<endl;
  for(int i=0;i<length;i++){
    cout<<output[i].size()<<" ";
    for(int j=0;j<output[i].size();j++)cout<<output[i][j]<<" ";
    cout<<'\n';
  }
}
