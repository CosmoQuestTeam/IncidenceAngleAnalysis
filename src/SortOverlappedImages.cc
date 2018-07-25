#include "SortOverlappedImages.h"

using namespace std;

SortOverlappedImages::SortOverlappedImages(vector <OverlappedImages> &OVERLAPPEDIMAGES, string FIELD)
{
  field = FIELD;
  overlappedimages = OVERLAPPEDIMAGES;
}

bool SortOverlappedImages::cmp_by_id(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetId() < b.GetId());
}

bool SortOverlappedImages::cmp_by_image1_area(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_area() < b.GetImage1_area());
}

bool SortOverlappedImages::cmp_by_image1_id(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_id() < b.GetImage1_id());
}

bool SortOverlappedImages::cmp_by_image1_incidence_angle(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_incidence_angle() < b.GetImage1_incidence_angle());
}

bool SortOverlappedImages::cmp_by_image1_lower_left_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_lower_left_latitude() < b.GetImage1_lower_left_latitude());
}

bool SortOverlappedImages::cmp_by_image1_lower_left_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_lower_left_longitude() < b.GetImage1_lower_left_longitude());
}

bool SortOverlappedImages::cmp_by_image1_lower_right_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_lower_right_latitude() < b.GetImage1_lower_right_latitude());
}

bool SortOverlappedImages::cmp_by_image1_lower_right_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_lower_right_longitude() < b.GetImage1_lower_right_longitude());
}

bool SortOverlappedImages::cmp_by_image1_name(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_name() < b.GetImage1_name());
}

bool SortOverlappedImages::cmp_by_image1_upper_left_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_upper_left_latitude() < b.GetImage1_upper_left_latitude());
}

bool SortOverlappedImages::cmp_by_image1_upper_left_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_upper_left_longitude() < b.GetImage1_upper_left_longitude());
}

bool SortOverlappedImages::cmp_by_image1_upper_right_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_upper_right_latitude() < b.GetImage1_upper_right_latitude());
}

bool SortOverlappedImages::cmp_by_image1_upper_right_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage1_upper_right_longitude() < b.GetImage1_upper_right_longitude());
}

bool SortOverlappedImages::cmp_by_image2_area(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_area() < b.GetImage2_area());
}

bool SortOverlappedImages::cmp_by_image2_id(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_id() < b.GetImage2_id());
}

bool SortOverlappedImages::cmp_by_image2_incidence_angle(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_incidence_angle() < b.GetImage2_incidence_angle());
}

bool SortOverlappedImages::cmp_by_image2_lower_left_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_lower_left_latitude() < b.GetImage2_lower_left_latitude());
}

bool SortOverlappedImages::cmp_by_image2_lower_left_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_lower_left_longitude() < b.GetImage2_lower_left_longitude());
}

bool SortOverlappedImages::cmp_by_image2_lower_right_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_lower_right_latitude() < b.GetImage2_lower_right_latitude());
}

bool SortOverlappedImages::cmp_by_image2_lower_right_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_lower_right_longitude() < b.GetImage2_lower_right_longitude());
}

bool SortOverlappedImages::cmp_by_image2_name(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_name() < b.GetImage2_name());
}

bool SortOverlappedImages::cmp_by_image2_upper_left_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_upper_left_latitude() < b.GetImage2_upper_left_latitude());
}

bool SortOverlappedImages::cmp_by_image2_upper_left_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_upper_left_longitude() < b.GetImage2_upper_left_longitude());
}

bool SortOverlappedImages::cmp_by_image2_upper_right_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_upper_right_latitude() < b.GetImage2_upper_right_latitude());
}

bool SortOverlappedImages::cmp_by_image2_upper_right_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetImage2_upper_right_longitude() < b.GetImage2_upper_right_longitude());
}

bool SortOverlappedImages::cmp_by_overlap_area(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_area() < b.GetOverlap_area());
}

bool SortOverlappedImages::cmp_by_overlap_lower_left_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_lower_left_latitude() < b.GetOverlap_lower_left_latitude());
}

bool SortOverlappedImages::cmp_by_overlap_lower_left_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_lower_left_longitude() < b.GetOverlap_lower_left_longitude());
}

bool SortOverlappedImages::cmp_by_overlap_lower_right_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_lower_right_latitude() < b.GetOverlap_lower_right_latitude());
}

bool SortOverlappedImages::cmp_by_overlap_lower_right_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_lower_right_longitude() < b.GetOverlap_lower_right_longitude());
}

bool SortOverlappedImages::cmp_by_overlap_upper_left_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_upper_left_latitude() < b.GetOverlap_upper_left_latitude());
}

bool SortOverlappedImages::cmp_by_overlap_upper_left_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_upper_left_longitude() < b.GetOverlap_upper_left_longitude());
}

bool SortOverlappedImages::cmp_by_overlap_upper_right_latitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_upper_right_latitude() < b.GetOverlap_upper_right_latitude());
}

bool SortOverlappedImages::cmp_by_overlap_upper_right_longitude(OverlappedImages &a, OverlappedImages &b)
{
  return (a.GetOverlap_upper_right_longitude() < b.GetOverlap_upper_right_longitude());
}

int SortOverlappedImages::GetFieldValue()
{
  /********************************/
  /* Retrieve field column number */
  /********************************/
  if(field.compare("id") == 0)
  {
    return 1;
  }
  if(field.compare("image1_area") == 0)
  {
    return 2;
  }
  if(field.compare("image1_id") == 0)
  {
    return 3;
  }
  if(field.compare("image1_incidence_angle") == 0)
  {
    return 4;
  }
  if(field.compare("image1_lower_left_latitude") == 0)
  {
    return 5;
  }
  if(field.compare("image1_lower_left_longitude") == 0)
  {
    return 6;
  }
  if(field.compare("image1_lower_right_latitude") == 0)
  {
    return 7;
  }
  if(field.compare("image1_lower_right_longitude") == 0)
  {
    return 8;
  }
  if(field.compare("image1_name") == 0)
  {
    return 9;
  }
  if(field.compare("image1_upper_left_latitude") == 0)
  {
    return 10;
  }
  if(field.compare("image1_upper_left_longitude") == 0)
  {
    return 11;
  }
  if(field.compare("image1_upper_right_latitude") == 0)
  {
    return 12;
  }
  if(field.compare("image1_upper_right_longitude") == 0)
  {
    return 13;
  }
  if(field.compare("image2_area") == 0)
  {
    return 14;
  }
  if(field.compare("image2_id") == 0)
  {
    return 15;
  }
  if(field.compare("image2_incidence_angle") == 0)
  {
    return 16;
  }
  if(field.compare("image2_lower_left_latitude") == 0)
  {
    return 17;
  }
  if(field.compare("image2_lower_left_longitude") == 0)
  {
    return 18;
  }
  if(field.compare("image2_lower_right_latitude") == 0)
  {
    return 19;
  }
  if(field.compare("image2_lower_right_longitude") == 0)
  {
    return 20;
  }
  if(field.compare("image2_name") == 0)
  {
    return 21;
  }
  if(field.compare("image2_upper_left_latitude") == 0)
  {
    return 22;
  }
  if(field.compare("image2_upper_left_longitude") == 0)
  {
    return 23;
  }
  if(field.compare("image2_upper_right_latitude") == 0)
  {
    return 24;
  }
  if(field.compare("image2_upper_right_longitude") == 0)
  {
    return 25;
  }
  if(field.compare("overlap_area") == 0)
  {
    return 26;
  }
  if(field.compare("overlap_upper_left_latitude") == 0)
  {
    return 27;
  }
  if(field.compare("overlap_upper_left_longitude") == 0)
  {
    return 28;
  }
  if(field.compare("overlap_upper_right_latitude") == 0)
  {
    return 29;
  }
  if(field.compare("overlap_upper_right_longitude") == 0)
  {
    return 30;
  }
  if(field.compare("overlap_lower_left_latitude") == 0)
  {
    return 31;
  }
  if(field.compare("overlap_lower_left_longitude") == 0)
  {
    return 32;
  }
  if(field.compare("overlap_lower_right_latitude") == 0)
  {
    return 33;
  }
  if(field.compare("overlap_lower_right_longitude") == 0)
  {
    return 34;
  }

  return 0;
}

vector <OverlappedImages> SortOverlappedImages::GetOverlappedimages()
{
  return overlappedimages;
}

void SortOverlappedImages::arrange()
{
  /***************************************************/
  /* Declaration/Initilization of function variables */
  /***************************************************/
  int fieldvalue;

  /***************************/
  /* Get field column number */
  /***************************/
  fieldvalue = GetFieldValue();
  
  /**********************************************/
  /* Determine which field to sort on then sort */
  /**********************************************/
  switch(fieldvalue)
  {
    case 1:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_id);
      break;
    }
    case 2:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_area);
      break;
    }
    case 3:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_id);
      break;
    }
    case 4:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_incidence_angle);
      break;
    }
    case 5:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_lower_left_latitude);
      break;
    }
    case 6:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_lower_left_longitude);
      break;
    }
    case 7:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_lower_right_latitude);
      break;
    }
    case 8:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_lower_right_longitude);
      break;
    }
    case 9:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_name);
      break;
    }
    case 10:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_upper_left_latitude);
      break;
    }
    case 11:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_upper_left_longitude);
      break;
    }
    case 12:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_upper_right_latitude);
      break;
    }
    case 13:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image1_upper_right_longitude);
      break;
    }
    case 14:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_area);
      break;
    }
    case 15:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_id);
      break;
    }
    case 16:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_incidence_angle);
      break;
    }
    case 17:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_lower_left_latitude);
      break;
    }
    case 18:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_lower_left_longitude);
      break;
    }
    case 19:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_lower_right_latitude);
      break;
    }
    case 20:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_lower_right_longitude);
      break;
    }
    case 21:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_name);
      break;
    }
    case 22:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_upper_left_latitude);
      break;
    }
    case 23:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_upper_left_longitude);
      break;
    }
    case 24:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_upper_right_latitude);
      break;
    }
    case 25:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_image2_upper_right_longitude);
      break;
    }
    case 26:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_area);
      break;
    }
    case 27:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_lower_left_latitude);
      break;
    }
    case 28:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_lower_left_longitude);
      break;
    }
    case 29:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_lower_right_latitude);
      break;
    }
    case 30:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_lower_right_longitude);
      break;
    }
    case 31:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_upper_left_latitude);
      break;
    }
    case 32:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_upper_left_longitude);
      break;
    }
    case 33:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_upper_right_latitude);
      break;
    }
    case 34:
    {
      sort(overlappedimages.begin(), overlappedimages.end(), cmp_by_overlap_upper_right_longitude);
      break;
    }
    default:
    {
      printf("Invalid field value %d.\n", fieldvalue);
      printf("Terminating program ...\n");
      exit(EXIT_FAILURE);
    }
  }
  
  return;
}
