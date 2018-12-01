#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  int n;
  cin>>n;
  vi input(n);
  
  double sum = 0;
  for(int i = 0;i<n;i++){cin>>input[i];sum+= input[i];}
  
  sort(input.begin(),input.end());
  
  int i = 0;
  while(sum/n < 4.5){
    
    int change = 5-input[i];
    input[i] += change;
    sum += change;
    i++;
    
  }
  cout<<i<<endl;
}
