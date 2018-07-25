#include "ImageSets.h"

using namespace std;

ImageSets::ImageSets(int ID, string NAME, int AID, double P, double SA, double ULLAT, double ULLONG, double URLAT, double URLONG, double LRLAT, double LRLONG, double LLLAT, double LLLONG, double PR, string DESCRIP, string DET, string CREATE, string UPDATE)
{
  application_id = AID;
  created_at = CREATE;
  description = DESCRIP;
  details = DET;
  height = 0;
  id = ID;
  lower_left_latitude = LLLAT;
  lower_left_longitude = LLLONG;
  lower_left_x = 0;
  lower_left_y = 0;
  lower_right_latitude = LRLAT;
  lower_right_longitude = LRLONG;
  lower_right_x = 0;
  lower_right_y = 0;
  maximum_latitude = 0;
  maximum_longitude = 0;
  maximum_x = 0;
  maximum_y = 0;
  minimum_latitude = 0;
  minimum_longitude = 0;
  minimum_x = 0;
  minimum_y = 0;
  name = NAME;
  pixel_resolution = PR;
  priority = P;
  sun_angle = SA;
  updated_at = UPDATE;
  upper_left_corner_x_status = "";
  upper_left_corner_y_status = "";
  upper_left_latitude = ULLAT;
  upper_left_longitude = ULLONG;
  upper_left_x = 0;
  upper_left_y = 0;
  upper_right_latitude = URLAT;
  upper_right_longitude = URLONG;
  upper_right_x = 0;
  upper_right_y = 0;
  width = 0;
}

double ImageSets::GetLower_left_latitude()
{
  return lower_left_latitude;
}

double ImageSets::GetLower_left_longitude()
{
  return lower_left_longitude;
}

double ImageSets::GetLower_left_x()
{
  return lower_left_x;
}

double ImageSets::GetLower_left_y()
{
  return lower_left_y;
}

double ImageSets::GetLower_right_latitude()
{
  return lower_right_latitude;
}

double ImageSets::GetLower_right_longitude()
{
  return lower_right_longitude;
}

double ImageSets::GetLower_right_x()
{
  return lower_right_x;
}

double ImageSets::GetLower_right_y()
{
  return lower_right_y;
}

double ImageSets::GetMaximum_latitude()
{
  return maximum_latitude;
}

double ImageSets::GetMaximum_longitude()
{
  return maximum_longitude;
}

double ImageSets::GetMaximum_x()
{
  return maximum_x;
}

double ImageSets::GetMaximum_y()
{
  return maximum_y;
}

double ImageSets::GetMinimum_latitude()
{
  return minimum_latitude;
}

double ImageSets::GetMinimum_longitude()
{
  return minimum_longitude;
}

double ImageSets::GetMinimum_x()
{
  return minimum_x;
}

double ImageSets::GetMinimum_y()
{
  return minimum_y;
}

double ImageSets::GetPixel_resolution()
{
  return pixel_resolution;
}

double ImageSets::GetPriority()
{
  return priority;
}

double ImageSets::GetSun_angle()
{
  return sun_angle;
}

double ImageSets::GetUpper_left_latitude()
{
  return upper_left_latitude;
}

double ImageSets::GetUpper_left_longitude()
{
  return upper_left_longitude;
}

double ImageSets::GetUpper_left_x()
{
  return upper_left_x;
}

double ImageSets::GetUpper_left_y()
{
  return upper_left_y;
}

double ImageSets::GetUpper_right_latitude()
{
  return upper_right_latitude;
}

double ImageSets::GetUpper_right_longitude()
{
  return upper_right_longitude;
}

double ImageSets::GetUpper_right_x()
{
  return upper_right_x;
}

double ImageSets::GetUpper_right_y()
{
  return upper_right_y;
}

int ImageSets::GetApplication_id()
{
  return application_id;
}

int ImageSets::GetHeight()
{
  return height;
}

int ImageSets::GetId()
{
  return id;
}

int ImageSets::GetWidth()
{
  return width;
}

ProjectiveTransformation ImageSets::GetProjective_transformation()
{
  return pt;
}

string ImageSets::GetCreated_at()
{
  return created_at;
}

string ImageSets::GetDescription()
{
  return description;
}

string ImageSets::GetDetails()
{
  return details;
}

string ImageSets::GetName()
{
  return name;
}

string ImageSets::GetUpdated_at()
{
  return updated_at;
}

string ImageSets::GetUpper_left_corner_x_status()
{
  return upper_left_corner_x_status;
}

string ImageSets::GetUpper_left_corner_y_status()
{
  return upper_left_corner_y_status;
}

vector <double> ImageSets::GetPhysical_height()
{
  return physical_height;
}

vector <double> ImageSets::GetPhysical_width()
{
  return physical_width;
}

void ImageSets::AuxilaryFunction(bool CalculatePhysical_Height_Width)
{
  /*******************************************/
  /* Step 1: Determine image reference point */
  /*******************************************/
  DetermineImageReference();

  /*******************************************/
  /* Step 2: Retrieve image width and height */
  /*******************************************/
  RetrieveWidth();
  RetrieveHeight();

  /*******************************************************************/
  /* Step 3: Calculate bounding region x and y cartesian coordinates */
  /*******************************************************************/
  CalculateUpper_left_x();
  CalculateUpper_left_y();
  CalculateUpper_right_x();
  CalculateUpper_right_y();
  CalculateLower_right_x();
  CalculateLower_right_y();
  CalculateLower_left_x();
  CalculateLower_left_y();

  /*******************************************************/
  /* Step 4: Determine minimum/maximum coordinate values */
  /*******************************************************/
  DetermineCoordinateExtrema();
  
  /*******************************************/
  /* Step 5: Calculate transformation matrix */
  /*******************************************/
  CalculateTransforms();

  /****************************************************************/
  /* Step 6: Calculate physical image width and height (Optional) */
  /****************************************************************/
  if(CalculatePhysical_Height_Width)
  {
    CalculatePhysical_width();
    CalculatePhysical_height();  
  }
}

void ImageSets::CalculateLower_left_x()
{
  /**************************************************/
  /* Calculate image's lower left corner x position */
  /**************************************************/
  double lambda = lower_left_longitude*(M_PI/180); // Unit: radian
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter) 
  lower_left_x = EquirectangularProjection::CalculateX(lambda, lambda_0, phi_1, R_moon); // Unit: meter
}

void ImageSets::CalculateLower_left_y()
{
  /*******************************************/
  /* Calculate image's lower left y position */
  /*******************************************/
  double phi = lower_left_latitude*(M_PI/180); // Unit: radian
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  lower_left_y = EquirectangularProjection::CalculateY(phi, phi_1, R_moon); // Unit: meter
}

void ImageSets::CalculateLower_right_x()
{
  /***************************************************/
  /* Calculate image's lower right corner x position */
  /***************************************************/
  double lambda = lower_right_longitude*(M_PI/180); // Unit: radian
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter) 
  lower_right_x = EquirectangularProjection::CalculateX(lambda, lambda_0, phi_1, R_moon); // Unit: meter
}

void ImageSets::CalculateLower_right_y()
{
  /********************************************/
  /* Calculate image's lower right y position */
  /********************************************/
  double phi = lower_right_latitude*(M_PI/180); // Unit: radian
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  lower_right_y = EquirectangularProjection::CalculateY(phi, phi_1, R_moon); // Unit: meter
}

void ImageSets::CalculatePhysical_height()
{
  /*******************************************************************************/
  /* Iterate through columns of image and calculate physical height along column */
  /*******************************************************************************/
  for(int i=0; i<width; i++)
  {
    double h_0 = pt.ComputeTarget2SourceCoordinate_y(i, 0);
    double h_1 = pt.ComputeTarget2SourceCoordinate_y(i, height);
    double diff = abs(h_1-h_0);
    physical_height.push_back(diff); // Unit: meters
  }
}

void ImageSets::CalculatePhysical_width()
{
  /************************************************************************/
  /* Iterate through rows of image and calculate physical width along row */
  /************************************************************************/
  for(int i=0; i<height; i++)
  {
    double w_0 = pt.ComputeTarget2SourceCoordinate_x(0, i);
    double w_1 = pt.ComputeTarget2SourceCoordinate_x(width, i);
    double diff = abs(w_1-w_0);
    physical_height.push_back(diff); // Unit: meters
  }
}

void ImageSets::CalculateTransforms()
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector < vector <double> > source_coordinates(4, vector <double> (2));
  vector < vector <double> > target_coordinates(4, vector <double> (2));

  /******************************************/
  /* Retrieve source and target coordinates */
  /******************************************/
  source_coordinates[0][0] = upper_left_longitude;
  source_coordinates[0][1] = upper_left_latitude;
  source_coordinates[1][0] = upper_right_longitude;
  source_coordinates[1][1] = upper_right_latitude;
  source_coordinates[2][0] = lower_right_longitude;
  source_coordinates[2][1] = lower_right_latitude;
  source_coordinates[3][0] = lower_left_longitude;
  source_coordinates[3][1] = lower_left_latitude;
  target_coordinates[0][0] = 0;
  target_coordinates[0][1] = 0;
  target_coordinates[1][0] = width;
  target_coordinates[1][1] = 0;
  target_coordinates[2][0] = width;
  target_coordinates[2][1] = height;
  target_coordinates[3][0] = 0;
  target_coordinates[3][1] = height;
  
  /************************************/
  /* Compute transformation matricies */
  /************************************/
  ProjectiveTransformation PT(source_coordinates, target_coordinates);

  /***********************************/
  /* Record transformation matricies */
  /***********************************/
  pt = PT;
}

void ImageSets::CalculateUpper_left_x()
{
  /**************************************************/
  /* Calculate image's upper left corner x position */
  /**************************************************/
  double lambda = upper_left_longitude*(M_PI/180); // Unit: radian
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter) 
  upper_left_x = EquirectangularProjection::CalculateX(lambda, lambda_0, phi_1, R_moon); // Unit: meter
}

void ImageSets::CalculateUpper_left_y()
{
  /*******************************************/
  /* Calculate image's upper left y position */
  /*******************************************/
  double phi = upper_left_latitude*(M_PI/180); // Unit: radian
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean rsadius of the moon (Unit: meter)
  upper_left_y = EquirectangularProjection::CalculateY(phi, phi_1, R_moon); // Unit: meter
}

void ImageSets::CalculateUpper_right_x()
{
  /***************************************************/
  /* Calculate image's upper right corner x position */
  /***************************************************/
  double lambda = upper_right_longitude*(M_PI/180); // Unit: radian
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter) 
  upper_right_x = EquirectangularProjection::CalculateX(lambda, lambda_0, phi_1, R_moon); // Unit: meter
}

void ImageSets::CalculateUpper_right_y()
{
  /*******************************************/
  /* Calculate image's lower left y position */
  /*******************************************/
  double phi = upper_right_latitude*(M_PI/180); // Unit: radian
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  upper_right_y = EquirectangularProjection::CalculateY(phi, phi_1, R_moon); // Unit: meter
}

void ImageSets::DetermineCoordinateExtrema()
{
  /***************************************************************************/
  /* Determine maximum/minimum selenographic and cartesian coordinate values */
  /***************************************************************************/
  if(upper_left_corner_x_status.compare("MAX") == 0)
  {
    maximum_longitude = (upper_left_longitude > lower_left_longitude) ? upper_left_longitude : lower_left_longitude;
    maximum_x = (upper_left_x > lower_left_x) ? upper_left_x : lower_left_x;
    minimum_longitude = (upper_right_longitude < lower_right_longitude) ? upper_right_longitude : lower_right_longitude;
    minimum_x = (upper_right_x < lower_right_x) ? upper_right_x : lower_right_x;
  }
  else
  {
    maximum_longitude = (upper_right_longitude > lower_right_longitude) ? upper_right_longitude : lower_right_longitude;
    maximum_x = (upper_right_x > lower_right_x) ? upper_right_x : lower_right_x;
    minimum_longitude = (upper_left_longitude < lower_left_longitude) ? upper_left_longitude : lower_left_longitude;
    minimum_x = (upper_left_x < lower_left_x) ? upper_left_x : lower_left_x;
  }
  if(upper_left_corner_y_status.compare("MAX") == 0)
  {
    maximum_latitude = (upper_left_latitude > upper_right_latitude) ? upper_left_latitude : upper_right_latitude;
    maximum_y = (upper_left_y > upper_right_y) ? upper_left_y : upper_right_y;
    minimum_latitude = (lower_left_latitude < lower_right_latitude) ? lower_left_latitude : lower_right_latitude;
    minimum_y = (lower_left_y < lower_right_y) ? lower_left_y : lower_right_y;
  }
  else
  {
    maximum_latitude = (lower_left_latitude > lower_right_latitude) ? lower_left_latitude : lower_right_latitude;
    maximum_y = (lower_left_y > lower_right_y) ? lower_left_y : lower_right_y;
    minimum_latitude = (upper_left_latitude < upper_right_latitude) ? upper_left_latitude : upper_right_latitude;
    minimum_y = (upper_left_y < upper_right_y) ? upper_left_y : upper_right_y;
  }
}

void ImageSets::DetermineImageReference()
{
  /*******************************************************/
  /* Determine if x coordinate of upper left hand corner */
  /* (user perspective) is a minimum or a maximum with   */
  /* respect to the upper right hand corner              */
  /*******************************************************/
  upper_left_corner_x_status = (upper_left_longitude < upper_right_longitude) ? "MIN" : "MAX";
  
  /*******************************************************/
  /* Determine if y coordinate of upper left hand corner */
  /* (user perspective) is a minimum or a maximum with   */
  /* respect to the lower left hand corner               */
  /*******************************************************/
  upper_left_corner_y_status = (upper_left_latitude < lower_left_latitude) ? "MIN" : "MAX";
}

void ImageSets::RetrieveHeight()
{
  /*************************/
  /* Retrieve image height */
  /*************************/
  int p1 = details.find("<height>")+8;
  int p2 = details.find("</height>");
  int length = p2-p1;
  string str = details.substr(p1, length);
  height = stoi(str, nullptr);
}

void ImageSets::RetrieveWidth()
{
  /************************/
  /* Retrieve image width */
  /************************/
  int p1 = details.find("<width>")+7;
  int p2 = details.find("</width>");
  int length = p2-p1;
  string str = details.substr(p1, length);
  width = stoi(str, nullptr);
}
