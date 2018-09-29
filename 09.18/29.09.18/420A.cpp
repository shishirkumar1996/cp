#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int check[] = {'B','C','D','E','F','G','J','K','L','N','P','Q','R','S','Z'};
  
  int size = 15;
  string input;
  cin>>input;
  for(int i=0;i<input.size();i++)
    for(int j=0;j<size;j++)if(input[i]==check[j]){cout<<"NO"<<endl;return 0;}
  
  for(int i=0;i<input.size()/2;i++)if(input[i] != input[input.size()-1-i]){
    cout<<"NO"<<endl;return 0;
  }
  cout<<"YES"<<endl;

}
