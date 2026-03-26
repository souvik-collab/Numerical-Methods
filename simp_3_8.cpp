#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float f(float x) {
    return  ( x * x);
}

float simp38(float a, float b, int n) {
    float h = (b - a) / n; 
    float sum = f(a) + f(b); 

    
    for (int i = 1; i < n; i++) {
        if (i%3==0)
        {
            sum += 2 * f(a + i * h);
        }
        else
        {
            sum += 3 * f(a + i * h);
        }
    }

    return ((3.0/8.0)*h * sum);
}

int main() {

    float lower_limit , upper_limit ;
    int intervals; 
    cout<<"Enter Lower Limit: ";
    cin>>lower_limit;
    cout<<"Enter Upper Limit: ";
    cin>>upper_limit;
    cout<<"Enter No. of Intervals: ";
    cin>>intervals;
    float result = simp38(lower_limit, upper_limit, intervals);
    cout << "The integral value is: " << fixed<<setprecision(6)<<result << endl;

    return 0;
}
