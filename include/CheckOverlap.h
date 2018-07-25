/* HEADER FILE: CheckOverlap.h */

#ifndef CHECKOVERLAP_H
#define CHECKOVERLAP_H
#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>
#include "EquirectangularProjection.h"

class CheckOverlap
{
  /*************************************************/
  /* Declaration/Initialization of class variables */
  /*************************************************/
  double polygon_1_max_x;
  double polygon_1_max_y;
  double polygon_1_min_x;
  double polygon_1_min_y;
  double polygon_2_max_x;
  double polygon_2_max_y;
  double polygon_2_min_x;
  double polygon_2_min_y;
  double Polygon_Overlap_Area;
  std::vector < std::vector <double> > Polygon_1;
  std::vector < std::vector <double> > Polygon_2;
  std::vector < std::vector <double> > Polygon_Overlap;
  
  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    CheckOverlap();
    CheckOverlap(std::vector < std::vector <double> > &, double, double, double, double, double, std::vector < std::vector <double> > &, double, double, double, double, double);
    bool are_Overlapping();
    bool do_LinesIntersect(double, double, double, double, double, double);
    bool is_PointAllowed(double, double, double, double, double, double);
    double GetPolygon_Overlap_Area();
    std::vector <double> LineIntersectionPoint(double, double, double, double, double, double, double, double);
    std::vector < std::vector <double> > GetPolygon_Overlap();
    void AuxilaryFunction();
    void CalculateOverlapArea();
    void CalculateOverlapBoundary();
    void ConstructOverlapBoundary(double, double, double, double);
};

#endif
