#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI_F 3.14159265
#include "exact_functions.h"


int main(void)
{
    // Definitions and memory allocation
    float *pGamma1 = NULL;
    float *pBeta1 = NULL;
    float *pMach1 = NULL;
    float p_ratio = 0;
    float rho_ratio = 0;
    float T_ratio = 0;
    float U_ratio_prl = 0;
    float U_ratio_perp = 0;
    float gamma1 = 0;
    float beta1 = 0;
    float Mach1 = 0;

    pGamma1 = (float*) malloc(2*sizeof(float));
    pBeta1 = (float*) malloc(2*sizeof(float));
    pMach1 = (float*) malloc(2*sizeof(float));

    if (pGamma1 == NULL || pBeta1 == NULL || pMach1 == NULL)
    {
        printf("Memory allocation could not be done, program is exiting.");
        return -1;
    }
    
    // Taking values
    printf("Please enter specific heat ratio: \n");
    scanf("%f", &gamma1);
    *pGamma1 = gamma1;
    printf("Please enter wave angle in degrees: \n");
    scanf("%f", &beta1);
    *pBeta1 = beta1*PI_F/180;
    printf("Please enter Mach number: \n");
    scanf("%f", &Mach1);
    *pMach1 = Mach1;

    // Function executions
    p_ratio = exact_pressure(pGamma1, pBeta1, pMach1);
    rho_ratio = exact_density(pGamma1, pBeta1, pMach1);
    T_ratio = exact_temp(p_ratio, rho_ratio);
    U_ratio_prl = vel_ratio_prl(pGamma1, pBeta1, pMach1);
    //U_ratio_perp = vel_ratio_perp(pGamma1, pBeta1, pMach1);

    // Display
    printf("Given inputs are: \n");
    printf("Specific heat ratio is: %f\n", gamma1);
    printf("Wave angle is: %f degrees\n", beta1);
    printf("Mach number is: %f\n", Mach1);
    printf("Resulting exact static pressure ratio is: %f\n", p_ratio);
    printf("Resulting exact density ratio is: %f\n", rho_ratio);
    printf("Resulting exact temperature ratio is: %f\n", T_ratio);

    // Freeing memory
    free(pGamma1);
    pGamma1 = NULL;
    free(pBeta1);
    pBeta1 = NULL;
    free(pMach1);
    pMach1 = NULL;

    return 0;
}
