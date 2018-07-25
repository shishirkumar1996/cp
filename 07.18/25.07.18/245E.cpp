#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

int main(){

  string input;
  cin>>input;
  int n= input.length();
  
  stack< int > process;
  
  int ans = 0;
  for(int i=0;i<n;i++){
    if(input[i] == '+'){process.push(i);ans = max(ans,(int)process.size());}
    else if(input[i]=='-'){
      if(process.size())process.pop();
      else ans++;
    }
  }
  cout<<ans<<endl;


}
