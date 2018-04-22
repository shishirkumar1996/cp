#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;


void calc(int n, vi input){
  
  int left = 1,right = n;
  int time_left = 0,time_right = 0;
  lld count_left = 0,count_right = 0;
  lld total_count = 0;
  for(int i =1;i<=n;i++)
    total_count += input[i];
  while(total_count > 0){
    if(time_left <= time_right){
      count_left++;
      total_count-=input[count_left];
      time_left += input[count_left];
    }
    else{
      total_count-= input[n-count_right];
      time_right += input[n-count_right];
      count_right++; 
    }
  
  }
  cout<<count_left<<" "<<count_right<<endl;
  
}

int main(){
  faster
  int n;
  cin>>n;
  vi input(n+1);
  input[0] = 0;
  for(int i = 1;i<=n;i++)
    cin>>input[i];
    
  calc(n,input);
}
