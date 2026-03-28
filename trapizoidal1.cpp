#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return  pow(x,3)+1;
}

// Trapezoidal Rule implementation
double trapezoidal(double a, double b, long n) {
    double h = (b - a) / double(n); // Width of each sub-interval
    double sum =  f(a)+f(b); // Sum of first and last term

    // Sum of middle terms multiplied by 2
    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }

    return (h / 2) * sum;
}
double precision (double a ,double b)
{
     long intervals=10; 
    

    double i1= trapezoidal(a, b, intervals);
    double i2= 1e4;
    while(abs(i2-i1)>1e-6)
    {
        i1=i2;
        intervals *= 10;
        i2= trapezoidal(a, b, intervals);
        
    }
    return i2;
}

int main() {

    double lower_limit, upper_limit ;
    long intervals=100; 
    cout<<"Enter The Lower Limit : ";
    cin>>lower_limit;
    cout<<"Enter The Upper Limit : ";
    cin>>upper_limit;

  
    cout << "The integral value is: " << fixed<<setprecision(6)<<precision(lower_limit,upper_limit)<< endl;
 

    return 0;
}
