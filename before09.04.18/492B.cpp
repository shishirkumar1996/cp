#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


double solution(int length,vector<int>lantern){
  
  //sorting first
  for(int i = 0;i<lantern.size()-1;i++){
    for(int j= 0;j<lantern.size()-1;j++){
      if(lantern[j]>lantern[j+1]){
        int temp = lantern[j];
        lantern[j] = lantern[j+1];
        lantern[j+1] = temp;
      }
    }
   }
   
   double maxm = 0;
   maxm = max(lantern[0],length-lantern[lantern.size()-1]);
   
   for(int i = 1;i<lantern.size();i++){
    maxm = max((lantern[i]-lantern[i-1])/2.0,maxm);
   }
   
   return maxm;
}


int main(){
  
  int n,length;
  cin>>n>>length;
  
  vector<int> lantern(n);
  for(int i = 0;i<n;i++){
    cin>>lantern[i];
  }

  printf("%.10f\n",solution(length,lantern));

}
