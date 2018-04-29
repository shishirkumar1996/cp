#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

string calc(int a,int b,int c){

  if(a==1 || b==1 || c==1)
    return "YES";
   
  int count =0;
  if(a==2)
    count++;
  if(b==2)
    count++;
  if(c==2)
    count++;
  if(count >=2)
    return "YES";
 
  int count4 = 0;
  if(a==4) count4++;
  if(b==4 ) count4++;
  if(c==4) count4++;
 
  
  int maxm = 0;
  maxm = max(max(max(c,maxm),b),a);
  if(maxm == 3 and count==1)
    return "NO";
  
  if(maxm <=3||(count==1 && count4==2))
    return "YES";
  else
    return "NO";


}

int main(){

  int a,b,c;
  cin>>a>>b>>c;
  cout<<calc(a,b,c)<<endl;

}
