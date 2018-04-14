#include<bits/stdc++.h>

#define vc vector< char >
#define vcc vector < vc >

using namespace std;

int check(vcc input,vcc rotated){

  for(int i =0;i<input.size();i++)
    for(int j = 0;j<input.size();j++)
      if(input[i][j] != rotated[i][j])
        return 0;
  return 1;
}


int fliphorizontal(vcc input,vcc output){

  vcc rotated;
  rotated.resize(output.size());
  for(int i = 0;i<output.size();i++)
    rotated[i].resize(output.size());
  
  for(int i =0;i<output.size();i++)
    for(int j = 0;j<output.size();j++)
      rotated[output.size()-1-i][j]  = output[i][j];
      
  return check(input,rotated);  

}

int flipvertical(vcc input,vcc output){
  vcc rotated;
  rotated.resize(input.size());
  for(int i = 0;i<output.size();i++)
    rotated[i].resize(output.size());
  
  for(int i =0;i<output.size();i++)
    for(int j = 0;j<output.size();j++)
      rotated[i][output.size()-1-j]  = output[i][j];
      
  return check(input,rotated);  

}

int main(){

  int n;
  cin>>n;
  vcc input,output;
  input.resize(n);
  output.resize(n);
  
  for(int i = 0;i<n;i++){
    input[i].resize(n);
    output[i].resize(n);
  }
  
  for(int i =0;i<n;i++)
    for(int j =0;j<n;j++)
      cin>>input[i][j];
  
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
      cin>>output[i][j];  
  
  vcc new_output;
  for(int i = 0;i<4;i++){
    
    if(check(input,output)||fliphorizontal(input,output)||flipvertical(input,output)){
      cout<<"Yes"<<endl;
      return 0;
    }
    new_output = output;
    new_output.resize(n);
    for(int j = 0;j<output.size();j++)
      new_output[j].resize(output.size());
    
//    if(i==3)
//      cout<<"here"<<endl;
    for(int k =0;k<n;k++)
      for(int l = 0;l<n;l++){
        new_output[l][output.size()-1-k] = output[k][l];
//        if(i==3)
//          cout<<"here"<<endl;
      }
    output = new_output;
  }
  cout<<"No"<<endl;
  

}

