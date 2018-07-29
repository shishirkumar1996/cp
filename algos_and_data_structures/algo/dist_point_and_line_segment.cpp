#include<bits/stdc++.h>

using namespace std;
 
struct Vec2{
    float x;float y;
    Vec2 operator-( const Vec2& a ){
        Vec2 v;
        v.x = x - a.x;v.y = y - a.y;
        return v;
    }
 
    Vec2 operator*( float a ){
        Vec2 v;
        v.x = x * a;v.y = y * a;
        return v;
    }
};
 
float Dot( const Vec2& a, const Vec2& b ){return a.x * b.x + a.y * b.y;}
 
int main( )
{
    Vec2 a, b, p;
    a.x = 1.0f;a.y = 1.0f;        //point also defined as vector
    b.x = 5.0f;b.y = 2.0f;
 
    p.x = 3.0f;p.y = 3.0f;
 
    Vec2 n = b - a;
    Vec2 pa = a - p;
    Vec2 c = n * (Dot( n, pa ) / Dot( n, n ));
    Vec2 d = pa - c;
    float d2 = Dot( d, d );
 
    printf( "Distance squared: %f\n", d2 );
}
