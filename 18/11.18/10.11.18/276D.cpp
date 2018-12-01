#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 60

using namespace std;

int main(){

  lld l,r;
  cin>>l>>r;
  
  lld temp = r;
  int num = 0;
  int a[NUM],b[NUM];
  for(int i=0;i<NUM;i++)a[i] = b[i] = 0;
  while(temp){ a[num++] = temp%2; temp /= 2;}
  temp = l;
  num = 0;
  while(temp){ b[num++] = temp%2; temp /= 2; }
  
  lld ans = 0;
  int index = NUM-1;
  while(index>=0){
    if(a[index]==1 && b[index]==0) break;
    index--;
  }
  while(index>=0){ ans = 2*ans+1;index--; }
  cout<<ans<<endl;
}
