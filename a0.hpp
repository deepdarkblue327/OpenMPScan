/*  Sunil
 *  UMASANKAR
 *  suniluma
 */

#ifndef A0_HPP
#define A0_HPP
#include<omp.h>
template <typename T, typename Op>

void omp_scan(int n, const T* in, T* out, Op op) {
    #pragma omp parallel
    {
        std::cout<<omp_get_num_threads()<<std::endl;
    }

} // omp_scan

#endif // A0_HPP
