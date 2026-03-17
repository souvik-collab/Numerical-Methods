#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
float f(float x)
{
    return pow(x,2)-(5*x)+6;
}
float df(float x)
{
    return 2*pow(x,1)-5;
}
void nr(float x)
{
    double h=f(x)/df(x);
    while(abs(h)>0.0001)
    {
        h=f(x)/df(x);
        x=x-h;
    }
    cout<<"the root is: "<<fixed<<setprecision(5)<<x <<endl;
}

int main(void)
{
    float a;
    cout<<"Enter Approximation Root Value : ";
    cin>>a;
    nr(a);
    return 0;

}