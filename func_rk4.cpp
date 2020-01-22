/* Introduction to Scientific Programming, Programming project, 2019/2020 */
/* (c) Matthias Braendel, 2019 */
/* func_rk4.cpp */

#include <vector>
#include "func.h"
#include "func_segway.h"

void f_rk4( std::vector< std::vector<double> >          &y,
            const std::vector<double>                   &tspan,
            const std::vector< std::vector<double> >    &A,
            const std::vector<double>                   &b1,
            std::vector<double>                         &F,
            const std::vector<double>                   &b2,
            const std::vector<double>                   &T,
            const std::vector<double>                   &C,
            const std::vector<double>                   &K){
    /* initialization of temporary vectors */
    // #################
    // Your code here...
    // TASK 3.1: declare and initialize the temporary vectors k1,k2,k3,k4,yn,yt
    // #################
    // Initialising two variables as follows...
    int n = 4; // The size of each temperory vector
    int s = tspan.size() - 1; // To get the last value of the tspan to get step size
    // Declaring and initialising k1
    std::vector<double> k1(n);
    f_vecinit(k1);
    // Declaring and initialising k2
    std::vector<double> k2(n);
    f_vecinit(k2);
    // Declaring and initialising k3
    std::vector<double> k3(n);
    f_vecinit(k3);
    // Declaring and initialising k4
    std::vector<double> k4(n);
    f_vecinit(k4);
    // Declaring and initialising yn
    std::vector<double> yn(n);
    f_vecinit(yn);
    // Declaring and initialising yt
    std::vector<double> yt(n);
    f_vecinit(yt);
    // #################
    // Your code here...
    // TASK 3.2: compute the time step size h
    double h; // Initialisation of time step size h
    h = (tspan[s] - tspan[0]) / s; // Computation of time step size h
    // #################
    /* classical Runge-Kutta method */
    for(unsigned int m = 0; m < tspan.size(); m++){
        // #################
        // Your code here...
        // TASK 3.3+4: implement the following pseudo code:
        // (1) yn = y[:][m]; // m-th colum for the m-th time step of y
        // (2) yt = yn;
        // (3) f_segway(yt,...,k1); // new k1
        // (4) yt = yn+0.5*h*k1;
        // (5) f_segway(yt,...,k2); // new k2
        // (6) yt = yn+0.5*h*k2;
        // (7) f_segway(yt,...,k3); // new k3
        // (8) yt = yn+h*k3;
        // (9) f_segway(yt,...,k4); // new k4
        // #################
        // compute new k1
        // compute new k2
        // compute new k3
        // compute new k4
        /* update y */
        // #################
        // Your code here...

        // copying values of mth column of y to yn
        for (unsigned int i = 0; i < 4; i++) {
            yn[i] = y[i][m];
        }
        // copying values of yn to yt
        f_veccpy(yt, yn); // func.h

        // computing new k1
        f_segway(m, yt, A, b1, F, b2, T, K, k1);

        // updating yt
        for (unsigned int l = 0; l < 4; l++) {
            yt[l] = yn[l] + (0.5 * h * k1[l]);
        }

        // computing new k2
        f_segway(m, yt, A, b1, F, b2, T, K, k2);

        // updating yt
        for (unsigned int l = 0; l < 4; l++) {
            yt[l] = yn[l] + (0.5 * h * k2[l]);
        }

        // computing new k3
        f_segway(m, yt, A, b1, F, b2, T, K, k3);

        // updating yt
        for (unsigned int l = 0; l < 4; l++) {
            yt[l] = yn[l] + ( h * k3[l]);
        }

        // computing new k4
        f_segway(m, yt, A, b1, F, b2, T, K, k4);

        // TASK 3.4: update new column of y with the old column and the k's
        // y[:][m+1] = y[:][m]+h/6*(k1+2*k2+2*k3+k4);
        
        // Creating a loop to compute and update the values in y
        for (unsigned int i = 0; i < 4; i++) {
            y[i][m + 1] = y[i][m] + ((h / 6) * (k1[i] + (2 * k2[i]) + (2 * k3[i]) + k4[i]));
        }
        
        // #################
    }
}
