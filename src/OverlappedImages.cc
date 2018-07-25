#include "OverlappedImages.h"

using namespace std;

OverlappedImages::OverlappedImages()
{
}

OverlappedImages::OverlappedImages(int ID, int IMAGE1ID, string IMAGE1NAME, double IMAGE1ULLONG, double IMAGE1ULLAT, double IMAGE1URLONG, double IMAGE1URLAT, double IMAGE1LRLONG, double IMAGE1LRLAT, double IMAGE1LLLONG, double IMAGE1LLLAT, double IMAGE1AREA, double IMAGE1INCIDENCEANGLE, int IMAGE2ID, string IMAGE2NAME, double IMAGE2ULLONG, double IMAGE2ULLAT, double IMAGE2URLONG, double IMAGE2URLAT, double IMAGE2LRLONG, double IMAGE2LRLAT, double IMAGE2LLLONG, double IMAGE2LLLAT, double IMAGE2AREA, double IMAGE2INCIDENCEANGLE, double OVERLAPULLONG, double OVERLAPULLAT, double OVERLAPURLONG, double OVERLAPURLAT, double OVERLAPLRLONG, double OVERLAPLRLAT, double OVERLAPLLLONG, double OVERLAPLLLAT, double OVERLAPAREA)
{
  /***********************/
  /* Retrieve parameters */
  /***********************/
  id = ID;
  image1_area = IMAGE1AREA;
  image1_id = IMAGE1ID;
  image1_incidence_angle = IMAGE1INCIDENCEANGLE;
  image1_lower_left_latitude = IMAGE1LLLAT;
  image1_lower_left_longitude = IMAGE1LLLONG;
  image1_lower_right_latitude = IMAGE1LRLAT;
  image1_lower_right_longitude = IMAGE1LRLONG;
  image1_name = IMAGE1NAME;
  image1_upper_left_latitude = IMAGE1ULLAT;
  image1_upper_left_longitude = IMAGE1ULLONG;
  image1_upper_right_latitude = IMAGE1URLAT;
  image1_upper_right_longitude = IMAGE1URLONG;
  image2_area = IMAGE2AREA;
  image2_id = IMAGE2ID;
  image2_incidence_angle = IMAGE2INCIDENCEANGLE;
  image2_lower_left_latitude = IMAGE2LLLAT;
  image2_lower_left_longitude = IMAGE2LLLONG;
  image2_lower_right_latitude = IMAGE2LRLAT;
  image2_lower_right_longitude = IMAGE2LRLONG;
  image2_name = IMAGE2NAME;
  image2_upper_left_latitude = IMAGE2ULLAT;
  image2_upper_left_longitude = IMAGE2ULLONG;
  image2_upper_right_latitude = IMAGE2URLAT;
  image2_upper_right_longitude = IMAGE2URLONG;
  overlap_area = OVERLAPAREA;
  overlap_lower_left_latitude = OVERLAPLLLAT;
  overlap_lower_left_longitude = OVERLAPLLLONG;
  overlap_lower_right_latitude = OVERLAPLRLAT;
  overlap_lower_right_longitude = OVERLAPLRLONG;
  overlap_upper_left_latitude = OVERLAPULLAT;
  overlap_upper_left_longitude = OVERLAPULLONG;
  overlap_upper_right_latitude = OVERLAPURLAT;
  overlap_upper_right_longitude = OVERLAPURLONG;
}

double OverlappedImages::GetImage1_area()
{
  return image1_area;
}

double OverlappedImages::GetImage1_incidence_angle()
{
  return image1_incidence_angle;
}

double OverlappedImages::GetImage1_lower_left_latitude()
{
  return image1_lower_left_latitude;
}

double OverlappedImages::GetImage1_lower_left_longitude()
{
  return image1_lower_left_longitude;
}

double OverlappedImages::GetImage1_lower_right_latitude()
{
  return image1_lower_right_latitude;
}

double OverlappedImages::GetImage1_lower_right_longitude()
{
  return image1_lower_right_longitude;
}

double OverlappedImages::GetImage1_upper_left_latitude()
{
  return image1_upper_left_latitude;
}

double OverlappedImages::GetImage1_upper_left_longitude()
{
  return image1_upper_left_longitude;
}

double OverlappedImages::GetImage1_upper_right_latitude()
{
  return image1_upper_right_latitude;
}

double OverlappedImages::GetImage1_upper_right_longitude()
{
  return image1_upper_right_longitude;
}

double OverlappedImages::GetImage2_area()
{
  return image2_area;
}

double OverlappedImages::GetImage2_incidence_angle()
{
  return image2_incidence_angle;
}

double OverlappedImages::GetImage2_lower_left_latitude()
{
  return image2_lower_left_latitude;
}

double OverlappedImages::GetImage2_lower_left_longitude()
{
  return image2_lower_left_longitude;
}

double OverlappedImages::GetImage2_lower_right_latitude()
{
  return image2_lower_right_latitude;
}

double OverlappedImages::GetImage2_lower_right_longitude()
{
  return image2_lower_right_longitude;
}

double OverlappedImages::GetImage2_upper_left_latitude()
{
  return image2_upper_left_latitude;
}

double OverlappedImages::GetImage2_upper_left_longitude()
{
  return image2_upper_left_longitude;
}

double OverlappedImages::GetImage2_upper_right_latitude()
{
  return image2_upper_right_latitude;
}

double OverlappedImages::GetImage2_upper_right_longitude()
{
  return image2_upper_right_longitude;
}

double OverlappedImages::GetOverlap_area()
{
  return overlap_area;
}

double OverlappedImages::GetOverlap_lower_left_latitude()
{
  return overlap_lower_left_latitude;
}

double OverlappedImages::GetOverlap_lower_left_longitude()
{
  return overlap_lower_left_longitude;
}

double OverlappedImages::GetOverlap_lower_right_latitude()
{
  return overlap_lower_right_latitude;
}

double OverlappedImages::GetOverlap_lower_right_longitude()
{
  return overlap_lower_right_longitude;
}

double OverlappedImages::GetOverlap_upper_left_latitude()
{
  return overlap_upper_left_latitude;
}

double OverlappedImages::GetOverlap_upper_left_longitude()
{
  return overlap_upper_left_longitude;
}

double OverlappedImages::GetOverlap_upper_right_latitude()
{
  return overlap_upper_right_latitude;
}

double OverlappedImages::GetOverlap_upper_right_longitude()
{
  return overlap_upper_right_longitude;
}

int OverlappedImages::GetId()
{
  return id;
}

int OverlappedImages::GetImage1_id()
{
  return image1_id;
}

int OverlappedImages::GetImage2_id()
{
  return image2_id;
}

string OverlappedImages::GetImage1_name()
{
  return image1_name;
}

string OverlappedImages::GetImage2_name()
{
  return image2_name;
}

void OverlappedImages::Display(OverlappedImages a)
{
  /********************/
  /* Print header row */
  /********************/
  printf("%-5s %-19s %10s %10s %10s %10s %10s %10s %10s %10s %5s %-19s %10s %10s %10s %10s %10s %10s %10s %10s %5s %10s %10s %10s %10s %10s %10s %10s %10s\n", 
	 "ID",
	 "I1NAME",
	 "I1ULLONG",
	 "I1ULLAT",
	 "I1URLONG",
	 "I1URLAT",
	 "I1LRLONG",
	 "I1LRLAT",
	 "I1LLLONG",
	 "I1LLLAT",
	 "I1IA", 
	 "I2NAME",
	 "I2ULLONG",
	 "I2ULLAT",
	 "I2URLONG",
	 "I2URLAT",
	 "I2LRLONG",
	 "I2LRLAT",
	 "I2LLLONG",
	 "I2LLLAT", 
	 "I2IA", 
	 "OULLONG",
	 "OULLAT",
	 "OURLONG",
	 "OURLAT",
	 "OLRLONG",
	 "OLRLAT",
	 "OLLLONG",
	 "OLLLAT");
  
  /******************/
  /* Print data row */
  /******************/
  printf("%-5d %-19s %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %5.2lf %-19s %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %5.2lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf\n", 
	 a.GetId(), 
	 a.GetImage1_name().c_str(), 
	 a.GetImage1_upper_left_longitude(),
	 a.GetImage1_upper_left_latitude(),
	 a.GetImage1_upper_right_longitude(),
	 a.GetImage1_upper_right_latitude(),
	 a.GetImage1_lower_right_longitude(),
	 a.GetImage1_lower_right_latitude(),
	 a.GetImage1_lower_left_longitude(),
	 a.GetImage1_lower_left_latitude(),
	 a.GetImage1_incidence_angle(),
	 a.GetImage2_name().c_str(),
	 a.GetImage2_upper_left_longitude(),
	 a.GetImage2_upper_left_latitude(),
	 a.GetImage2_upper_right_longitude(),
	 a.GetImage2_upper_right_latitude(),
	 a.GetImage2_lower_right_longitude(),
	 a.GetImage2_lower_right_latitude(),
	 a.GetImage2_lower_left_longitude(),
	 a.GetImage2_lower_left_latitude(), 
	 a.GetImage2_incidence_angle(), 
	 a.GetOverlap_upper_left_longitude(),
	 a.GetOverlap_upper_left_latitude(),
	 a.GetOverlap_upper_right_longitude(),
	 a.GetOverlap_upper_right_latitude(),
	 a.GetOverlap_lower_right_longitude(),
	 a.GetOverlap_lower_right_latitude(),
	 a.GetOverlap_lower_left_longitude(),
	 a.GetOverlap_lower_left_latitude());

  return;
}

void OverlappedImages::Display(vector <OverlappedImages> &list)
{
  /********************/
  /* Print header row */
  /********************/
  printf("%-5s %-19s %10s %10s %10s %10s %10s %10s %10s %10s %5s %-19s %10s %10s %10s %10s %10s %10s %10s %10s %5s %10s %10s %10s %10s %10s %10s %10s %10s\n", 
	 "ID",
	 "I1NAME",
	 "I1ULLONG",
	 "I1ULLAT",
	 "I1URLONG",
	 "I1URLAT",
	 "I1LRLONG",
	 "I1LRLAT",
	 "I1LLLONG",
	 "I1LLLAT",
	 "I1IA", 
	 "I2NAME",
	 "I2ULLONG",
	 "I2ULLAT",
	 "I2URLONG",
	 "I2URLAT",
	 "I2LRLONG",
	 "I2LRLAT",
	 "I2LLLONG",
	 "I2LLLAT", 
	 "I2IA", 
	 "OULLONG",
	 "OULLAT",
	 "OURLONG",
	 "OURLAT",
	 "OLRLONG",
	 "OLRLAT",
	 "OLLLONG",
	 "OLLLAT");
  
  /*******************/
  /* Print data rows */
  /*******************/
  for(int i=0; i<(int)list.size(); i++)
    printf("%-5d %-19s %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %5.2lf %-19s %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %5.2lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf\n",
	 list[i].GetId(), 
	 list[i].GetImage1_name().c_str(), 
	 list[i].GetImage1_upper_left_longitude(),
	 list[i].GetImage1_upper_left_latitude(),
	 list[i].GetImage1_upper_right_longitude(),
	 list[i].GetImage1_upper_right_latitude(),
	 list[i].GetImage1_lower_right_longitude(),
	 list[i].GetImage1_lower_right_latitude(),
	 list[i].GetImage1_lower_left_longitude(),
	 list[i].GetImage1_lower_left_latitude(),
	 list[i].GetImage1_incidence_angle(),
	 list[i].GetImage2_name().c_str(),
	 list[i].GetImage2_upper_left_longitude(),
	 list[i].GetImage2_upper_left_latitude(),
	 list[i].GetImage2_upper_right_longitude(),
	 list[i].GetImage2_upper_right_latitude(),
	 list[i].GetImage2_lower_right_longitude(),
	 list[i].GetImage2_lower_right_latitude(),
	 list[i].GetImage2_lower_left_longitude(),
	 list[i].GetImage2_lower_left_latitude(), 
	 list[i].GetImage2_incidence_angle(), 
	 list[i].GetOverlap_upper_left_longitude(),
	 list[i].GetOverlap_upper_left_latitude(),
	 list[i].GetOverlap_upper_right_longitude(),
	 list[i].GetOverlap_upper_right_latitude(),
	 list[i].GetOverlap_lower_right_longitude(),
	 list[i].GetOverlap_lower_right_latitude(),
	 list[i].GetOverlap_lower_left_longitude(),
	 list[i].GetOverlap_lower_left_latitude());

  return;
}
