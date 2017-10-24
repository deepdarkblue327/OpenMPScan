/*  Sunil
 *  UMASANKAR
 *  suniluma
 */

#ifndef A0_HPP
#define A0_HPP
#include<omp.h>
using namespace std;

/*
template <typename T, typename Op>
void recursion(int n, const T* in, T* out, Op op) {
    omp_set_dynamic(true);
    omp_set_num_threads(omp_get_num_procs());
    vector<T> y(n/2+1, 0);
    vector<T> z(n/2+1, 0);

    out[0] = in[0];
    if(n == 1) {
        z[0] = y[0];
        return;
    }

    #pragma omp parallel for
    for(int i = 0; i < n/2; i++) {
        y[i] = op(in[2*i],in[2*i + 1]);
    }

    recursion(n/2,y.data(),z.data(),op);
    #pragma omp parallel for
    for(int i = 1; i < n; i++) {
        if (i%2 == 0) {
            out[i] = op(z[i/2 - 1], in[i]);
        }
        else {
            out[i] = z[(i-1)/2];
        }

    }


} // omp_scan

*/

template <typename T, typename Op>
void omp_scan(int n, const T* in, T* out, Op op) {
    omp_set_dynamic(true);
    int number_of_processors = omp_get_num_procs();
    omp_set_num_threads(number_of_processors);
    int parallel_chunk = n/number_of_processors;

    //int k = 0;
    //int parallel_chunk = 5;
    //int n = 9;
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
