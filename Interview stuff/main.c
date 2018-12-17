#include <stdio.h>
#include <stdlib.h>

int dateconv(int baktun, int katun, int tun, int uinal, int kin);

int main()
{
    int baktun, katun, tun, uinal, kin;

    printf("Please input the baktun(1-20), katun(1-20), tun(1-20), uinal(1-18) and kin(1-20), respectively:");
    scanf("%d %d %d %d %d", &baktun, &katun, &tun, &uinal, &kin);

    dateconv(baktun, katun, tun, uinal, kin);

return 0;
}

int dateconv(int baktun, int katun, int tun, int uinal, int kin){

    float extday=0, extmonth=0, extyear=0;
    int datetot = kin + uinal*18 + tun*20*18 + katun*400*18 + baktun*8000*18;


    if(datetot>2028819 || datetot<2018811){
        printf("\nYour mayan date is outside of the range specified");
        return -1;
    }
    datetot -= 2018811;

    extday = (float) (datetot%365);
    extyear = datetot/365;

    printf("%g %g %g", extday, extmonth, extyear);


    if(extday<=31 && extday>0){
        extmonth = 1;
        extday = extday;
    }if(extday<=59 && extday>31){
        extmonth = 2;
        extday -= 31;
    }if(extday<=90 && extday>59){
        extmonth = 3;
        extday -= 59;
    }if(extday<=121 && extday>90){
        extmonth = 4;
        extday -= 90;
    }if(extday<=151 && extday>121){
        extmonth = 5;
        extday -= 121;
    }if(extday<=182 && extday>151){
        extmonth = 6;
        extday -= 151;
    }if(extday<=212 && extday>182){
        extmonth = 7;
        extday -= 182;
    }if(extday<=243 && extday>212){
        extmonth = 8;
        extday -= 212;
    }if(extday<=274 && extday>243){
        extmonth = 9;
        extday -= 243;
    }if(extday<=304 && extday>274){
        extmonth = 10;
        extday -= 274;
    }if(extday<=335 && extday>304){
        extmonth = 11;
        extday -= 304;
    }if(extday<367 && extday>335){
        extmonth = 12;
        extday -= 335;
    }

    int day = extday;
    int month = extmonth;
    int year = extyear + 2000;

    if(year%4 ==0){
        day += 1;
    }

    printf("\n%d %d %d", day, month, year);

return 0;
}
