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
    int thread_id;
    omp_set_dynamic(false);
    omp_set_num_threads(omp_get_num_procs());
    #pragma omp parallel
    {
        thread_id=omp_get_thread_num();
        cout<<thread_id;

    }
} // omp_scan

#endif // A0_HPP
