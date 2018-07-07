#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  
  faster
  int n,m,k;
  cin>>n>>m>>k;
  
  vi first(n),second(m);
  for(int i=  0;i<n;i++)cin>>first[i];
  for(int i=0;i<m;i++)cin>>second[i];
  
  sort(first.begin(),first.end());
  sort(second.begin(),second.end());
  int carry = 0;
  
  int index1=0,index2=0;
  while(true){
//    cout<<index1<<" "<<index2<<endl;
    if(index1==n && index2<m){carry = -1;break;}
    else if(index1<n && index2==m){carry = 1;break;}
    else if(index1==n && index2==m) break;
    else if(first[index1]>second[index2]){ carry =1; index2++;}
    else if(first[index1]==second[index2] && !carry){
     carry = 0;
     index1++;index2++;
    }
    else if(first[index1] <= second[index2]){
      index1++;index2++;carry =-1;
    }
  }
  if(carry==1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

}
