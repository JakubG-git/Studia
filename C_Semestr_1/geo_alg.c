#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

bool ifTriangle(double a, double b, double c){
    if((a + b > c)&&(a + c > b)&&(c + b > a))
        return true;
    return false;
}

double iloczynSkalarny(double *wek, double *wek2){
    return (wek[0] * wek2[0]) + (wek[1] * wek2[1]);
}

double wspA(double *a, double *b){
    if (b[0] - a[0] == 0)
    {
        return 0;
    }
    return (b[1] - a[1]) / (b[0] - a[0]);
}
double dlugoscOdcinka(double *a, double *b){
    return hypot((b[0] - a[0]), (b[1] - a[1]));
}
double bugCheck(double *a){
    printf(" %f ", *a);
    if(fabs(*a) < 1.0e-15){
        *a = 0;
    }
}
void createVector(double *a, double *b, double *wektor){
    wektor[0] = b[0] - a[0];
    wektor[1] = b[1] - a[1];
}

bool checkIfNonZeroVector(double *wektor){
    if(wektor[0] == 0 && wektor[1] == 0){
        return false;
    }
    return true;
}


bool ifTriangeRectangular2(double *a, double *b, double *c){
    double wektorAB[2];
    double wektorAC[2];
    double wektorBC[2];
    createVector(a, b, wektorAB);
    createVector(a, c, wektorAC);
    createVector(b, c, wektorBC);
    if(!(checkIfNonZeroVector(wektorAB) 
    && checkIfNonZeroVector(wektorAC) 
    && checkIfNonZeroVector(wektorBC))){
        return false;
    }
    double iloczynSkalarny1 = iloczynSkalarny(wektorAB, wektorBC);
    double iloczynSkalarny2 = iloczynSkalarny(wektorAB, wektorAC);
    double iloczynSkalarny3 = iloczynSkalarny(wektorAC, wektorBC);
    if(iloczynSkalarny1 || iloczynSkalarny2 || iloczynSkalarny3){
        return true;
    }
    return false;
}

bool ifTriangleRectangular(double *a, double *b, double *c){
    double wspAB, wspAC, wspBC;
    bool condition;
    wspAB = wspA(a, b);
    wspAC = wspA(a, c);
    wspBC = wspA(b, c);
    bugCheck(&wspAB);bugCheck(&wspAC);bugCheck(&wspBC);
    if((wspAB  == -1 * wspAC)||(wspAC  == -1 * wspBC)||(wspAB  == -1 * wspBC))
        if(ifTriangle(dlugoscOdcinka(a, b), dlugoscOdcinka(a, c), dlugoscOdcinka(b, c)))   
            return true;
    return false;
    
}

int main(void){
    double punktA[2] = {0, 0}; //0 - x, 1 - y
    double punktB[2] = {0, 1}; //0 - x, 1 - y
    double punktC[2] = {1, 1}; //0 - x, 1 - y
    if(ifTriangeRectangular2(punktA, punktB, punktC)){
        printf("Dziala");
    }
    else{
        printf("Nie dziala");
    }
    return 0;
}
