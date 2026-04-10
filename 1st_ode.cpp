#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

double df(double y)
{
    return (-y) ;
}
int main()
{
    double x,y,y0,x0=0;
    // initial condition T X=0 ,Y=5
    y0=5;
    y=y0;
    //separation between two consecutive x value is h=0.01
    double h=0.01;
    ofstream out("ode1.dat");
    out<<x0<<"\t"<<y0<<endl;
    for (x=h;x<=10;x=x+h)
    {
        
        y=y+(h*df(y));
        out<<x<<"\t"<<y<<endl;
        

    }
    return 0;
}