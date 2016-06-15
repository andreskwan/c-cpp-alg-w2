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
#include <map>       // std::vector

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

__uint128_t calc_fib_fast_noVector(long long n) {
    __uint128_t oneStepBefore = 1;
    __uint128_t twoStespBefore = 0;
    __uint128_t value = 0;
    if (n == 0) {
        return n;
    } else if (n == 1) {
        return n;
    }
        
    for (int i = 2 ; i <= n ; i++) {
        value = oneStepBefore + twoStespBefore;
        twoStespBefore = oneStepBefore;
        oneStepBefore =     value;
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

int pisano_period(std::map<std::string, vector<int>> myMap) {
    int first_fibo[] = {0,1,1};
    vector<int> cycle = myMap["cycle"];
    vector<int> index_of_zeros = myMap["index_of_zeros"];
//    print_vector(cycle, "Cycle");
//    print_vector(index_of_zeros, "index_of_zeros");
    for (int i = 0 ; i < index_of_zeros.size() - 1 ; i++) {
        //crete subvector
        vector<int> sub(&cycle[index_of_zeros[i]],&cycle[index_of_zeros[i+1]]);
//        print_vector(sub, "sub");
        vector<int>::iterator it;
        it = std::search(sub.begin(), sub.end(), first_fibo, first_fibo+3);
        if (it!=sub.end()){
            return index_of_zeros[i];
        }
    }
    return 0;
}


/* this return value is not being used
 * I need to return a map that holds two vectors cycle and index_of_zeros
 *
 */
//vector<int> calc_pisano_cycle(int n){
std::map<std::string, vector<int>> calc_pisano_cycle(unsigned long long n){
    vector<int> cycle;
    vector<int> index_of_zeros;
    
    cycle.push_back(0);
    cycle.push_back(1);
    int zeros = 0;
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
    }
//    print_vector(cycle, "pisano cycle: ");
//    print_vector(index_of_zeros, "pisano index_of_zeros: ");
//    std::cout << "pisano period: " << pisano_period(cycle, index_of_zeros) << "\n";
    std::map<std::string, vector<int>> myMap;
    myMap.insert(std::pair<std::string, vector<int>> {"cycle", cycle});
    myMap.insert(std::pair<std::string, vector<int>> {"index_of_zeros", index_of_zeros});
    return myMap;
}

unsigned long long calc_mod_fib(unsigned long long n, unsigned long long m){
//    354224848179261915075 - true
//    3736710778780434371   - wrong 
    std::map<std::string, vector<int>> mapOfarrays = calc_pisano_cycle(m);
    unsigned long long period = pisano_period(mapOfarrays);
//    std::cout << "pisano period: " << period << "\n";
    unsigned long long remain = n % period;
//    std::cout << "remain: " << remain << "\n";
    __uint128_t fibo_of_remain = calc_fib_fast_noVector(remain);
//    std::cout << "fibo_of_remain: " << fibo_of_remain << "\n";
    unsigned long long module = fibo_of_remain % m;
//    std::cout << "module: " << module << "\n";
    return module;
}


int main() {
    unsigned long long n = 0;
    unsigned long long m = 0;
    std::cin >> n >> m;
//    std::cout << "Fast: " << calc_fib_fast(n) << '\n';
//    std::cout << "Slow: " << calc_fib(n) << '\n';
//    std::cout << calc_fib_fast(n) << '\n';
//    uncomment
//    std::cout << calc_fib_fast_noVector(n) << '\n';
    if (m == 1) {
//        std::cout << "pisano period: 1";
        std::cout << 1;
        return 0;
    }
    
//    calc_pisano_cycle(n);
    std::cout << calc_mod_fib(n, m);
    return 0;
}