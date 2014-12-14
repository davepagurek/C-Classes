#include <stdio.h>
#include <assert.h>

float abs(float x) {
    if (x>=0) return x;
    return -x;
}

int sign(float x) {
    if (x>0) return 1;
    if (x<0) return -1;
    return 0;
}

float f(float x) {
    //-5x^4 + 3x^3 -2x^2 + x + 8
    return ((((-5*x +3)*x-2)*x +1)*x +8);
}

float root(float (*f)(float), float a, float b, float precision) {
    if (f(a)==0) return a;
    if (f(b)==0) return b;
    assert(sign(f(a)) != sign(f(b)));

    float c;
    while(1) {
        c = (a+b)/2;
        //printf("%f\n", c);
        if (abs(f(c))<= precision) return c;
        if (sign(f(c))==sign(f(a))) {
            a=c;
        } else {
            b=c;
        }
    }
}

int gcd(int a, int b) {
    if (a<b) return gcd(b, a);
    if (a==b) return a;
    int r;
    do {
        r = a%b;
        a=b;
        b=r;
    } while (r!=0);
    return a;
}

int main() {
    printf("%f\n", root(&f, 0, 2, 0.001));
    printf("%d\n", gcd(2352, 65799));
    return 0;
}
