#include "Quadrilateral.h"

using namespace std;

Quadrilateral::Quadrilateral()
{
}

Quadrilateral::Quadrilateral(double ULX, double ULY, double URX, double URY, double LRX, double LRY, double LLX, double LLY) : quadrilateral(4, std::vector <double>(2))
{
  /***********************/
  /* Retrieve parameters */
  /***********************/
  area = 0;
  lower_left_x = LLX;
  lower_left_y = LLY;
  lower_right_x = LRX;
  lower_right_y = LRY;
  perimeter = 0;
  upper_left_x = ULX;
  upper_left_y = ULY;
  upper_right_x = URX;
  upper_right_y = URY;

  /************************/
  /* Define quadrilateral */
  /************************/
  VectorizeQuadrilateral();
  
  /*****************************/
  /* Execute auxilary function */
  /*****************************/
  AuxilaryFunction();
}

double Quadrilateral::GetArea()
{
  return area;
}

double Quadrilateral::GetLower_left_x()
{
  return lower_left_x;
}

double Quadrilateral::GetLower_left_y()
{
  return lower_left_y;
}

double Quadrilateral::GetLower_right_x()
{
  return lower_right_x;
}

double Quadrilateral::GetLower_right_y()
{
  return lower_right_y;
}

double Quadrilateral::GetPerimeter()
{
  return perimeter;
}

double Quadrilateral::GetUpper_left_x()
{
  return upper_left_x;
}

double Quadrilateral::GetUpper_left_y()
{
  return upper_left_y;
}

double Quadrilateral::GetUpper_right_x()
{
  return upper_right_x;
}

double Quadrilateral::GetUpper_right_y()
{
  return upper_right_y;
}

vector < vector <double> > Quadrilateral::GetVector()
{
  return quadrilateral;
}

void Quadrilateral::AuxilaryFunction()
{
  /**************************************/
  /* Calculate the lengths of the edges */
  /**************************************/
  CalculateEdgeLengths();
  
  /************************************************/
  /* Calculate quadrilateral's perimeter and area */
  /************************************************/
  CalculatePerimeter();
  CalculateArea();
}

void Quadrilateral::CalculateArea()
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double numerator;
  double denominator;

  /******************************************************/
  /* Calculate interior angle at lower left hand corner */
  /******************************************************/
  numerator = (upper_left_x-lower_left_x)*(lower_right_x-lower_left_x)+(upper_left_y-lower_left_y)*(lower_right_y-lower_left_y);
  denominator = length_left_edge*length_bottom_edge;
  double cos_A = numerator/denominator;
  double sin_A = sqrt(1-cos_A*cos_A);

  /*******************************************************/
  /* Calculate interior angle at upper right hand corner */
  /*******************************************************/
  numerator = (upper_right_x-upper_left_x)*(upper_right_x-lower_right_x)+(upper_right_y-upper_left_y)*(upper_right_y-lower_right_y);
  denominator = length_top_edge*length_right_edge;
  double cos_C = numerator/denominator;
  double sin_C = sqrt(1-cos_C*cos_C);

  /***********************************/
  /* Calculate area of quadrilateral */
  /***********************************/
  area = 0.5*length_left_edge*length_bottom_edge*sin_A+0.5*length_top_edge*length_right_edge*sin_C;
}

void Quadrilateral::CalculateEdgeLengths()
{
  length_bottom_edge = sqrt((lower_left_x-lower_right_x)*(lower_left_x-lower_right_x)+(lower_left_y-lower_right_y)*(lower_left_y-lower_right_y));
  length_left_edge = sqrt((upper_left_x-lower_left_x)*(upper_left_x-lower_left_x)+(upper_left_y-lower_left_y)*(upper_left_y-lower_left_y));
  length_right_edge = sqrt((upper_right_x-lower_right_x)*(upper_right_x-lower_right_x)+(upper_right_y-lower_right_y)*(upper_right_y-lower_right_y));
  length_top_edge = sqrt((upper_left_x-upper_right_x)*(upper_left_x-upper_right_x)+(upper_left_y-upper_right_y)*(upper_left_y-upper_right_y));
}

void Quadrilateral::CalculatePerimeter()
{
  perimeter = length_top_edge+length_right_edge+length_bottom_edge+length_left_edge;
}

void Quadrilateral::Display()
{
  /*********************************************/
  /* Print parameters and attributes to screen */
  /*********************************************/
  printf("Parameters:\n");
  printf("Upper left corner x = %lf\n", upper_left_x);
  printf("Upper left corner y = %lf\n", upper_left_y);
  printf("Upper right corner x = %lf\n", upper_right_x);
  printf("Upper right corner y = %lf\n", upper_right_y);
  printf("Lower right corner x = %lf\n", lower_right_x);
  printf("Lower right corner y = %lf\n", lower_right_y);
  printf("Lower left corner x = %lf\n", lower_left_x);
  printf("Lower left corner y = %lf\n", lower_left_y);
  printf("Attributes:\n");
  printf("Area = %lf\n", area);
  printf("Perimeter => (X = %lf)\n", perimeter);
}

void Quadrilateral::VectorizeQuadrilateral()
{
  /************************************************************/
  /* Define the boundary of the quadrilateral going clockwise */
  /* starting at the upper left hand corner                   */
  /************************************************************/
  quadrilateral[0][0] = upper_left_x;
  quadrilateral[0][1] = upper_left_y;
  quadrilateral[1][0] = upper_right_x;
  quadrilateral[1][1] = upper_right_y;
  quadrilateral[2][0] = lower_right_x;
  quadrilateral[2][1] = lower_right_y;
  quadrilateral[3][0] = lower_left_x;
  quadrilateral[3][1] = lower_left_y;
}
