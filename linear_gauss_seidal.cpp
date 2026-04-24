#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

struct mat{
    double x[3][3];
    int m,n;
};
double f(float a,float b,float c,float d,float e,float g)
{
    return sqrt(pow(a-d,2)+pow(b-e,2)+pow(c-g,2));
}

int main(void)
{
    double p=12,q=10,r=4,x,y,z,x0=0,y0=3,z0=-3;
    int i,j;
    mat a,b;
    a.m=3;
    a.n=3;
    b.m=3;
    b.n=1;
    // cout<<"Enter the approx value of x,y,z : ";
    // cin>>x0>>y0>>z0;
    ifstream in("linear.dat");
    for(i=0;i<a.m;i++)
    {
        for(j=0;j<a.n;j++)
        {
            in>>a.x[i][j];
        }
    }
    for(i=0;i<b.m;i++)
    {
        for(j=0;j<b.n;j++)
        {
            in>>b.x[i][j];
          //  cout<<.x[i][j]<<endl;
        }
    }
    
    /*
    //checking matrix A
    cout<<"\t\t\t Matrix A \n\n";
    for(i=0;i<a.m;i++)
    {
        for(j=0;j<a.n;j++)
        {
            cout<<a.x[i][j]<<"\t";
        }
        cout<<endl;
    }
        //checking matrix B 
    cout<<"\n\n\t\t\t Matrix b \n\n";
    for(i=0;i<b.m;i++)
    {
        for(j=0;j<b.n;j++)
        {
            cout<<b.x[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    
    while(f(p,q,r,x0,y0,z0)>1e-6)
    {
        p=x0;
        q=y0;
        r=z0;
        x0=(b.x[0][0]-a.x[0][1]*y-a.x[0][2]*z)/float(a.x[0][0]);
        x=x0;
        
        y0=(b.x[1][0]-a.x[1][0]*x-a.x[1][2]*z)/float(a.x[1][1]);
        y=y0;
        
        z0=(b.x[2][0]-a.x[2][0]*x-a.x[2][1]*y)/float(a.x[2][2]);
        z=z0;
        
        
        //cout<<"\n\t The value of x,y,z :"<<x<<" , "<<y<<" , "<<z<<endl;
    }
    cout<<"\n\t The value of x,y,z :"<<x<<" , "<<y<<" , "<<z<<endl;


}
/*
value of matrix A : 
4 1 2
3 5 1
1 1 3

value of matrix B :
4 7 3
*/
