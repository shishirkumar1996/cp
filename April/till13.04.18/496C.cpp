#include<bits/stdc++.h>

#define vc vector < char >
#define vcc vector < vc >

using namespace std;

int calc(int n,int m,vcc input){

  int result = 0;
  vector < string > process;
  for(int i = 0;i<n;i++)
    process.push_back("");
  
  for(int j= 0;j<m;j++){
  
    int flag = 1;
    for(int i = 0;i<n-1;i++){
      string first(1,input[i][j]);
      string second(1,input[i+1][j]);
      if(process[i]+first==process[i+1]+second)
        flag = 0;
      else
      if(process[i]+first>process[i+1]+second){
//        cout<<process[i]<<" "<<process[i+1]<<endl;
        flag = -1;
        result++;
        break;
      }
    
    }
    if(flag==1)
      break;
    if(flag == 0){
      for(int l = 0;l<n;l++){
          string add(1,input[l][j]);
          process[l] += add;
        }
    }  
    
  }

  return result;

}

int main(){

  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vcc input;
  input.resize(n);
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      char c;
      cin>>c;
      input[i].push_back(c);
    }
  
  }
  cout<<calc(n,m,input)<<endl;

}
