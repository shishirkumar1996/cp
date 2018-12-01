#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< double,pair< int,int > >
#define vp vector< pr >

using namespace std;

int compare(pr a,pr b){
  return a.first<b.first||(a.first==b.first && a.second.first>b.second.first);
}

int main(){

  faster
  int n,k;
  cin>>n>>k;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  vp process;
  int i = 0;
  
  while(input[i]>=0 && i<n)i++;
  int sum = 0;
  int ans = 0;
  int temp_sum = 0;
  int dirn = 1;
  for(;i<n;i++){
    if(input[i]<0){ 
      if(dirn==1){
        ans++;
        if(temp_sum)process.push_back(make_pair(temp_sum/2.0,make_pair(temp_sum,2)));
        temp_sum = 0;
      }
      dirn=-1; sum++;
    }
    else if(input[i]>=0){ 
      if(dirn==-1) ans++;  
      temp_sum++; dirn=1;
    }
  }
  if(temp_sum) process.push_back(make_pair(temp_sum/1.0,make_pair(temp_sum,1)));
  
  if(sum>k){cout<<-1<<endl;return 0;}
  sort(process.begin(),process.end(),compare);
  
  int temp = k-sum;
  int index = 0;
  while(temp>0&&index<process.size()){
    if(process[index].second.first>temp){index++;continue;}
    ans -= process[index].second.second;
    temp -= process[index].second.first;
    index++;
  }  
  cout<<ans<<endl;
}
