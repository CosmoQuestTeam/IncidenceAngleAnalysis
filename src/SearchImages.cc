#include "SearchImages.h"

using namespace std;

bool SearchImages::EqualityComparison(vector <Images> &images, int index, string field, void *value)
{
  /********************************/
  /* Retrieve field column number */
  /********************************/
  if(field.compare("application_id") == 0)
  {
    return (images[index].GetApplication_id() == *static_cast<int *>(value));
  }
  if(field.compare("created_at") == 0)
  {
    return (images[index].GetCreated_at().compare(*static_cast<string *>(value)) == 0);
  }
  if(field.compare("details") == 0)
  {
    return (images[index].GetDetails().compare(*static_cast<string *>(value)) == 0);
  }
  if(field.compare("done") == 0)
  {
    return (images[index].GetDone() == *static_cast<int *>(value));
  }
  if(field.compare("file_location") == 0)
  {
    return (images[index].GetFile_location().compare(*static_cast<string *>(value)) == 0);
  }
  if(field.compare("height") == 0)
  {
    return (images[index].GetHeight() == *static_cast<int *>(value));
  }
  if(field.compare("id") == 0)
  {
    return (images[index].GetId() == *static_cast<int *>(value));
  }
  if(field.compare("image_set_id") == 0)
  {
    return (images[index].GetImage_set_id() == *static_cast<int *>(value));
  }
  if(field.compare("lower_left_latitude") == 0)
  {
    return (images[index].GetLower_left_latitude() == *static_cast<double *>(value));
  }
  if(field.compare("lower_left_longitude") == 0)
  {
    return (images[index].GetLower_left_longitude() == *static_cast<double *>(value));
  }
  if(field.compare("lower_left_x") == 0)
  {
    return (images[index].GetLower_left_x() == *static_cast<double *>(value));
  }
  if(field.compare("lower_left_y") == 0)
  {
    return (images[index].GetLower_left_y() == *static_cast<double *>(value));
  }
  if(field.compare("lower_right_latitude") == 0)
  {
    return (images[index].GetLower_right_latitude() == *static_cast<double *>(value));
  }
  if(field.compare("lower_right_longitude") == 0)
  {
    return (images[index].GetLower_right_longitude() == *static_cast<double *>(value));
  }
  if(field.compare("lower_right_x") == 0)
  {
    return (images[index].GetLower_right_x() == *static_cast<double *>(value));
  }
  if(field.compare("lower_right_y") == 0)
  {
    return (images[index].GetLower_right_y() == *static_cast<double *>(value));
  }
  if(field.compare("maximum_latitude") == 0)
  {
    return (images[index].GetMaximum_latitude() == *static_cast<double *>(value));
  }
  if(field.compare("maximum_longitude") == 0)
  {
    return (images[index].GetMaximum_longitude() == *static_cast<double *>(value));
  }
  if(field.compare("maximum_x") == 0)
  {
    return (images[index].GetMaximum_x() == *static_cast<double *>(value));
  }
  if(field.compare("maximum_y") == 0)
  {
    return (images[index].GetMaximum_y() == *static_cast<double *>(value));
  }
  if(field.compare("minimum_latitude") == 0)
  {
    return (images[index].GetMinimum_latitude() == *static_cast<double *>(value));
  }
  if(field.compare("minimum_longitude") == 0)
  {
    return (images[index].GetMinimum_longitude() == *static_cast<double *>(value));
  }
  if(field.compare("minimum_x") == 0)
  {
    return (images[index].GetMinimum_x() == *static_cast<double *>(value));
  }
  if(field.compare("minimum_y") == 0)
  {
    return (images[index].GetMinimum_y() == *static_cast<double *>(value));
  }
  if(field.compare("name") == 0)
  {
    return (images[index].GetName().compare(*static_cast<string *>(value)) == 0);
  }
  if(field.compare("premarked") == 0)
  {
    return (images[index].GetPremarked() == *static_cast<int *>(value));
  }
  if(field.compare("priority") == 0)
  {
    return (images[index].GetPriority() == *static_cast<double *>(value));
  }  
  if(field.compare("sun_angle") == 0)
  {
    return (images[index].GetSun_angle() == *static_cast<double *>(value));
  }
  if(field.compare("updated_at") == 0)
  {
    return (images[index].GetUpdated_at().compare(*static_cast<string *>(value)) == 0);
  }
  if(field.compare("upper_left_corner_x_status") == 0)
  {
    return (images[index].GetUpper_left_corner_x_status().compare(*static_cast<string *>(value)) == 0);
  }
  if(field.compare("upper_left_corner_y_status") == 0)
  {
    return (images[index].GetUpper_left_corner_y_status().compare(*static_cast<string *>(value)) == 0);
  }
  if(field.compare("upper_left_latitude") == 0)
  {
    return (images[index].GetUpper_left_latitude() == *static_cast<double *>(value));
  }
  if(field.compare("upper_left_longitude") == 0)
  {
    return (images[index].GetUpper_left_longitude() == *static_cast<double *>(value));
  }
  if(field.compare("upper_left_x") == 0)
  {
    return (images[index].GetUpper_left_x() == *static_cast<double *>(value));
  }
  if(field.compare("upper_left_y") == 0)
  {
    return (images[index].GetUpper_left_y() == *static_cast<double *>(value));
  }
  if(field.compare("upper_right_latitude") == 0)
  {
    return (images[index].GetUpper_right_latitude() == *static_cast<double *>(value));
  }
  if(field.compare("upper_right_longitude") == 0)
  {
    return (images[index].GetUpper_right_longitude() == *static_cast<double *>(value));
  }
  if(field.compare("upper_right_x") == 0)
  {
    return (images[index].GetUpper_right_x() == *static_cast<double *>(value));
  }
  if(field.compare("upper_right_y") == 0)
  {
    return (images[index].GetUpper_right_y() == *static_cast<double *>(value));
  }
  if(field.compare("width") == 0)
  {
    return (images[index].GetWidth() == *static_cast<int *>(value));
  }
  if(field.compare("x_relative") == 0)
  {
    return (images[index].GetX_relative() == *static_cast<double *>(value));
  }
  if(field.compare("y_relative") == 0)
  {
    return (images[index].GetY_relative() == *static_cast<double *>(value));
  }

  return false;
}

bool SearchImages::GreaterThanComparison(vector <Images> &images, int index, string field, void *value)
{
  /********************************/
  /* Retrieve field column number */
  /********************************/
  if(field.compare("application_id") == 0)
  {
    return (images[index].GetApplication_id() > *static_cast<int *>(value));
  }
  if(field.compare("created_at") == 0)
  {
    return (images[index].GetCreated_at() > *static_cast<string *>(value));
  }
  if(field.compare("details") == 0)
  {
    return (images[index].GetDetails() > *static_cast<string *>(value));
  }
  if(field.compare("done") == 0)
  {
    return (images[index].GetDone() > *static_cast<int *>(value));
  }
  if(field.compare("file_location") == 0)
  {
    return (images[index].GetFile_location() > *static_cast<string *>(value));
  }
  if(field.compare("height") == 0)
  {
    return (images[index].GetHeight() > *static_cast<int *>(value));
  }
  if(field.compare("id") == 0)
  {
    return (images[index].GetId() > *static_cast<int *>(value));
  }
  if(field.compare("image_set_id") == 0)
  {
    return (images[index].GetImage_set_id() > *static_cast<int *>(value));
  }
  if(field.compare("lower_left_latitude") == 0)
  {
    return (images[index].GetLower_left_latitude() > *static_cast<double *>(value));
  }
  if(field.compare("lower_left_longitude") == 0)
  {
    return (images[index].GetLower_left_longitude() > *static_cast<double *>(value));
  }
  if(field.compare("lower_left_x") == 0)
  {
    return (images[index].GetLower_left_x() > *static_cast<double *>(value));
  }
  if(field.compare("lower_left_y") == 0)
  {
    return (images[index].GetLower_left_y() > *static_cast<double *>(value));
  }
  if(field.compare("lower_right_latitude") == 0)
  {
    return (images[index].GetLower_right_latitude() > *static_cast<double *>(value));
  }
  if(field.compare("lower_right_longitude") == 0)
  {
    return (images[index].GetLower_right_longitude() > *static_cast<double *>(value));
  }
  if(field.compare("lower_right_x") == 0)
  {
    return (images[index].GetLower_right_x() > *static_cast<double *>(value));
  }
  if(field.compare("lower_right_y") == 0)
  {
    return (images[index].GetLower_right_y() > *static_cast<double *>(value));
  }
  if(field.compare("maximum_latitude") == 0)
  {
    return (images[index].GetMaximum_latitude() > *static_cast<double *>(value));
  }
  if(field.compare("maximum_longitude") == 0)
  {
    return (images[index].GetMaximum_longitude() > *static_cast<double *>(value));
  }
  if(field.compare("maximum_x") == 0)
  {
    return (images[index].GetMaximum_x() > *static_cast<double *>(value));
  }
  if(field.compare("maximum_y") == 0)
  {
    return (images[index].GetMaximum_y() > *static_cast<double *>(value));
  }
  if(field.compare("minimum_latitude") == 0)
  {
    return (images[index].GetMinimum_latitude() > *static_cast<double *>(value));
  }
  if(field.compare("minimum_longitude") == 0)
  {
    return (images[index].GetMinimum_longitude() > *static_cast<double *>(value));
  }
  if(field.compare("minimum_x") == 0)
  {
    return (images[index].GetMinimum_x() > *static_cast<double *>(value));
  }
  if(field.compare("minimum_y") == 0)
  {
    return (images[index].GetMinimum_y() > *static_cast<double *>(value));
  }
  if(field.compare("name") == 0)
  {
    return (images[index].GetName() > *static_cast<string *>(value));
  }
  if(field.compare("premarked") == 0)
  {
    return (images[index].GetPremarked() > *static_cast<int *>(value));
  }
  if(field.compare("priority") == 0)
  {
    return (images[index].GetPriority() > *static_cast<double *>(value));
  }  
  if(field.compare("sun_angle") == 0)
  {
    return (images[index].GetSun_angle() > *static_cast<double *>(value));
  }
  if(field.compare("updated_at") == 0)
  {
    return (images[index].GetUpdated_at() > *static_cast<string *>(value));
  }
  if(field.compare("upper_left_corner_x_status") == 0)
  {
    return (images[index].GetUpper_left_corner_x_status() > *static_cast<string *>(value));
  }
  if(field.compare("upper_left_corner_y_status") == 0)
  {
    return (images[index].GetUpper_left_corner_y_status() > *static_cast<string *>(value));
  }
  if(field.compare("upper_left_latitude") == 0)
  {
    return (images[index].GetUpper_left_latitude() > *static_cast<double *>(value));
  }
  if(field.compare("upper_left_longitude") == 0)
  {
    return (images[index].GetUpper_left_longitude() > *static_cast<double *>(value));
  }
  if(field.compare("upper_left_x") == 0)
  {
    return (images[index].GetUpper_left_x() > *static_cast<double *>(value));
  }
  if(field.compare("upper_left_y") == 0)
  {
    return (images[index].GetUpper_left_y() > *static_cast<double *>(value));
  }
  if(field.compare("upper_right_latitude") == 0)
  {
    return (images[index].GetUpper_right_latitude() > *static_cast<double *>(value));
  }
  if(field.compare("upper_right_longitude") == 0)
  {
    return (images[index].GetUpper_right_longitude() > *static_cast<double *>(value));
  }
  if(field.compare("upper_right_x") == 0)
  {
    return (images[index].GetUpper_right_x() > *static_cast<double *>(value));
  }
  if(field.compare("upper_right_y") == 0)
  {
    return (images[index].GetUpper_right_y() > *static_cast<double *>(value));
  }
  if(field.compare("width") == 0)
  {
    return (images[index].GetWidth() > *static_cast<int *>(value));
  }
  if(field.compare("x_relative") == 0)
  {
    return (images[index].GetX_relative() > *static_cast<double *>(value));
  }
  if(field.compare("y_relative") == 0)
  {
    return (images[index].GetY_relative() > *static_cast<double *>(value));
  }

  return false;
}

bool SearchImages::LessThanComparison(vector <Images> &images, int index, string field, void *value)
{
  /********************************/
  /* Retrieve field column number */
  /********************************/
  if(field.compare("application_id") == 0)
  {
    return (images[index].GetApplication_id() < *static_cast<int *>(value));
  }
  if(field.compare("created_at") == 0)
  {
    return (images[index].GetCreated_at() < *static_cast<string *>(value));
  }
  if(field.compare("details") == 0)
  {
    return (images[index].GetDetails() < *static_cast<string *>(value));
  }
  if(field.compare("done") == 0)
  {
    return (images[index].GetDone() < *static_cast<int *>(value));
  }
  if(field.compare("file_location") == 0)
  {
    return (images[index].GetFile_location() < *static_cast<string *>(value));
  }
  if(field.compare("height") == 0)
  {
    return (images[index].GetHeight() < *static_cast<int *>(value));
  }
  if(field.compare("id") == 0)
  {
    return (images[index].GetId() < *static_cast<int *>(value));
  }
  if(field.compare("image_set_id") == 0)
  {
    return (images[index].GetImage_set_id() < *static_cast<int *>(value));
  }
  if(field.compare("lower_left_latitude") == 0)
  {
    return (images[index].GetLower_left_latitude() < *static_cast<double *>(value));
  }
  if(field.compare("lower_left_longitude") == 0)
  {
    return (images[index].GetLower_left_longitude() < *static_cast<double *>(value));
  }
  if(field.compare("lower_left_x") == 0)
  {
    return (images[index].GetLower_left_x() < *static_cast<double *>(value));
  }
  if(field.compare("lower_left_y") == 0)
  {
    return (images[index].GetLower_left_y() < *static_cast<double *>(value));
  }
  if(field.compare("lower_right_latitude") == 0)
  {
    return (images[index].GetLower_right_latitude() < *static_cast<double *>(value));
  }
  if(field.compare("lower_right_longitude") == 0)
  {
    return (images[index].GetLower_right_longitude() < *static_cast<double *>(value));
  }
  if(field.compare("lower_right_x") == 0)
  {
    return (images[index].GetLower_right_x() < *static_cast<double *>(value));
  }
  if(field.compare("lower_right_y") == 0)
  {
    return (images[index].GetLower_right_y() < *static_cast<double *>(value));
  }
  if(field.compare("maximum_latitude") == 0)
  {
    return (images[index].GetMaximum_latitude() < *static_cast<double *>(value));
  }
  if(field.compare("maximum_longitude") == 0)
  {
    return (images[index].GetMaximum_longitude() < *static_cast<double *>(value));
  }
  if(field.compare("maximum_x") == 0)
  {
    return (images[index].GetMaximum_x() < *static_cast<double *>(value));
  }
  if(field.compare("maximum_y") == 0)
  {
    return (images[index].GetMaximum_y() < *static_cast<double *>(value));
  }
  if(field.compare("minimum_latitude") == 0)
  {
    return (images[index].GetMinimum_latitude() < *static_cast<double *>(value));
  }
  if(field.compare("minimum_longitude") == 0)
  {
    return (images[index].GetMinimum_longitude() < *static_cast<double *>(value));
  }
  if(field.compare("minimum_x") == 0)
  {
    return (images[index].GetMinimum_x() < *static_cast<double *>(value));
  }
  if(field.compare("minimum_y") == 0)
  {
    return (images[index].GetMinimum_y() < *static_cast<double *>(value));
  }
  if(field.compare("name") == 0)
  {
    return (images[index].GetName() < *static_cast<string *>(value));
  }
  if(field.compare("premarked") == 0)
  {
    return (images[index].GetPremarked() < *static_cast<int *>(value));
  }
  if(field.compare("priority") == 0)
  {
    return (images[index].GetPriority() < *static_cast<double *>(value));
  }  
  if(field.compare("sun_angle") == 0)
  {
    return (images[index].GetSun_angle() < *static_cast<double *>(value));
  }
  if(field.compare("updated_at") == 0)
  {
    return (images[index].GetUpdated_at() < *static_cast<string *>(value));
  }
  if(field.compare("upper_left_corner_x_status") == 0)
  {
    return (images[index].GetUpper_left_corner_x_status() < *static_cast<string *>(value));
  }
  if(field.compare("upper_left_corner_y_status") == 0)
  {
    return (images[index].GetUpper_left_corner_y_status() < *static_cast<string *>(value));
  }
  if(field.compare("upper_left_latitude") == 0)
  {
    return (images[index].GetUpper_left_latitude() < *static_cast<double *>(value));
  }
  if(field.compare("upper_left_longitude") == 0)
  {
    return (images[index].GetUpper_left_longitude() < *static_cast<double *>(value));
  }
  if(field.compare("upper_left_x") == 0)
  {
    return (images[index].GetUpper_left_x() < *static_cast<double *>(value));
  }
  if(field.compare("upper_left_y") == 0)
  {
    return (images[index].GetUpper_left_y() < *static_cast<double *>(value));
  }
  if(field.compare("upper_right_latitude") == 0)
  {
    return (images[index].GetUpper_right_latitude() < *static_cast<double *>(value));
  }
  if(field.compare("upper_right_longitude") == 0)
  {
    return (images[index].GetUpper_right_longitude() < *static_cast<double *>(value));
  }
  if(field.compare("upper_right_x") == 0)
  {
    return (images[index].GetUpper_right_x() < *static_cast<double *>(value));
  }
  if(field.compare("upper_right_y") == 0)
  {
    return (images[index].GetUpper_right_y() < *static_cast<double *>(value));
  }
  if(field.compare("width") == 0)
  {
    return (images[index].GetWidth() < *static_cast<int *>(value));
  }
  if(field.compare("x_relative") == 0)
  {
    return (images[index].GetX_relative() < *static_cast<double *>(value));
  }
  if(field.compare("y_relative") == 0)
  {
    return (images[index].GetY_relative() < *static_cast<double *>(value));
  }

  return false;
}

double SearchImages::Difference(vector <Images> &images, int index, string field, void *value)
{
  /********************************/
  /* Retrieve field column number */
  /********************************/
  if(field.compare("application_id") == 0)
  {
    return static_cast<double>(images[index].GetApplication_id() - *static_cast<int *>(value));
  }
  if(field.compare("created_at") == 0)
  {
    return static_cast<double>(images[index].GetCreated_at().compare(*static_cast<string *>(value)));
  }
  if(field.compare("details") == 0)
  {
    return static_cast<double>(images[index].GetDetails().compare(*static_cast<string *>(value)));
  }
  if(field.compare("done") == 0)
  {
    return static_cast<double>(images[index].GetDone() - *static_cast<int *>(value));
  }
  if(field.compare("file_location") == 0)
  {
    return static_cast<double>(images[index].GetFile_location().compare(*static_cast<string *>(value)));
  }
  if(field.compare("height") == 0)
  {
    return static_cast<double>(images[index].GetHeight() - *static_cast<int *>(value));
  }
  if(field.compare("id") == 0)
  {
    return static_cast<double>(images[index].GetId() - *static_cast<int *>(value));
  }
  if(field.compare("image_set_id") == 0)
  {
    return static_cast<double>(images[index].GetImage_set_id() - *static_cast<int *>(value));
  }
  if(field.compare("lower_left_latitude") == 0)
  {
    return static_cast<double>(images[index].GetLower_left_latitude() - *static_cast<double *>(value));
  }
  if(field.compare("lower_left_longitude") == 0)
  {
    return static_cast<double>(images[index].GetLower_left_longitude() - *static_cast<double *>(value));
  }
  if(field.compare("lower_left_x") == 0)
  {
    return static_cast<double>(images[index].GetLower_left_x() - *static_cast<double *>(value));
  }
  if(field.compare("lower_left_y") == 0)
  {
    return static_cast<double>(images[index].GetLower_left_y() - *static_cast<double *>(value));
  }
  if(field.compare("lower_right_latitude") == 0)
  {
    return static_cast<double>(images[index].GetLower_right_latitude() - *static_cast<double *>(value));
  }
  if(field.compare("lower_right_longitude") == 0)
  {
    return static_cast<double>(images[index].GetLower_right_longitude() - *static_cast<double *>(value));
  }
  if(field.compare("lower_right_x") == 0)
  {
    return static_cast<double>(images[index].GetLower_right_x() - *static_cast<double *>(value));
  }
  if(field.compare("lower_right_y") == 0)
  {
    return static_cast<double>(images[index].GetLower_right_y() - *static_cast<double *>(value));
  }
  if(field.compare("maximum_latitude") == 0)
  {
    return static_cast<double>(images[index].GetMaximum_latitude() - *static_cast<double *>(value));
  }
  if(field.compare("maximum_longitude") == 0)
  {
    return static_cast<double>(images[index].GetMaximum_longitude() - *static_cast<double *>(value));
  }
  if(field.compare("maximum_x") == 0)
  {
    return static_cast<double>(images[index].GetMaximum_x() - *static_cast<double *>(value));
  }
  if(field.compare("maximum_y") == 0)
  {
    return static_cast<double>(images[index].GetMaximum_y() - *static_cast<double *>(value));
  }
  if(field.compare("minimum_latitude") == 0)
  {
    return static_cast<double>(images[index].GetMinimum_latitude() - *static_cast<double *>(value));
  }
  if(field.compare("minimum_longitude") == 0)
  {
    return static_cast<double>(images[index].GetMinimum_longitude() - *static_cast<double *>(value));
  }
  if(field.compare("minimum_x") == 0)
  {
    return static_cast<double>(images[index].GetMinimum_x() - *static_cast<double *>(value));
  }
  if(field.compare("minimum_y") == 0)
  {
    return static_cast<double>(images[index].GetMinimum_y() - *static_cast<double *>(value));
  }
  if(field.compare("name") == 0)
  {
    return static_cast<double>(images[index].GetName().compare(*static_cast<string *>(value)));
  }
  if(field.compare("premarked") == 0)
  {
    return static_cast<double>(images[index].GetPremarked() - *static_cast<int *>(value));
  }
  if(field.compare("priority") == 0)
  {
    return static_cast<double>(images[index].GetPriority() - *static_cast<double *>(value));
  }  
  if(field.compare("sun_angle") == 0)
  {
    return static_cast<double>(images[index].GetSun_angle() - *static_cast<double *>(value));
  }
  if(field.compare("updated_at") == 0)
  {
    return static_cast<double>(images[index].GetUpdated_at().compare(*static_cast<string *>(value)));
  }
  if(field.compare("upper_left_corner_x_status") == 0)
  {
    return static_cast<double>(images[index].GetUpper_left_corner_x_status().compare(*static_cast<string *>(value)));
  }
  if(field.compare("upper_left_corner_y_status") == 0)
  {
    return static_cast<double>(images[index].GetUpper_left_corner_y_status().compare(*static_cast<string *>(value)));
  }
  if(field.compare("upper_left_latitude") == 0)
  {
    return static_cast<double>(images[index].GetUpper_left_latitude() - *static_cast<double *>(value));
  }
  if(field.compare("upper_left_longitude") == 0)
  {
    return static_cast<double>(images[index].GetUpper_left_longitude() - *static_cast<double *>(value));
  }
  if(field.compare("upper_left_x") == 0)
  {
    return static_cast<double>(images[index].GetUpper_left_x() - *static_cast<double *>(value));
  }
  if(field.compare("upper_left_y") == 0)
  {
    return static_cast<double>(images[index].GetUpper_left_y() - *static_cast<double *>(value));
  }
  if(field.compare("upper_right_latitude") == 0)
  {
    return static_cast<double>(images[index].GetUpper_right_latitude() - *static_cast<double *>(value));
  }
  if(field.compare("upper_right_longitude") == 0)
  {
    return static_cast<double>(images[index].GetUpper_right_longitude() - *static_cast<double *>(value));
  }
  if(field.compare("upper_right_x") == 0)
  {
    return static_cast<double>(images[index].GetUpper_right_x() - *static_cast<double *>(value));
  }
  if(field.compare("upper_right_y") == 0)
  {
    return static_cast<double>(images[index].GetUpper_right_y() - *static_cast<double *>(value));
  }
  if(field.compare("width") == 0)
  {
    return static_cast<double>(images[index].GetWidth() - *static_cast<int *>(value));
  }
  if(field.compare("x_relative") == 0)
  {
    return static_cast<double>(images[index].GetX_relative() - *static_cast<double *>(value));
  }
  if(field.compare("y_relative") == 0)
  {
    return static_cast<double>(images[index].GetY_relative() - *static_cast<double *>(value));
  }

  return false;
}

int SearchImages::BinarySearch(vector <Images> &images, int m, int n, string field, void *value)
{
  if(n >= m)
  {
    /***********************************/
    /* Calculate value of middle index */
    /***********************************/
    int midpoint = m+(n-m)/2;
    
    /****************************************************/
    /* Compare wanted value to value of middle element. */
    /* If equal, return index of middle element.        */
    /****************************************************/
    if(EqualityComparison(images, midpoint, field, value))
    {
      return midpoint;
    }

    /**************************************************/
    /* If value of the middle element is smaller than */
    /* the wanted value, then the wanted value must   */
    /* reside in the right portion of the array.      */
    /**************************************************/
    if(LessThanComparison(images, midpoint, field, value))
    {
      return BinarySearch(images, midpoint+1, n, field, value);
    }

    /*************************************************/
    /* If value of the middle element is larger than */
    /* the wanted value, then the wanted value must  */
    /* reside in the left portion of the array.      */
    /*************************************************/
    if(GreaterThanComparison(images, midpoint, field, value))
    {
      return BinarySearch(images, m, midpoint-1, field, value);
    }
  }

  /***********************************************************/
  /* If value is not present in array, return negative index */
  /***********************************************************/
  return -1;
}

int SearchImages::FirstNearestValue(vector <Images> &images, int m, int n, string field, void *value)
{
  /*************************************************/
  /* Declaration/Initialization of class variables */
  /*************************************************/
  double diff1;
  double diff2;
  
  if((n-m) > 1)
  {
    /******************************************************************/
    /* Calculate index at boundary between first and second quantile. */
    /* Calculate index at boundary between second and third quantile. */
    /******************************************************************/
    int boundary1 = m+(n-m)/3;
    int boundary2 = m+2*(n-m)/3;
    
    /************************************************************************/
    /* Calculate difference between value to value at the index of boundary */
    /* one and repeat for the value at the index of boundary two            */
    /************************************************************************/  
    diff1 = Difference(images, boundary1, field, value);
    diff2 = Difference(images, boundary2, field, value);
    
    /*************************************************/
    /* If either differences equal zero, simply find */
    /* the first occurence of value in data set      */
    /*************************************************/
    if((diff1 == 0) || (diff2 == 0))
    {
      return FirstOccurence(images, m, n, field, value);
    }
  
    /**************************************/
    /* If the first difference is greater */
    /* than zero, examine first quantile  */
    /**************************************/
    if(diff1 > 0)
    {
      return FirstNearestValue(images, 0, boundary1-1, field, value);
    }

    /*************************************/
    /* If the second difference is less  */
    /* than zero, examine third quantile */
    /**************************************/
    if(diff2 < 0)
    {
      return FirstNearestValue(images, boundary2+1, n, field, value);
    }

    /*********************************************/
    /* If zero lies between the two differences, */
    /* then examine second quantile              */
    /*********************************************/
    if((diff1 < 0) && (diff2 > 0))
    {
      return FirstNearestValue(images, boundary1+1, boundary2-1, field, value);
    }
  }

  /************************************************************/
  /* Calculate difference between value to value at the index */
  /* of m one and repeat for the value at the index of n      */
  /************************************************************/
  diff1 = Difference(images, m, field, value);
  diff2 = Difference(images, n, field, value);
    
  return (diff1 < diff2) ? FirstOccurence(images, m, n, field, images[m].GetValue(field)) : FirstOccurence(images, m, n, field, images[n].GetValue(field));
}

int SearchImages::FirstOccurence(vector <Images> &images, int m, int n, string field, void *value)
{
  if((n-m) > 1)
  {
    /***********************************************************/
    /* Find midpoint between upper and lower bounding indicies */
    /***********************************************************/
    int midpoint = m+(n-m)/2;

    /*********************************************************/
    /* Compare value of midpoint element to reference value. */
    /* If less than reference value, move lowerbounding      */
    /* index to midpoint position. If equal to searched      */
    /* value, move upperbounding index to midpoint position  */
    /*********************************************************/
    if(LessThanComparison(images, midpoint, field, value))
    {
      return FirstOccurence(images, midpoint, n, field, value);
    }
    else
    {
      return FirstOccurence(images, m, midpoint, field, value);
    }
  }

  /*********************************************************/
  /* Check to see if quantities at indicies m or n matches */
  /* reference value when indicies are one unit apart      */
  /*********************************************************/
  if(EqualityComparison(images, m, field, value))
  {
    return m;
  }
  if(EqualityComparison(images, n, field, value))
  {
    return n;
  }

  return -1;
}

int SearchImages::LastNearestValue(vector <Images> &images, int m, int n, string field, void *value)
{
  /*************************************************/
  /* Declaration/Initialization of class variables */
  /*************************************************/
  double diff1;
  double diff2;
  
  if((n-m) > 1)
  {
    /******************************************************************/
    /* Calculate index at boundary between first and second quantile. */
    /* Calculate index at boundary between second and third quantile. */
    /******************************************************************/
    int boundary1 = m+(n-m)/3;
    int boundary2 = m+2*(n-m)/3;
    
    /************************************************************************/
    /* Calculate difference between value to value at the index of boundary */
    /* one and repeat for the value at the index of boundary two            */
    /************************************************************************/  
    diff1 = Difference(images, boundary1, field, value);
    diff2 = Difference(images, boundary2, field, value);
    
    /*************************************************/
    /* If either differences equal zero, simply find */
    /* the first occurence of value in data set      */
    /*************************************************/
    if((diff1 == 0) || (diff2 == 0))
    {
      return LastOccurence(images, m, n, field, value);
    }
  
    /**************************************/
    /* If the first difference is greater */
    /* than zero, examine first quantile  */
    /**************************************/
    if(diff1 > 0)
    {
      return LastNearestValue(images, 0, boundary1-1, field, value);
    }

    /*************************************/
    /* If the second difference is less  */
    /* than zero, examine third quantile */
    /**************************************/
    if(diff2 < 0)
    {
      return LastNearestValue(images, boundary2+1, n, field, value);
    }

    /*********************************************/
    /* If zero lies between the two differences, */
    /* then examine second quantile              */
    /*********************************************/
    if((diff1 < 0) && (diff2 > 0))
    {
      return LastNearestValue(images, boundary1+1, boundary2-1, field, value);
    }
  }

  /************************************************************/
  /* Calculate difference between value to value at the index */
  /* of m one and repeat for the value at the index of n      */
  /************************************************************/
  diff1 = Difference(images, m, field, value);
  diff2 = Difference(images, n, field, value);
    
  return (diff1 < diff2) ? LastOccurence(images, m, n, field, images[m].GetValue(field)) : LastOccurence(images, m, n, field, images[n].GetValue(field));
}


int SearchImages::LastOccurence(vector <Images> &images, int m, int n, string field, void *value)
{
  if((n-m) > 1)
  {
    /***********************************************************/
    /* Find midpoint between upper and lower bounding indicies */
    /***********************************************************/
    int midpoint = m+(n-m)/2;
    
    /********************************************************/
    /* Compare value of midpoint element to searched value. */
    /* If less than searched value, move lowerbounding      */
    /* index to midpoint position. If equal to searched     */
    /* value, move upperbounding index to midpoint position */
    /********************************************************/
    if(GreaterThanComparison(images, midpoint, field, value))
    {
      return LastOccurence(images, m, midpoint, field, value);
    }
    else
    {
      return LastOccurence(images, midpoint, n, field, value);
    }
  }

  /*********************************************************/
  /* Check to see if quantities at indicies m or n matches */
  /* reference value when indicies are one unit apart      */
  /*********************************************************/
  if(EqualityComparison(images, n, field, value))
  {
    return n;
  }
  if(EqualityComparison(images, m, field, value))
  {
    return m;
  }

  return -1;  
}
