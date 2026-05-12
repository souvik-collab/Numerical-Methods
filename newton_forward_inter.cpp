#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

float u_mul(float u,float n)
{
    float mul=u;
    for(int i=1;i<n;i++)
    {
        mul *=(u-i);
    }
    return mul;

}
int fact(int n)
{
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        ans *= i;
    }
    return ans;
}
int main(void)
{
    ifstream in("intra.dat");
    float x[10],y[10][10];
    int i,j,k,n=10;
    //read data  here n=10 data points 
    for(i=0;i<n;i++)
    {
        in>>x[i];
    }
    for(i=0;i<n;i++)
    {
        in>>y[i][0];
    }
    //checking all right ?
    for(i=0;i<n;i++)
    {
        cout<<x[i]<<"\t"<<y[i][0]<<endl;
    }
    //calculate forward diff table 
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
    float val,x1;
    cout<<"Enter your Query point : ";
    cin>>x1;
    //here step size h=10
    int h=10;
    float u;
    u=(x1-x[0])/h;
    val=y[0][0];
    for(i=1;i<n;i++)
    {
        val += u_mul(u,i)*y[0][i]/float(fact(i));
    }
    cout<<"the answer is "<<val<<endl;

    return 0;
}