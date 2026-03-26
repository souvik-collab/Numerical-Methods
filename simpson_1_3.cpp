#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float f(float x) {
    return  ( x * x);
}


float simp13(float a, float b, int n) {
    float h = (b - a) / n; 
    float sum = f(a) + f(b); 

    
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

int main() {

    float lower_limit , upper_limit ;
    int intervals; 
    cout<<"Enter Lower Limit: ";
    cin>>lower_limit;
    cout<<"Enter Upper Limit: ";
    cin>>upper_limit;
    cout<<"Enter No. of Intervals: ";
    cin>>intervals;
    float result = simp13(lower_limit, upper_limit, intervals);
    cout << "The integral value is: " << result <<endl;

    return 0;
}
