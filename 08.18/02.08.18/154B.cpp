#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 100007

using namespace std;


int prime[NUM];
vector< set< int > > process(NUM);

void sieve(){

  for(int i=0;i<NUM;i++)prime[i] = i;
  for(int i=2;i<NUM;i++)
    if(prime[i] == i)
      for(int j=2*i;j<NUM;j+=i)prime[j] = i;
    
  
  
  for(int i=2;i<NUM;i++){
    process[i] = process[i/prime[i]];
    process[i].insert(prime[i]);
  }
}

int main(){
  
  faster
  sieve();
  int n,m;
  cin>>n>>m;
  
  set< int > tot;
  bool on[n+1];
  int bringer[n+1];
  for(int i=0;i<=n;i++) on[i] = false;
  
  
  for(int i=0;i<m;i++){
    char a;int x;
    cin>>a>>x;
    if(a=='+'){
      if(on[x]==true){cout<<"Already on"<<endl;}
      else{
        int flag = 1;
        set< int >::iterator it;
        for(it=process[x].begin();it != process[x].end();it++)
          if(tot.count(*it)){
            cout<<"Conflict with "<<bringer[*it]<<endl;flag=0;break;
          }
        if(flag==1){
          on[x] = true;
          cout<<"Success"<<endl;
          for(it=process[x].begin();it != process[x].end();it++){
            tot.insert(*it);
            bringer[*it] = x;
          }
        }         
      }
    }else if(a=='-'){
      if(on[x]==false){cout<<"Already off"<<endl;}
      else {
        on[x] = false;
        cout<<"Success"<<endl;
        set< int >::iterator it;
        for(it=process[x].begin();it != process[x].end();it++) tot.erase(*it);               
      }
    }
  }

}
