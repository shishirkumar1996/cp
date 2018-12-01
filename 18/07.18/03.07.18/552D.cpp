#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int, int >
#define vp vector< pr >

using namespace std;

int gcd(int a,int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

int main(){

  int n;
  cin>>n;
  vp input(n);
  
  for(int i =0;i<n;i++) cin>>input[i].first>>input[i].second;
  
  lld ans = 0;
  
  for(int i= 0;i<n;i++){
    map< pr , int >process;
    
    for(int j=i+1;j<n;j++){
      if(input[j].first-input[i].first==0) process[make_pair(1,0)]++;
      else if(input[j].second-input[i].second==0) process[make_pair(0,1)]++;
      
      else {
        int y = input[j].second-input[i].second;
        int x =input[j].first - input[i].first;
        
        if(y>0 && x<0 || y<0 && x>0){
          int g = gcd(abs(y),abs(x));
          process[make_pair(-abs(y)/g,abs(x)/g)]++;
        } else if(y>0 && x>0 || y<0 && x<0){
          int g = gcd(abs(y),abs(x));
          process[make_pair(abs(y)/g,abs(x)/g)]++;
        }
      }
    }
    lld temp = 0;
    map< pr, int >::iterator it;
    for(it = process.begin();it!= process.end();it++)
      temp += (*it).second*(n-1-i-(*it).second);
    
     ans += temp/2;
  }
  cout<<ans<<endl;

}
