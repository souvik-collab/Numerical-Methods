#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return  1/sqrt(x);
}

// Simpson 1/3 Rule implementation
double simp13(double a, double b, long n) {
    double h = (b - a) / double(n); // Width of each sub-interval
    double sum =  f(a)+f(b); // Sum of first and last term

    // Sum of middle terms multiplied by 2
    for (int i = 1; i < n; i++) {
        if (i%2==0)
        {
            sum += 2 * f(a + i * h);
        }
        else
        {
            sum += 4 * f(a + i * h);
        }
    }

    return (h / 3) * sum;
}
double precision (double a ,double b)
{
     long intervals=10; 
    

    double i1= simp13(a, b, intervals);
    double i2= 1e4;
    while(abs(i2-i1)>1e-6)
    {
        i1=i2;
        intervals *= 10;
        i2= simp13(a, b, intervals);
        
    }
    return i2;
}

int main() {

    double lower_limit, upper_limit ,sum=0,sum1=1;
    double mid;
    int j=0;
    cout<<"Enter the lower limit : ";
    cin>>lower_limit;
    cout<<"Enter the upper limit : ";
    cin>>upper_limit;
    if (abs(f(lower_limit))>1e6)
    {
        while(abs(sum1 - sum)>1e-6)
        {
         sum1=sum;
         mid=(lower_limit+upper_limit)/2.0;
         sum +=precision(mid,upper_limit);
         upper_limit=mid;
         j++;
         cout<<"Sum : "<<sum<<"\t\t iterations : "<<j<<endl;
        }

    }
    else if (abs(f(upper_limit))>1e6)
    {
         while(abs(sum1 - sum)>1e-6)
        {
         sum1=sum;
         mid=(lower_limit+upper_limit)/2.0;
         sum +=precision(lower_limit,mid);
         lower_limit=mid;
         j++;
         cout<<"Sum : "<<sum<<"\t\t iterations : "<<j<<endl;
        }
    }
    else
    {
        sum=precision(lower_limit,upper_limit);
    }
    
    
    cout << "The integral value is: " << fixed<<setprecision(6)<<sum<< endl;

    return 0;
}