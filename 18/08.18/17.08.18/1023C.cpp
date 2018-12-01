#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int n,k;
  cin>>n>>k;
  string input;
  cin>>input;
  
  string answer(k,'#');
  int index = 0;
  int diff = (n-k)/2;
  bool rem[n];
  for(int i=0;i<n;i++) rem[i] = false;
  stack< int > process;
  for(int i=0;i<input.size();i++){
    if(input[i]=='('){
      process.push(i);
      if(diff){rem[i] = true;diff--;}
      else {answer[index]='(';index++;}
    } else if(input[i]==')'){
      int top = process.top();
      process.pop();
      if(!rem[top]){answer[index]=')';index++;}
    }
  }
  cout<<answer<<endl;
}
