#include<bits/stdc++.h>
#define  faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

int main(){

  int n;
  cin>>n;
  string input;
  cin>>input;
  
  int turn = 0;
  
  int count = 0;
  for(int i = 0;i<input.size();i++)
    count += (input[i]-'0');
  
  if((n+1)/2 > count){
    cout<<"No"<<endl;
    return 0;
  }
  
  for(int i =0;i<n;i++){
    if(input[i]-'0' ==1 && turn == 1){
      cout<<"No"<<endl;
      return 0;
    }
    turn = input[i]-'0';
  }
  cout<<"Yes"<<endl;
  

}

