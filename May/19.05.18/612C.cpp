#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int same(char c,char d){

  return((c=='<' && d== '>')||(c=='{' && d== '}')|| (c=='[' && d== ']') || (c=='(' && d==')'));
}

int open(char c){
  
  return( c=='<'||c=='{'||c=='['||c=='(');
}

int close(char c){ 
  return( c=='>'||c=='}'||c==']'||c==')');
}

int main(){
  
  faster
  string input;
  cin>>input;
  
  int count = 0;
  stack< char > process;
  
  for(int i = 0;i<input.size();i++){
    if(open(input[i])) process.push(input[i]);
    else
    {
      if(process.size()){
        if(!same(process.top(),input[i])) count++;
        process.pop();
      }
      else {
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }
  if(process.size()){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<count<<endl;

}
