#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

int main(void)
{
    int n=10,i,j;
    float x[n],y[n],sum=0,p,x1;
    ifstream in("interpol.dat");
    for(i=0;i<n;i++)
    {
        in>>x[i]>>y[i];

    }
    x1=4;
    for(i=0;i<n;i++)
    {
        p=1;
        for(j=0;j<n;j++)
        {
            if(i != j)
            {
                p *= (x1-x[j])/(x[i]-x[j]);
            }
        }
        sum += y[i]*p;
    }
    cout<<sum<<endl;
    return 0;

}   