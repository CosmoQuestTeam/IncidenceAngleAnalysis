#include "Images.h"

using namespace std;

Images::Images(int ID, int ISID, int AID, string NAME, string FL, double P, int PM, int DONE, double SA, string DET, string CREATE, string UPDATE)
{
  application_id = AID;
  created_at = CREATE;
  details = DET;
  done = DONE;
  file_location = FL;
  height = 0;
  horizontal_resolution = 0;
  id = ID;
  image_set_id = ISID;
  lower_left_latitude = 0;
  lower_left_longitude = 0;
  lower_left_x = 0;
  lower_left_y = 0;
  lower_right_latitude = 0;
  lower_right_longitude = 0;
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
  pixel_resolution = 0;
  premarked = PM;
  priority = P;
  sun_angle = SA;
  updated_at = UPDATE;
  upper_left_latitude = 0;
  upper_left_longitude = 0;
  upper_left_x = 0;
  upper_left_corner_x_status = "";
  upper_left_y = 0;
  upper_left_corner_y_status = "";
  upper_right_latitude = 0;
  upper_right_longitude = 0;
  upper_right_x = 0;
  upper_right_y = 0;
  vertical_resolution = 0;
  width = 0;
  x_offset = 0;
  x_relative = 0;
  x_shift = 0;
  y_offset = 0;
  y_relative = 0;
  y_shift = 0;
}

double Images::GetHorizontal_resolution()
{
  return horizontal_resolution;
}

double Images::GetLower_left_latitude()
{
  return lower_left_latitude;
}

double Images::GetLower_left_longitude()
{
  return lower_left_longitude;
}

double Images::GetLower_left_x()
{
  return lower_left_x;
}

double Images::GetLower_left_y()
{
  return lower_left_y;
}

double Images::GetLower_right_latitude()
{
  return lower_right_latitude;
}

double Images::GetLower_right_longitude()
{
  return lower_right_longitude;
}

double Images::GetLower_right_x()
{
  return lower_right_x;
}

double Images::GetLower_right_y()
{
  return lower_right_y;
}

double Images::GetMaximum_latitude()
{
  return maximum_latitude;
}

double Images::GetMaximum_longitude()
{
  return maximum_longitude;
}

double Images::GetMaximum_x()
{
  return maximum_x;
}

double Images::GetMaximum_y()
{
  return maximum_y;
}

double Images::GetMinimum_latitude()
{
  return minimum_latitude;
}

double Images::GetMinimum_longitude()
{
  return minimum_longitude;
}

double Images::GetMinimum_x()
{
  return minimum_x;
}

double Images::GetMinimum_y()
{
  return minimum_y;
}

double Images::GetPhysical_height()
{
  return physical_height;
}

double Images::GetPhysical_width()
{
  return physical_width;
}

double Images::GetPixel_resolution()
{
  return pixel_resolution;
}

double Images::GetPriority()
{
  return priority;
}

double Images::GetSun_angle()
{
  return sun_angle;
}

double Images::GetUpper_left_latitude()
{
  return upper_left_latitude;
}

double Images::GetUpper_left_longitude()
{
  return upper_left_longitude;
}

double Images::GetUpper_left_x()
{
  return upper_left_x;
}

double Images::GetUpper_left_y()
{
  return upper_left_y;
}

double Images::GetUpper_right_latitude()
{
  return upper_right_latitude;
}

double Images::GetUpper_right_longitude()
{
  return upper_right_longitude;
}

double Images::GetUpper_right_x()
{
  return upper_right_x;
}

double Images::GetUpper_right_y()
{
  return upper_right_y;
}

double Images::GetVertical_resolution()
{
  return vertical_resolution;
}

double Images::GetX_offset()
{
  return x_offset;
}

double Images::GetX_shift()
{
  return x_shift;
}

double Images::GetY_offset()
{
  return y_offset;
}

double Images::GetY_shift()
{
  return y_shift;
}

int Images::GetApplication_id()
{
  return application_id;
}

int Images::GetDone()
{
  return done;
}

int Images::GetHeight()
{
  return height;
}

int Images::GetId()
{
  return id;
}

int Images::GetImage_set_id()
{
  return image_set_id;
}

int Images::GetPremarked()
{
  return premarked;
}

int Images::GetWidth()
{
  return width;
}

int Images::GetX_relative()
{
  return x_relative;
}

int Images::GetY_relative()
{
  return y_relative;
}

ProjectiveTransformation Images::GetProjective_transformation()
{
  return pt;
}

string Images::GetCreated_at()
{
  return created_at;
}

string Images::GetDetails()
{
  return details;
}

string Images::GetFile_location()
{
  return file_location;
}

string Images::GetName()
{
  return name;
}

string Images::GetUpdated_at()
{
  return updated_at;
}

string Images::GetUpper_left_corner_x_status()
{
  return upper_left_corner_x_status;
}

string Images::GetUpper_left_corner_y_status()
{
  return upper_left_corner_y_status;
}

void Images::AuxilaryFunction(string XORIGIN, string YORIGIN, double PR, double HR, double VR, double XOFFSET, double YOFFSET, double XSHIFT, double YSHIFT, ProjectiveTransformation PT)
{
  /*********************************/
  /* Step 1: Set image orientation */
  /*********************************/
  SetUpper_left_corner_x_status(XORIGIN);
  SetUpper_left_corner_y_status(YORIGIN);
  
  /********************************/
  /* Step 2: Set pixel resolution */
  /********************************/
  SetPixel_resolution(PR);
  SetHorizontal_resolution(HR);
  SetVertical_resolution(VR);

  /*******************************/
  /* Step 3: Set x and y offsets */
  /*******************************/
  SetX_offset(XOFFSET);
  SetY_offset(YOFFSET);

  /******************************/
  /* Step 4: Set x and y shifts */
  /******************************/
  SetX_shift(XSHIFT);
  SetY_shift(YSHIFT);

  /****************************************/
  /* Step 4: Set transformation matricies */
  /****************************************/
  SetProjective_transformation(PT);
  
  /********************************************/
  /* Step 4: Retrieve relative x and y values */
  /********************************************/
  RetrieveX_relative();
  RetrieveY_relative();

  /*******************************************/
  /* Step 5: Retrieve image width and height */
  /*******************************************/
  RetrieveWidth();
  RetrieveHeight();

  /*****************************************************/
  /* Step 6: Calculate physical image width and height */
  /*****************************************************/
  CalculatePhysical_width();
  CalculatePhysical_height();

  /*******************************************************************/
  /* Step 7: Calculate bounding region x and y cartesian coordinates */
  /*******************************************************************/
  CalculateUpper_left_x();
  CalculateUpper_left_y();
  CalculateUpper_right_x();
  CalculateUpper_right_y();
  CalculateLower_right_x();
  CalculateLower_right_y();
  CalculateLower_left_x();
  CalculateLower_left_y();

  /**************************************************************************************/
  /* Step 8: Calculate bounding region latitude and longitude selenographic coordinates */
  /**************************************************************************************/
  CalculateUpper_left_latitude();
  CalculateUpper_left_longitude();
  CalculateUpper_right_latitude();
  CalculateUpper_right_longitude();
  CalculateLower_right_latitude();
  CalculateLower_right_longitude();
  CalculateLower_left_latitude();
  CalculateLower_left_longitude();

  /*******************************************************/
  /* Step 9: Determine minimum/maximum coordinate values */
  /*******************************************************/
  DetermineCoordinateExtrema();
}

void Images::CalculateLower_left_latitude()
{
  /***********************************************************************/
  /* Calculate latitude of sub-image lower left corner as viewed by user */
  /***********************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  lower_left_latitude = EquirectangularProjection::CalculateLatitude(lower_left_y, phi_1, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateLower_left_longitude()
{
  /************************************************************************/
  /* Calculate longitude of sub-image lower left corner as viewed by user */
  /************************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  lower_left_longitude = EquirectangularProjection::CalculateLongitude(lower_left_x, phi_1, lambda_0, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateLower_left_x()
{
  /*************************************************************************/
  /* Calculate x position of sub-image lower left corner as viewed by user */
  /*************************************************************************/
  lower_left_x = upper_left_x+height*x_shift; // Unit: meter
}

void Images::CalculateLower_left_y()
{
  /*************************************************************************/
  /* Calculate y position of sub-image lower left corner as viewed by user */
  /*************************************************************************/
  lower_left_y = (upper_left_corner_y_status.compare("MIN") == 0) ? upper_left_y+height*vertical_resolution : upper_left_y-height*vertical_resolution; // Unit: meter
}

void Images::CalculateLower_right_latitude()
{
  /************************************************************************/
  /* Calculate latitude of sub-image lower right corner as viewed by user */
  /************************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  lower_right_latitude = EquirectangularProjection::CalculateLatitude(lower_right_y, phi_1, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateLower_right_longitude()
{
  /*************************************************************************/
  /* Calculate longitude of sub-image lower right corner as viewed by user */
  /*************************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  lower_right_longitude = EquirectangularProjection::CalculateLongitude(lower_right_x, phi_1, lambda_0, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateLower_right_x()
{
  /**************************************************************************/
  /* Calculate x position of sub-image lower right corner as viewed by user */
  /**************************************************************************/
  lower_right_x = (upper_left_corner_x_status.compare("MIN") == 0) ? upper_left_x+width*horizontal_resolution+height*x_shift : upper_left_x-width*horizontal_resolution+height*x_shift; // Unit: meter
}

void Images::CalculateLower_right_y()
{
  /**************************************************************************/
  /* Calculate y position of sub-image lower right corner as viewed by user */
  /**************************************************************************/
  lower_right_y = (upper_left_corner_y_status.compare("MIN") == 0) ? upper_left_y+height*vertical_resolution+width*y_shift : upper_left_y-height*vertical_resolution+width*y_shift; // Unit: meter
}

void Images::CalculatePhysical_height()
{
  physical_height = height*vertical_resolution;
}

void Images::CalculatePhysical_width()
{
  physical_width = width*horizontal_resolution;
}

void Images::CalculateUpper_left_latitude()
{
  /***********************************************************************/
  /* Calculate latitude of sub-image upper left corner as viewed by user */
  /***********************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  upper_left_latitude = EquirectangularProjection::CalculateLatitude(upper_left_y, phi_1, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateUpper_left_longitude()
{
  /************************************************************************/
  /* Calculate longitude of sub-image upper left corner as viewed by user */
  /************************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  upper_left_longitude = EquirectangularProjection::CalculateLongitude(upper_left_x, phi_1, lambda_0, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateUpper_left_x()
{
  /*************************************************************************/
  /* Calculate x position of sub-image upper left corner as viewed by user */
  /*************************************************************************/
  upper_left_x = (upper_left_corner_x_status.compare("MIN") == 0) ? x_offset+x_relative*horizontal_resolution+y_relative*x_shift : x_offset-x_relative*horizontal_resolution+y_relative*x_shift; // Unit: meter
}

void Images::CalculateUpper_left_y()
{
  /*************************************************************************/
  /* Calculate y position of sub-image upper left corner as viewed by user */
  /*************************************************************************/
  upper_left_y = (upper_left_corner_y_status.compare("MIN") == 0) ? y_offset+y_relative*vertical_resolution+x_relative*y_shift : y_offset-y_relative*vertical_resolution+x_relative*y_shift; // Unit:meter
}

void Images::CalculateUpper_right_latitude()
{
  /************************************************************************/
  /* Calculate latitude of sub-image upper right corner as viewed by user */
  /************************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  upper_right_latitude = EquirectangularProjection::CalculateLatitude(upper_right_y, phi_1, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateUpper_right_longitude()
{
  /*************************************************************************/
  /* Calculate longitude of sub-image upper right corner as viewed by user */
  /*************************************************************************/
  double phi_1 = 0; // Flat square projection (Unit: radian)
  double lambda_0 = 0; // Central meridian (Unit: radian)
  double R_moon = 1737400; // Physical mean radius of the moon (Unit: meter)
  upper_right_longitude = EquirectangularProjection::CalculateLongitude(upper_right_x, phi_1, lambda_0, R_moon)*(180/M_PI); // Unit: degree
}

void Images::CalculateUpper_right_x()
{
  /**************************************************************************/
  /* Calculate x position of sub-image upper right corner as viewed by user */
  /**************************************************************************/
  upper_right_x = (upper_left_corner_x_status.compare("MIN") == 0) ? upper_left_x+width*horizontal_resolution : upper_left_x-width*horizontal_resolution; // Unit:meter
}

void Images::CalculateUpper_right_y()
{
  /**************************************************************************/
  /* Calculate y position of sub-image upper right corner as viewed by user */
  /**************************************************************************/
  upper_right_y = upper_left_y+width*y_shift; // Unit:meter
}

void Images::DetermineCoordinateExtrema()
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

void Images::RetrieveHeight()
{
  /******************************************************/
  /* Parse "details" string to retrieve value of height */
  /******************************************************/
  int p1 = details.find("<height>")+8;
  int p2 = details.find("</height>");
  int length = p2-p1;
  string str = details.substr(p1, length);
  height = stoi(str, nullptr);
}

void Images::RetrieveWidth()
{
  /*****************************************************/
  /* Parse "details" string to retrieve value of width */
  /*****************************************************/
  int p1 = details.find("<width>")+7;
  int p2 = details.find("</width>");
  int length = p2-p1;
  string str = details.substr(p1, length);
  width = stoi(str, nullptr);
}

void Images::RetrieveX_relative()
{
  /***********************************************************/
  /* Retrieve x position relative to associated master image */
  /***********************************************************/
  int p1 = details.find("<x>")+3;
  int p2 = details.find("</x>");
  int length = p2-p1;
  string str = details.substr(p1, length);
  x_relative = stoi(str, nullptr);
}

void Images::RetrieveY_relative()
{
  /***********************************************************/
  /* Retrieve y position relative to associated master image */
  /***********************************************************/
  int p1 = details.find("<y>")+3;
  int p2 = details.find("</y>");
  int length = p2-p1;
  string str = details.substr(p1, length);
  y_relative = stoi(str, nullptr);
}

void Images::SetHorizontal_resolution(double val)
{
  horizontal_resolution = val;
}

void Images::SetPixel_resolution(double val)
{
  pixel_resolution = val;
}

void Images::SetProjective_transformation(ProjectiveTransformation PT)
{
  pt = PT;
}

void Images::SetVertical_resolution(double val)
{
  vertical_resolution = val;
}

void Images::SetUpper_left_corner_x_status(string str)
{
  upper_left_corner_x_status = str;
}

void Images::SetUpper_left_corner_y_status(string str)
{
  upper_left_corner_y_status = str;
}

void Images::SetX_offset(double val)
{
  x_offset = val;
}

void Images::SetX_shift(double val)
{
  x_shift = val;
}

void Images::SetY_offset(double val)
{
  y_offset = val;
}

void Images::SetY_shift(double val)
{
  y_shift = val;
}

void * Images::GetValue(string field)
{
  if(field.compare("application_id") == 0)
  {
    return &application_id;
  }
  if(field.compare("created_at") == 0)
  {
    return &created_at;
  }
  if(field.compare("details") == 0)
  {
    return &details;
  }
  if(field.compare("done") == 0)
  {
    return &done;
  }
  if(field.compare("file_location") == 0)
  {
    return &file_location;
  }
  if(field.compare("height") == 0)
  {
    return &height;
  }
  if(field.compare("horizontal_resolution") == 0)
  {
    return &horizontal_resolution;
  }
  if(field.compare("id") == 0)
  {
    return &id;
  }
  if(field.compare("image_set_id") == 0)
  {
    return &image_set_id;
  }
  if(field.compare("lower_left_latitude") == 0)
  {
    return &lower_left_latitude;
  }
  if(field.compare("lower_left_longitude") == 0)
  {
    return &lower_left_longitude;
  }
  if(field.compare("lower_left_x") == 0)
  {
    return &lower_left_x;
  }
  if(field.compare("lower_left_y") == 0)
  {
    return &lower_left_y;
  }
  if(field.compare("lower_right_latitude") == 0)
  {
    return &lower_right_latitude;
  }
  if(field.compare("lower_right_longitude") == 0)
  {
    return &lower_right_longitude;
  }
  if(field.compare("lower_right_x") == 0)
  {
    return &lower_right_x;
  }
  if(field.compare("lower_right_y") == 0)
  {
    return &lower_right_y;
  }
  if(field.compare("name") == 0)
  {
    return &name;
  }
  if(field.compare("physical_height") == 0)
  {
    return &physical_height;
  }
  if(field.compare("physical_width") == 0)
  {
    return &physical_width;
  }
  if(field.compare("pixel_resolution") == 0)
  {
    return &pixel_resolution;
  }
  if(field.compare("premarked") == 0)
  {
    return &premarked;
  }
  if(field.compare("priority") == 0)
  {
    return &priority;
  }
  if(field.compare("sun_angle") == 0)
  {
    return &sun_angle;
  }  
  if(field.compare("updated_at") == 0)
  {
    return &updated_at;
  }
  if(field.compare("upper_left_latitude") == 0)
  {
    return &upper_left_latitude;
  }
  if(field.compare("upper_left_longitude") == 0)
  {
    return &upper_left_longitude;
  }
  if(field.compare("upper_left_x") == 0)
  {
    return &upper_left_x;
  }
  if(field.compare("upper_left_corner_x_status") == 0)
  {
    return &upper_left_corner_x_status;
  }
  if(field.compare("upper_left_y") == 0)
  {
    return &upper_left_y;
  }
  if(field.compare("upper_left_corner_y_status") == 0)
  {
    return &upper_left_corner_y_status;
  }
  if(field.compare("upper_right_latitude") == 0)
  {
    return &upper_right_x;
  }
  if(field.compare("upper_right_longitude") == 0)
  {
    return &upper_right_y;
  }
  if(field.compare("upper_right_x") == 0)
  {
    return &upper_right_x;
  }
  if(field.compare("upper_right_y") == 0)
  {
    return &upper_right_y;
  }
  if(field.compare("vertical_resolution") == 0)
  {
    return &vertical_resolution;
  }
  if(field.compare("width") == 0)
  {
    return &width;
  }
  if(field.compare("x_offset") == 0)
  {
    return &x_offset;
  }
  if(field.compare("x_relative") == 0)
  {
    return &x_relative;
  }
  if(field.compare("x_shift") == 0)
  {
    return &x_shift;
  }
  if(field.compare("y_offset") == 0)
  {
    return &y_offset;
  }
  if(field.compare("y_relative") == 0)
  {
    return &y_relative;
  }
  if(field.compare("y_shift") == 0)
  {
    return &y_shift;
  }
  return NULL;
}
