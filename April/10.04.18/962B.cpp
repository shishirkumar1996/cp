#include<bits/stdc++.h>


using namespace std;


int calc(int n,int a,int b,string input){

  int counter = 0;
  int sum = 0;
  
  for(int i = 0;i<n;i++){
    if(a==0 && b==0)
      break;
    if(input[i]=='*')
      counter = 0;
    else
    {
      if(counter==0){
        sum++;
        if(a>b)
          a--,counter = 1;
        else b--,counter = 2;               
      }
      else if(counter ==1){
        if(b>0)
          b--,counter = 2,sum++; 
        else
          counter = 0;
      }
      else if(counter==2){
        if(a>0)
          a--,counter = 1,sum++;
        else
          counter = 0;
      }     
    }
  }
  
  return sum;

}

int main(){

  int n,a,b;
  string input;
  cin>>n>>a>>b>>input;
  cout<<calc(n,a,b,input)<<endl;

}

