#include<bits/stdc++.h>
#define vs vector< string >


using namespace std;


void calc(int n,int m,vs first,vs second){

  bool visited[n];
  memset(visited,false,n);
  
  int flag = 0,row = 0,column = 0;
  for(int i = 0;i<=n-m;i++){ //column of second
    
    int index = 0;
    while(visited[index])
        index++;
    for(int j = 0;j<m;j++){     // row of second
      
     string s = second[j].substr(i,m);
     if(s== first[index]){
//      cout<<s<<endl;
      if(j==m-1){
        cout<<index-m+2<<" "<<i+1<<endl;
        return;
      }
      visited[index] = true;
      flag= 1;
      index++;
     }
     else{
      if(j==0)
        index++;
      else if(flag){
        i += m-1;
//        cout<<i<<endl;
        break;
        }
     }
    }
  }
}

int main(){
  
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vs first(n);
  vs second(m);
  for(int i = 0;i<n;i++)
    cin>>first[i];
  for(int i = 0;i<m;i++)
    cin>>second[i];
  calc(n,m,first,second);
}
