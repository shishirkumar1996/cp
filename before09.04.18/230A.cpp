#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;



string solution(int initial,vector<vector <int> >dragon){
  
  //sorting first on the basis of first column
  for(int i = 0;i<dragon.size()-1;i++){
    for(int j = 0;j<dragon.size()-1;j++){
      if((dragon[j][0]>dragon[j+1][0])||(dragon[j][0]==dragon[j+1][0] && 
      dragon[j][1] < dragon[j+1][1]))
      {
        int temp1 = dragon[j][0];
        int temp2 = dragon[j][1];
        
        temp1 = dragon[j][0];
        temp2 = dragon[j][1];
        
        dragon[j][0] = dragon[j+1][0];
        dragon[j][1] = dragon[j+1][1];
        
        dragon[j+1][0] = temp1;
        dragon[j+1][1] = temp2;
        
      }
    }
  }
  
  for(int i = 0;i<dragon.size();i++){
    if(dragon[i][0] >= initial)
      return "NO";
    else
      initial = initial+dragon[i][1];  
  }
  
  return "YES";

}



int main(){
  
  int n,s;
  cin>>s>>n;
  vector<  vector <int> > dragon(n,vector<int>(2));
  
  
  for(int i = 0;i<n;i++){
    cin>>dragon[i][0]>>dragon[i][1];
  }
  
  cout<<solution(s,dragon)<<endl;

}
