/* HEADER FILE: OverlappedImages.h */

#ifndef OVERLAPPEDIMAGES_H
#define OVERLAPPEDIMAGES_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Images.h"

class OverlappedImages
{
  /**********************************/
  /* Declaration of class variables */
  /**********************************/
  private:
    double image1_area;
    double image1_incidence_angle;
    double image1_lower_left_latitude;
    double image1_lower_left_longitude;
    double image1_lower_right_latitude;
    double image1_lower_right_longitude;
    double image1_upper_left_latitude;
    double image1_upper_left_longitude;
    double image1_upper_right_latitude;
    double image1_upper_right_longitude;
    double image2_area;
    double image2_incidence_angle;
    double image2_lower_left_latitude;
    double image2_lower_left_longitude;
    double image2_lower_right_latitude;
    double image2_lower_right_longitude;
    double image2_upper_left_latitude;
    double image2_upper_left_longitude;
    double image2_upper_right_latitude;
    double image2_upper_right_longitude;
    double overlap_area;
    double overlap_lower_left_latitude;
    double overlap_lower_left_longitude;
    double overlap_lower_right_latitude;
    double overlap_lower_right_longitude;
    double overlap_upper_right_latitude;
    double overlap_upper_right_longitude;
    double overlap_upper_left_latitude;
    double overlap_upper_left_longitude;
    int id;
    int image1_id;
    int image2_id;
    std::string image1_name;
    std::string image2_name;

  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    OverlappedImages();
    OverlappedImages(int, int, std::string, double, double, double, double, double, double, double, double, double, double, int, std::string, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
    double GetImage1_area();
    double GetImage1_incidence_angle();
    double GetImage1_lower_left_latitude();
    double GetImage1_lower_left_longitude();
    double GetImage1_lower_right_latitude();
    double GetImage1_lower_right_longitude();
    double GetImage1_upper_left_latitude();
    double GetImage1_upper_left_longitude();
    double GetImage1_upper_right_latitude();
    double GetImage1_upper_right_longitude();
    double GetImage2_area();
    double GetImage2_incidence_angle();
    double GetImage2_lower_left_latitude();
    double GetImage2_lower_left_longitude();
    double GetImage2_lower_right_latitude();
    double GetImage2_lower_right_longitude();
    double GetImage2_upper_left_latitude();
    double GetImage2_upper_left_longitude();
    double GetImage2_upper_right_latitude();
    double GetImage2_upper_right_longitude();
    double GetOverlap_area();
    double GetOverlap_lower_left_latitude();
    double GetOverlap_lower_left_longitude();
    double GetOverlap_lower_right_latitude();
    double GetOverlap_lower_right_longitude();
    double GetOverlap_upper_left_latitude();
    double GetOverlap_upper_left_longitude();
    double GetOverlap_upper_right_latitude();
    double GetOverlap_upper_right_longitude();
    int GetId();
    int GetImage1_id();
    int GetImage2_id();
    std::string GetImage1_name();
    std::string GetImage2_name();
    static void Display(OverlappedImages);
    static void Display(std::vector <OverlappedImages> &);
};

#endif
