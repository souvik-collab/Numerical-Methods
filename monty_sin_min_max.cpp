#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;
double f(double x)
{
    return sin(x);
}
double maxf(double a ,double b)
{
    double max=f(a),h=0.001,m=f(a),m0;
    for(double x=a;x<=b;x=x+h)
    {
        m0=m;
        m=f(x);
        if(m>m0)
        {
            if(m>max){max=m;}
        }
        else
        {
            if(m0>max){max=m0;}
        }
    }
    return max;

}
double minf(double a ,double b)
{
    double min=f(a),h=0.001,m=f(a),m0;
    for(double x=a;x<=b;x=x+h)
    {
        m0=m;
        m=f(x);
        if(m<m0)
        {
            if(m<min){min=m;}
        }
        else
        {
            if(m0<min){min=m0;}
        }
    }
    return min;

}
int main()
{
    //Integration upper limit x1=3*pi/2 & lower limit x0=0
    double a=0,b=(3.0/2.0)*M_PI;
    double x,y,x0=a,x1=b,y0=minf(a,b),y1=maxf(a,b);
    int n=10000000,count=0,count1=0;
    srand(time(NULL));
    double sq=(y1-y0)*(x1-x0);
    for(int i=0;i<n;i++)
    {
        x=x0+(x1-x0)*rand()/float(RAND_MAX);
        y=y0+(y1-y0)*rand()/float(RAND_MAX);
       
        if(y>0 && y<f(x))
        {
            count++;
        }
        if(y<0 && y>f(x))
        {
            count1++;
        }
        

        
    }
        
        double area= float(count - count1)*sq/float(n);
        cout<<"Area : "<<area<<endl;
    
        
        return 0;
}