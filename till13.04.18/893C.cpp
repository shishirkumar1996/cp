#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define vl vector < lld >
#define MAXM 100000000000
using namespace std;


lld calc(int n,int m,vl coins,vii input){

  lld amount = 0;
  
  bool visited[n+1];
  memset(visited,false,n+1);
  
  for(int i = 1;i<=n;i++){
    
    if(visited[i])
      continue;
    lld minm = MAXM;
    stack< int > person;
    person.push(i);
    while(person.size()){
      
      int t =  person.top();
      person.pop();
      visited[t] = true;
      minm= min(minm,coins[t]);
      for(int j = 0;j<input[t].size();j++){
        int next= input[t][j];
        if(!visited[next])
          person.push(next);
      }
    }
//    cout<<minm<<" "<<i<<endl;
    amount += minm;  
  }
  return amount;
}

int main(){

  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vl coins;
  vii input;
  coins.resize(n+1);
  input.resize(n+1);
  for(int i = 1;i<=n;i++)
  {
    lld num;
    cin>>num;
    coins[i] = num;
  }
  for(int i = 1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }
  
  cout<<calc(n,m,coins,input)<<endl;
}
