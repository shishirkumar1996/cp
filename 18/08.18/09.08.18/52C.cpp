#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

struct node{
  int l,r;
  lld x,lazy;   //x carries the value
  node() {}
  node(int _l,int _r) : l(_l),r(_r),x(INT_MAX),lazy(0) {}
  node(int _l,int _r, lld _x) : node(_l,_r) {x = _x;}
  node(node a,node b) : node(a.l,b.r) { x=min(a.x,b.x);}
  void update(lld v) { x=v;}
  void range_update(lld v) { lazy = v; }
  void apply() { x+= lazy;lazy = 0;}
  void push(node &u) { u.lazy += lazy; } 
};

struct segment_tree{
  int n;
  vector< node > arr;
  segment_tree() {}
  segment_tree(const vector< lld > &a) : n(a.size()),arr(4*n){mk(a,0,0,n-1);}
  node mk(const vector< lld> &a,int i,int l,int r){
    int m = (l+r)/2;
    return arr[i] = l>r?node(l,r):
    (l==r?node(l,r,a[l]):node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r))); }
    
  node update(int at,lld v,int i=0){
    propogate(i);
    int hl = arr[i].l,hr= arr[i].r;
    if(at<hl || hr<at) return arr[i];
    if(hl==at && at==hr){arr[i].update(v);return arr[i];}
    return arr[i] = node(update(at,v,2*i+1),update(at,v,2*i+2));}
    
  node query(int l,int r, int i=0){
    propogate(i);
    int hl = arr[i].l,hr = arr[i].r;
    if(r<hl||hr<l) return node(hl,hr);
    if(l<=hl && hr<=r )return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2));}
  
  node range_update(int l,int r,lld v, int i=0){
    propogate(i);
    int hl = arr[i].l,hr = arr[i].r;
    if(r<hl||hr<l) return arr[i];
    if(l<=hl && hr<=r){ arr[i].range_update(v);propogate(i); return arr[i];}
    return arr[i] = node(range_update(l,r,v,2*i+1),range_update(l,r,v,2*i+2));}

    void propogate(int i){
    if(arr[i].l<arr[i].r) {arr[i].push(arr[2*i+1]); arr[i].push(arr[2*i+2]); }
    arr[i].apply();
  }  
};

int main(){
  
  faster
  int n;
  cin>>n;
  vi arr(n);
  for(int i=0;i<n;i++)cin>>arr[i]; 
  
  segment_tree s(arr);
  int m;
  cin>>m;
  string str;
  getline(cin,str);
  for(int i=0;i<m;i++){
    getline(cin,str);
    stringstream st(str);
    int a = INT_MAX,b= INT_MAX,c = INT_MAX;
    st>>a>>b>>c;
    if(c==INT_MAX){
      if(b<a){
        int l1 = 0,r1 = b;
        int l2 = a,r2 = n-1;
//        cout<<l1<<" "<<r1<<" "<<s.query(l1,r1).x<<endl;
        cout<<min(s.query(l1,r1).x,s.query(l2,r2).x)<<endl;
      } else cout<<s.query(a,b).x<<endl;
    } else {
      if(b<a){
        s.range_update(0,b,c);
        s.range_update(a,n-1,c);
      } else s.range_update(a,b,c);
    }
  }
}
