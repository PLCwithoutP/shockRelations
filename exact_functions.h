#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
// Include Guards

float exact_pressure(float *pGamma1, float *pBeta1, float *pMach1);
float exact_density(float *pGamma1, float *pBeta1, float *pMach1);
float exact_temp(float p_ratio,float rho_ratio);
float vel_ratio_prl(float *pGamma1, float *pBeta1, float *pMach1);
float vel_ratio_perp(float *pGamma1, float *pBeta1, float *pMach1);

#endif
