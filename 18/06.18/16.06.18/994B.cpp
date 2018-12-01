#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0):
#define vi vector< lld >
#define pr pair< lld, lld >
#define vpr vector< pr >

using namespace std;

int main(){


  int n,k;
  cin>>n>>k;
  vi power(n),coin(n);
  
  for(int i= 0;i<n;i++) cin>>power[i];
  for(int i =0;i<n;i++) cin>>coin[i];
  
  if(k==0){
    for(int i = 0;i<n;i++) cout<<coin[i]<<" ";
    cout<<endl;
    return 0;
  }
  
  vpr process;
  for(int i = 0;i<n;i++) process.push_back(make_pair(power[i],i));
  
  
  sort(process.begin(),process.end());
  
  vpr answer;
  priority_queue< lld > temp;
  lld sum = 0,size = 0;
  for(int i=  0;i<n;i++){
    lld p = process[i].first,index = process[i].second;
    answer.push_back(make_pair(index,sum+coin[index]));
    if(size<k) sum+= coin[index],temp.push(-coin[index]),size++;
    else if(-temp.top()<coin[index]){
      lld top = -temp.top();
      temp.pop(); 
      sum -= top;
      temp.push(-coin[index]);
      sum += coin[index];
    }
//    cout<<index<<" "<<answer[i].first<<" "<<answer[i].second<<" "<<size<<" "<<temp.top()<<endl;
  }
  
  sort(answer.begin(),answer.end());
  for(int i =0;i<n;i++) cout<<answer[i].second<<" ";
  cout<<endl;

}
