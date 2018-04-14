#include<bits/stdc++.h>


using namespace std;

void calc(int n,vector<int > input){

  int minm=INT_MAX,maxm=INT_MIN;
  int num_min=0,num_max=0,num_mid=0;
  
  for(int i= 0;i<n;i++)
    minm= min(minm,input[i]),maxm = max(maxm,input[i]);


  vector < int > result;
  int similarity = 0;
  if(maxm==minm+1){
    for(int i = 0;i<n;i++){
      result.push_back(input[i]);
      similarity++;
    }
  }
  else{
    for(int i = 0;i<n;i++)
      if(input[i]==minm)
        num_min++;
      else if(input[i]==maxm)
        num_max++;
      else
        num_mid++;
        
        
    if(2*min(num_min,num_max) > (num_mid/2)*2){
      int minimize_counter = min(num_min,num_max);
      int maximize_counter = min(num_min,num_max);
      
      for(int i = 0;i<input.size();i++){
        int temp = input[i];
        if(input[i]==minm && maximize_counter > 0)
          temp = input[i]+1,maximize_counter--;
        else if(input[i]==maxm && minimize_counter > 0)
          temp = input[i]-1,minimize_counter++;
        
        result.push_back(temp);
        if(input[i] == result[i])
          similarity++;
      }
    }
    else{
      int minimize_counter = (num_mid/2);
      int maximize_counter = (num_mid/2);

      for(int i = 0;i<input.size();i++){
        int temp = input[i];
        if(input[i] != minm && input[i] != maxm){
          if(minimize_counter)
            temp= input[i]-1,minimize_counter--;
          else
          if(maximize_counter)
            temp = input[i]+1,maximize_counter--;
          
        }
        result.push_back(temp);
        if(result[i]==input[i])
            similarity++;
      }
    }
  
  }
  cout<<similarity<<endl;
  for(int i = 0;i<result.size();i++)
    cout<<result[i]<<" ";
  cout<<endl;
  
}

int main(){

  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector< int > input(n);
  for(int i = 0;i<n;i++)
    cin>>input[i];
  calc(n,input);
}
