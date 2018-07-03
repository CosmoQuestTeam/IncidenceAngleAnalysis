/* HEADER FILE: Images.h */

#ifndef IMAGES_H
#define IMAGES_H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "EquirectangularProjection.h"
#include "ProjectiveTransformation.h"

class Images
{
  /***********************************/
  /* Declaration of class variables */
  /***********************************/
  private:
    double horizontal_resolution;
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
    double physical_height;
    double physical_width;
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
    double vertical_resolution;
    double x_offset;
    double x_shift;
    double y_offset;
    double y_shift;
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
    std::string created_at;
    std::string details;
    std::string file_location;
    std::string name;
    std::string updated_at;
    std::string upper_left_corner_x_status;
    std::string upper_left_corner_y_status;

  /************************************/
  /* Declaration of class functions */
  /************************************/
  public:
    Images(int, int, int, std::string, std::string, double, int, int, double, std::string, std::string, std::string);
    double GetHorizontal_resolution();
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
    double GetPhysical_height();
    double GetPhysical_width();
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
    double GetVertical_resolution();
    double GetX_offset();
    double GetX_shift();
    double GetY_offset();
    double GetY_shift();
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
    std::string GetCreated_at();
    std::string GetDetails();
    std::string GetFile_location();
    std::string GetName();
    std::string GetUpdated_at();
    std::string GetUpper_left_corner_x_status();
    std::string GetUpper_left_corner_y_status();
    void AuxilaryFunction(std::string, std::string, double, double, double, double, double, double, double, ProjectiveTransformation);
    void CalculateLower_left_latitude();
    void CalculateLower_left_longitude();
    void CalculateLower_left_x();
    void CalculateLower_left_y();
    void CalculateLower_right_latitude();
    void CalculateLower_right_longitude();
    void CalculateLower_right_x();
    void CalculateLower_right_y();
    void CalculatePhysical_height();
    void CalculatePhysical_width();
    void CalculateUpper_left_latitude();
    void CalculateUpper_left_longitude();
    void CalculateUpper_left_x();
    void CalculateUpper_left_y();
    void CalculateUpper_right_latitude();
    void CalculateUpper_right_longitude();
    void CalculateUpper_right_x();
    void CalculateUpper_right_y();
    void DetermineCoordinateExtrema();
    void RetrieveHeight();
    void RetrieveWidth();
    void RetrieveX_relative();
    void RetrieveY_relative();
    void SetHorizontal_resolution(double);
    void SetPixel_resolution(double);
    void SetProjective_transformation(ProjectiveTransformation);
    void SetVertical_resolution(double);
    void SetUpper_left_corner_x_status(std::string);
    void SetUpper_left_corner_y_status(std::string);
    void SetX_offset(double);
    void SetX_shift(double);
    void SetY_offset(double);
    void SetY_shift(double);
    void *GetValue(std::string);
};

#endif
