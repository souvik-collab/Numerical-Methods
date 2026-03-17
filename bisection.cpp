#include<iostream>
#include<cmath>
#include<iomanip>
//bisection method
using namespace std;
float f(float x)
{
    return pow(x,2)-3;
}
void bisection(float a,float b)
{
    
    if (f(a)==0)
    {
        cout<<"the root is = "<<a<<endl;
    }
    if (f(b)==0)
    {
        cout<<"the root is = "<<b<<endl;
    }
    float c;
    while(abs(b-a)>=0.00001)
    {
        c=(a+b)/2.0;
        if(f(c)==0)
        {
            
            cout<<c<<endl;
        }
        else if(f(a)*f(c)<0)
        {
            b=c;
        }
        else
        {
            a=c;
            
        }
        cout<<c<<endl;
    }
       
        
    cout<<"root is = "<<fixed<<setprecision(8) <<c<<endl;
}
int main(void)
{
    float h,k;
    h=-5,k=7;
    bisection(h,k);

    return 0;

}
