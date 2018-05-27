#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

int main(){
  
  faster
  string input;
  cin>>input;
  
  for(int i = 0;i<input.size();i++)
    if(input[i] != input[input.size()-1-i]){cout<<input.size()<<endl;return 0;}
  
  for(int i = 1;i<input.size();i++) if(input[i] != input[i-1]){
    cout<<input.size()-1<<endl;return 0;
  }
  
  cout<<0<<endl;

}
