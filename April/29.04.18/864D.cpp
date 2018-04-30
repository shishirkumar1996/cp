#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;


void calc(int n,vi input){

  
  map<int ,int > process;
  map<int , int > present;
  for(int i = 0;i<n;i++)
    process[input[i]]++;
   
  int ans = 0;
  int index = 1;
  for(int i = 0;i<n;i++)
    if(process[input[i]] > 1){
      
      while(process[index]>0)
        index++;
      
      if(index > input[i] && !present[input[i]]){
        present[input[i]] = 1;
        continue;
      }
      ans++;
      process[input[i]]--;
      input[i] = index;
      process[index]++;
      input[i] = index;
    }
  cout<<ans<<endl;
  for(int i = 0;i<n;i++)
    cout<<input[i]<<" ";
  cout<<endl;

}

int main(){

  int n;
  cin>>n;
  vi input(n);
  for(int i =0;i<n;i++)
    cin>>input[i];
  
  calc(n,input);

}
