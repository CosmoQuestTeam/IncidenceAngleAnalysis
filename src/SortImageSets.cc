#include "SortImageSets.h"

using namespace std;

SortImageSets::SortImageSets(vector <ImageSets> &IMAGESETS, string FIELD)
{
  field = FIELD;
  imagesets = IMAGESETS;
}

bool SortImageSets::cmp_by_application_id(ImageSets &a, ImageSets &b)
{
  return (a.GetApplication_id() < b.GetApplication_id());
}

bool SortImageSets::cmp_by_created_at(ImageSets &a, ImageSets &b)
{
  return (a.GetCreated_at() < b.GetCreated_at());
}

bool SortImageSets::cmp_by_description(ImageSets &a, ImageSets &b)
{
  return (a.GetDescription() < b.GetDescription());
}

bool SortImageSets::cmp_by_details(ImageSets &a, ImageSets &b)
{
  return (a.GetDetails() < b.GetDetails());
}

bool SortImageSets::cmp_by_height(ImageSets &a, ImageSets &b)
{
  return (a.GetHeight() < b.GetHeight());
}

bool SortImageSets::cmp_by_horizontal_latitudinal_change(ImageSets &a, ImageSets &b)
{
  return (a.GetHorizontal_latitudinal_change() < b.GetHorizontal_latitudinal_change());
}

bool SortImageSets::cmp_by_horizontal_resolution(ImageSets &a, ImageSets &b)
{
  return (a.GetHorizontal_resolution() < b.GetHorizontal_resolution());
}

bool SortImageSets::cmp_by_id(ImageSets &a, ImageSets &b)
{
  return (a.GetId() < b.GetId());
}

bool SortImageSets::cmp_by_lower_left_latitude(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_left_latitude() < b.GetLower_left_latitude());
}

bool SortImageSets::cmp_by_lower_left_longitude(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_left_longitude() < b.GetLower_left_longitude());
}

bool SortImageSets::cmp_by_lower_left_x(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_left_x() < b.GetLower_left_x());
}

bool SortImageSets::cmp_by_lower_left_y(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_left_y() < b.GetLower_left_y());
}

bool SortImageSets::cmp_by_lower_right_latitude(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_right_latitude() < b.GetLower_right_latitude());
}

bool SortImageSets::cmp_by_lower_right_longitude(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_right_longitude() < b.GetLower_right_longitude());
}

bool SortImageSets::cmp_by_lower_right_x(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_right_x() < b.GetLower_right_x());
}

bool SortImageSets::cmp_by_lower_right_y(ImageSets &a, ImageSets &b)
{
  return (a.GetLower_right_y() < b.GetLower_right_y());
}

bool SortImageSets::cmp_by_name(ImageSets &a, ImageSets &b)
{
  return (a.GetName() < b.GetName());
}

bool SortImageSets::cmp_by_physical_height(ImageSets &a, ImageSets &b)
{
  return (a.GetPhysical_height() < b.GetPhysical_height());
}

bool SortImageSets::cmp_by_physical_width(ImageSets &a, ImageSets &b)
{
  return (a.GetPhysical_width() < b.GetPhysical_width());
}

bool SortImageSets::cmp_by_pixel_resolution(ImageSets &a, ImageSets &b)
{
  return (a.GetPixel_resolution() < b.GetPixel_resolution());
}

bool SortImageSets::cmp_by_priority(ImageSets &a, ImageSets &b)
{
  return (a.GetPriority() < b.GetPriority());
}

bool SortImageSets::cmp_by_sun_angle(ImageSets &a, ImageSets &b)
{
  return (a.GetSun_angle() < b.GetSun_angle());
}

bool SortImageSets::cmp_by_updated_at(ImageSets &a, ImageSets &b)
{
  return (a.GetUpdated_at() < b.GetUpdated_at());
}

bool SortImageSets::cmp_by_upper_left_corner_x_status(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_left_corner_x_status() < b.GetUpper_left_corner_x_status());
}

bool SortImageSets::cmp_by_upper_left_corner_y_status(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_left_corner_y_status() < b.GetUpper_left_corner_y_status());
}

bool SortImageSets::cmp_by_upper_left_latitude(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_left_latitude() < b.GetUpper_left_latitude());
}

bool SortImageSets::cmp_by_upper_left_longitude(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_left_longitude() < b.GetUpper_left_longitude());
}

bool SortImageSets::cmp_by_upper_left_x(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_left_x() < b.GetUpper_left_x());
}

bool SortImageSets::cmp_by_upper_left_y(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_left_y() < b.GetUpper_left_y());
}

bool SortImageSets::cmp_by_upper_right_latitude(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_right_latitude() < b.GetUpper_right_latitude());
}

bool SortImageSets::cmp_by_upper_right_longitude(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_right_longitude() < b.GetUpper_right_longitude());
}

bool SortImageSets::cmp_by_upper_right_x(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_right_x() < b.GetUpper_right_x());
}

bool SortImageSets::cmp_by_upper_right_y(ImageSets &a, ImageSets &b)
{
  return (a.GetUpper_right_y() < b.GetUpper_right_y());
}

bool SortImageSets::cmp_by_vertical_longitudinal_change(ImageSets &a, ImageSets &b)
{
  return (a.GetVertical_longitudinal_change() < b.GetVertical_longitudinal_change());
}

bool SortImageSets::cmp_by_vertical_resolution(ImageSets &a, ImageSets &b)
{
  return (a.GetVertical_resolution() < b.GetVertical_resolution());
}

bool SortImageSets::cmp_by_width(ImageSets &a, ImageSets &b)
{
  return (a.GetWidth() < b.GetWidth());
}

int SortImageSets::GetFieldValue()
{
  /********************************/
  /* Retrieve field column number */
  /********************************/
  if(field.compare("application_id") == 0)
  {
    return 1;
  }
  if(field.compare("created_at") == 0)
  {
    return 2;
  }
  if(field.compare("description") == 0)
  {
    return 3;
  }
  if(field.compare("details") == 0)
  {
    return 4;
  }
  if(field.compare("height") == 0)
  {
    return 5;
  }
  if(field.compare("horizontal_latitudinal_change") == 0)
  {
    return 6;
  }
  if(field.compare("horizontal_resolution") == 0)
  {
    return 7;
  }
  if(field.compare("id") == 0)
  {
    return 8;
  }
  if(field.compare("lower_left_latitude") == 0)
  {
    return 9;
  }
  if(field.compare("lower_left_longitude") == 0)
  {
    return 10;
  }
  if(field.compare("lower_left_x") == 0)
  {
    return 11;
  }
  if(field.compare("lower_left_y") == 0)
  {
    return 12;
  }
  if(field.compare("lower_right_latitude") == 0)
  {
    return 13;
  }
  if(field.compare("lower_right_longitude") == 0)
  {
    return 14;
  }
  if(field.compare("lower_right_x") == 0)
  {
    return 15;
  }
  if(field.compare("lower_right_y") == 0)
  {
    return 16;
  }
  if(field.compare("name") == 0)
  {
    return 17;
  }
  if(field.compare("physical_height") == 0)
  {
    return 18;
  }
  if(field.compare("physical_width") == 0)
  {
    return 19;
  }
  if(field.compare("pixel_resolution") == 0)
  {
    return 20;
  }
  if(field.compare("priority") == 0)
  {
    return 21;
  }
  if(field.compare("sun_angle") == 0)
  {
    return 22;
  }
  if(field.compare("updated_at") == 0)
  {
    return 23;
  }
  if(field.compare("upper_left_corner_x_status") == 0)
  {
    return 24;
  }
  if(field.compare("upper_left_corner_y_status") == 0)
  {
    return 25;
  }
  if(field.compare("upper_left_latitude") == 0)
  {
    return 26;
  }
  if(field.compare("upper_left_longitude") == 0)
  {
    return 27;
  }
  if(field.compare("upper_left_x") == 0)
  {
    return 28;
  }
  if(field.compare("upper_left_y") == 0)
  {
    return 29;
  }
  if(field.compare("upper_right_latitude") == 0)
  {
    return 30;
  }
  if(field.compare("upper_right_longitude") == 0)
  {
    return 31;
  }
  if(field.compare("upper_right_x") == 0)
  {
    return 32;
  }
  if(field.compare("upper_right_y") == 0)
  {
    return 33;
  }
  if(field.compare("vertical_longitudinal_change") == 0)
  {
    return 34;
  }
  if(field.compare("vertical_resolution") == 0)
  {
    return 35;
  }
  if(field.compare("width") == 0)
  {
    return 36;
  }
  
  return 0;
}

vector <ImageSets> SortImageSets::GetImageSets()
{
  return imagesets;
}

void SortImageSets::arrange()
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
      sort(imagesets.begin(), imagesets.end(), cmp_by_application_id);
      break;
    }
    case 2:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_created_at);
      break;
    }
    case 3:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_description);
      break;
    }
    case 4:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_details);
      break;
    }
    case 5:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_height);
      break;
    }
    case 6:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_horizontal_latitudinal_change);
      break;
    }
    case 7:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_horizontal_resolution);
      break;
    }
    case 8:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_id);
      break;
    }
    case 9:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_left_latitude);
      break;
    }
    case 10:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_left_longitude);
      break;
    }
    case 11:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_left_x);
      break;
    }
    case 12:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_left_y);
      break;
    }
    case 13:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_right_latitude);
      break;
    }
    case 14:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_right_longitude);
      break;
    }
    case 15:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_right_x);
      break;
    }
    case 16:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_lower_right_y);
      break;
    }
    case 17:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_name);
      break;
    }
    case 18:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_physical_height);
      break;
    }
    case 19:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_physical_width);
      break;
    }
    case 20:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_pixel_resolution);
      break;
    }
    case 21:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_priority);
      break;
    }
    case 22:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_sun_angle);
      break;
    }
    case 23:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_updated_at);
      break;
    }
    case 24:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_left_corner_x_status);
      break;
    }
    case 25:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_left_corner_y_status);
      break;
    }
    case 26:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_left_latitude);
      break;
    }
    case 27:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_left_longitude);
      break;
    }
    case 28:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_left_x);
      break;
    }
    case 29:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_left_y);
      break;
    }
    case 30:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_right_latitude);
      break;
    }
    case 31:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_right_longitude);
      break;
    }
    case 32:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_right_x);
      break;
    }
    case 33:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_upper_right_y);
      break;
    }
    case 34:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_vertical_longitudinal_change);
      break;
    }
    case 35:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_vertical_resolution);
      break;
    }
    case 36:
    {
      sort(imagesets.begin(), imagesets.end(), cmp_by_width);
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
