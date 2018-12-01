#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  
  vector< string > output;
  int i=0,n=input.length();
  while(i<n){
    string process = "";
    if(input[i] == '@'){cout<<"No solution"<<endl;return 0;}
    while(i<n && input[i] != '@'){
      string x(1,input[i]);
      process += x;
      i++;
    }
    if(i==n){
      if(output.size()==0){cout<<"No solution"<<endl;return 0;}
      output[output.size()-1] += process;break;
    }
    string x(1,input[i]);
    process += x;
    i++;
    if(i==n || input[i]=='@'){
      cout<<"No solution"<<endl;return 0;}  
    
    x[0] = input[i];
    process += x;
    i++;
    output.push_back(process);
    }
    for(int i=0;i<output.size()-1;i++)cout<<output[i]<<",";
    cout<<output[output.size()-1]<<endl;
}
