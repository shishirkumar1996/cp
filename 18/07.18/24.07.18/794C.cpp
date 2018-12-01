#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string a,b;
  cin>>a>>b;
  
  int n = a.length();
  char ans[n];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  
  int index_1l = 0,index_1r =(n+1)/2-1,index_2l = 0,index_2r = n/2-1;
  int l=0,r = n-1;
  for(int i=0;i<n;i++)
    if(i%2==0){
      if(a[index_1l]<b[index_2l]) ans[l++] = a[index_1l++];
      else ans[r--] = a[index_1r--];
    }
    else {
      if(b[index_2l]>a[index_1l]) ans[l++] = b[index_2l++];
      else ans[r--] =  b[index_2r--];
    }
  
  for(int i=0;i<n;i++)cout<<ans[i];
  cout<<endl;
}
