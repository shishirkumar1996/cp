#include<bits/stdc++.h>
#define lld long long int

using namespace std;

struct node{
  int l,r;
  lld x,lazy;   //x carries the value
  node() {}
  node(int _l,int _r) : l(_l),r(_r),x(0),lazy(0) {} // for minimum range query initialize x with INT_MAX
  node(int _l,int _r, lld _x) : node(_l,_r) {x = _x;}
  node(node a,node b) : node(a.l,b.r) { x=a.x+b.x;} // for minimum range query it will be x = min(a.x,b.x)
  void update(lld v) { x=v;}
  void range_update(lld v) { lazy = v; }
  void apply() { if(lazy) x= (r-l+1)-x;lazy = 0;} //for minimum range query it will be x += lazy. used mainly in lazy propogation
  void push(node &u) { u.lazy ^= 1; } 
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
    
  node update(int at,int i=0){
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
  
  vector< lld > a;
  int arr[] = {1,3,5,7,9,11};
  for(int i=0;i<6;i++)a.push_back(arr[i]);
  
  cout<<"provide the upper and lower bound inclusive"<<endl;
  int x,y;
  cin>>x>>y;
  segment_tree s(a);
  node z = s.query(x,y);
  cout<<z.x<<endl;  
  cout<<" updating 1 with 5"<<endl;
  s.update(1,5);
  cout<<s.query(x,y).x<<endl;    

}


