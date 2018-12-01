#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define NUM 200007
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

struct node{
  int l,r;
  lld x,lazy;   //x carries the value
  node() {}
  node(int _l,int _r) : l(_l),r(_r),x(0),lazy(0) {} // for minimum range query initialize x with INT_MAX
  node(int _l,int _r, lld _x) : node(_l,_r) {x = _x;}
  node(node a,node b) : node(a.l,b.r) { x=a.x+b.x;} // for minimum range query it will be x = min(a.x,b.x)
  void update() { x = x^1;}
  void range_update() { lazy ^=1; }
  void apply() { if(lazy) x= (r-l+1)-x;lazy = 0;} //for minimum range query it will be x += lazy. used mainly in lazy propogation
  void push(node &u) { if(lazy)u.lazy ^= 1; } 
};

struct segment_tree{
  int n;
  vector< node > arr;
  segment_tree() {}
  segment_tree(const vector< int > &a) : n(a.size()),arr(4*n){mk(a,0,0,n-1);}
  node mk(const vector< int > &a,int i,int l,int r){
    int m = (l+r)/2;
    return arr[i] = l>r?node(l,r):
    (l==r?node(l,r,a[l]):node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r))); }
    
  node update(int at,int i=0){
    propogate(i);
    int hl = arr[i].l,hr= arr[i].r;
    if(at<hl || hr<at) return arr[i];
    if(hl==at && at==hr){arr[i].update();return arr[i];}
    return arr[i] = node(update(at,2*i+1),update(at,2*i+2));}
    
  node query(int l,int r, int i=0){
    propogate(i);
    int hl = arr[i].l,hr = arr[i].r;
    if(r<hl||hr<l) return node(hl,hr);
    if(l<=hl && hr<=r )return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2));}
  
  node range_update(int l,int r, int i=0){
    propogate(i);
    int hl = arr[i].l,hr = arr[i].r;
    if(r<hl||hr<l) return arr[i];
    if(l<=hl && hr<=r){ arr[i].range_update();propogate(i); return arr[i];}
    return arr[i] = node(range_update(l,r,2*i+1),range_update(l,r,2*i+2));}

    void propogate(int i){
    if(arr[i].l<arr[i].r) {arr[i].push(arr[2*i+1]); arr[i].push(arr[2*i+2]); }
    arr[i].apply();
  }  
};

vii graph(NUM);

int start[NUM],en[NUM];
int timer =0;

void dfs(int v,int p=-1){
  start[v] = timer++;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];

    if(child==p)continue;
    dfs(child,v);
  }
  en[v] = timer-1;
}
int main(){
  
  faster
  int n;
  cin>>n;
  vector< int > vec(n,0);
  segment_tree s(vec);
  
  for(int i=1;i<n;i++){
    int x;
    cin>>x;
    x--;
    graph[i].push_back(x);graph[x].push_back(i);
  }  
  dfs(0);
  
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(x) s.range_update(start[i],start[i]);
  } 
  
  int q;
  cin>>q;
  for(int i=1;i<=q;i++){
    string a;int b;
    cin>>a>>b;
    b--;
    if(a=="get") cout<<s.query(start[b],en[b]).x<<'\n';
    else s.range_update(start[b],en[b]);
  }
}


