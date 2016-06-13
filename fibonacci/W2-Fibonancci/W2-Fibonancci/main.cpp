//
//  main.cpp
//  W2-Fibonancci
//
//  Created by Andres Kwan on 4/29/16.
//  Copyright © 2016 kwan.coursera.altgoritms. All rights reserved.
//

#include <iostream>     // std::cout
#include <algorithm>    // std::search
#include <vector>       // std::vector

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

void print_vector(vector<int> cycle, std::string message){
    std::cout << "\n";
    std::cout << message << ": ";
    for(int i = 0; i < cycle.size(); i++ ){
        std::cout << cycle[i] << " ";
    }
    std::cout << "\n";
}

int pisano_period(vector<int> cycle, vector<int> index_of_zeros) {
    int first_fibo[] = {0,1,1};
//    print_vector(cycle, "Cycle");
//    print_vector(index_of_zeros, "index_of_zeros");
    for (int i = 0 ; i < index_of_zeros.size() - 1 ; i++) {
        //crete subvector
        vector<int> sub(&cycle[index_of_zeros[i]],&cycle[index_of_zeros[i+1]]);
//        print_vector(sub, "sub");
        vector<int>::iterator it;
        it = std::search(sub.begin(), sub.end(), first_fibo, first_fibo+3);
        if (it!=sub.end()){
//            std::cout << "needle1 found at position " << (it-sub.begin()) << '\n';
            return index_of_zeros[i];
        }
    }
    return 0;
}

vector<int> calc_pisano_cycle(int n){
    //change to dynamic size
    vector<int> cycle;
    vector<int> index_of_zeros;
    
    cycle.push_back(0);
    cycle.push_back(1);
    int zeros = 0;
    // stop when found 4 zeros
    // what about n and 0s?
    // n * n
    for (int i = 2 ; zeros <= 4; i++) {
        //      std::cout << "\nstart i: "<< i << "\n";
        cycle.push_back(cycle[i-1] + cycle[i-2]);
        if (cycle[i] >= n) {
            cycle[i] = cycle[i] % n;
        }
        if (cycle[i] == 0) {
            zeros++;
            // std::cout << "zeros: " <<zeros << "\n";
            // count which zero has been validated
            // avoid to repeat
            
            index_of_zeros.push_back(i);
        }
        
        //if z>=2 validate //and coun
        //could be done in a reactive way, when zero set
        
    }
//    print_vector(cycle, "pisano cycle: ");
//    print_vector(index_of_zeros, "pisano index_of_zeros: ");
    std::cout << "pisano period: " << pisano_period(cycle, index_of_zeros) << "\n";
    return cycle;
}

//int calc_mod_fib(int n, int m){
//    int period = pisano_period(m);
//    int remain = n % period;
//    int fibo_of_remain = calc_fib_fast_noVector(remain);
//    return fibo_of_remain % m;
//}


int main() {
    int n = 0;
    std::cin >> n;
//    std::cout << "Fast: " << calc_fib_fast(n) << '\n';
//    std::cout << "Slow: " << calc_fib(n) << '\n';
//    std::cout << calc_fib_fast(n) << '\n';
//    uncomment
//    std::cout << calc_fib_fast_noVector(n) << '\n';
    if (n == 1) {
        std::cout << "pisano period: 1";
        return 1;
    }
    calc_pisano_cycle(n);
    return 0;
}