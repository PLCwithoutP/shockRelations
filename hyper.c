#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI_F 3.14159265

float exact_pressure(float *pGamma1, float *pBeta1, float *pMach1);
float exact_density(float *pGamma1, float *pBeta1, float *pMach1);

int main(void)
{
  // Definitions and memory allocation
  float *pGamma1 = NULL;
  float *pBeta1 = NULL;
  float *pMach1 = NULL;
  float p_ratio = 0;
  float rho_ratio = 0;
  float gamma1 = 0;
  float beta1 = 0;
  float Mach1 = 0;

  pGamma1 = (float*) malloc(sizeof(float));
  pBeta1 = (float*) malloc(sizeof(float));
  pMach1 = (float*) malloc(sizeof(float));

  if (pGamma1 == NULL || pBeta1 == NULL || pMach1 == NULL)
  {
      printf("Memory allocation is unsuccessful, program is exiting.");
      return -1;
  }

  // Taking values
  printf("Please enter specific heat ratio: \n");
  scanf("%f", &gamma1);
  *pGamma1 = gamma1;
  printf("Please enter wave angle: \n");
  scanf("%f", &beta1);
  *pBeta1 = beta1;
  printf("Please enter Mach number: \n");
  scanf("%f", &Mach1);
  *pMach1 = Mach1;  

  // Function executions
  p_ratio = exact_pressure(pGamma1, pBeta1, pMach1);
  density_ratio = exact_density(pGamma1, pBeta1, pMach1);

  // Display
  printf("Given inputs are: \n");
  printf("Specific heat ratio is: %f\n", gamma1);
  printf("Wave angle is: %f\n", beta1);
  printf("Mach number is: %f\n", Mach1);
  printf("Resulting exact static pressure ratio is: %f\n", p_ratio);
  printf("Resulting exact density ratio is: %f\n", rho_ratio);

  // Freeing memory
  free(pGamma1);
  pGamma1 = NULL;
  free(pBeta1);
  pBeta1 = NULL;
  free(pMach1);
  pMach1 = NULL;
  
  return 0;
}

float exact_pressure(float *pGamma1, float *pBeta1, float *pMach1)
{
  float tempGamma1 = 0;
  float tempBeta1 = 0; // degrees
  float tempBeta1Rad = 0; // radian
  float tempMach1 = 0;
  float p_ratio = 0;

  tempGamma1 = *pGamma1;
  tempBeta1 = *pBeta1;
  tempMach1 = *pMach1;
  tempBeta1Rad = tempBeta1*PI_F/180;

  p_ratio = 1 + (2*tempGamma1*(pow(tempMach1*sin(tempBeta1Rad),2) - 1))/(tempGamma1 + 1);
  
  return p_ratio;
}

float exact_density(float *pGamma1, float *pBeta1, float *pMach1)
{
  float tempGamma1 = 0;
  float tempBeta1 = 0; // degrees
  float tempBeta1Rad = 0; // radian
  float tempMach1 = 0;
  float rho_ratio = 0;

  tempGamma1 = *pGamma1;
  tempBeta1 = *pBeta1;
  tempMach1 = *pMach1;
  tempBeta1Rad = tempBeta1*PI_F/180;

  rho_ratio = ((tempGamma1 + 1)*pow(tempMach1*sin(tempBeta1Rad),2))/((tempGamma1 - 1)*pow(tempMach1*sin(tempBeta1Rad),2) + 2);

  return rho_ratio;
]
