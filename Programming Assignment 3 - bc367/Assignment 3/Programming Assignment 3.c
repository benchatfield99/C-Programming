#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 20
#define SMAX 1

/*
* bc367
* Assessment ### for the PHY2027 module
*/

/*
 *
 * This program contains and runs a database that takes students names, marks and grades and allows
 * the user to sort through all of the stored data to find the grade and mark relevant to the student
 * that they input and look for.
 */

 //Defining the structure
typedef struct students{
    char name1[NMAX];
    char name2[NMAX];
    int age;
    float score1, score2, score3, score4, score5;
    float avgmark;
    char finalgrade[SMAX];

}Database;

//These are all the defined functions used in the program
void indata(int nostudents, Database *student);
void final_mark(int nostudents, Database *student);
void retrieve(int nostudents, Database *student, char studentinput[NMAX]);

int main()
{

    int nostudents = 8, choice;
    char studentinput[NMAX];

    //Setting the size of memory based on the amount of students in the database
    Database *student = NULL;
    student = (Database *) malloc(nostudents * sizeof(Database));

    indata(nostudents, student);
    final_mark(nostudents, student);

    int x=0;
    //While loop to allow selections of options and keep the program running until the user chooses to end
    while(x<1){

    printf("\nDo you want to find the mark and grade of a student or exit the program? (1 for PROCEED) (2 for EXIT)\n");
    scanf("%d", &choice);

    //Switch to record the choice from above
    switch (choice){

    case 1:
        printf("Please enter the first name of the student you would like to see:\n");
        scanf("%s", studentinput);

        retrieve(nostudents, student, studentinput);
        break;

    case 2:
        ++x;
        break;

    default:
        printf("Your input was not recognised...");
        return -1;
    }
    }

return 0;
}

void indata(int nostudents, Database *student){

    //This first function collects all the data from the text file and stores it in the structure under multiple students
    FILE *infile;
    infile = fopen("studentinfo.txt", "r");

    if(infile == NULL){
            printf("I am unable to open the file...");
            return -1;
    }


    for(int i=0; !feof(infile); ++i){
        fscanf(infile, "%s %s %d %f %f %f %f %f", &student[i].name1, &student[i].name2, &student[i].age, &student[i].score1
                     , &student[i].score2, &student[i].score3, &student[i].score4, &student[i].score5);
            printf("%s %s %d %f %f %f %f %f\n", student[i].name1, student[i].name2, student[i].age, student[i].score1, student[i].score2
                   , student[i].score3, student[i].score4, student[i].score5);
    }

fclose(infile);
}

void final_mark(int nostudents, Database *student){

    //This function calculates the average mark and final grade, then stores these in the structure under the student
    for(int n=0; n<nostudents; ++n){

            student[n].avgmark = (student[n].score1 + student[n].score2 + student[n].score3 + student[n].score4 + student[n].score5)/(5);

            if(student[n].avgmark>=70){
                    strcpy(student[n].finalgrade, "A");
            }if(student[n].avgmark>=60 && student[n].avgmark<70){
                    strcpy(student[n].finalgrade, "B");
            }if(student[n].avgmark>=50 && student[n].avgmark<60){
                    strcpy(student[n].finalgrade, "C");
            }if(student[n].avgmark>=40 && student[n].avgmark<50){
                    strcpy(student[n].finalgrade, "D");
            }if(student[n].avgmark<40){
                    strcpy(student[n].finalgrade, "F");
            }

            printf("\nstudent[%d] - %s %s, final MARK = %f, final GRADE = %s\n", n, student[n].name2, student[n].name1, student[n].avgmark, student[n].finalgrade);

    }

}

void retrieve(int nostudents, Database *student, char studentinput[NMAX]){

    //This function takes the choice from main and the name of the student that was input and sorts through the structure to find their details

            if(strcmp(student[0].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[0].name1
                           , student[0].avgmark, student[0].finalgrade);
            }else if(strcmp(student[1].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[1].name1
                           , student[1].avgmark, student[1].finalgrade);
            }else if(strcmp(student[2].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[2].name1
                           , student[2].avgmark, student[2].finalgrade);
            }else if(strcmp(student[3].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[3].name1
                           , student[3].avgmark, student[3].finalgrade);
            }else if(strcmp(student[4].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[4].name1
                           , student[4].avgmark, student[4].finalgrade);
            }else if(strcmp(student[4].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[4].name1
                           , student[4].avgmark, student[4].finalgrade);
            }else if(strcmp(student[5].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[5].name1
                           , student[5].avgmark, student[5].finalgrade);
            }else if(strcmp(student[6].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[6].name1
                           , student[6].avgmark, student[6].finalgrade);
            }else if(strcmp(student[7].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[7].name1
                           , student[7].avgmark, student[7].finalgrade);
            }else if(strcmp(student[8].name1, studentinput) == 0){
                printf("The student with first name: %s, achieved a mark and grade of: %f - %s", student[8].name1
                           , student[8].avgmark, student[8].finalgrade);
            }else{
                printf("There is no record of a student with that name achieving a mark or a grade.");
            }
}




/* ---------------- RESULTS -----------------------

John Doe 21 78.000000 67.000000 40.000000 16.000000 20.000000
Jane Doe 23 58.000000 47.000000 50.000000 26.000000 30.000000
Tom Doe 19 68.000000 57.000000 20.000000 66.000000 50.000000
Beth Doe 20 38.000000 57.000000 60.000000 56.000000 60.000000
Jason Doe 21 78.000000 77.000000 70.000000 86.000000 80.000000
Sandra Doe 22 98.000000 17.000000 60.000000 36.000000 50.000000
Tim Doe 25 28.000000 27.000000 50.000000 46.000000 20.000000
Sarah Doe 26 18.000000 97.000000 30.000000 26.000000 10.000000

student[0] - Doe John, final MARK = 44.200001, final GRADE = D

student[1] - Doe Jane, final MARK = 42.200001, final GRADE = D

student[2] - Doe Tom, final MARK = 52.200001, final GRADE = C

student[3] - Doe Beth, final MARK = 54.200001, final GRADE = C

student[4] - Doe Jason, final MARK = 78.199997, final GRADE = A

student[5] - Doe Sandra, final MARK = 52.200001, final GRADE = C

student[6] - Doe Tim, final MARK = 34.200001, final GRADE = F

student[7] - Doe Sarah, final MARK = 36.200001, final GRADE = F

Do you want to find the mark and grade of a student or exit the program? (1 for PROCEED) (2 for EXIT)
1
Please enter the first name of the student you would like to see:
John
The student with first name: John, achieved a mark and grade of: 44.200001 - D
Do you want to find the mark and grade of a student or exit the program? (1 for PROCEED) (2 for EXIT)
1
Please enter the first name of the student you would like to see:
Tim
The student with first name: Tim, achieved a mark and grade of: 34.200001 - F
Do you want to find the mark and grade of a student or exit the program? (1 for PROCEED) (2 for EXIT)

(THIS REPEATS UNTIL EXIT IS CHOSEN)




*/
