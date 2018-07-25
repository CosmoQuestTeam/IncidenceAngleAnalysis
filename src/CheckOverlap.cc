/* CalculateOverlapBoundary function uses Sutherland–Hodgman Algorithm */
/* are_Overlapping function uses ray-casting algorithm */

#include "CheckOverlap.h"

using namespace std;

CheckOverlap::CheckOverlap()
{
}

CheckOverlap::CheckOverlap(vector < vector <double> > &FP, double FPMINX, double FPMINY, double FPMAXX, double FPMAXY, double AREA_FP, vector < vector <double> > &SP, double SPMINX, double SPMINY, double SPMAXX, double SPMAXY, double AREA_SP)
{
  /***********************/
  /* Retrieve parameters */
  /***********************/
  if(AREA_FP > AREA_SP)
  {
    Polygon_1 = FP;
    polygon_1_min_x = FPMINX;
    polygon_1_min_y = FPMINY;
    polygon_1_max_x = FPMAXX;
    polygon_1_max_y = FPMAXY;
    Polygon_2 = SP;
    polygon_2_min_x = SPMINX;
    polygon_2_min_y = SPMINY;
    polygon_2_max_x = SPMAXX;
    polygon_2_max_y = SPMAXY;
  }
  else
  {
    Polygon_1 = SP;
    polygon_1_min_x = SPMINX;
    polygon_1_min_y = SPMINY;
    polygon_1_max_x = SPMAXX;
    polygon_1_max_y = SPMAXY;
    Polygon_2 = FP;
    polygon_2_min_x = FPMINX;
    polygon_2_min_y = FPMINY;
    polygon_2_max_x = FPMAXX;
    polygon_2_max_y = FPMAXY;
  }
}

bool CheckOverlap::are_Overlapping()
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int nedges;
  int n_intersections;
  int nverticies;

  /******************************************************************/
  /* First: Test if rectangular bounding region of polygons overlap */
  /******************************************************************/
  if((polygon_1_min_x > polygon_2_max_x) || (polygon_2_min_x > polygon_1_max_x))
    return false;
  if((polygon_1_min_y > polygon_2_max_y) || (polygon_2_min_y > polygon_1_max_y))
    return false;
  
  /****************************************/
  /* Second: Test to see if any verticies */
  /* of polygon 2 are within polygon 1    */
  /****************************************/
  nedges = (int)Polygon_1.size();
  nverticies = (int)Polygon_2.size();
  for(int i=0; i<nverticies; i++)
  {
    n_intersections = 0;
    for(int j=0; j<nedges; j++)
    {
      int k = (j+1)%nedges;
      if(do_LinesIntersect(Polygon_2[i][0], Polygon_2[i][1], Polygon_1[j][0], Polygon_1[j][1], Polygon_1[k][0], Polygon_1[k][1]))
	n_intersections++;
    }
  if(n_intersections%2 == 1)
      return true;
  }
  
  return false;
}

bool CheckOverlap::do_LinesIntersect(double x, double y, double x1, double y1, double x2, double y2)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double Ax;
  double Ay;
  double Bx;
  double By;
  double Px;
  double Py;
  double max_x;
  double min_x;
  double slope_line_segment;
  double slope_test_line;
  
  /****************************************************************************/
  /* Determine which point is the highest point and set test point coordinate */
  /****************************************************************************/
  if(y1 < y2)
  {
    Ax = x1;
    Ay = y1;
    Bx = x2;
    By = y2;
    Px = x;
    Py = y;
  }
  else
  {
    Ax = x2;
    Ay = y2;
    Bx = x1;
    By = y1;
    Px = x;
    Py = y;
  }
  
  /***************************************/
  /* Determine max and min x coordinates */
  /***************************************/
  if(Ax < Bx)
  {
    max_x = Bx;
    min_x = Ax;
  }
  else
  {
    max_x = Ax;
    min_x = Bx;
  }
  
  /************************************/
  /* Adjust test point's y coordinate */
  /************************************/
  if((Py == Ay) || (Py == By))
    Py += 1.0;

  /*************************************************************/
  /* 1) If test point is lower than point A or higher than point */
  /*    B, then horizontal ray to infinity from test point can   */
  /*    not intersect line AB.                                   */
  /* 2) If test point lies between the y bounds of line AB but   */
  /*    exceeds the maximum x coordinate of line AB, then        */
  /*    horizontal ray to infinity from test point can not       */
  /*    intersect line AB.                                       */
  /* 3) If test point lies between the y bounds of line AB and   */
  /*    does not exceed the maximum x coordinate of line AB,     */
  /*    then horizontal ray to infinity from test point must     */
  /*    intersect line AB.                                       */
  /*************************************************************/
  if((Py < Ay) || (Py > By))
    return false;
  else if(Px >= max_x)
    return false;
  else
    if(Px < min_x)
      return true;
    else
    {
      if(Ax != Bx)
	slope_line_segment = (By-Ay)/(Bx-Ax);
      else
	slope_line_segment = numeric_limits<double>::infinity();
      if(Ax != Px)
	slope_test_line = (Py-Ay)/(Px-Ax);
      else
	slope_test_line = numeric_limits<double>::infinity();
      if(slope_test_line >= slope_test_line)
	return true;
      else
	return false;
    }
}

bool CheckOverlap::is_PointAllowed(double x1, double y1, double x2, double y2, double x, double y)
{
  /*****************************************************/
  /* Determine general position of test point relative */
  /* to line defined by (x1, y1) to (x2, y2)           */
  /*****************************************************/
  double P = (x2-x1)*(y-y1)-(y2-y1)*(x-x1);

  /**************************/
  /* Restriction conditions */
  /**************************/
  if(P < 0)
    return true;

  return false;
}

double CheckOverlap::GetPolygon_Overlap_Area()
{
  return Polygon_Overlap_Area;
}

vector <double> CheckOverlap::LineIntersectionPoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double denominator;
  double numerator;
  vector <double> IntersectionPoint(2);

  /********************/
  /* Define constants */
  /********************/
  double c1 = x1-x2;
  double c2 = x3-x4;
  double c3 = y1-y2;
  double c4 = y3-y4;
  double c5 = x1*y2-y1*x2;
  double c6 = x3*y4-y3*x4;
  
  /***********************************/
  /* Calculate point of intersection */
  /***********************************/
  numerator = c5*c2-c1*c6;
  denominator = c1*c4-c3*c2;
  IntersectionPoint[0] = numerator/denominator;
  numerator = c5*c4-c3*c6;
  IntersectionPoint[1] = numerator/denominator;

  return IntersectionPoint;
}

vector < vector <double> > CheckOverlap::GetPolygon_Overlap()
{
  return Polygon_Overlap;
}

void CheckOverlap::AuxilaryFunction()
{
  CalculateOverlapBoundary();
  CalculateOverlapArea();
}

void CheckOverlap::CalculateOverlapArea()
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double denominator;
  double numerator;
  
  /**************************************/
  /* If overlap area is a quadrilateral */
  /**************************************/
  if(Polygon_Overlap.size() == 4)
  {
    /******************/
    /* Define corners */
    /******************/
    double conv = (M_PI/180); 
    double upper_left_x = EquirectangularProjection::CalculateX(Polygon_Overlap[0][0]*conv, 0.0, 0.0, 1737400.0);
    double upper_left_y = EquirectangularProjection::CalculateY(Polygon_Overlap[0][1]*conv, 0.0, 1737400.0);
    double upper_right_x = EquirectangularProjection::CalculateX(Polygon_Overlap[1][0]*conv, 0.0, 0.0, 1737400.0);
    double upper_right_y = EquirectangularProjection::CalculateY(Polygon_Overlap[1][1]*conv, 0.0, 1737400.0);
    double lower_right_x = EquirectangularProjection::CalculateX(Polygon_Overlap[2][0]*conv, 0.0, 0.0, 1737400.0);
    double lower_right_y = EquirectangularProjection::CalculateY(Polygon_Overlap[2][1]*conv, 0.0, 1737400.0);
    double lower_left_x = EquirectangularProjection::CalculateX(Polygon_Overlap[3][0]*conv, 0.0, 0.0, 1737400.0);
    double lower_left_y = EquirectangularProjection::CalculateY(Polygon_Overlap[3][1]*conv, 0.0, 1737400.0);

    /***************************/
    /* Define lengths of edges */
    /***************************/
    double length_top_edge = sqrt((upper_left_x-upper_right_x)*(upper_left_x-upper_right_x)+(upper_left_y-upper_right_y)*(upper_left_y-upper_right_y));
    double length_right_edge = sqrt((upper_right_x-lower_right_x)*(upper_right_x-lower_right_x)+(upper_right_y-lower_right_y)*(upper_right_y-lower_right_y));
    double length_bottom_edge = sqrt((lower_right_x-lower_left_x)*(lower_right_x-lower_left_x)+(lower_right_y-lower_left_y)*(lower_right_y-lower_left_y));
    double length_left_edge = sqrt((lower_left_x-upper_left_x)*(lower_left_x-upper_left_x)+(lower_left_y-upper_left_y)*(lower_left_y-upper_left_y));
    
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
    Polygon_Overlap_Area = 0.5*length_left_edge*length_bottom_edge*sin_A+0.5*length_top_edge*length_right_edge*sin_C;
  }
  else
    Polygon_Overlap_Area = 0;
}

void CheckOverlap::CalculateOverlapBoundary()
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  int nedges;

  /****************************************************/
  /* Assign verticies of Polygon_2 to Polygon_Overlap */
  /****************************************************/
  Polygon_Overlap = Polygon_2;
  
  /***********************************/
  /* Iterate over edges of polygon_1 */
  /***********************************/
  nedges = (int)Polygon_1.size();
  for(int i=0; i<nedges; i++)
  {
    int j = (i+1)%nedges;
    double x1 = Polygon_1[i][0];
    double y1 = Polygon_1[i][1];
    double x2 = Polygon_1[j][0];
    double y2 = Polygon_1[j][1];
    ConstructOverlapBoundary(x1, y1, x2, y2);
  }
}

void CheckOverlap::ConstructOverlapBoundary(double x1, double y1, double x2, double y2)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  int nedges;
  vector <double> retainedpoint(2);
  vector < vector <double> > temp_polygon;
  
  /******************************************/
  /* Iterate through each edge of polygon_2 */
  /******************************************/
  nedges = (int)Polygon_Overlap.size();
  for(int i=0; i<nedges; i++)
  {
    /**********************************/
    /* Retrieve first edge of polygon */
    /**********************************/
    int j = (i+1)%nedges;
    double p1_x = Polygon_Overlap[i][0];
    double p1_y = Polygon_Overlap[i][1];
    double p2_x = Polygon_Overlap[j][0];
    double p2_y = Polygon_Overlap[j][1];
    
    /*********************************************************/
    /* Determine position of edge relative to rejection line */
    /*********************************************************/
    bool pass_p1 = is_PointAllowed(x1, y1, x2, y2, p1_x, p1_y);
    bool pass_p2 = is_PointAllowed(x1, y1, x2, y2, p2_x, p2_y);
    
    /**********************************************************/
    /* Condition 1: If first point is outside bounding region */
    /* and second point is inside of bounding region          */
    /**********************************************************/
    if(!pass_p1 && pass_p2)
    {
      retainedpoint = LineIntersectionPoint(p1_x, p1_y, p2_x, p2_y, x1, y1, x2, y2);
      temp_polygon.push_back(retainedpoint);
      retainedpoint[0] = p2_x;
      retainedpoint[1] = p2_y;
      temp_polygon.push_back(retainedpoint);
      continue;
    }
    
    /******************************************/
    /* Condition 2: If both points are inside */
    /* of bounding region, keep second point  */
    /******************************************/
    if(pass_p1 && pass_p2)
    {
      retainedpoint[0] = p2_x;
      retainedpoint[1] = p2_y;
      temp_polygon.push_back(retainedpoint);
      continue;
    }
    
    /*********************************************************/
    /* Condition 3: If first point is inside bounding region */
    /* and second point is outside of bounding region        */
    /*********************************************************/
    if(pass_p1 && !pass_p2)
    {
      retainedpoint = LineIntersectionPoint(p1_x, p1_y, p2_x, p2_y, x1, y1, x2, y2);
      temp_polygon.push_back(retainedpoint);
      continue;
    }
  }

  /*****************************/
  /* Overwrite Polygon_Overlap */
  /*****************************/
  if((int)temp_polygon.size() != 0)
    Polygon_Overlap = temp_polygon;
}
