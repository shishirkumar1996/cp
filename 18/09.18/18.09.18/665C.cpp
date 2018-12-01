#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  int n = input.length();
  
  for(int i=1;i<n;i++){
    if(input[i]==input[i-1]){
      if(input[i-1]!='a' && input[i+1] != 'a') input[i] = 'a';
      else if(input[i-1]!='b' && input[i+1] != 'b') input[i] = 'b';
      else input[i] = 'c';
    }
  }
  cout<<input<<endl;
}
