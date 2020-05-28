#include <stdio.h>
#include <math.h>
#define EPSILON  0.001
double function(double x){
    int redID[6]={3, 5, 7, 3, 8, 6};
    double polynomial = redID[5];
	
	for(int i=0;i<=4; ++i)
	{
		polynomial = (polynomial+redID[i]*pow(x, 5-i));
	}
	
    return polynomial;
}
double derivFunction(double x){
    int redID[6]={3, 5, 7, 3, 8, 6};
    double derivPolynomial = redID[4];
	
	for(int i=0;i<=3; ++i)
	{
		derivPolynomial = (derivPolynomial+redID[i]*(5-i)*pow(x, 5-i-1));
	}
	
    return derivPolynomial;
}
double NewtonRaphsonMethod(double x){
    double h = function(x) / derivFunction(x); 
    while (h >= EPSILON || -h>= EPSILON) 
    { 
        h = function(x)/derivFunction(x); 
        x = x - h;
    }
    printf("The value of the root is: %lf\n", x);
    return x;
}
int main()
{
    /*range can be anything since this polynomial has only one root, but closer initial values would be close to 1, lets take domain from -1000 to 1000*/
    int testInputs[25]={-100, -900, -800, -700, -600, -500, -400, -300, -200, 
    -100, 0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000,-0.01, 0.135, -0.05, 175.98};
    for(int i=0;i<25; ++i){
        NewtonRaphsonMethod(testInputs[i]);
    }
    return 0;
}
