#include "SortImages.h"

using namespace std;

SortImages::SortImages(vector <Images> &IMAGES, string FIELD)
{
  field = FIELD;
  images = IMAGES;
}

bool SortImages::cmp_by_application_id(Images &a, Images &b)
{
  return (a.GetApplication_id() < b.GetApplication_id());
}

bool SortImages::cmp_by_created_at(Images &a, Images &b)
{
  return (a.GetCreated_at() < b.GetCreated_at());
}

bool SortImages::cmp_by_details(Images &a, Images &b)
{
  return (a.GetDetails() < b.GetDetails());
}

bool SortImages::cmp_by_done(Images &a, Images &b)
{
  return (a.GetDone() < b.GetDone());
}

bool SortImages::cmp_by_file_location(Images &a, Images &b)
{
  return (a.GetFile_location() < b.GetFile_location());
}

bool SortImages::cmp_by_height(Images &a, Images &b)
{
  return (a.GetHeight() < b.GetHeight());
}

bool SortImages::cmp_by_horizontal_resolution(Images &a, Images &b)
{
  return (a.GetHorizontal_resolution() < b.GetHorizontal_resolution());
}

bool SortImages::cmp_by_id(Images &a, Images &b)
{
  return (a.GetId() < b.GetId());
}

bool SortImages::cmp_by_image_set_id(Images &a, Images &b)
{
  return (a.GetImage_set_id() < b.GetImage_set_id());
}

bool SortImages::cmp_by_lower_left_latitude(Images &a, Images &b)
{
  return (a.GetLower_left_latitude() < b.GetLower_left_latitude());
}

bool SortImages::cmp_by_lower_left_longitude(Images &a, Images &b)
{
  return (a.GetLower_left_longitude() < b.GetLower_left_longitude());
}

bool SortImages::cmp_by_lower_left_x(Images &a, Images &b)
{
  return (a.GetLower_left_x() < b.GetLower_left_x());
}

bool SortImages::cmp_by_lower_left_y(Images &a, Images &b)
{
  return (a.GetLower_left_y() < b.GetLower_left_y());
}

bool SortImages::cmp_by_lower_right_latitude(Images &a, Images &b)
{
  return (a.GetLower_right_latitude() < b.GetLower_right_latitude());
}

bool SortImages::cmp_by_lower_right_longitude(Images &a, Images &b)
{
  return (a.GetLower_right_longitude() < b.GetLower_right_longitude());
}

bool SortImages::cmp_by_lower_right_x(Images &a, Images &b)
{
  return (a.GetLower_right_x() < b.GetLower_right_x());
}

bool SortImages::cmp_by_lower_right_y(Images &a, Images &b)
{
  return (a.GetLower_right_y() < b.GetLower_right_y());
}

bool SortImages::cmp_by_name(Images &a, Images &b)
{
  return (a.GetName() < b.GetName());
}

bool SortImages::cmp_by_physical_height(Images &a, Images &b)
{
  return (a.GetPhysical_height() < b.GetPhysical_height());
}

bool SortImages::cmp_by_physical_width(Images &a, Images &b)
{
  return (a.GetPhysical_width() < b.GetPhysical_width());
}

bool SortImages::cmp_by_pixel_resolution(Images &a, Images &b)
{
  return (a.GetPixel_resolution() < b.GetPixel_resolution());
}

bool SortImages::cmp_by_premarked(Images &a, Images &b)
{
  return (a.GetPremarked() < b.GetPremarked());
}

bool SortImages::cmp_by_priority(Images &a, Images &b)
{
  return (a.GetPriority() < b.GetPriority());
}

bool SortImages::cmp_by_sun_angle(Images &a, Images &b)
{
  return (a.GetSun_angle() < b.GetSun_angle());
}

bool SortImages::cmp_by_updated_at(Images &a, Images &b)
{
  return (a.GetUpdated_at() < b.GetUpdated_at());
}

bool SortImages::cmp_by_upper_left_corner_x_status(Images &a, Images &b)
{
  return (a.GetUpper_left_corner_x_status() < b.GetUpper_left_corner_x_status());
}

bool SortImages::cmp_by_upper_left_corner_y_status(Images &a, Images &b)
{
  return (a.GetUpper_left_corner_y_status() < b.GetUpper_left_corner_y_status());
}

bool SortImages::cmp_by_upper_left_latitude(Images &a, Images &b)
{
  return (a.GetUpper_left_latitude() < b.GetUpper_left_latitude());
}

bool SortImages::cmp_by_upper_left_longitude(Images &a, Images &b)
{
  return (a.GetUpper_left_longitude() < b.GetUpper_left_longitude());
}

bool SortImages::cmp_by_upper_left_x(Images &a, Images &b)
{
  return (a.GetUpper_left_x() < b.GetUpper_left_x());
}

bool SortImages::cmp_by_upper_left_y(Images &a, Images &b)
{
  return (a.GetUpper_left_y() < b.GetUpper_left_y());
}

bool SortImages::cmp_by_upper_right_latitude(Images &a, Images &b)
{
  return (a.GetUpper_right_latitude() < b.GetUpper_right_latitude());
}

bool SortImages::cmp_by_upper_right_longitude(Images &a, Images &b)
{
  return (a.GetUpper_right_longitude() < b.GetUpper_right_longitude());
}

bool SortImages::cmp_by_upper_right_x(Images &a, Images &b)
{
  return (a.GetUpper_right_x() < b.GetUpper_right_x());
}

bool SortImages::cmp_by_upper_right_y(Images &a, Images &b)
{
  return (a.GetUpper_right_y() < b.GetUpper_right_y());
}

bool SortImages::cmp_by_vertical_resolution(Images &a, Images &b)
{
  return (a.GetVertical_resolution() < b.GetVertical_resolution());
}

bool SortImages::cmp_by_width(Images &a, Images &b)
{
  return (a.GetWidth() < b.GetWidth());
}

bool SortImages::cmp_by_x_offset(Images &a, Images &b)
{
  return (a.GetX_offset() < b.GetX_offset());
}

bool SortImages::cmp_by_x_relative(Images &a, Images &b)
{
  return (a.GetX_relative() < b.GetX_relative());
}

bool SortImages::cmp_by_x_shift(Images &a, Images &b)
{
  return (a.GetX_shift() < b.GetX_shift());
}

bool SortImages::cmp_by_y_offset(Images &a, Images &b)
{
  return (a.GetY_offset() < b.GetY_offset());
}

bool SortImages::cmp_by_y_relative(Images &a, Images &b)
{
  return (a.GetY_relative() < b.GetY_relative());
}

bool SortImages::cmp_by_y_shift(Images &a, Images &b)
{
  return (a.GetY_shift() < b.GetY_shift());
}

int SortImages::GetFieldValue()
{
  /************************/
  /* Retrieve field value */
  /************************/
  if(field.compare("application_id") == 0)
  {
    return 1;
  }
  if(field.compare("created_at") == 0)
  {
    return 2;
  }
  if(field.compare("details") == 0)
  {
    return 3;
  }
  if(field.compare("done") == 0)
  {
    return 4;
  }
  if(field.compare("file_location") == 0)
  {
    return 5;
  }
  if(field.compare("height") == 0)
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
  if(field.compare("image_set_id") == 0)
  {
    return 9;
  }
  if(field.compare("lower_left_latitude") == 0)
  {
    return 10;
  }
  if(field.compare("lower_left_longitude") == 0)
  {
    return 11;
  }
  if(field.compare("lower_left_x") == 0)
  {
    return 12;
  }
  if(field.compare("lower_left_y") == 0)
  {
    return 13;
  }
  if(field.compare("lower_right_latitude") == 0)
  {
    return 14;
  }
  if(field.compare("lower_right_longitude") == 0)
  {
    return 15;
  }
  if(field.compare("lower_right_x") == 0)
  {
    return 16;
  }
  if(field.compare("lower_right_y") == 0)
  {
    return 17;
  }
  if(field.compare("name") == 0)
  {
    return 18;
  }
  if(field.compare("physical_height") == 0)
  {
    return 19;
  }
  if(field.compare("physical_width") == 0)
  {
    return 20;
  }
  if(field.compare("pixel_resolution") == 0)
  {
    return 21;
  }
  if(field.compare("premarked") == 0)
  {
    return 22;
  }
  if(field.compare("priority") == 0)
  {
    return 23;
  }
  if(field.compare("sun_angle") == 0)
  {
    return 24;
  }  
  if(field.compare("updated_at") == 0)
  {
    return 25;
  }
  if(field.compare("upper_left_corner_x_status") == 0)
  {
    return 26;
  }
  if(field.compare("upper_left_corner_y_status") == 0)
  {
    return 27;
  }
  if(field.compare("upper_left_latitude") == 0)
  {
    return 28;
  }
  if(field.compare("upper_left_longitude") == 0)
  {
    return 29;
  }
  if(field.compare("upper_left_x") == 0)
  {
    return 30;
  }
  if(field.compare("upper_left_y") == 0)
  {
    return 31;
  }
  if(field.compare("upper_right_latitude") == 0)
  {
    return 32;
  }
  if(field.compare("upper_right_longitude") == 0)
  {
    return 33;
  }
  if(field.compare("upper_right_x") == 0)
  {
    return 34;
  }
  if(field.compare("upper_right_y") == 0)
  {
    return 35;
  }
  if(field.compare("vertical_resolution") == 0)
  {
    return 36;
  }
  if(field.compare("width") == 0)
  {
    return 37;
  }
    if(field.compare("x_offset") == 0)
  {
    return 38;
  }
  if(field.compare("x_relative") == 0)
  {
    return 39;
  }
  if(field.compare("x_shift") == 0)
  {
    return 40;
  }
  if(field.compare("y_offset") == 0)
  {
    return 41;
  }
  if(field.compare("y_relative") == 0)
  {
    return 42;
  }
  if(field.compare("y_shift") == 0)
  {
    return 43;
  }
  
  return 0;
}

vector <Images> SortImages::GetImages()
{
  return images;
}

void SortImages::arrange()
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
      sort(images.begin(), images.end(), cmp_by_application_id);
      break;
    }
    case 2:
    {
      sort(images.begin(), images.end(), cmp_by_created_at);
      break;
    }
    case 3:
    {
      sort(images.begin(), images.end(), cmp_by_details);
      break;
    }
    case 4:
    {
      sort(images.begin(), images.end(), cmp_by_done);
      break;
    }
    case 5:
    {
      sort(images.begin(), images.end(), cmp_by_file_location);
      break;
    }
    case 6:
    {
      sort(images.begin(), images.end(), cmp_by_height);
      break;
    }
    case 7:
    {
      sort(images.begin(), images.end(), cmp_by_horizontal_resolution);
      break;
    }
    case 8:
    {
      sort(images.begin(), images.end(), cmp_by_id);
      break;
    }
    case 9:
    {
      sort(images.begin(), images.end(), cmp_by_image_set_id);
      break;
    }
    case 10:
    {
      sort(images.begin(), images.end(), cmp_by_lower_left_latitude);
      break;
    }
    case 11:
    {
      sort(images.begin(), images.end(), cmp_by_lower_left_longitude);
      break;
    }
    case 12:
    {
      sort(images.begin(), images.end(), cmp_by_lower_left_x);
      break;
    }
    case 13:
    {
      sort(images.begin(), images.end(), cmp_by_lower_left_y);
      break;
    }
    case 14:
    {
      sort(images.begin(), images.end(), cmp_by_lower_right_latitude);
      break;
    }
    case 15:
    {
      sort(images.begin(), images.end(), cmp_by_lower_right_longitude);
      break;
    }
    case 16:
    {
      sort(images.begin(), images.end(), cmp_by_lower_right_x);
      break;
    }
    case 17:
    {
      sort(images.begin(), images.end(), cmp_by_lower_right_y);
      break;
    }
    case 18:
    {
      sort(images.begin(), images.end(), cmp_by_name);
      break;
    }
    case 19:
    {
      sort(images.begin(), images.end(), cmp_by_physical_height);
      break;
    }
    case 20:
    {
      sort(images.begin(), images.end(), cmp_by_physical_width);
      break;
    }
    case 21:
    {
      sort(images.begin(), images.end(), cmp_by_pixel_resolution);
      break;
    }
    case 22:
    {
      sort(images.begin(), images.end(), cmp_by_premarked);
      break;
    }
    case 23:
    {
      sort(images.begin(), images.end(), cmp_by_priority);
      break;
    }
    case 24:
    {
      sort(images.begin(), images.end(), cmp_by_sun_angle);
      break;
    }
    case 25:
    {
      sort(images.begin(), images.end(), cmp_by_updated_at);
      break;
    }
    case 26:
    {
      sort(images.begin(), images.end(), cmp_by_upper_left_corner_x_status);
      break;
    }
    case 27:
    {
      sort(images.begin(), images.end(), cmp_by_upper_left_corner_y_status);
      break;
    }
    case 28:
    {
      sort(images.begin(), images.end(), cmp_by_upper_left_latitude);
      break;
    }
    case 29:
    {
      sort(images.begin(), images.end(), cmp_by_upper_left_longitude);
      break;
    }
    case 30:
    {
      sort(images.begin(), images.end(), cmp_by_upper_left_x);
      break;
    }
    case 31:
    {
      sort(images.begin(), images.end(), cmp_by_upper_left_y);
      break;
    }
    case 32:
    {
      sort(images.begin(), images.end(), cmp_by_upper_right_latitude);
      break;
    }
    case 33:
    {
      sort(images.begin(), images.end(), cmp_by_upper_right_longitude);
      break;
    }
    case 34:
    {
      sort(images.begin(), images.end(), cmp_by_upper_right_x);
      break;
    }
    case 35:
    {
      sort(images.begin(), images.end(), cmp_by_upper_right_y);
      break;
    }
    case 36:
    {
      sort(images.begin(), images.end(), cmp_by_vertical_resolution);
      break;
    }
    case 37:
    {
      sort(images.begin(), images.end(), cmp_by_width);
      break;
    }
    case 38:
    {
      sort(images.begin(), images.end(), cmp_by_x_offset);
      break;
    }
    case 39:
    {
      sort(images.begin(), images.end(), cmp_by_x_relative);
      break;
    }
    case 40:
    {
      sort(images.begin(), images.end(), cmp_by_x_shift);
      break;
    }
    case 41:
    {
      sort(images.begin(), images.end(), cmp_by_y_offset);
      break;
    }
    case 42:
    {
      sort(images.begin(), images.end(), cmp_by_y_relative);
      break;
    }
    case 43:
    {
      sort(images.begin(), images.end(), cmp_by_y_shift);
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
