#include "Marks.h"

using namespace std;

Marks::Marks(int ID, int UID, int IID, int AID, int IUID, int MMID, int SMID, double X, double Y, double DIA, int SUBTIME, int C, double S, string T, string SUBTYPE, string DET, string CREATE, string UPDATE)
{
  application_id = AID;
  confirmed = C;
  created_at = CREATE;
  details = DET;
  diameter = DIA;
  id = ID;
  image_id = IID;
  image_user_id = IUID;
  latitude = 0;
  longitude = 0;
  machine_mark_id = MMID;
  physical_diameter = 0;
  physical_x = 0;
  physical_y = 0;
  score = S;
  shared_mark_id = SMID;
  submit_time = SUBTIME;
  sub_type = SUBTYPE;
  type = T;
  updated_at = UPDATE;
  user_id = UID;
  x = X;
  x_adjusted = 0;
  y = Y;
  y_adjusted = 0;
}

double Marks::GetDiameter()
{
  return diameter;
}

double Marks::GetLatitude()
{
  return latitude;
}

double Marks::GetLongitude()
{
  return longitude;
}

double Marks::GetPhysical_diameter()
{
  return physical_diameter;
}

double Marks::GetPhysical_x()
{
  return physical_x;
}

double Marks::GetPhysical_y()
{
  return physical_y;
}

double Marks::GetScore()
{
  return score;
}

double Marks::GetX()
{
  return x;
}

double Marks::GetX_adjusted()
{
  return x_adjusted;
}

double Marks::GetY()
{
  return y;
}

double Marks::GetY_adjusted()
{
  return y_adjusted;
}

int Marks::GetApplication_id()
{
  return application_id;
}

int Marks::GetConfirmed()
{
  return confirmed;
}

int Marks::GetId()

{
  return id;
}

int Marks::GetImage_id()
{
  return image_id;
}

int Marks::GetImage_user_id()
{
  return image_user_id;
}

int Marks::GetMachine_mark_id()
{
  return machine_mark_id;
}

int Marks::GetShared_mark_id()
{
  return shared_mark_id;
}

int Marks::GetSubmit_time()
{
  return submit_time;
}

int Marks::GetUser_id()
{
  return user_id;
}

string Marks::GetCreated_at()
{
  return created_at;
}

string Marks::GetDetails()
{
  return details;
}

string Marks::GetSub_type()
{
  return sub_type;
}

string Marks::GetType()
{
  return type;
}

string Marks::GetUpdated_at()
{
  return updated_at;
}

void Marks::AuxilaryFunction(vector <double> &adjustedpixelcoordinate, vector <double> &selenographiccoordinate, vector <double> &cartesiancoordinate, double d)
{
  /******************************************************/
  /* Sets the adjusted (global image) pixel coordinates */
  /******************************************************/
  x_adjusted = adjustedpixelcoordinate[0];
  y_adjusted = adjustedpixelcoordinate[1];
  
  /*******************************************/
  /* Sets the latitude and longitude of mark */
  /*******************************************/
  longitude = selenographiccoordinate[0];
  latitude = selenographiccoordinate[1];

  /******************************************************************/
  /* Sets the cartesian x and y position of mark in units of meters */
  /******************************************************************/
  physical_x = cartesiancoordinate[0];
  physical_y = cartesiancoordinate[1];
  
  /**********************************/
  /* Sets physical diameter of mark */
  /**********************************/
  physical_diameter = d;
}  

void * Marks::GetValue(string field)
{
  if(field.compare("id") == 0)
  {
    return &id;
  }
  if(field.compare("user_id") == 0)
  {
    return &user_id;
  }
  if(field.compare("image_id") == 0)
  {
    return &image_id;
  }
  if(field.compare("application_id") == 0)
  {
    return &application_id;
  }
  if(field.compare("image_user_id") == 0)
  {
    return &image_user_id;
  }
  if(field.compare("machine_mark_id") == 0)
  {
    return &machine_mark_id;
  }
  if(field.compare("shared_mark_id") == 0)
  {
    return &shared_mark_id;
  }
  if(field.compare("x") == 0)
  {
    return &x;
  }
  if(field.compare("y") == 0)
  {
    return &y;
  }
  if(field.compare("diameter") == 0)
  {
    return &diameter;
  }
  if(field.compare("submit_time") == 0)
  {
    return &submit_time;
  }
  if(field.compare("confirmed") == 0)
  {
    return &confirmed;
  }
  if(field.compare("score") == 0)
  {
    return &score;
  }
  if(field.compare("type") == 0)
  {
    return &type;
  }
  if(field.compare("sub_type") == 0)
  {
    return &sub_type;
  }
  if(field.compare("details") == 0)
  {
    return &details;
  }
  if(field.compare("created_at") == 0)
  {
    return &created_at;
  }
  if(field.compare("updated_at") == 0)
  {
    return &updated_at;
  }

  return NULL;
}

void Marks::SetX(double value)
{
  x = value;
}

void Marks::SetY(double value)
{
  y = value;
}
