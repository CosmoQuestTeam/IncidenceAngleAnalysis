/* HEADER FILE: SortOverlappedImages.h */

#ifndef SORTOVERLAPPEDIMAGES_H
#define SORTOVERLAPPEDIMAGES_H
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include "OverlappedImages.h"

class SortOverlappedImages
{
  /**********************************/
  /* Declaration of class variables */
  /**********************************/
  private:
    std::string field;
    std::vector <OverlappedImages> overlappedimages;

  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    SortOverlappedImages(std::vector <OverlappedImages> &, std::string);
    static bool cmp_by_id(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_area(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_id(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_incidence_angle(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_lower_left_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_lower_left_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_lower_right_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_lower_right_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_name(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_upper_left_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_upper_left_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_upper_right_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image1_upper_right_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_area(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_id(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_incidence_angle(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_lower_left_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_lower_left_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_lower_right_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_lower_right_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_name(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_upper_left_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_upper_left_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_upper_right_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_image2_upper_right_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_area(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_lower_left_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_lower_left_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_lower_right_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_lower_right_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_upper_left_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_upper_left_longitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_upper_right_latitude(OverlappedImages &, OverlappedImages &);
    static bool cmp_by_overlap_upper_right_longitude(OverlappedImages &, OverlappedImages &);
    int GetFieldValue();
    std::vector <OverlappedImages> GetOverlappedimages();
    void arrange();
};

#endif
