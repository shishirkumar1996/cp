#include<bits/stdc++.h>
#define faster ios::sync_with_base(stdio);cin.tie(0);
#define lld long long int
#define vi vector< lld >


using namespace std;

int main(){


  lld n,m,num_stair,num_elevator,query;
  cin>>n>>m>>num_stair>>num_elevator>>query;
  
  set< lld > elevator;
  set< lld > stair;
  
  set< lld > :: iterator it1,it2;
  
  for(int i =0;i<num_stair;i++){
    lld x;
    cin>>x;
    stair.insert(x);
  }
    
  for(int i=  0;i<num_elevator;i++){
    lld x;
    cin>>x;
    elevator.insert(x);
  }
  
  for(int i =0;i<query;i++){
  
    lld int_row,int_col,fin_row,fin_col;
  
    lld dist_stair = INT_MAX;
    lld dist_elev = INT_MAX;
    if(num_stair > 0){
      it1 = stair.lower_bound(int_col);
      if(it1-v.begin() < num_stair)
        dist_stair1 = max(dist_stair1,*it1-int_col);
      it2 = it1;
      it2--;
      
      if(it2 - v.begin() >= 0)
        dist_stair1 = max(dist_stair1,int_col-*it2);
    
      it1 = stair.lower_bound(fin_col);
      if(it1-v.begin() < num_stair)
        dist_stair1 = max(dist_stair1,*it1-int_col);
      it2 = it1;
      it1--;
      if(it2 - v.begin() >= 0)
        dist_stair1 = max(dist_stair1,int_col-*it2);
    
    
    }
    
    if(num_elevator > 0){
      it1 = stair.lower_bound(int_col);
      if(it1-v.begin() < num_elevator)
        dist_stair1 = max(dist_stair1,*it1-int_col);
      it2 = it1;
      it1--;
      if(it2 - v.begin() >= 0)
        dist_stair1 = max(dist_stair1,int_col-*it2);
    }    
    
  
  
  }


}
