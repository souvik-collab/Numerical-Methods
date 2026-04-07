#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>

using namespace std;

float f(float x,float y)
{
    return pow(x,3)-(3*x)*pow(y,2)+8;
}
float g(float x,float y)
{
    return 3*y*pow(x,2)-pow(y,3);
}
float fx(float x,float y)
{
    return 3*pow(x,2)-3*pow(y,2);
}
float fy(float x,float y)
{
    return -6*x*y;
}
float gx(float x,float y)
{
    return 6*x*y;
}
float gy(float x,float y)
{
    return 3*pow(x,2)-3*pow(y,2);
}
float deter(float a, float b,float c,float d)
{
    return (a*d-b*c);
}


int main(void)
{
    ofstream out1("frac1.dat");
    ofstream out2("frac2.dat");
    ofstream out3("frac3.dat");
    float x,y,p,v,x1,y1;
    for(x1=-3;x1<=3;x1=x1+0.01)
    {
        for(y1=-3;y1<=3;y1=y1+0.01)
        {
            x=x1;
            y=y1;
            p=deter(fx(x,y),fy(x,y),gx(x,y),gy(x,y));
            if (p==0)
            {
                cout<<"Diverging\n";
            }
            else
            {
                while(fabs(f(x,y))>0.0001 || fabs(g(x,y))>0.0001)
                {
                    v=deter(fx(x,y),fy(x,y),gx(x,y),gy(x,y));
                    if(v==0)
                    {
                        cout<<"Diverging\n";
                    }
                    else
                    {
                        x=x-(((gy(x,y)*f(x,y))-(fy(x,y)*g(x,y)))/v);
                        y=y-(((fx(x,y)*g(x,y))-(gx(x,y)*f(x,y)))/v);
                    }
                }
    
            }
            if(fabs(x-1)<0.0001 && fabs(y-(-1.7320))<0.0001)
            {
                out1<<x1<<" "<<y1<<endl;
            }
            if(fabs(x-1)<0.0001 && fabs(y-1.7320)<0.0001)
            {
                out2<<x1<<" "<<y1<<endl;
            }
            if(fabs(x-(-2))<0.0001 && fabs(y)<0.0001)
            {
                out3<<x1<<" "<<y1<<endl;
            }
        }
    }
    return 0;

}