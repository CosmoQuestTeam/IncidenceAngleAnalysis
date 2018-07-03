#include "ImageSets.h"

using namespace std;

ImageSets::ImageSets(int ID, string NAME, int AID, double P, double SA, double ULLAT, double ULLONG, double URLAT, double URLONG, double LRLAT, double LRLONG, double LLLAT, double LLLONG, double PR, string DESCRIP, string DET, string CREATE, string UPDATE)
{
  application_id = AID;
  created_at = CREATE;
  description = DESCRIP;
  details = DET;
  height = 0;
  horizontal_latitudinal_change = 0;
  horizontal_resolution = 0;
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
  physical_height = 0;
  physical_width = 0;
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
  vertical_longitudinal_change = 0;
  vertical_resolution = 0;
  width = 0;
  x_shift = 0;
  y_shift = 0;
}

double ImageSets::GetHorizontal_latitudinal_change()
{
  return horizontal_latitudinal_change;
}

double ImageSets::GetHorizontal_resolution()
{
  return horizontal_resolution;
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

double ImageSets::GetPhysical_height()
{
  return physical_height;
}

double ImageSets::GetPhysical_width()
{
  return physical_width;
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

double ImageSets::GetVertical_longitudinal_change()
{
  return vertical_longitudinal_change;
}

double ImageSets::GetVertical_resolution()
{
  return vertical_resolution;
}

double ImageSets::ImageSets::GetX_shift()
{
  return x_shift;
}

double ImageSets::GetY_shift()
{
  return y_shift;
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

void ImageSets::AuxilaryFunction()
{
  /*****************************************************/
  /* Step 1: Determine image reference point and shape */
  /*****************************************************/
  DetermineImageReference();
  DetermineImageShape();

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
  
  /*****************************************************/
  /* Step 5: Calculate physical image width and height */
  /*****************************************************/
  CalculatePhysical_width();
  CalculatePhysical_height();

  /***************************************************************/
  /* Step 6: Calculate horizontal and vertical pixel resolutions */
  /***************************************************************/
  CalculateHorizontal_resolution();
  CalculateVertical_resolution();

  /**********************************************************************************/
  /* Step 7: Calculate x and y shift from rectangular region into a rhomboid region */
  /**********************************************************************************/
  CalculateXShift();
  CalculateYShift();
  
  /*******************************************/
  /* Step 8: Calculate transformation matrix */
  /*******************************************/
  CalculateTransforms();
}

void ImageSets::CalculateHorizontal_resolution()
{
  /*******************************************/
  /* Declaration/Initialization of variables */
  /*******************************************/
  double x_range;
  double n_pixels;

  /*********************/
  /* Calculate x range */
  /*********************/
  x_range = physical_width;

  /*******************************/
  /* Retrieve number of x pixels */
  /*******************************/
  n_pixels = width;

  /*****************************************/
  /* Calculate horizontal pixel resolution */
  /*****************************************/
  horizontal_resolution = x_range/n_pixels;
}

void ImageSets::CalculatePhysical_height()
{
  physical_height = (upper_left_corner_y_status.compare("MAX") == 0) ? upper_left_y-lower_left_y : lower_left_y-upper_left_y;
}

void ImageSets::CalculatePhysical_width()
{
  physical_width = (upper_left_corner_x_status.compare("MAX") == 0) ? upper_left_x-upper_right_x : upper_right_x-upper_left_x;
}

void ImageSets::CalculateVertical_resolution()
{
  /*******************************************/
  /* Declaration/Initialization of variables */
  /*******************************************/
  double y_range;
  double n_pixels;

  /*********************/
  /* Calculate y range */
  /*********************/
  y_range = physical_height;

  /*******************************/
  /* Retrieve number of y pixels */
  /*******************************/
  n_pixels = height;

  /***************************************/
  /* Calculate vertical pixel resolution */
  /***************************************/
  vertical_resolution = y_range/n_pixels;
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

void ImageSets::CalculateXShift()
{
  /*******************************************/
  /* Calculate shift in x per pixel from     */
  /* rectangular region into rhomboid region */
  /*******************************************/
  double lambda = vertical_longitudinal_change*(M_PI/180); // Unit: radian
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  x_shift = EquirectangularProjection::CalculateX(lambda, lambda_0, phi_1, R_moon)/height; // Unit: meters per pixel;
}

void ImageSets::CalculateYShift()
{
  /*******************************************/
  /* Calculate shift in y per pixel from     */
  /* rectangular region into rhomboid region */
  /*******************************************/
  double phi = horizontal_latitudinal_change*(M_PI/180); // Unit: radian
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  y_shift = EquirectangularProjection::CalculateY(phi, phi_1, R_moon)/width; // Unit: meters per pixel
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

void ImageSets::DetermineImageShape()
{
  /************************************************/
  /* Determine if longitude varies along a column */
  /************************************************/
  vertical_longitudinal_change = lower_left_longitude-upper_left_longitude;
  
  /********************************************/
  /* Determine if latitude varies along a row */
  /********************************************/
  horizontal_latitudinal_change = upper_right_latitude-upper_left_latitude;
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
