#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< int , int >
#define vp vector< pr >
#define vi vector< int >
using namespace std;

int compare(pr a,pr b){

  return a.first > b.first;

}


int calc(int n,int a,int b,vi input){

  vp process;
  lld sum = 0;
  for(int i = 0;i<n;i++){
    process.push_back(make_pair(input[i],i));
    sum = sum+input[i];
  }
  
  int initial = input[0];
  sort(process.begin(),process.end(),compare);
  lld total = sum;
  
    
  int ans = 0;
  int index = 0;
  while( (initial*a*1.0)/total < b){
    if(process[index].second != 0){
      ans++,total -= process[index].first;
    }
    index++; 
  }
  return ans;

}
int main(){
  faster
  int n,a,b;
  cin>>n>>a>>b;
  vi input(n);
  for(int i = 0;i<n;i++)
    cin>>input[i];
  cout<<calc(n,a,b,input)<<endl;
}
