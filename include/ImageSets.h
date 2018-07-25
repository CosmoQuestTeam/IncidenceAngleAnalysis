/* HEADER FILE: ImageSets.h */

#ifndef IMAGESETS_H
#define IMAGESETS_H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "EquirectangularProjection.h"
#include "ProjectiveTransformation.h"

class ImageSets
{
  /***********************************/
  /* Declaration of class variables */
  /***********************************/
  private:
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
    double pixel_resolution;
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
    int height;
    int id;
    int width;
    ProjectiveTransformation pt;
    std::string created_at;
    std::string description;
    std::string details;
    std::string name;
    std::string updated_at;
    std::string upper_left_corner_x_status;
    std::string upper_left_corner_y_status;
    std::vector <double> physical_height;
    std::vector <double> physical_width;

  /************************************/
  /* Declaration of class functions */
  /************************************/
  public:
    ImageSets(int, std::string, int, double, double, double, double, double, double, double, double, double, double, double, std::string, std::string, std::string, std::string);
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
    double GetPixel_resolution();
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
    int GetHeight();
    int GetId();
    int GetWidth();
    ProjectiveTransformation GetProjective_transformation();
    std::string GetCreated_at();
    std::string GetDescription();
    std::string GetDetails();
    std::string GetName();
    std::string GetUpdated_at();
    std::string GetUpper_left_corner_x_status();
    std::string GetUpper_left_corner_y_status();
    std::vector <double> GetPhysical_height();
    std::vector <double> GetPhysical_width();
    void AuxilaryFunction(bool = false);
    void CalculateLower_left_x();
    void CalculateLower_left_y();
    void CalculateLower_right_x();
    void CalculateLower_right_y();
    void CalculatePhysical_height();
    void CalculatePhysical_width();
    void CalculateTransforms();
    void CalculateUpper_left_x();
    void CalculateUpper_left_y();
    void CalculateUpper_right_x();
    void CalculateUpper_right_y();
    void DetermineCoordinateExtrema();
    void DetermineImageReference();
    void RetrieveHeight();
    void RetrieveWidth();
};

#endif
