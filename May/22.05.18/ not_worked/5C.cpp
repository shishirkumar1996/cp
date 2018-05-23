#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);


using namespace std;

int main(){
  
  faster
  string input;
  cin>>input;
  
  int c[input.size()],d[input.size()];
  for(int i = 0;i<input.size();i++) c[i] = d[i] = 0;
  
  stack< char > process;
  
  for(int i = 0;i<input.size();i++){
    if(input[i] == '(') process.push(i);
    else{
      if(process.size()){
        int top = process.top();
        process.pop();
        d[i] = top;
        c[i]  = i-top+1;
        if(top>0 && input[top-1] == ')') c[i] += c[top-1];
      }
    }
  }
  
  int max = 0,num = 1;
  
  for(int i = 0;i<input.size();i++){
      if(max>0 && max==c[i]) num++;
      else if(max<c[i]) max = c[i],num=1;
  }
  cout<<max<<" "<<num<<endl;
}
