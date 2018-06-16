#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false); cin.tie(0);


using namespace std;

int main(){

  faster
  int n,k;
  cin>>n>>k;
  string input;
  cin>>input;
  string output = input;
  
  map< char, int > set;
  vector< char  >  process;
  for(int i =0;i<input.size();i++) {
    if(!set[input[i]])
      process.push_back(input[i]);
    set[input[i]] = 1;
  }

  sort(process.begin(),process.end());
  
  if(k>n){
    int diff = k-n;
    while(diff--) output += process[0];    
    cout<<output<<endl;
    return 0;
  }
  output = output.substr(0,k);
  
  for(int i = k-1;i>=0;i--){
    
    int flag = 0;
    int index = 0;
    for(int j = 0;j<process.size();j++)
      if(process[j]==output[i]) index =j;
      
      if(index < process.size()-1){
        output[i] = process[index+1];
        break;
      }
      output[i] = process[0];    
  }
  cout<<output<<endl;
}

