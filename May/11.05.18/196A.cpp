#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);


using namespace std;

int main(){

  string input;
  cin>>input;
  
  string  output = "";
  char maxm = input[input.size()-1];
  output += input[input.size()-1];
  for(int i = input.size()-2;i>=0;i--) 
    if(input[i] >= maxm) {
      output = input[i]+output;
      maxm = input[i];
    }
  cout<<output<<endl;

}
