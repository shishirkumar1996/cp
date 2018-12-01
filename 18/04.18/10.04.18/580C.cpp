#include<bits/stdc++.h>

#define lli long long int
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >

using namespace std;


int calc(int n,int m,vii input,vi cat){
  
  int count = 0;
  
  priority_queue< pr > pr_queue;
  pr start;
  start.first = 0;
  start.second = cat[0];
  bool visited[n];
  memset(visited,false,n);
  pr_queue.push(start);
  
  while(pr_queue.size()){
    pr top = pr_queue.top();
    pr_queue.pop();
    visited[top.first] = true;
    if(top.second > m)
      continue;
    int flag = 0;
    for(int i = 0;i<input[top.first].size();i++){
      if(visited[input[top.first][i]] == true)
        continue;
      flag = 1;
      int ct =  cat[input[top.first][i]];
      int num = (ct==1)?top.second+ct:0;
      pr next;
      next.first = input[top.first][i];
      next.second = num;
      pr_queue.push(next);
    }
    if(!flag)
      count++;
  }
  
  return count;
}


int main(){
  
  int n,m;
  cin>>n>>m;
  vi cat;
  for(int i = 0;i<n;i++){
    int num;
    cin>>num;
    cat.push_back(num);
  }
  
  vii input;
  input.resize(n);
  for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    input[a-1].push_back(b-1);
    input[b-1].push_back(a-1);
  }
  

  cout<<calc(n,m,input,cat)<<endl;

}


