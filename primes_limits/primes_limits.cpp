#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int MAX = 100000;
    long long int primes[MAX];

    primes[0] = 2;
    primes[1] = 3;

    long int prime_count = 2;   // holds the number of primes
    long long int prime_index = 4;

    // below calculates the primes
    // note that it is not optimized. For primality it is sufficient to check up to square root
    while(prime_count < MAX){
        bool is_prime = true;
        for(long int i = 0; i < prime_count; ++i){
            if(prime_index % primes[i] == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes[prime_count] = prime_index;
            ++prime_count;
        }
        ++prime_index;
    }

    // let p(x) denotes the number of primes between 2 and x
    // lim[x-->inf] (x*ln(x)/x) ->1
    // below line is a numerical verification of the above
    cout << prime_count*log(primes[MAX-1])/primes[MAX-1] << endl;

    return 0;
}
