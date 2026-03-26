#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float f(float x) {
    return  1/( x * x);
}

// Trapezoidal Rule implementation
float trapezoidal(float a, float b, int n) {
    float h = (b - a) / n; // Width of each sub-interval
    float sum = f(a) + f(b); // Sum of first and last term

    // Sum of middle terms multiplied by 2
    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }

    return (h / 2) * sum;
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
    float result = trapezoidal(lower_limit, upper_limit, intervals);
    cout << "The integral value is: " << result << std::endl;

    return 0;
}
