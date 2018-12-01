#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define pr pair< int , int >

using namespace std;

int main(){
  
  faster
  int k;
  cin>>k;
  vii input(k),process(k);
  map< lld, pr  > num;
  for(int i = 0;i<k;i++){
    int n;
    cin>>n;
    for(int j = 0;j<n;j++){
      lld x;
      cin>>x;
      input[i].push_back(x);process[i].push_back(0);
    }
  }
  for(int i = 0;i<k;i++){
    lld sum = 0;
    for(int j = 0;j<input[i].size();j++) sum+= input[i][j];
    for(int j = 0;j<input[i].size();j++){
      process[i][j] = sum-input[i][j];
      if(num.find(process[i][j]) != num.end()&& num[process[i][j]].first != i+1){
        cout<<"YES"<<endl;
        cout<<num[process[i][j]].first<<" "<<num[process[i][j]].second<<endl;
        cout<<i+1<<" "<<j+1<<endl;
        return 0;
      }else num[process[i][j]] = make_pair(i+1,j+1);
    }
    
  }
  cout<<"NO"<<endl;
}
