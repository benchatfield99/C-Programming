#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Assessment 1 for the PHY2027 module
Date:05/10/2018
bc367

This program asks the user to provide values for the angle of elevation
and the initial speed of a projectile on the ground, it then checks
that the values entered adhere to certain sanity checks before doing a series
of calculations to compute the maximum height and distance reached by the projectile*/

#define gravity 9.80665
#define PI 3.14159

int main(){

    //defining the variables I will use for my calculations
    float input_velocity, input_angle, angle_rad;
    float height, distance, time;
    float velocity_x, velocity_y;

    printf("Please input values for initial velocity and angle of elevation in the form:\nvelocity \nangle\n");
    scanf("%g\n %g", &input_velocity, &input_angle);

    //These are the sanity checks to ensure entered values are in reason with the problem
    if (input_velocity<0 || input_velocity>3e+8){

        printf("Input velocity must be greater than zero but not larger than c\n");
        return -1;

    }if (input_angle>90 || input_angle<0){

        printf("Input angle must be between 0 and 90\n");
        return -1;

    }else{

        printf("Input values accepted\n");

    }

    //This is the start of the calculations which involve a set of suvat equations and numerical definition

    angle_rad = (input_angle*PI)/(180.0);
    velocity_x = input_velocity*cos(angle_rad);
    velocity_y = input_velocity*sin(angle_rad);
    time = (velocity_y)/(gravity);

    //These are the final calculations of the values the program is running to produce
    height = (pow(velocity_y,2))/(2.0*gravity);
    distance = (2.0*velocity_x)*(time);

    printf("The measurements of height and distance calculated from the input values of velocity are: height=%g and distance:%g", height, distance);

    return 0;

}


/* RESULTS -----------------------------------

i) velocity=6, angle=0, height=0 distance=0

ii) velocity=6, angle=90* height =1.83549 (would still reach a max height) distance=9.31e-6 (Not zero due to Pi only being defined to 5d.p

iii) velocity=6 angle=45 height=0.92 distance=3.67

iv) velocity=-6 angle=45 output=Input velocity must be greater than zero but not larger than c

*/


