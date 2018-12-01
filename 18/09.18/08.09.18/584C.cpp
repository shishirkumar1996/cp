#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){


  int n,t;
  cin>>n>>t;
  string first,second;
  cin>>first>>second;

  int same = 0,different = 0;
  for(int i=0;i<n;i++)if(first[i]==second[i])same++;else different++;
  
  if((different+1)/2>t||t>n){cout<<-1<<endl;return 0;}
  int first_same = n-t,second_same = n-t;
  
  string output(n,' ');
  for(int i=0;i<n;i++)
    if(first[i]==second[i]){
      if(first_same){
        output[i]=first[i];
        first_same--;
        second_same--;
      }else{
        if(first[i]=='a')output[i]='b';else output[i] = 'a';
      }
    }
  
  for(int i=0;i<n;i++){
    if(first[i] != second[i]){
      if(first_same){
        output[i] = first[i]; first_same--;
      }else if(second_same){
        output[i] = second[i]; second_same--;
      }else{
        if(first[i] != 'a' && second[i] != 'a') output[i] = 'a';
        else if(first[i] != 'b' && second[i] != 'b') output[i] = 'b';
        else output[i] = 'c'; 
      }
    }
  }
  cout<<output<<endl;
}
