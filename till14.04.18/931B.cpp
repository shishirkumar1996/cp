#include<bits/stdc++.h>

using namespace std;


int calc(int n,int a,int b){

  int ans = log2(n);
  int x = n/2;
  while(true){
    
    int rem1 = (a-1)/x;
    int rem2 = (b-1)/x;
    if(rem1==rem2){
//      cout<<rem1<<" "<<rem2<<endl;
      ans--;
      a = a%x;
      b = b%x;
      if(b==0) b = x;
      if(a==0) a = x;
//      cout<<a<<" "<<b<<endl;
      x = x/2;
    }
    else
      return ans;
  }

}

int main()
{
  ios::sync_with_stdio(false);
  int n,a,b;
  cin>>n>>a>>b;
  int ans = calc(n,a,b);
  
  if(ans==log2(n))
    cout<<"Final!"<<endl;  
  else
    cout<<ans<<endl;

}
