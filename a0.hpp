/*  SUNIL
 *  UMASANKAR
 *  suniluma
 */

#ifndef A0_HPP
#define A0_HPP
#include<omp.h>
using namespace std;


template <typename T, typename Op>
void omp_scan(int n, const T* in, T* out, Op op) {
    omp_set_dynamic(true);
    int number_of_processors = omp_get_num_procs();
    omp_set_num_threads(number_of_processors);
    int parallel_chunk = n/number_of_processors;

    #pragma omp parallel for
    for(int i = 0; i < n; i+=parallel_chunk) {
        out[i] = in[i];
        for(int j = i+1; j < n && j < i+parallel_chunk ; j++) {
            out[j] = out[j-1] + in[j];
        }
    }

    for(int i = 2*parallel_chunk-1; i < n; i+=parallel_chunk) {
        out[i] += out[i-parallel_chunk];
    }

    #pragma omp parallel for
    for(int i = parallel_chunk; i < n; i+=parallel_chunk) {
        int temp = i+parallel_chunk;
        if (temp > n) {
            temp = n+1;
        }
        #pragma omp parallel for
        for(int j = i; j < temp-1; j++) {
            out[j] += out[i-1];
        }
    }

} // omp_scan

#endif // A0_HPP
