#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int n,m,p;
  cin>>n>>m>>p;
  
  string op;
  char input[n+2];
  for(int i=1;i<=n;i++) cin>>input[i];
  cin>>op;
  
  stack< int > process;
  map< int, int > match;
  int next[n+1],prev[n+1];
  for(int i=0;i<=n+1;i++)next[i] = i+1,prev[i] = i-1;
  
  for(int i=1;i<=n;i++){
    if(input[i] == '(') process.push(i);
    else {
      int top = process.top();
      process.pop();
      match[top] = i; match[i] = top;
    }
  }
  
  int cursor = p;
  for(int i=0;i<op.length();i++){
//    cout<<cursor<<" "<<next[cursor]<<" "<<prev[cursor]<<endl;
    if(op[i] == 'R') cursor = next[cursor];
    else if(op[i] == 'L') cursor = prev[cursor];
    else {
      int x,y;
      if(input[cursor] == '(') x=cursor,y=match[cursor];
      else y = cursor, x = match[cursor];
        int temp = prev[x];
        next[prev[x]] = next[y];
        prev[next[y]] = prev[x];
        if(next[temp]<n) cursor = next[temp]; else cursor = temp;
       
    }
  }
  int index = 0;
  while(next[index]<=n){
    index = next[index];
    cout<<input[index];
  }
  cout<<endl;
}
