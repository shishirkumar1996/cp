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
  for(int i=  0;i<n;i++)
    for(int j = 0;j<m;j++){
      char a;
      cin>>a;
      input[i].push_back((a-'0'));  
  }

  vi process(m);
  for(int i = 0;i<m;i++) process[i] = 0;
  
  for(int i =0;i<n;i++)
    for(int j = 0;j<m;j++) process[j] +=  input[i][j];


  for(int i =0;i<n;i++){
    vi mid = process;
    for(int j = 0;j<m;j++) mid[j] -= input[i][j];
    int flag = 1;
    for(int j = 0;j<m;j++)if(mid[j] == 0) {flag = 0;    break;}
    if(flag==1){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}
