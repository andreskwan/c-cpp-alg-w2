//
//  main.cpp
//  lcm
//
//  Created by Andres Kwan on 5/1/16.
//  Copyright © 2016 kwan.coursera.altgoritms. All rights reserved.
//

#include <iostream>

long long gcd_fast(long long a, long long b) {
    while ((a > 0) && (b > 0)) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

long long lcm(long long a, long long b) {
    //write your code here
    long long gcd = gcd_fast(a, b);
    return a*b/gcd;
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}