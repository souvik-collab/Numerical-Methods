#include<iostream>
#include<ctime>
#include<fstream>

using namespace std;

// unit circle equation. x^2+y^2=1
double f(double x,double y,double a,double b)
{
    return ((pow(x,2)/pow(a,2))+(pow(y,2)/pow(b,2)));
}

int main(void)
{
    double a,b;
    cout<<"Enter semi major and minor axis length : ";
    cin>>a>>b;
    double x,y,x0=-a,x1=a,y0=-b,y1=b,area;
    int n=1000000,count=0;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        x=x0+(x1-x0)*rand()/float(RAND_MAX);
        y=y0+(y1-y0)*rand()/float(RAND_MAX);
        if(f(x,y,a,b)<=1)
        {
            count++;
        }
    }    
    area=(float(count)/float(n))*(x1-x0)*(y1-y0);
    cout<<"Area : "<<area<<endl;
    return 0;
    
}