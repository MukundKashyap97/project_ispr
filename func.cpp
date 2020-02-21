/* Introduction to Scientific Programming, Programming project, 2019/2020 */
/* (c) Matthias Braendel, 2019 */
/* func.cpp */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "func.h"

void f_introduction(){
    std::cout << "\nHello, this is the programming project for the students of the module";
    std::cout << "\nIntroduction to Scientific Programming, WS 2019/2020, TUBAF";
    std::cout << "\n\nGoal is to complete the code given to create a little movie of ";
    std::cout << "an inverse pendulum balancing itself!\n";
}

// https://www.geeksforgeeks.org/passing-vector-function-cpp/
void f_vecinit(std::vector<double> &v){
    for(unsigned int m = 0; m < v.size(); m++){
        v[m] = 0.0;
    }
}

void f_filltspan(std::vector<double> &v, double tsta, double tend, int framerate){
    // #################
    // Your code here...
    // TASK 2.1: fill the tspan array with time-steps: tstart, tstart+h,...tend
   
    // Creating a loop to fill tspan array below... 
    float step;
    step = 1.0 / framerate;
    for (unsigned int i = 0; i < v.size();i++) {
        if (i == 0){
            v[i] = tsta;
        }
        else {
            v[i] = v[i - 1] + step;
        }
    }
    
    // #################
}

void f_printtimeoptions(const std::vector<double> &v, double tsta, double tend,int framerate){
    // #################
    // Your code here...
    // TASK 2.2: print time options as shown below, but with your actual values from your actual variables
    
    std::cout << "\n  Values:\n\t start time: " << std::to_string(tsta) << "\n\t end time: " << std::to_string(tend) << "\n\t framerate: " << std::to_string(framerate) << "\n\t #steps: " << std::to_string(v.size()) << "\n";
    
    // #################
    
    std::cout << "\n  Expected values:\n\t start time: 0.000\n\t end time: 10.000\n\t framerate: 100\n\t #steps: 1001\n";
}

void f_printmodelparameters(double g, double m1, double m2, double l){
    // #################
    // Your code here...
    // TASK 2.3: see f_printtimeoptions
    
    std::cout << "\n  Values:\n\t gravitational constant: " << g << "\n\t mass of wagon: " << m1 << "\n\t mass of pendulum: " << m2 << "\n\t length of pendulum: " << l << "\n";
    
    // #################
    
    std::cout << "\n  Expected values:\n\t gravitational constant: 9.810\n\t mass of wagon: 1.080\n\t mass of pendulum: 0.360\n\t length of pendulum: 0.204\n";
}


void f_printcoefficients(const std::vector<double> &C){
    // #################
    // Your code here...
    // TASK 2.4: see f_printmodelparameters
    
    std::cout << "\n  Values:\n\t C_0: " << C[0] << "\n\t C_1: " << C[1] << "\n\t C_2: " << C[2];
    std::cout << "\n\t C_3: " << C[3] << "\n\t C_4: " << C[4] << "\n\t C_5: " << C[5] << "\n";
    
    // #################
    std::cout << "\n  Expected values:\n\t C_0: -0.051\n\t C_1: 0.051\n\t C_2: 0.694\n\t C_3: 3.676\n\t C_4: 36.066\n\t C_5: 50.061\n";
}

void f_filldisturbance(std::vector<double> &T, double valT, std::vector<double> tdist, int framerate){
    int index = int(tdist[0]*framerate);
    for(unsigned int m = 0; m < tdist.size(); m++){
        T[index+m] = valT;
    }
   
}

void f_printdisturbance(double valT, double tdiststa, double tdistend, int framerate){
    // #################
    // Your code here...
    // TASK 2.5: see f_printcoefficients
    
    std::cout << "\n Values:\n\t start time: " << std::to_string(tdiststa) << "\n\t end time: " << tdistend;
    std::cout << "\n\t stepsize: " << (1.00 / framerate) << "\n\t magnitude: " << std::to_string(valT) << "\n";
    
    // #################
    std::cout << "\n  Expected values:\n\t start time: 1.000\n\t end time: 1.100\n\t stepsize: 0.010\n\t magnitude: 1.000\n";
}

void f_matinit(std::vector< std::vector<double> > &A){
    unsigned int nofrows = A.size();
    for(unsigned int mr = 0; mr < nofrows; mr++){
        unsigned int nofcols = A[mr].size();
        for(unsigned int mc = 0; mc < nofcols; mc++){
            A[mr][mc] = 0.0;
        }
    }
    /* or
    for(unsigned int mr = 0; mr < nofrows; mr++){
        f_vecinit(A[mr]);
    } */
}

void f_printlinearsystem(const std::vector< std::vector<double> > &A,const std::vector<double> &b1, const std::vector<double> &b2, const std::vector<double> &K){
    std::cout << "\nLinear system A*x+b1*F+b2*T:";
    // #################
    // Your code here...
    // TASK 2.6: obtain the following format with your variables
    
    // Creating nested loop to display the values in the specified format... 
    std::cout << "\n  Values: ";
    for (int i = 0; i < 4; i++) {
        std::cout << "\n\t | ";
        for (unsigned int w = 0; w < A[i].size(); w++) {
            std::cout << std::to_string(A[i][w]) << " ";
        }
        std::cout << "| |x_" << i + 1 << "| + ";
        std::cout << "|" << std::to_string(b1[i]) << "|*F + " << "|" << std::to_string(b2[i]) << "|*T\t";
    }
    
    // #################
    
    std::cout << "\n  Expected values:\n\t|0.000	1.000	0.000	0.000||x_1|  +  |0.000|*F  +  |0.000|*T\n\t|0.000	0.000	2.264	0.000||x_2|  +  |0.855|*F  +  |3.142|*T\n\t|0.000	0.000	0.000	1.000||x_3|  +  |0.000|*F  +  |0.000|*T\n\t|0.000	0.000	44.389	0.000||x_4|  +  |3.142|*F  +  |61.613|*T\n";
    std::cout << "\n  Control Matrix K:\n\t";
    
    // #################
    // Your code here...
    // TASK 2.6: display the control matrix K, that is actually a vector
    
    std::cout << "\n Values: \n\t| ";
    for (unsigned int w = 0; w < K.size(); w++) {
        std::cout << K[w] << " ";
    }
    std::cout<<"|\n";
    
    // #################
    
    std::cout << "\n  Expected values:\n\t|-0.779 -1.622 25.477 3.624|\n";
}

void f_systemhasbeensetup(){
    std::cout << "\nThe system has been set up successfully!\n";
}

unsigned int f_checksize(const unsigned int v, const unsigned int w){
    /* check for equal size of the vectors, if not ... */
    if(v != w){
        std::cout << "Different vector sizes!\n";
        /* check, which vector is smaller, take its size ... */
        if(v < w){
            return v;
        }else{
            return w;
        }
    }else{
        return v;
    }
}

void f_veccpy(std::vector<double> &v, const std::vector<double> &w){
    unsigned int msize = f_checksize(v.size(),w.size());
    // #################
    // Your code here...
    // TASK 5.1: copy v's values on w
    // Using the notation specified in vector libraries
    
    for (unsigned int i = 0; i < msize; i++) {
        v[i] = w[i];
    }
    
    // #################
}

double f_scalarp(const std::vector<double> &v, const std::vector<double> &w){
    unsigned int msize = f_checksize(v.size(),w.size());
    double val = 0.0;
    // #################
    // Your code here...
    // TASK 5.2: do the scalar product computation
    // Creating a loop to do the scalar product computation below...
    
    for (unsigned int i = 0; i < msize; i++) {
        val = val + (v[i] * w[i]);
    }
    
    // #################
    return val; // val is the scalar product after the termination of the loop
}

void f_matvecmult(std::vector<double> &w, const std::vector< std::vector<double> > &A, const std::vector<double> &v){
    /* row size: */
    unsigned int mrsize = f_checksize(A.size(),w.size());
    /* col size: */
    unsigned int mcsize = f_checksize(A[0].size(),v.size());
    /* w = A*v */
    // #################
    // Your code here...
    // TASK 5.3: do the matrix vector multiplication
    // Creating a loop and using a defined function to compute the matrix product
    
    for (unsigned int i = 0; i < mrsize; i++) {
        w[i] = f_scalarp(A[i], v);
    }
    
    // #################
}

void f_vecupd(std::vector<double> &w, const double a, const std::vector<double> &v){
    // #################
    // Your code here...
    // TASK 5.4: write a routine, that assings the vector w = w + a*v
    unsigned int msize = f_checksize(v.size(), w.size());
    // Creating a loop to perform the specified routine 
    
    for (unsigned int i = 0; i < msize; i++) {
        w[i] = w[i] + (a * v[i]); // w = w + a*v for each iteration
    }
    
    // #################
}

void f_succeed(){
    std::cout << "\nThe classical Runga-Kutta method finished!\n";
}

void f_fileoutput(const std::vector<double> &tspan, const std::vector< std::vector<double> > &y, const std::vector<double> &F, const std::vector<double> &T){
    std::ofstream F_out;
    F_out.open("segway.txt", std::ios::out);
    for(unsigned int m = 0; m < tspan.size(); m++){
        F_out << tspan[m] << " " << y[0][m+1] << " " << y[2][m+1] << " " << F[m] << " " << T[m] << "\n";
    }
    F_out.close();
    std::cout << "\nWrote data to file segway.txt!\n";
}

void f_vecshow(const std::vector<double> &v){
    for(unsigned int m = 0; m < v.size(); m++){
        std::cout << v[m] << "\t";
    }
}

void f_matshow(const std::vector< std::vector<double> > &A){
    for(unsigned int i = 0; i < A.size(); i++){
        for(unsigned int j = 0; j < A[i].size(); j++){
            std::cout << A[i][j] << " ";
        }
    std::cout << "\n";
}
}
