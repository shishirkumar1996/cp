#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  vii input(n);
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    for(int j=0;j<m;j++){
      int a;
      cin>>a;
      input[i].push_back(a);
    }
    sort(input[i].begin(),input[i].end());
  }
  
  for(int i=0;i<n;i++){
    int flag = 1;
    for(int j=0;j<n;j++){
      if(i==j)continue;
      int n = input[i].size(),m=input[j].size();
      int index1 = 0,index2 = 0;
      while(index1<n && index2<m){
        if(input[i][index1]<input[j][index2])index1++;
        else if(input[i][index1]==input[j][index2]){index1++;index2++;}
        else if(input[i][index1]>input[j][index2])break;
      }
      if(index2==m){flag = 0;break;} 
    }
    if(!flag)cout<<"NO"<<endl; else cout<<"YES"<<endl;
  }
}
