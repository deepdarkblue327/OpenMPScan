/*  Sunil
 *  UMASANKAR
 *  suniluma
 */

#ifndef A0_HPP
#define A0_HPP
#include<omp.h>
using namespace std;

template <typename T, typename Op>

void omp_scan(int n, const T* in, T* out, Op op) {
    static long steps = 100000000;
    double step = 1.0/(double)steps;
    double sum = 0.0;
    omp_set_num_threads(4);
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < steps; i++) {
        double x = (i+0.5)*step;
        sum += 4.0/(1.0 + x*x);
    }
    double pi = step*sum;
    cout<<pi<<endl;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp critical
            cout<<omp_get_thread_num()<<"  ";

            //std::cout<<omp_get_num_threads();
        }
    }


} // omp_scan

#endif // A0_HPP
