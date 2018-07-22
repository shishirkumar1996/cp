#include<bits/stdc++.h>

using namespace std;

struct Point{ int x,y;};

int compareX(Point a,Point b){return a.x < b.x;}

int compareY(Point a,Point b){return a.y<b.y;}

float dist(Point p1,Point p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
 
float stripClosest(Point strip[],int size, float d){
  float min = d;
  sort(strip,strip+size,compareY);
  
  for(int i=0;i<size;i++)
    for(int j=i+1;j<size && (strip[j].y - strip[i].y) < min;++j)
      if(dist(strip[i],strip[j])<min) min = dist(strip[i],strip[j]);
}

float closestPoint(Point P[],int n){
  if(n<=3) return bruteForce(P,n);
  
  int mid = n/2;
  Point midPoint = P[mid];
  
  float dl = closestPoint(P,mid);
  float dr = closestPoint(P+mid,n-mid);
  float d=min(dl,dr);
  Point strip[n];
  int j=0;
  for(int i=0;i<n;i++) if(abs(P[i].x-midPoint.x)<d) strip[j] = P[i],j++;

  return min(d,stripClosest(strip,j,d));
}

float closest( Point P[], int n){
  sort(P,P+n,compareX);
  return closestPoint(P,n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout<<" The smallest distance is "<<closest(P,n)<<endl;
    return 0;
}

