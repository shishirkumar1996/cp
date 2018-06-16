#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  
  vii input(n);
  for(int i =0;i<n;i++)
    for(int j = 0;j<m;j++){
      int a;
      cin>>a;
      input[i].push_back(a);
    }
    
  for(int i =  0;i<m;i++)
    for(int j =i;j<m;j++){
      vii process = input;
      for(int k = 0;k<n;k++){int temp = process[k][i];process[k][i] = process[k][j];process[k][j] = temp;}  
      
      int flag = 1;
      for(int k = 0;k<n;k++){
        int count = 0;
        for(int l = 0;l<m;l++) if(process[k][l] != l+1) count++;
        if(count>2){flag = 0;break;}
      }
      if(flag){cout<<"YES"<<endl;return 0;}
    }
  cout<<"NO"<<endl;
}
