/**
 * @file MachineLearning.cpp
 * @author juchunyu
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<vector>

#define SIZE 6
using namespace std;

int main(){
     /***
      Y = 2 X +9,
      (1,11) (2,13) (3,15) (4,17)
      */  
    double a[SIZE][2]    = {1,11,2,13,3,15,4,17,5,19,6,21};
    double iterations    = 1000;
    double tolerance     = 0.01;
    double Y             = 0.1;
    int  J_iterations    = 0;
    /*
    *F = W*X+B
    *J = (W*Xi+B-yi)^2/2*n
    */
    double W = 0;
    double B = 0;
    double W_temp;
    double B_temp;
    double J_last;
    double J_current;
    double W_result;
    double B_result;

    for(int k = 0;k < SIZE;k++){
        J_last += (W * a[k][0] + B - a[k][1]) *  (W * a[k][0] + B - a[k][1]);
    }
    J_last = J_last/(2*SIZE);

    for(int i = 0;i < iterations;i++){
       double DJDW = 0;
       for(int k = 0;k < SIZE;k++){
           DJDW += (W * a[k][0] + B - a[k][1]) * a[k][0];
       }
       DJDW = DJDW/SIZE;

       double DJDB = 0;
       for(int k = 0;k < SIZE;k++){
           DJDB += W * a[k][0] + B -a[k][1];
       }
       DJDB = DJDB/SIZE;

       W_temp = W- Y * DJDW;
       B_temp = B - Y * DJDB;

       W = W_temp;
       B = B_temp;
       J_current = 0;
       for(int k = 0;k < SIZE;k++){
          J_current += (W * a[k][0] + B - a[k][1]) * (W * a[k][0] + B - a[k][1]);
       }
       J_current = J_current/(2*SIZE);
       if(abs(J_current - J_last) < tolerance){
            W_result     = W;
            B_result     = B;
            J_iterations = i;
            break;
       }
       J_last = J_current;
    } 

    cout<<"W_result:"<<W_result<<endl;
    cout<<"B_result:"<<B_result<<endl;
    cout<<"J_iterations:"<<J_iterations<<endl;
}
