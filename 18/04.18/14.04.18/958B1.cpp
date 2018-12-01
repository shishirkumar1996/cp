#include<bits/stdc++.h>

#define vi vector< int >
#define vii vector< vi >
using namespace std;


int calc(int n,vii input){

  int res = 0;
  for(int i = 1;i<=n;i++)
    if(input[i].size()==1)
      res++;
  return res;
}

int main(){
  
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vii input;
  input.resize(n+1);
  
  for(int i =1;i<n;i++){
    int a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }
  cout<<calc(n,input)<<endl;

}
