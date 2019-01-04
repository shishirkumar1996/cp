#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	double x1,y1,r1,x2,y2,r2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	
	double d = dist(x1,y1,x2,y2);
	double ans = 0;
	if(d>r1+r2) ans = (d-r1-r2);
	else{
		double x = r1,y = r2;
		if(x<y)swap(x,y);
		if(x>=y+d) ans = (x-y-d);
	}
	ans = ans/2;
	cout<<setprecision(9)<<fixed;
	cout<<ans<<endl;
}
