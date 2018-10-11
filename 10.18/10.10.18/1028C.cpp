#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';
#define MAXM (lld)(1e10)

using namespace std;


struct rectangle{ lld l_x,l_y,h_x,h_y; };

bool comp(rectangle a,rectangle b){
  return (a.l_x==b.l_x)&&(a.l_y==b.l_y)&&(a.h_x==b.h_x)&&(a.h_y==b.h_y);
}

rectangle join(rectangle a,rectangle b){
  
  rectangle y;
  y.l_x = y.l_y = y.h_x = y.h_y = MAXM;
//  if(comp(a,y)||comp(b,y))return y;
  if(a.l_x>b.h_x|| a.h_x<b.l_x||a.l_y>b.h_y||a.h_y<b.l_y)return y;
  rectangle r;
  r.l_x = max(a.l_x,b.l_x);
  r.l_y = max(a.l_y,b.l_y);
  r.h_x = min(a.h_x,b.h_x);
  r.h_y = min(a.h_y,b.h_y);
  return r;
}

int compare(rectangle a,rectangle b){ return (a.l_x<b.l_x)||(a.l_x==b.l_x && a.l_y< b.l_y); }

int main(){
  int n;
  cin>>n;
  vector< rectangle > input(n);
  rectangle y;
  y.l_x = y.l_y = y.h_x = y.h_y = MAXM;
  for(int i=0;i<n;i++){
    cin>>input[i].l_x>>input[i].l_y>>input[i].h_x>>input[i].h_y;
  }
  sort(input.begin(),input.end(),compare);
  vector< rectangle > prefix(n),suffix(n);
  prefix[0] = input[0];suffix[n-1] = input[n-1];
  for(int i=1;i<n;i++){
    prefix[i] = join(prefix[i-1],input[i]);
    suffix[n-1-i]=join(suffix[n-i],input[n-1-i]);
  }
  
  for(int i=0;i<n;i++){
    if(i==0){
      if(!comp(suffix[i+1],y)){
        cout<<suffix[i+1].l_x<<" "<<suffix[i+1].l_y<<endl;return 0;
      }
    } else if(i==n-1){
      if(!comp(prefix[i-1],y)){
        cout<<prefix[i-1].l_x<<" "<<prefix[i-1].l_y<<endl;return 0;
      }
    } else{
      rectangle temp = join(prefix[i-1],suffix[i+1]);
      if(!comp(temp,y)){
        cout<<temp.l_x<<" "<<temp.l_y<<endl;return 0;
      }
    }
  }  
}
