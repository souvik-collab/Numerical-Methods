#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;
double f(double x)
{
    return sin(x);
}
int main()
{
    double x,y,x0=0,x1=(3.0/2.0)*M_PI,y0=-1,y1=1;
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