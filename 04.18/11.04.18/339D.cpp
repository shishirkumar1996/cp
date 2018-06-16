#include<bits/stdc++.h>
#define lld long long int

using namespace std;


vector< lld > calc(lld p,lld b,vector< lld > input,int n){
  p--;
  p += pow(2,n)-1;
  int levels = n+1;
  input[p] = b;
  int index = p;
  int counter = 0;
  while(index > 0){
    int x;
    if(index %2 == 0)
      x = index -1;
    else 
      x = index+1;
    int new_index = (index-1)/2;
    if(counter == 0)
      input[new_index] = input[index] | input[x];
    else if(counter == 1)
      input[new_index] = input[index] ^ input[x];
    counter ^= 1;
  
    index = new_index;
  }
  
  return input;

}




int main(){
  
  ios::sync_with_stdio(false);
  
  int n,m;
  cin>>n>>m;
  vector<lld> input;
  input.resize(int(pow(2,n))*2-1);
  for(int i = 0;i<pow(2,n);i++){
    lld num;
    cin>>num;
    input[pow(2,n)-1+i] = num;
  }
  
  int counter = 0; // 0 for applying or , 1 for applying xor
  int levels = n+1;
  for(int i = n-1;i>=0;i--) //nth level of the leaves is already taken care of
  {
    for(int j = pow(2,i)-1; j < pow(2,i+1)-1;j++){
      if(counter == 0)
        input[j] = input[2*j+1] | input[2*j+2];
      else if(counter==1)
        input[j] = input[2*j+1] ^ input[2*j+2];
    }
    counter  = counter ^ 1;
  }
  
  for(int i = 0;i<m;i++){
    lld p,b;
    cin>>p>>b;
//    input = calc(p,b,input,n);
    
  p--;
  p += pow(2,n)-1;
  input[p] = b;
  int index = p;
  int counter = 0;
  while(index > 0){
    int x;
    if(index %2 == 0)
      x = index -1;
    else 
      x = index+1;
    int new_index = (index-1)/2;
    if(counter == 0)
      input[new_index] = input[index] | input[x];
    else if(counter == 1)
      input[new_index] = input[index] ^ input[x];
    counter ^= 1;
  
    index = new_index;
  }
  
    cout<<input[0]<<endl;      
  } 
  

}
