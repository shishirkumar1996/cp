#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define pr pair < lld, lld >
#define vp vector < pr >

using namespace std;

int compare(int a,int b){
  return a<b;
}


lld calc(int n,int m,vi input,vp query){
  
  map< lld ,lld > start;
  map< lld ,lld > end;
  
  sort(input.begin(),input.end(),compare);
  for(int i = 0;i<query.size();i++){
    pr q = query[i];
    start[q.first-1]++;
    end[q.second-1]++;
  }
  
  vector< lld > co;
  lld counter = 0;
  lld sum = 0;
  for(int i = 0;i<n;i++){
//    cout<<start[i]<<" "<<end[i]<<endl;
    counter += start[i];
    co.push_back(counter);
    counter -= end[i];
  }
  
  sort(co.begin(),co.end(),compare);
  for(int i = 0;i<n;i++)
    sum += co[i]*input[i];
  
  return sum;

}

int main(){

  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vi input;
  vp query;
  for(int i = 0;i<n;i++){
    lld num;
    cin>>num;
    input.push_back(num);
  }
  for(int i = 0;i<m;i++){
    lld a,b;
    cin>>a>>b;
    query.push_back(make_pair(a,b));
  }  
  
  cout<<calc(n,m,input,query)<<endl;
}

