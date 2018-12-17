#include <stdio.h>
#include <stdlib.h>
#define LMAX 10
#define MERCURYE 0.206
#define VENUSE 0.007
#define EARTHE 0.017
#define MARSE 0.093
#define JUPITERE 0.048
#define SATURNE 0.056

/*
* bc367
* Project for the PHY2027 module
* Deadline: 14-12-18
*/


/*
 * This program utilises the Runge-Kutte method to
 * approximate the orbits of planets, it also
 * provides a way of visualising these generated orbits
 *
 */

typedef struct planets{
    char name[LMAX];
    float position[2];
    float velocity[2];
    float acceleration[2];
    float eccen;
}Planet;

void planet_sim(int inputtwo, Planet *planet);
void all_sim(Planet *planet);

int main()
{
    int input, inputtwo;

    Planet *planet = NULL;
    planet = (Planet *) malloc(7 * sizeof(Planet));

    int x=0;
    while(x<1){

            printf("Do you want to simulate orbits of planets? (1 - PROCEED) (0 - EXIT)\n");
            scanf("%i", &input);

            switch(input){

            case 0:
                ++x;
                break;

            case 1:
                printf("\nYou have selected to simulate the orbits, please select which of the following you would like to simulate:\n");
                printf("Mercury - [0]\n Venus - [1]\n Earth - [2]\n Mars - [3]\n Jupiter - [4]\n Saturn - [5]\n Uranus - [6]\n All - [7]\n");
                scanf("%i", &inputtwo);
            }

            if(inputtwo>=0 && inputtwo<7){
                planet_sim(inputtwo, planet);
            }if(inputtwo == 7){
                all_sim(planet);
            }else{
                printf("Input is not recognised...");
                return 0;
            }


return 0;
}

void planet_sim(int inputtwo, Planet *planet){

}

void all_sim(Planet *planet){

}
