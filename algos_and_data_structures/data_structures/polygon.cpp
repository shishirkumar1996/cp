//must include geometry primitives

typedef vector< point > polygon;
double polygon_area_signed( polygon p){
  double area = 0;int cnt = p.size();
  for(int i=1;i<=cnt-1;i++) area += cross(p[i]-[0],p[i+1]-p[0]);
  return area/2;}
  double polygon_area(polygon a){ return abs(polygon_area_signed(p)); }

#define CHK( f,a,b,c) (f(a)<f(b) && f(b)<=f(c) && ccw(a,c,b) < 0)
int point_in_polygon(polygon p,point q){
  int n = p.size();
  bool in  = false;
  double d;
  for(int i=0,j=n-1;i<n;j=i++)
    if(collinear(p[i],q,p[j]) && 0<=(d=progress(q,p[i],p[j])) && d<=1)
      return 0;
  for(int i=0,j=n-1;i<n;j = i++)
    if(CHK(real,p[i],q,p[j]) || CHK(real,p[j],q,p[i])) in = !in;
  return in ? -1: 1;
}
