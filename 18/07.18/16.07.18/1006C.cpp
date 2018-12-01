#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  lld input[n];
  lld sum = 0;
  for(int i=0;i<n;i++){ 
    cin>>input[i];
    sum += input[i];
  }
  
  lld maxm = 0;
  map< lld, int > process;
  int i = 0;
  lld temp = 0;
  while(temp+input[i]<= sum/2){
    temp += input[i];
    i++;
    process[temp]++;
  }
  
  i = n-1;
  temp = 0;
  while(temp+input[i]<=sum/2){
    temp += input[i];
    i--;
    if(process[temp]) maxm = max(maxm,temp);
  }

  
  cout<<maxm<<endl;
}
