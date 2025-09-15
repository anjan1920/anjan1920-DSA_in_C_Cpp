#include <iostream>
#include <cmath>  // For round()

using namespace std;

//  GCD using the Euclidean algorithm

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b; // Store remainder
        b = a % b;   // Compute new remainder
        a = temp;    // Update  previous remainder
    }
    return a;
}

int main() {
    double original_value = 3.124;  
    int precision = 4;  

    // Convert the floating-point number to a fraction
    // Multiply by 10^precision to shift decimal point for get upto 4 decimal point number
    double scale = pow(10, precision); 
    int neu = round(original_value * scale); // /number get converted to decimal
    int deno = scale;  // scaling factor 


    // Output the original and modified values before simplification
    cout << "Original value: " << original_value << endl;
    cout << "Modified value: " << static_cast<double>(neu) / deno << endl;

    //find gcd
    int divisor = gcd(neu, deno); 
    cout << "GCD is: " << divisor << endl; 

    // Divide both numerator and denominator by the GCD
    neu /= divisor; 
    deno /= divisor; 

   
    cout << "Numerator: " << neu << endl;
    cout << "Denominator: " << deno << endl;

    return 0; 
}
