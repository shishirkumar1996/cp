#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >
#define NUM 9

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  vs input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  map< string, int > individual[n],complete;
  
  for(int i=0;i<n;i++){
    for(int l=1;l<=NUM;l++){
      for(int j=0;j<=NUM-l;j++){
        string x= input[i].substr(j,l);
        individual[i][x]++;
        complete[x]++;
      }
    }
  }
  
  for(int i=0;i<n;i++){
    int flag = 0;
    for(int l=1;l<=NUM;l++){
      for(int j=0;j<=NUM-l;j++){
        string x= input[i].substr(j,l);
        if(individual[i][x]==complete[x]){
          flag = 1;
          cout<<x<<endl;
          break;
        }
      }
      if(flag)break;
    }
  }

}
