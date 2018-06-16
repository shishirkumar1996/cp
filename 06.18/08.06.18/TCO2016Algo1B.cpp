#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

class ExploringNumbers{

  public:
  int numberOfSteps(int n){
    
    int visited[1000];
    for(int i = 1;i<1000;i++) visited[i]=false;
    
    
    int ans=0;
    
    while(true){
      ans++;
      if(n<1000 && visited[n]) return -1;
      if(n<1000) visited[n] = true;
      
      int flag = 0;
      for(int i = 2;i<=pow(n,0.5);i++) if(n%i==0) flag = 1;
      if(!flag && n!=1) return ans;
      
      int x = 0;
      while(n) x= (n%10)*(n%10)+x, n = n/10;
      n = x; 
    }
    return 0;
  }
};

int main(){
  
  int n;
  cin>>n;
  ExploringNumbers e;
  cout<<e.numberOfSteps(n)<<endl;
}
