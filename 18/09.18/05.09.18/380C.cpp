#include<bits/stdc++.h>
#define lld long long int

using namespace std;

struct node{
  int l,r;
  lld x,a,b;   //x carries the value
  node() {}
  node(int _l,int _r) : l(_l),r(_r),x(0),a(0),b(0) {}
  node(int _l,int _r, char _x) : node(_l,_r) {
    x = 0;
    if(_x=='('){a=1;b=0;}
    else {a=0;b=1;}
  }
  node(node a1,node b1) : node(a1.l,b1.r) {
    lld temp = min(a1.a,b1.b);
    x = a1.x+b1.x+2*temp;a = a1.a+b1.a-temp;b = a1.b+b1.b-temp;
  }
};

struct segment_tree{
  int n;
  vector< node > arr;
  segment_tree() {}
  segment_tree(const string &a) : n(a.length()),arr(4*n){mk(a,0,0,n-1);}
  node mk(const string &a,int i,int l,int r){
    int m = (l+r)/2;
    return arr[i] = l>r?node(l,r):
    (l==r?node(l,r,a[l]):node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r))); }
    
  node query(int l,int r, int i=0){
    int hl = arr[i].l,hr = arr[i].r;
    if(r<hl||hr<l) return node(hl,hr);
    if(l<=hl && hr<=r )return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2));}
};

int main(){
  
  string a;
  cin>>a;
  segment_tree s(a);
  int q;
  cin>>q;
  for(int i=1;i<=q;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    cout<<s.query(a,b).x<<endl;  
  }
}


