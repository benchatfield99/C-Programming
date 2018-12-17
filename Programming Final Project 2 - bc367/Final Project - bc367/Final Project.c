#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 15

/*
* Final Project for the PHY2027 module
* Date: 12/12/2018
*/


/* This program provides and executes 3 different methods for solving the integrand of a linear polynomial
 * the first is the trapezium rule, the second is Simpson's rule and the last is an exact integral method
 * the results of the integral are then printed on the screen.
 *
 *
 */

 //although it wasn't strictly needed I used a structure here along with the *integral
 //to allow implementation of storing more than one integral at a time however this wasn't implemented fully in time
typedef struct polynomial{
    int order;
    float limits[2];
    int partitions;
}Poly;


void trap_rule(Poly *integral, float coeff[]);
void simp_rule(Poly *integral, float coeff[]);
void exact_rule(Poly *integral, float coeff[]);


int main()
{
    int choice, order, i=0;

    //setting the pointer as spoken about earlier (with dynamic allocation)
    Poly *integral = NULL;
    integral = (Poly *) malloc(sizeof(Poly));

    printf("Please choose a polynomial order for example highest power of x^n where n is the order polynomial:\n");
    scanf("%i", &integral[0].order);
    printf("Choose coefficients for each of the orders given (starting with the smallest power)\n");

    float *coeff = (float*) calloc(integral[0].order, sizeof(float));

    //scanning in the polynomial coefficients (cannot put in structure as allocated depending on order)
    while(i<=integral[0].order){
            printf("Please enter coefficient %i:\n", i);
            scanf("%f", &coeff[i]);
            ++i;
    }

    int p=0;
    while(p<1){
    printf("\n\nPlease select which integration method you want to use:\n(1) - Trapezoidal Rule\n(2) - Simpson's Rule\n(3) - Exact Integral\n(0) - Exit\n");
    scanf("%i", &choice);

    switch(choice){

    case 1:
        trap_rule(integral, coeff);
        break;

    case 2:
        simp_rule(integral, coeff);
        break;

    case 3:
        exact_rule(integral, coeff);
        break;

    case 0:
        ++p;
        return 0;

    default:
        printf("Input not recognised...");
        return -1;
    }
    }

return 0;
}

//function for the trapezium rule method
void trap_rule(Poly *integral, float coeff[]){

    //scanning in all the method specific conditions
    printf("\nPlease enter the limits of the integral (smaller then larger):\n");
    scanf("%f %f", &integral[0].limits[0], &integral[0].limits[1]);

    printf("Please enter the number of parses/partitions to compute for this integral:\n");
    scanf("%i", &integral[0].partitions);

    //defining all the variables used for the method
    int order = integral[0].order;
    float h = ((sqrt(pow((integral[0].limits[0]-integral[0].limits[1]),2)))/((float) integral[0].partitions));
    float y[integral[0].partitions + 1];
    float x[integral[0].partitions + 1];

    //finding the x values (boundary points between trapeziums)
    for(int s=0; s<(integral[0].partitions + 1); ++s){

            x[s] = integral[0].limits[0] + s*h;
    }

    //nested for loop to build the substituted values and all the y values at the same time
    for(int m=0; m<integral[0].partitions+1; ++m){
        for(int n=0; n<=order; ++n){

            y[m] += (coeff[n])*(pow(x[m],n));
        }
    }

    //final loop to collect element sums and do final products/sums
    float area=0;
    for(int t=0; t<(integral[0].partitions+1); ++t){

            area += h*y[t];
    }

    //adjustment that needs to be made for the correct formula
    area -= (h/2)*(y[0] + (float) y[(integral[0].partitions+1)]);

    printf("\nThe area calculated for the polynomial input was: %f", area);
    area = 0;
    free(coeff);
}

void simp_rule(Poly *integral, float coeff[]){

    printf("\nPlease enter the limits of the integral (smaller then larger):\n");
    scanf("%f %f", &integral[0].limits[0], &integral[0].limits[1]);

    printf("Please enter the number of parses/partitions to compute for this integral:\n");
    scanf("%i", &integral[0].partitions);

    int order = integral[0].order;
    float h = ((sqrt(pow((integral[0].limits[0]-integral[0].limits[1]),2)))/((float) integral[0].partitions));
    float y[integral[0].partitions + 1];
    float x[integral[0].partitions + 1];

    //finding the x values (not points between trapeziums this time but the spacing between consecutive tries)
    for(int s=0; s<(integral[0].partitions + 1); ++s){

            x[s] = integral[0].limits[0] + s*h;
    }

    //nested for loop to build the substituted values and all the y values at the same time
    for(int q=0; q<(integral[0].partitions+1); ++q){
            for(int r=0; r<=order; ++r){

                    y[q] += (coeff[r])*(pow(x[q],r));
            }
    }

    //final loop to collect element sums and do final products/sums
    float area=0;
    for(int e=0; e<(integral[0].partitions+1); ++e){

            area += 2*(h/3)*(y[2*e]);
            area += 4*(h/3)*(y[2*e +1]);

    }

    //adjustments for the formula again
    area -= (h/3)*(y[0]);
    area -= (h/3)*(y[integral[0].partitions + 1]);

    printf("\nThe area calculated for the polynomial input was: %f", area);
    area = 0;
    free(coeff);
}

void exact_rule(Poly *integral, float coeff[]){

    printf("\nPlease enter the limits of the integral (smaller then larger):\n");
    scanf("%f %f", &integral[0].limits[0], &integral[0].limits[1]);

    int order = integral[0].order;
    float *ymark = (float*) calloc(NMAX, sizeof(float));
    float area=0;

    //handles the case of a simple rectangular area
    if(order == 0){

        area = coeff[0]*integral[0].limits[1] - coeff[0]*integral[0].limits[0];

    //This for loop conducts the integration as would be done on paper but converted into code
    }else if(order != 0){
        for(int n=0; n<=order; ++n){

                ymark[n] = (((coeff[n])*(pow(integral[0].limits[1],n+1)))-(coeff[n]*(pow(integral[0].limits[0],n+1))))/(n+1);
        }

        //final loop to collect element sums and do final products/sums
        for(int i=0; i<=order; ++i){

                area += ymark[i];
        }
    }

    printf("\nThe area calculated for the polynomial input was: %f", area);
    area = 0;
    free(coeff);
}

/* --------------------------- RESULTS --------------------------------------------

*** The example polynomial used was: 3x^2 + 2x +5, between the limits of 0 -> 2. ***


For the TRAPEZIUM RULE the value obtained for 10 partitions was:

    24.365 - This is 2.365 away from the target value, however the trapezium rule becomes
             closer and closer as the partition value is increased.

For the SIMPSON'S RULE the value obtained for 10 partitions was:

    23.549999 - This is 1.549999 away from the target value, the simpson's rule doesnt become
                better the more partitions are selected rather has an optimum value of partitions to get the closest fit which happens to be fairly close to 10.

For the EXACT INTEGRAL the value obtained was:

    22 - This is the value that was expected and it shows that the function is working as intended.

*** A second example used was: 5, between limits of 0 -> 5. A single integer was used here as this is an exception and could cause problems. ***


For the TRAPEZIUM RULE the value obtained for 15 partitions was:

    27.760412 - This is 2.760412 away from the desired value and is so far away as the trapezium rule has difficulty
                with single integers as they cannot be approximated to trapeziums.

For the SIMPSON'S RULE the value obtained for 15 partitions was:

    28.038191 - This is far away from the desired value as well purely because the number of partitions chosen wasn't near
               the optimum point.

For the EXACT INTEGRAL the value obtained was:

    25 - This again proves the function is working correctly.


*/


/* THE CODE RESULTS OF EACH OF THE CASES EXPLAINED ARE SHOWN BELOW: -------------

1a)

Please choose a polynomial order for example highest power of x^n where n is the order polynomial:
2
Choose coefficients for each of the orders given (starting with the smallest power)
Please enter coefficient 0:
5
Please enter coefficient 1:
2
Please enter coefficient 2:
3
Please select which integration method you want to use:
(1) - Trapezoidal Rule
(2) - Simpson's Rule
(3) - Exact Integral
(0) - Exit
1

Please enter the limits of the integral (smaller then larger):
0
2
Please enter the number of parses/partitions to compute for this integral:
10

The area calculated for the polynomial input was: 24.365000

1b)

Please choose a polynomial order for example highest power of x^n where n is the order polynomial:
2
Choose coefficients for each of the orders given (starting with the smallest power)
Please enter coefficient 0:
5
Please enter coefficient 1:
2
Please enter coefficient 2:
3
Please select which integration method you want to use:
(1) - Trapezoidal Rule
(2) - Simpson's Rule
(3) - Exact Integral
(0) - Exit
2

Please enter the limits of the integral (smaller then larger):
0
2
Please enter the number of parses/partitions to compute for this integral:
10

The area calculated for the polynomial input was: 23.549999

1c)

Please choose a polynomial order for example highest power of x^n where n is the order polynomial:
2
Choose coefficients for each of the orders given (starting with the smallest power)
Please enter coefficient 0:
5
Please enter coefficient 1:
2
Please enter coefficient 2:
3
Please select which integration method you want to use:
(1) - Trapezoidal Rule
(2) - Simpson's Rule
(3) - Exact Integral
(0) - Exit
3

Please enter the limits of the integral (smaller then larger):
0
2

The area calculated for the polynomial input was: 22.000000

2a)

Please choose a polynomial order for example highest power of x^n where n is the order polynomial:
0
Choose coefficients for each of the orders given (starting with the smallest power)
Please enter coefficient 0:
5
Please select which integration method you want to use:
(1) - Trapezoidal Rule
(2) - Simpson's Rule
(3) - Exact Integral
(0) - Exit
1

Please enter the limits of the integral (smaller then larger):
0
5
Please enter the number of parses/partitions to compute for this integral:
15

The area calculated for the polynomial input was: 27.760412

2b)

Please choose a polynomial order for example highest power of x^n where n is the order polynomial:
0
Choose coefficients for each of the orders given (starting with the smallest power)
Please enter coefficient 0:
5
Please select which integration method you want to use:
(1) - Trapezoidal Rule
(2) - Simpson's Rule
(3) - Exact Integral
(0) - Exit
2

Please enter the limits of the integral (smaller then larger):
0
5
Please enter the number of parses/partitions to compute for this integral:
15

The area calculated for the polynomial input was: 28.038191

2c)

Please choose a polynomial order for example highest power of x^n where n is the order polynomial:
0
Choose coefficients for each of the orders given (starting with the smallest power)
Please enter coefficient 0:
5
Please select which integration method you want to use:
(1) - Trapezoidal Rule
(2) - Simpson's Rule
(3) - Exact Integral
(0) - Exit
3

Please enter the limits of the integral (smaller then larger):
0
5

The area calculated for the polynomial input was: 25.000000

*/














