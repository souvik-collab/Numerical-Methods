#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;
double f(double x,double y)
{
    return sin(x*y);
}
int main()
{
    double x,y,x0=0,x1=M_PI,y0=0,y1=M_PI,sum;
    int n=10000000;
    srand(time(NULL));
    double sq=(y1-y0)*(x1-x0);
    for(int i=0;i<n;i++)
    {
        x=x0+(x1-x0)*rand()/float(RAND_MAX);
        y=y0+(y1-y0)*rand()/float(RAND_MAX);
       
        sum += f(x,y);

        
    }
        
        double area= sum*sq/float(n);
        cout<<"Area : "<<area<<endl;
    
        
        return 0;
}