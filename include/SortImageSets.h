/* HEADER FILE: SortImageSets.h */

#ifndef SORTIMAGESETS_H
#define SORTIMAGESETS_H
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include "ImageSets.h"

class SortImageSets
{
  /**********************************/
  /* Declaration of class variables */
  /**********************************/
  private:
    std::string field;
    std::vector <ImageSets> imagesets;

  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    SortImageSets(std::vector <ImageSets> &, std::string);
    static bool cmp_by_application_id(ImageSets &, ImageSets &);
    static bool cmp_by_created_at(ImageSets &, ImageSets &);
    static bool cmp_by_description(ImageSets &, ImageSets &);
    static bool cmp_by_details(ImageSets &, ImageSets &);
    static bool cmp_by_height(ImageSets &, ImageSets &);
    static bool cmp_by_id(ImageSets &, ImageSets &);
    static bool cmp_by_lower_left_latitude(ImageSets &, ImageSets &);
    static bool cmp_by_lower_left_longitude(ImageSets &, ImageSets &);
    static bool cmp_by_lower_left_x(ImageSets &, ImageSets &);
    static bool cmp_by_lower_left_y(ImageSets &, ImageSets &);
    static bool cmp_by_lower_right_latitude(ImageSets &, ImageSets &);
    static bool cmp_by_lower_right_longitude(ImageSets &, ImageSets &);
    static bool cmp_by_lower_right_x(ImageSets &, ImageSets &);
    static bool cmp_by_lower_right_y(ImageSets &, ImageSets &);
    static bool cmp_by_maximum_latitude(ImageSets &, ImageSets &);
    static bool cmp_by_maximum_longitude(ImageSets &, ImageSets &);
    static bool cmp_by_maximum_x(ImageSets &, ImageSets &);
    static bool cmp_by_maximum_y(ImageSets &, ImageSets &);
    static bool cmp_by_minimum_latitude(ImageSets &, ImageSets &);
    static bool cmp_by_minimum_longitude(ImageSets &, ImageSets &);
    static bool cmp_by_minimum_x(ImageSets &, ImageSets &);
    static bool cmp_by_minimum_y(ImageSets &, ImageSets &);
    static bool cmp_by_name(ImageSets &, ImageSets &);
    static bool cmp_by_pixel_resolution(ImageSets &, ImageSets &);
    static bool cmp_by_priority(ImageSets &, ImageSets &);
    static bool cmp_by_sun_angle(ImageSets &, ImageSets &);
    static bool cmp_by_updated_at(ImageSets &, ImageSets &);
    static bool cmp_by_upper_left_corner_x_status(ImageSets &, ImageSets &);
    static bool cmp_by_upper_left_corner_y_status(ImageSets &, ImageSets &);
    static bool cmp_by_upper_left_latitude(ImageSets &, ImageSets &);
    static bool cmp_by_upper_left_longitude(ImageSets &, ImageSets &);
    static bool cmp_by_upper_left_x(ImageSets &, ImageSets &);
    static bool cmp_by_upper_left_y(ImageSets &, ImageSets &);
    static bool cmp_by_upper_right_latitude(ImageSets &, ImageSets &);
    static bool cmp_by_upper_right_longitude(ImageSets &, ImageSets &);
    static bool cmp_by_upper_right_x(ImageSets &, ImageSets &);
    static bool cmp_by_upper_right_y(ImageSets &, ImageSets &);
    static bool cmp_by_width(ImageSets &, ImageSets &);
    int GetFieldValue();
    std::vector <ImageSets> GetImageSets();
    void arrange();
};

#endif
