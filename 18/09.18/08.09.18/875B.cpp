#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >


using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  vi input(n+1);
  cout<<1<<" ";
  
  int last_taken = n+1;
  bool taken[n+1];
  for(int i=0;i<=n;i++)taken[i] = false;
  for(int i=1;i<=n;i++){
    cin>>input[i];
    taken[input[i]] = true;
    if(input[i]==last_taken-1){
      int index = input[i];
      while(taken[index]) index--;
      last_taken = index+1;
    }
    cout<<(i+1)-(n-last_taken+1)<<" ";
  }
  cout<<endl;
}
