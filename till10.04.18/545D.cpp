#include<bits/stdc++.h>

#define lli long long int

using namespace std;



int calc(int n,vector<lli> input){

  int count = 0;
  sort(input.begin(),input.end());
  
  lli  sum = 0;
  
  for(int i = 0;i<n;i++){
    if(input[i] >= sum)
      sum+= input[i],count++;
  
  }
  
  return count;

}


int main(){
  int n;
  cin>>n;
  vector<lli>input;
  for(int i =0 ;i<n;i++){
    lli num;
    cin>>num;
    input.push_back(num);
  }
  
  cout<<calc(n,input)<<endl;


}
