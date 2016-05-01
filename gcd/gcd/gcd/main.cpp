//
//  main.cpp
//  gcd
//
//  Created by Andres Kwan on 5/1/16.
//  Copyright © 2016 kwan.coursera.altgoritms. All rights reserved.
//

#include <iostream>

int gcd(int a, int b) {
    //write your code here
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int gcd_fast(int a, int b) {
    while ((a > 0) && (b > 0)) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}


int main() {
    int a, b;
    std::cin >> a >> b;
//    std::cout << gcd(a, b) << std::endl;
    std::cout << gcd_fast(a,b) << std::endl;
    return 0;
}