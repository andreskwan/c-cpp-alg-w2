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

int calc_fib_fast(int n) {
    vector<int> fibo_array;
    fibo_array.push_back(0);
    fibo_array.push_back(1);
    
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

int calc_fib_fast_noVector(int n) {
    int oneStepBefore = 1;
    int twoStespBefore = 0;
    int value = 0;
    if (n == 0) {
        return n;
    } else if (n == 1) {
        return n;
    }
        
    for (int i = 2 ; i <= n ; i++) {
        value = oneStepBefore + twoStespBefore;
        twoStespBefore = oneStepBefore;
        oneStepBefore = value;
    }
    return value;
}

vector<int> calc_pisano_cycle(int n){
    vector<int> cycle(n*7);

    cycle[0] = 0;
    cycle[1] = 1;
    int zeros = 0;
//    For small 0, 1, cycle is also small and period easy to find
//    if (n == 0) {
//        return n;
//    } else if (n == 1) {
//        return n;
//    }
    
    //stop when found 4 zeros
    //what about n and 0s?
    // n * n
    for (int i = 2 ; zeros <= 4 && i <= n * 7; i++) {
        std::cout << "\nstart i: "<< i << "\n";
//        std::cout << "b cycle[i-2]: "<< cycle[i-2] << "\n";
//        std::cout << "b cycle[i-1]: "<< cycle[i-1] << "\n";
        cycle[i] = cycle[i-1] + cycle[i-2];
//        std::cout << "\ni: "<< i <<" before mod: " << cycle[i] << "\n";
        if (cycle[i] >= n) {
            cycle[i] = cycle[i] % n;
//            std::cout << "after mod: " << cycle[i] << "\n";
        }
        if (cycle[i] == 0) {
            zeros++;
            std::cout << "zeros: " <<zeros << "\n";
        }
        std::cout << "\ncycle: ";
        for(int i = 0; i < cycle.size(); i++ ){
            std::cout << cycle[i] << " ";
        }
    }
    
    for(int i = 0; i < cycle.size(); i++ ){
        std::cout << cycle[i] << " ";
    }
    return cycle;
}

int pisano_period(int n) {
    vector<int> pisano_cycle = calc_pisano_cycle(n);
    return 0;
}


int calc_mod_fib(int n, int m){
    int period = pisano_period(m);
    int remain = n % period;
    int fibo_of_remain = calc_fib_fast_noVector(remain);
    return fibo_of_remain % m;
}


int main() {
    int n = 0;
    std::cin >> n;
//    std::cout << "Fast: " << calc_fib_fast(n) << '\n';
//    std::cout << "Slow: " << calc_fib(n) << '\n';
//    std::cout << calc_fib_fast(n) << '\n';
//    uncomment
//    std::cout << calc_fib_fast_noVector(n) << '\n';
    calc_pisano_cycle(n);
    return 0;
}