/*  v_dot function specific to the Double Pendulum problem
    CID: 01707131   */

#include "RK4.h"

// This method is specific to the Double Pendulum problem
void v_dot(std::vector<double> &f, std::vector<double> &l, std::vector<double> &m, std::vector<double> &v){

    // Implementing the v_dot vector evaluated symbolically in Part 1... Inevitable mess ahead.
    // For the specific problem, user is free to modify from here....
    f[0] = ( v[2] );
    f[1] = ( v[3] );
    f[2] = ( -( l[1] * m[1] * ( -G * sin(v[1]) + l[0] * pow(v[2], 2) * sin(v[0]-v[1]) ) * cos(v[0]-v[1]) )
                                /( -l[0] * l[1] * m[1] * pow(cos(v[0]-v[1]), 2) + l[0] * l[1] * (m[0]+m[1]) )
                    -( l[1] * (G * (m[0]+m[1]) * sin(v[0]) + l[1] * m[1] * pow(v[3], 2) * sin(v[0]-v[1])) )
                                /( -l[0] * l[1] * m[1] * pow(cos(v[0]-v[1]), 2) + l[0] * l[1] * (m[0]+m[1]) ) );

    f[3] = ( l[0] * (m[0]+m[1]) * (-G * sin(v[1]) + l[0] * pow(v[2], 2) * sin(v[0]-v[1]))
                                /( -l[0] * l[1] * m[1] * pow(cos(v[0]-v[1]), 2) + l[0] * l[1] * (m[0]+m[1]) )
                    +( l[0] * (G * (m[0]+m[1]) * sin(v[0]) + l[1] * m[1] * pow(v[3],2) * sin(v[0]-v[1])) * cos(v[0]-v[1]) )
                                /( -l[0] * l[1] * m[1] * pow(cos(v[0]-v[1]), 2) + l[0] * l[1] * (m[0]+m[1]) ) );

    // ... to here!
    return;
}