#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define MAXM 99999999999

using namespace std;

int main(){

  faster
  lld n,m,num_stair,num_elevator,v,query;
  cin>>n>>m>>num_stair>>num_elevator>>v;
  
  vi elevator(num_elevator);
  vi stair(num_stair);
  for(int i =0;i<num_stair;i++) cin>>stair[i];
    
  for(int i=  0;i<num_elevator;i++) cin>>elevator[i];

  cin>>query;
  sort(elevator.begin(),elevator.end());
  sort(stair.begin(),stair.end());  
    
  for(int i =0;i<query;i++){
    
    lld int_row,int_col,fin_row,fin_col;
    
    cin>>int_row>>int_col>>fin_row>>fin_col;
    if(int_row==fin_row){
      cout<<abs(int_col-fin_col)<<endl;
      continue;
    }
    
    lld ans = MAXM;
    if(num_stair>0){
      lld index = lower_bound(stair.begin(),stair.end(),int_col)-stair.begin();
      if(index != num_stair)  ans = min(ans,abs(stair[index]-int_col)+abs(stair[index]-fin_col)+abs(int_row-fin_row));
      if(index != 0) ans = min(ans,abs(stair[(index-1)] - int_col) + abs(stair[(index-1)]-fin_col)+abs(int_row-fin_row));
    }
    if(num_elevator >0){
      lld index = lower_bound(elevator.begin(),elevator.end(),int_col)-elevator.begin();
      if(index != num_elevator)  ans = min(ans,abs(elevator[index]-int_col)+abs(elevator[index]-fin_col)+(abs(int_row-fin_row)+v-1)/v);
      if(index != 0) ans = min(ans,abs(elevator[(index-1)] - int_col) + abs(elevator[(index-1)]-fin_col)+(abs(int_row-fin_row)+v-1)/v);
    }
    
    cout<<ans<<endl;
  }


}
