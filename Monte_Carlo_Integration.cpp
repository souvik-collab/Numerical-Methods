#include <iostream>
#include <cstdlib>
#include <cmath>
#include<iomanip>
using namespace std;

double f(double x)
{
    return 1/sqrt(x);
}
double random_generator(float min,float max)
{
    //srand(time(NULL));
    double random_val = (((double)rand() / RAND_MAX) * (max - min)) + min;
    return random_val;
}

double Monte_Carlo_Integration(float a,float b,long n)
{
    double sum=0;
    for(int i=0;i<n;i++)
    {
        double z=random_generator(a,b);
        sum += f(z);
        //cout<<setprecision(8)<<z<<"\t\t\t"<<setprecision(8)<<sum<<"\t\t\t"<<endl;
    }
    double ans=(b-a)*(sum/double(n));
    return ans;
    
}
double precision (double a ,double b)
{
     long intervals=10; 
    

    double i1= Monte_Carlo_Integration(a, b, intervals);
    double i2= 1e4;
    while(abs(i2-i1)>1e-4)
    {
        i1=i2;
        intervals *= 2;
        i2= Monte_Carlo_Integration(a, b, intervals);
        cout<<"Int 1 : "<<setprecision(8)<<i1<<"\t Int 2: "<<i2<<"\tValue of n: "<<intervals<<endl; 
        
    }
    cout<<"Sampling No. "<<intervals<<endl;
    return i2;
}
int main()
{
    //double area = M_PI;
    srand(time(NULL));
    float a=0;
    float b=1;

    double ans = precision(a,b);
    
    cout<<"\t\t"<<ans<<"\t\t"<<endl;
    
}