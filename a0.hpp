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
    int num_threads;
     omp_set_dynamic( 0 );
     omp_set_num_threads( omp_get_num_procs() );
    #pragma omp parallel
     { int id=omp_get_thread_num();
    #pragma omp single
     num_threads = omp_get_num_threads();
     cout<<"ID ";
     cout<<id<<endl;
     cout<<"NUM Procs ";
     cout<<num_threads<<endl;
 }


} // omp_scan

#endif // A0_HPP
