/* HEADER FILE: SortImages.h */

#ifndef SORTIMAGES_H
#define SORTIMAGES_H
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include "Images.h"

class SortImages
{
  /**********************************/
  /* Declaration of class variables */
  /**********************************/
  private:
    std::string field;
    std::vector <Images> images;

  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    SortImages(std::vector <Images> &, std::string);
    static bool cmp_by_application_id(Images &, Images &);
    static bool cmp_by_created_at(Images &, Images &);
    static bool cmp_by_details(Images &, Images &);
    static bool cmp_by_done(Images &, Images &);
    static bool cmp_by_file_location(Images &, Images &);
    static bool cmp_by_height(Images &, Images &);
    static bool cmp_by_horizontal_resolution(Images &, Images &);
    static bool cmp_by_id(Images &, Images &);
    static bool cmp_by_image_set_id(Images &, Images &);
    static bool cmp_by_lower_left_latitude(Images &, Images &);
    static bool cmp_by_lower_left_longitude(Images &, Images &);
    static bool cmp_by_lower_left_x(Images &, Images &);
    static bool cmp_by_lower_left_y(Images &, Images &);
    static bool cmp_by_lower_right_latitude(Images &, Images &);
    static bool cmp_by_lower_right_longitude(Images &, Images &);
    static bool cmp_by_lower_right_x(Images &, Images &);    
    static bool cmp_by_lower_right_y(Images &, Images &);
    static bool cmp_by_name(Images &, Images &);
    static bool cmp_by_physical_height(Images &, Images &);
    static bool cmp_by_physical_width(Images &, Images &);
    static bool cmp_by_pixel_resolution(Images &, Images &);
    static bool cmp_by_premarked(Images &, Images &);
    static bool cmp_by_priority(Images &, Images &);
    static bool cmp_by_sun_angle(Images &, Images &);
    static bool cmp_by_updated_at(Images &, Images &);
    static bool cmp_by_upper_left_corner_x_status(Images &, Images &);
    static bool cmp_by_upper_left_corner_y_status(Images &, Images &);
    static bool cmp_by_upper_left_latitude(Images &, Images &);
    static bool cmp_by_upper_left_longitude(Images &, Images &);
    static bool cmp_by_upper_left_x(Images &, Images &);
    static bool cmp_by_upper_left_y(Images &, Images &);
    static bool cmp_by_upper_right_latitude(Images &, Images &);
    static bool cmp_by_upper_right_longitude(Images &, Images &);
    static bool cmp_by_upper_right_x(Images &, Images &);
    static bool cmp_by_upper_right_y(Images &, Images &);
    static bool cmp_by_vertical_resolution(Images &, Images &);
    static bool cmp_by_width(Images &, Images &);
    static bool cmp_by_x_offset(Images &, Images &);
    static bool cmp_by_x_relative(Images &, Images &);
    static bool cmp_by_x_shift(Images &, Images &);
    static bool cmp_by_y_offset(Images &, Images &);
    static bool cmp_by_y_relative(Images &, Images &);
    static bool cmp_by_y_shift(Images &, Images &);
    int GetFieldValue();
    std::vector <Images> GetImages();
    void arrange();
};

#endif
