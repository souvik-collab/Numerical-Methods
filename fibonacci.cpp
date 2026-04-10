#include <iostream>
#include<fstream>

using namespace std;

int main(void)
{
    float f[20],r;
    ofstream out("fibo_tuto.dat");
    f[0]=1;
    f[1]=1;
    for(int i=0;i<18;i++)
    {
        f[i+2]=f[i+1]+f[i];
        
    }
    for(int i=0;i<20;i++)
    {
        cout<<f[i]<<",";
        r=f[i+1]/f[i];
        out<<i<<"\t"<<r<<endl;


    }
    cout<<"\n";

}