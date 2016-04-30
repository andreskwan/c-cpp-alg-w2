//
//  main.cpp
//  W2-Fibonancci
//
//  Created by Andres Kwan on 4/29/16.
//  Copyright © 2016 kwan.coursera.altgoritms. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


int calc_fib(int n) {
    if (n <= 1)
        return n;
    
    return calc_fib(n - 1) + calc_fib(n - 2);
}

int calc_fib_fast(int n, vector<int>&fibo_array) {

//    fibo_array.insert(0, 0);
//    fibo_array.insert(1, 1);
//        std::cout << "index: " << 0 << " value: " << fibo_array[0] << "\n";
//        std::cout << "index: " << 1 << " value: " << fibo_array[1] << "\n";
    for (int i = 2; i <= n; i++) {
        fibo_array[i] = fibo_array[i-1] + fibo_array[i-2];
//        std::cout << "index: " << i << " value: " << fibo_array[i] << "\n";
    }
    return fibo_array[n];
}

int main() {
    vector<int> fibo_array = {0, 1};
    for (int i = 2; i <= 46; i++) {
        fibo_array[i] = fibo_array[i-1] + fibo_array[i-2];
        //        std::cout << "index: " << i << " value: " << fibo_array[i] << "\n";
    }
    int n = 0;
    std::cin >> n;
    
//    std::cout << calc_fib(n) << '\n';
//    std::cout << calc_fib_fast(n,fibo_array) << '\n';
    std::cout << fibo_array[n] << '\n';
    return 0;
}
