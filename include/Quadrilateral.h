/* HEADER FILE: Quadrilateral.h */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include <math.h>
#include <stdio.h>
#include <vector>

class Quadrilateral
{
  /**********************************/
  /* Declaration of class variables */
  /**********************************/
  private:
    double area;
    double length_bottom_edge;
    double length_left_edge;
    double length_right_edge;
    double length_top_edge;
    double lower_left_x;
    double lower_left_y;
    double lower_right_x;
    double lower_right_y;
    double perimeter;
    double upper_left_x;
    double upper_left_y;
    double upper_right_x;
    double upper_right_y;
    std::vector < std::vector <double> > quadrilateral;

  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    Quadrilateral();
    Quadrilateral(double, double, double, double, double, double, double, double);
    double GetArea();
    double GetLength_bottom_edge();
    double GetLength_left_edge();
    double GetLength_right_edge();
    double GetLength_top_edge();
    double GetLower_left_x();
    double GetLower_left_y();
    double GetLower_right_x();
    double GetLower_right_y();
    double GetPerimeter();
    double GetUpper_left_x();
    double GetUpper_left_y();
    double GetUpper_right_x();
    double GetUpper_right_y();
    std::vector < std::vector <double> > GetVector();
    void AuxilaryFunction();
    void CalculateArea();
    void CalculateEdgeLengths();
    void CalculatePerimeter();
    void Display();
    void VectorizeQuadrilateral();
};

#endif
