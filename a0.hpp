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

    omp_set_dynamic(true);
    omp_set_num_threads(omp_get_num_procs());
    std::vector<T> y(n/2+1, 0);
    std::vector<T> z(n/2+1, 0);

    out[0] = in[0];
    if(n == 1) {
        z[0] = y[0];
        return;
    }

    #pragma omp parallel for
    for(int i = 0; i < n/2; i++) {
        y[i] = op(in[2*i],in[2*i + 1]);
    }

    omp_scan(n/2,y.data(),z.data(),op);
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

#endif // A0_HPP
