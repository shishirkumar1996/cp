#include<bits/stdc++.h>
#define lld long long int

using namespace std;



lld calc(int n,vector<lld> input){


  sort(input.begin(),input.end());
  
  lld sum = 0;
  for(int i = 0;i<input.size();i++){
    sum += abs(input[i]-(i+1));
  }

  return sum;

}



int main(){

  int n;
  vector<lld>input;
  
  cin>>n;
  for(int i = 0;i<n;i++){
    lld num = 0;
    cin>>num;
    input.push_back(num);
  }

  cout<<calc(n,input)<<endl;
}
