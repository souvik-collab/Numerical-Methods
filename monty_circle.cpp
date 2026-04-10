#include<iostream>
#include<ctime>
#include<fstream>

using namespace std;

// unit circle equation. x^2+y^2=1
double f(double x,double y)
{
    return (pow(x,2)+pow(y,2));
}

int main(void)
{
    double x,y,x0=-1,x1=1,y0=-1,y1=1,area;
    int n=1000000,count=0;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        x=x0+(x1-x0)*rand()/float(RAND_MAX);
        y=y0+(y1-y0)*rand()/float(RAND_MAX);
        if(f(x,y)<=1)
        {
            count++;
        }
    }    
    area=(float(count)/float(n))*(x1-x0)*(y1-y0);
    cout<<"Area : "<<area<<endl;
    return 0;
    
}