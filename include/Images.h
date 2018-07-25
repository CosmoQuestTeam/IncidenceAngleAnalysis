/* HEADER FILE: Images.h */

#ifndef IMAGES_H
#define IMAGES_H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "EquirectangularProjection.h"
#include "ProjectiveTransformation.h"
#include "Quadrilateral.h"

class Images
{
  /***********************************/
  /* Declaration of class variables */
  /***********************************/
  private:
    double area;
    double lower_left_latitude;
    double lower_left_longitude;
    double lower_left_x;
    double lower_left_y;
    double lower_right_latitude;
    double lower_right_longitude;
    double lower_right_x;
    double lower_right_y;
    double maximum_latitude;
    double maximum_longitude;
    double maximum_x;
    double maximum_y;
    double minimum_latitude;
    double minimum_longitude;
    double minimum_x;
    double minimum_y;
    double priority;
    double sun_angle;
    double upper_left_latitude;
    double upper_left_longitude;
    double upper_left_x;
    double upper_left_y;
    double upper_right_latitude;
    double upper_right_longitude;
    double upper_right_x;
    double upper_right_y;
    int application_id;
    int done;
    int height;
    int id;
    int image_set_id;
    int premarked;
    int width;
    int x_relative;
    int y_relative;
    ProjectiveTransformation pt;
    Quadrilateral quad;
    std::string created_at;
    std::string details;
    std::string file_location;
    std::string name;
    std::string updated_at;
    std::string upper_left_corner_x_status;
    std::string upper_left_corner_y_status;
    std::vector <double> physical_height;
    std::vector <double> physical_width;
    std::vector < std::vector <double> > shape_vector;

  /************************************/
  /* Declaration of class functions */
  /************************************/
  public:
    Images();
    Images(int, int, int, std::string, std::string, double, int, int, double, std::string, std::string, std::string);
    double GetArea();
    double GetLower_left_latitude();
    double GetLower_left_longitude();
    double GetLower_left_x();
    double GetLower_left_y();
    double GetLower_right_latitude();
    double GetLower_right_longitude();
    double GetLower_right_x();
    double GetLower_right_y();
    double GetMaximum_latitude();
    double GetMaximum_longitude();
    double GetMaximum_x();
    double GetMaximum_y();
    double GetMinimum_latitude();
    double GetMinimum_longitude();
    double GetMinimum_x();
    double GetMinimum_y();
    double GetPriority();
    double GetSun_angle();
    double GetUpper_left_latitude();
    double GetUpper_left_longitude();
    double GetUpper_left_x();
    double GetUpper_left_y();
    double GetUpper_right_latitude();
    double GetUpper_right_longitude();
    double GetUpper_right_x();
    double GetUpper_right_y();
    int GetApplication_id();
    int GetDone();
    int GetHeight();
    int GetId();
    int GetImage_set_id();
    int GetPremarked();
    int GetWidth();
    int GetX_relative();
    int GetY_relative();
    ProjectiveTransformation GetProjective_transformation();
    Quadrilateral GetQuadrilateral();
    std::string GetCreated_at();
    std::string GetDetails();
    std::string GetFile_location();
    std::string GetName();
    std::string GetUpdated_at();
    std::string GetUpper_left_corner_x_status();
    std::string GetUpper_left_corner_y_status();
    std::vector <double> GetPhysical_height();
    std::vector <double> GetPhysical_width();
    std::vector < std::vector <double> > GetShape_vector();
    void AuxilaryFunction(std::string, std::string, ProjectiveTransformation, bool = false);
    void CalculateBoundingRegionCartesianCoordinates();
    void CalculateBoundingRegionSelenographicCoordinates();
    void CalculatePhysical_height();
    void CalculatePhysical_width();
    void CalculateQuadrilateral();
    void DetermineCoordinateExtrema();
    void RetrieveHeight();
    void RetrieveWidth();
    void RetrieveX_relative();
    void RetrieveY_relative();
    void SetProjective_transformation(ProjectiveTransformation);
    void SetUpper_left_corner_x_status(std::string);
    void SetUpper_left_corner_y_status(std::string);
    void *GetValue(std::string);
};

#endif
