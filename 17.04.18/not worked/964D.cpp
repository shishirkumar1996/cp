#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;


void calc(int n,vii input){

  vi output;
  bool visited[n];
  memset(visited,false,n);
  
  int flag = 0;
  stack< int > dfs;
  for(int i = 1;i<=n;i++)
    if(input[i].size()%2 == 0){
      flag = 1;
      dfs.push(i);
      break;
    }
    
  if(!flag){
    cout<<"NO"<<endl;
    return;
  }
    
  while(dfs.size()){
    int top  = dfs.top();
    visited[top] = true;
    dfs.pop();
    output.push_back(top);
    int counter = 0;    
    for(int i = 0;i<input[top].size();i++)
      if(!visited[input[top][i]]){
        dfs.push(input[top][i]);
        counter++;
      }
    if(counter%2 != 0){
      cout<<"NO"<<endl;
      return;
    }
  
  }
  
  cout<<"YES"<<endl;
  for(int i =0;i<output.size();i++)
    cout<<output[i]<<endl;
}

int main(){

  int n;
  cin>>n;
  vii input(n+1);
  for(int i =1;i<=n;i++){
    int num;
    cin>>num;
    if(num > 0){
      input[num].push_back(i);
      input[i].push_back(num);
    }
  
  }
  calc(n,input);
  

}
