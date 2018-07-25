#include "SphericalLawofCosines.h"

double SphericalLawofCosines::CalculateDistance(double phi_0, double phi_1, double lambda_0, double lambda_1, double r)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double conv = M_PI/180;
  
  return r*acos(sin(phi_0*conv)*sin(phi_1*conv)+cos(phi_0*conv)*cos(phi_1*conv)*cos((lambda_1-lambda_0)*conv));
}
