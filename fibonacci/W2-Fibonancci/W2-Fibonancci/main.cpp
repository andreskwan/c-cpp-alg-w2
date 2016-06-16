//
//  main.cpp
//  W2-Fibonancci
//
//  Created by Andres Kwan on 4/29/16.
//  Copyright © 2016 kwan.coursera.altgoritms. All rights reserved.
//

#include <iostream>     // cout
#include <algorithm>    // search
#include <vector>       // vector
#include <map>          // vector

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::map;
using std::pair;

typedef long long longInt;
typedef unsigned long long unsigLongInt;
typedef __uint128_t extraLongInt;

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
//        cout << "index: " << 0 << " value: " << fibo_array[0] << "\n";
//        cout << "index: " << 1 << " value: " << fibo_array[1] << "\n";
    for (int i = 2; i <= n; i++) {
        fibo_array[i] = fibo_array[i-1] + fibo_array[i-2];
//        cout << "index: " << i << " value: " << fibo_array[i] << "\n";
    }
    return fibo_array[n];
}

extraLongInt calc_fib_fast_noVector(long long n) {
    extraLongInt oneStepBefore = 1;
    extraLongInt twoStespBefore = 0;
    extraLongInt value = 0;
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

void print_vector(vector<int> cycle, string message){
    cout << "\n";
    cout << message << ": ";
    for(int i = 0; i < cycle.size(); i++ ){
        cout << cycle[i] << " ";
    }
    cout << "\n";
}

int pisano_period(map<string, vector<int>> myMap) {
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
        it = search(sub.begin(), sub.end(), first_fibo, first_fibo+3);
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
map<string, vector<int>> calc_pisano_cycle(unsigLongInt n){
    vector<int> cycle;
    vector<int> index_of_zeros;
    
    cycle.push_back(0);
    cycle.push_back(1);
    int zeros = 0;
    for (int i = 2 ; zeros <= 4; i++) {
        //      cout << "\nstart i: "<< i << "\n";
        cycle.push_back(cycle[i-1] + cycle[i-2]);
        if (cycle[i] >= n) {
            cycle[i] = cycle[i] % n;
        }
        if (cycle[i] == 0) {
            zeros++;
            // cout << "zeros: " <<zeros << "\n";
            // count which zero has been validated
            // avoid to repeat
            index_of_zeros.push_back(i);
        }
    }
//    print_vector(cycle, "pisano cycle: ");
//    print_vector(index_of_zeros, "pisano index_of_zeros: ");
//    cout << "pisano period: " << pisano_period(cycle, index_of_zeros) << "\n";
    map<string, vector<int>> myMap;
    myMap.insert(pair<string, vector<int>> {"cycle", cycle});
    myMap.insert(pair<string, vector<int>> {"index_of_zeros", index_of_zeros});
    return myMap;
}

extraLongInt calc_mod_fib(unsigLongInt n, unsigLongInt m){
    
    map<string, vector<int>> mapOfarrays = calc_pisano_cycle(m);
    unsigLongInt period = pisano_period(mapOfarrays);
    
    cout << "pisano period: " << period << "\n";
    unsigLongInt remain = n % period;
    cout << "remain: " << remain << "\n";
    
    extraLongInt fibo_of_remain = calc_fib_fast_noVector(remain);
//    string s = std::to_string(fibo_of_remain);
    
//    cout <<"fibo_of_remain " <<  << "\n ";
//    cout << "fibo_of_remain: " << fibo_of_remain << "\n";
    
    extraLongInt module = fibo_of_remain % m;
//    cout << "module: " << module << "\n";
    return module;
}


int main() {
    unsigLongInt n = 0;
    unsigLongInt m = 1;
    cin >> n >> m;
//    cin >> n;
//    cout << "Fast: " << calc_fib_fast(n) << '\n';
//    cout << "Slow: " << calc_fib(n) << '\n';
//    cout << calc_fib_fast(n) << '\n';
//    uncomment
//    extraLongInt ivan =  calc_fib_fast_noVector(n);

//    cout <<  << '\n';
    if (m <= 1) {
//        cout << "pisano period: 1";
        cout << 1;
        return 0;
    }

////    calc_pisano_cycle(n);
////    for (int i = 1; i < 20 ; i++) {
////        unsigLongInt ene = i + n;
////        cout << "n: " << ene << " ";
////        cout << "mod  "<< m << " = " << calc_mod_fib(ene, m)  <<  "\n";
////    }
    extraLongInt result = calc_mod_fib(n, 100000);
    extraLongInt result2 = calc_mod_fib(result, m);
//    cout << calc_mod_fib(n, m);
    return 0;
}