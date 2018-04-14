#include<bits/stdc++.h>


using namespace std;



string calc(int n,int m,vector< int > input,vector < int >need){

  vector< int > process;
  
  int sum = 0;
  for(int i =0;i<need.size();i++)
    sum += need[i];
  
  int flag;
  for(int i =0;i<n-sum+1;i++){
    process = need;
    flag = 1; 
    for(int j = i;j<i+sum;j++){
      process[input[j]]--;
      if(process[input[j]]<0){
        flag = 0;
        break;
      }
    }
    if(flag)
      return "YES";
  }
  return "NO";

}

int main(){

  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vector< int > input(n);
  vector< int > need(m+1);
  for(int i =0;i<n;i++)
    cin>>input[i];
  
  for(int i =1;i<=m;i++)
    cin>>need[i];

  cout<<calc(n,m,input,need)<<endl;
}
