/* Introduction to Scientific Programming, Programming project, 2019/2020 */
/* (c) Matthias Braendel, 2019 */
/* func_segway.cpp */

#include <vector>
#include "func.h"


void f_segway(  unsigned int                                m,
                const std::vector<double>                   &yt,
                const std::vector< std::vector<double> >    &A,
                const std::vector<double>                   &b1,
                std::vector<double>                         &F,
                const std::vector<double>                   &b2,
                const std::vector<double>                   &T,
                const std::vector<double>                   &K,
                std::vector<double>                         &ki){
    /* Matlab Pseudocode
        F = -K*y;
        dydt = A*y+b1*F+b2*T;
        dydt -> k, which is one of: (k1,k2,k3,k4)
    */

    // Declaring and initialising the vectors dydt and temp
    std::vector<double> dydt(4), temp(4);
    f_vecinit(dydt);
    f_vecinit(temp);

    // #################
    // Your code here...
    // TASK 4.1: computing F = -K*y;

    // updating temp to get -K
    f_vecupd(temp, -1, K);

    // calling function to compute the product 
    F[m]=f_scalarp(temp, yt);

    // #################
    // #################
    // Your code here...
    // TASK 4.2: computing temp = A*y
   
    // Calling a function to do the computation as specified...
    f_matvecmult(temp, A, yt);
    
    // #################
    // #################
    // Your code here...
    // TASK 4.3: computing dydt = temp + b1*F+b2*T
    
    // Creating a loop to do the computation as specified...
    std::vector<double> temp1(4), temp2(4);
    f_vecinit(temp1);
    f_vecinit(temp2);
    f_vecupd(temp1, F[m], b1);
    f_vecupd(temp2, T[m], b2);
    for (unsigned i = 0; i < dydt.size(); i++) {
        dydt[i] = temp[i] + temp1[i] + temp2[i];
    }
    // #################
    // #################
    // Your code here...
    // TASK 4.4: assign dydt to k with the veccpy function
    
    // Calling a function to do the computation as specified...
    f_veccpy(ki,dydt);
    
    // #################
}
