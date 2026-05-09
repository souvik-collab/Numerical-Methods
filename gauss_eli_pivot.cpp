#include <iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<iomanip>

using namespace std;

typedef struct{
    float x[10][10];
    int m,n;
}mat;

int main(void)
{
    srand(time(0));
    float x,x0=-10,x1=10,s,sum;
    mat a,b;
    int i,j,k,l;
    // Matrix A Dimension
    a.m=3;
    a.n=4;
    //Matrix B Dimension (x,y,z)
    b.m=3;
    b.n=1;
    //to get omit random generate and try with own value then comment out line 29 to 39
    //write value in ge.dat file
    ofstream out("ge.dat");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
        x=x0+(x1-x0)*rand()/float(RAND_MAX);
        out<<x<<"\t";
        }
        out<<endl;
    }
    out<<endl;
    ifstream in("ge.dat");
    //assign value in Matrix A
    for(i=0;i<a.m;i++)
    {
        for(j=0;j<a.n;j++)
        {
            in>>a.x[i][j];
        }
    }
    //assign value in Matrix B
    for(i=0;i<b.m;i++)
    {
        for(j=0;j<b.n;j++)
        {
            b.x[i][j]=0;
        }
    }
    //See Matrix A Load Properly
    cout<<"\t\tMatrix A\n";
    for(i=0;i<a.m;i++)
    {
        for(j=0;j<a.n;j++)
        {
            cout<<fixed<<setprecision(5)<<a.x[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    //shape Matrix A to Upper Triangular Matrix 
    for(i=0;i<a.m;i++)
    {
        for(k=i+1;k<a.m;k++)
        {
            if(a.x[i][i]==0)
            {
                for(l=0;l<a.n;l++)
                {
                    swap(a.x[i][l],a.x[k][l]);
                }
            }
            s=a.x[k][i]/a.x[i][i];
            for(j=0;j<a.n;j++)
            {
                a.x[k][j]=a.x[k][j]-s*a.x[i][j];
            }
        }
    }
    //see is Matrix A Transform Properly

    cout<<"\t\tUpper Triangular Matrix of A\n";
    for(i=0;i<a.m;i++)
    {
        for(j=0;j<a.n;j++)
        {
            cout<<a.x[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";

    //calculate sum and determine the value

    for(i=2;i>=0;i--)
    {
        sum =0;
        for(j=0;j<3;j++)
        {
            sum += a.x[i][j]*b.x[j][0];
        }
        b.x[i][0]=(a.x[i][3]-sum)/float(a.x[i][i]);
    }

    cout<<"The Roots are : ";
    for(i=0;i<a.m;i++)
    {
        
        cout<<b.x[i][0]<<" , ";
        
    }
    cout<<"\n\n";

    return 0;


}
