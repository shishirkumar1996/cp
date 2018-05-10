#include<bits/stdc++.h>

using namespace std;



void calc(int n,long long int input[]){
  
  int start = -1,end = -1;

  int i;
  for(i = 1;i<n;i++)
    if(input[i]<input[i-1]){
      start = i-1;
      break;
    }
  
  for(int j = i+1;j<n;j++)
    if(input[j]>input[j-1]){
      end = j-1;
      break;
    }
    
  if(start != -1 && end == -1)
    end = n-1;
  else if(start == -1 && end == -1)
    start = end = 0;
  
  
  long long int sorted[n];
  for(int i = 0;i<n;i++)
    sorted[i] = input[i];
  sort(sorted,sorted+n);
  
  int flag = 0;
  for(int i = 0;i<n;i++){
    if((i<start || i>end) && sorted[i] != input[i])
    {
      flag = 1;
      break;
    }
  }
  if(flag == 1){
    cout<<"no"<<endl;
    return;
  }
  else
  {
    cout<<"yes"<<endl;
    cout<<start+1<<" "<<end+1<<" "<<endl;
  }
  
}


int main(){
  int n;
  cin>>n;
  long long int input[n];
  for(int i = 0;i<n;i++){
    int num;
    cin>>num;
    input[i] = num;
  }
  
  calc(n,input);
  
  
}

