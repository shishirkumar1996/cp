#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  string input;
  cin>>input;
  
  if(n==1){cout<<"Yes"<<endl;return 0;}
  map< char,int > process;
  for(int i=0;i<input.size();i++){
    process[input[i]]++;
    if(process[input[i]]==2){cout<<"Yes"<<endl;return 0;}
  }
  cout<<"No"<<endl;

}
