#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

class MultiplicationTable2{
  
  public:
    int minimalGoodSet(vi table){
      int minm = INT_MAX;
      int n = (int)pow(table.size(),0.5);
      for(int i = 0;i<n;i++){
        set< int > process;
        process.insert(i);
        while(true){
          set< int > temp = process;
          for(int x : process)
            for(int y : process){ temp.insert(table[n*x+y]);
            }
          if(temp==process) break;
          process= temp;        
        }
        minm =min(minm,(int)process.size());
      }  
      return minm;
    }  
};


int main(){

  vi table(1);
  int x[] = {0};

  for(int i = 0;i<table.size();i++) table[i] = x[i];
  MultiplicationTable2 m;
  cout<<m.minimalGoodSet(table)<<endl;

}
