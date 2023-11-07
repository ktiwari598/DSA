//
// Created by karan on 11/7/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * O(sqrt(n)) approach
 */
bool prime_numbers_test(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

/**
 * Sieve of Eratosthenes approach
 * Only suitable for finding prime numbers from 2 to 1e7
 */
bool prime[1000000000];

void sieve() {
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i <= 1000000000; i++) {
        if (prime[i]) {
            /**
             * Starting from i*i, as previous elements (i.e 2 to i-1, have already checked for primes)
             * Eg. i=5, 15 = 5*3 or 3*5, we have already marked all multiples of 3, so we start from i*i=25
             */
            for (int j = i * i; j <= 1000000000; j += i) {
                prime[j] = false;
            }
        }
    }
}


int main() {
    /*Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    /* You can call it like this : start = time(NULL);
    in both the way start contain total time in seconds
    since the Epoch. */
    time(&start);


    //cout<<prime_numbers_test(11)<<"\n";
    sieve();
    cout << prime[1100780] << " " << prime[7] << " " << prime[20] << endl;
    //for(auto it: primes) cout<<it<<" ";


    // Recording end time.
    time(&end);
    // Calculating total time taken by the program.
    auto time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}