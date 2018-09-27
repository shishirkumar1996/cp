#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  int n;
  cin>>n;
  vi input(n);
  
  vii process(101);
  string output(n,' ');
  int ones = 0,threes = 0;  
  for(int i=0;i<n;i++){
    cin>>input[i];
    process[input[i]].push_back(i);
  }
  for(int i=1;i<=100;i++){
    if(process[i].size()==1)ones++;
    else if(process[i].size()>=3) threes++;
  }
  if(ones%2 == 1 && threes == 0){ cout<<"NO"<<endl;return 0;}
  int flag = 0;
  if(ones%2==1){
    for(int i=1;i<=100;i++){
      if(process[i].size()>=3){
        flag = i;
        output[process[i][0]] = 'B';
        for(int j=1;j<process[i].size();j++)
          output[process[i][j]] = 'A';
      }
      if(flag)break;  
    }
  }
  int turn = 0;
  for(int i=1;i<=100;i++){
    if(process[i].size()==1){
      if(turn==0) output[process[i][0]] = 'A';
      else output[process[i][0]] = 'B';
      turn = turn^1;  
    } else if(flag==i)continue;
    else{
      for(int j=0;j<process[i].size();j++)output[process[i][j]] = 'A';
    }
  }
  cout<<"YES"<<endl;
  cout<<output<<endl;
}
