#include <iostream>
#include <QElapsedTimer>
#include <QDebug>

using namespace std;

int main()
{
    const int MAX = 100000;
    long long int primes[MAX];
    primes[0] = 2;
    primes[1] = 3;

    long int prime_count = 2;
    long long int prime_index = 4;
    QElapsedTimer timer;

    //start measuring time
    timer.start();
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

    //display primes
//    for (int i=0; i < 100; ++i)
//        cout << primes[i] << '\t';

    qDebug() << "First " << MAX << " primes found in " << timer.elapsed() << " milliseconds" << endl;
    system("PAUSE");

    return 0;
}
