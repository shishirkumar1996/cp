#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){
  
  int n,m,k,p;
  cin>>n>>m>>k>>p;
  
  set< lld > row_sum;
  set< lld > col_sum;
  lld col_dec = 0,row_dec = 0;
  
  vii input(n);
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    int a;cin>>a;input[i].push_back(a);  
  }
  
  lld ans = 0;
  for(int i=0;i<n;i++){
    lld sum =0;
    for(int j=0;j<m;j++) sum += input[i][j];
    row_sum.insert(-sum);
  }
  
  for(int j=0;j<m;j++){
    lld sum = 0;
    for(int i=0;i<n;i++) sum += input[i][j];
    col_sum.insert(-sum);
  }
  
  for(int i=0;i<k;i++){
    lld a  = -(*row_sum.begin());
    lld b = -(*col_sum.begin());
//    cout<<a-row_dec<<" "<<b-col_dec<<endl;
    if(a-row_dec>b-col_dec){
      row_sum.erase(row_sum.begin());
      ans += (a-row_dec);  
      col_dec += p;
      row_sum.insert(-(a-m*p));
    } else {
      col_sum.erase(col_sum.begin());
      ans += (b-col_dec);
      row_dec += p;
      col_sum.insert(-(b-n*p));
    }
  }
  cout<<ans<<endl;
}
