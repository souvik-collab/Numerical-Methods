#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

float w=1,b=0.17;

double f2(float t,float y,float z) // y_dot
{
    return (z);
}
double f3(float t,float y,float z) // z_dot
{
    return (-b*z-(pow(w,2)*sin(y)));
}

int main(void)
{
    float t=0,y=1,z=1,h=0.01,p1,p2,p3,p4,g1,g2,g3,g4;
    ofstream out("damp_osc.dat");
    for(t=0;t<=50;t=t+h)
    {
        p1=h*f2(t,y,z);
        g1=h*f3(t,y,z);
    
        p2=h*f2(t+h/2,y+p1/2,z+g1/2);
        g2=h*f3(t+h/2,y+p1/2,z+g1/2);
        
        p3=h*f2(t+h/2,y+p2/2,z+g2/2);
        g3=h*f3(t+h/2,y+p2/2,z+g2/2);
    
        p4=h*f2(t+h,y+p3,z+g3);
        g4=h*f3(t+h,y+p3,z+g3);
        
        
        y=y+(p1+2*p2+2*p3+p4)/6.0;
        z=z+(g1+2*g2+2*g3+g4)/6.0;
        
        out<<t<<"\t"<<y<<"\t"<<z<<endl;
    }
    return 0;
}