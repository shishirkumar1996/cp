#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >


using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  string input;
  cin>>input;
  
  map< char , int > process;
  for(int i= 0;i<n;i++) process[input[i]]++;
  
  char index = 'a';
  while(k){
    if(process[index]>0){
      int temp = min(process[index],k); 
      process[index] = process[index] - temp;
      k = k-temp;
      }
    else index++;
  }

  bool absent[n];
  for(int i = 0;i<n;i++) absent[i] = false;
  
  for(int i=n-1;i>=0;i--) 
  if(process[input[i]]) process[input[i]]--;
  else absent[i] = true;

  for(int i= 0;i<n;i++)if(!absent[i]) cout<<input[i];
  cout<<endl;

}
