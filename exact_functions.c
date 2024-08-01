#include "exact_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float exact_pressure(float *pGamma1, float *pBeta1, float *pMach1)
{
    float p_ratio = 0;

    p_ratio = 1 + (2*(*pGamma1)*(pow((*pMach1) * sin(*pBeta1),2) - 1))/((*pGamma1) + 1);

    return p_ratio;
}

float exact_density(float *pGamma1, float *pBeta1, float *pMach1)
{
    float rho_ratio = 0;

    rho_ratio = (((*pGamma1) + 1)*pow((*pMach1)*sin(*pBeta1),2))/(((*pGamma1) - 1)*pow((*pMach1)*sin(*pBeta1),2) + 2);

    return rho_ratio;
}

float exact_temp(float p_ratio, float rho_ratio)
{
    float T_ratio = 0;

    T_ratio = p_ratio / rho_ratio;

    return T_ratio;
}

float vel_ratio_prl(float *pGamma1, float *pBeta1, float *pMach1)
{
    float U_ratio_prl= 0;

    U_ratio_prl = 1 - (2*pow((*pMach1)*sin(*pBeta1),2) - 1)/((*pGamma1 + 1)*pow(*pMach1,2));

    return U_ratio_prl;
}

float vel_ratio_perp(float *pGamma1, float *pBeta1, float *pMach1)
{
    float U_ratio_perp= 0;

    U_ratio_prl = 1 - (2*pow((*pMach1)*sin(*pBeta1),2) - 1);

    return U_ratio_perp;
}
