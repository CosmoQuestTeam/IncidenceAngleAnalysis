#include "Utilities.h"

using namespace boost;
using namespace std;

bool Utilities::do_LinesIntersect(double x, double y, double x1, double y1, double x2, double y2)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double Ax;
  double Ay;
  double Bx;
  double By;
  double Px;
  double Py;
  double max_x;
  double min_x;
  double slope_line_segment;
  double slope_test_line;
  
  /****************************************************************************/
  /* Determine which point is the highest point and set test point coordinate */
  /****************************************************************************/
  if(y1 < y2)
  {
    Ax = x1;
    Ay = y1;
    Bx = x2;
    By = y2;
    Px = x;
    Py = y;
  }
  else
  {
    Ax = x2;
    Ay = y2;
    Bx = x1;
    By = y1;
    Px = x;
    Py = y;
  }
  
  /***************************************/
  /* Determine max and min x coordinates */
  /***************************************/
  if(Ax < Bx)
  {
    max_x = Bx;
    min_x = Ax;
  }
  else
  {
    max_x = Ax;
    min_x = Bx;
  }
  
  /************************************/
  /* Adjust test point's y coordinate */
  /************************************/
  if((Py == Ay) || (Py == By))
    Py += 1.0;

  /*************************************************************/
  /* 1) If test point is lower than point A or higher than point */
  /*    B, then horizontal ray to infinity from test point can   */
  /*    not intersect line AB.                                   */
  /* 2) If test point lies between the y bounds of line AB but   */
  /*    exceeds the maximum x coordinate of line AB, then        */
  /*    horizontal ray to infinity from test point can not       */
  /*    intersect line AB.                                       */
  /* 3) If test point lies between the y bounds of line AB and   */
  /*    does not exceed the maximum x coordinate of line AB,     */
  /*    then horizontal ray to infinity from test point must     */
  /*    intersect line AB.                                       */
  /*************************************************************/
  if((Py < Ay) || (Py > By))
    return false;
  else if(Px >= max_x)
    return false;
  else
    if(Px < min_x)
      return true;
    else
    {
      if(Ax != Bx)
	slope_line_segment = (By-Ay)/(Bx-Ax);
      else
	slope_line_segment = numeric_limits<double>::infinity();
      if(Ax != Px)
	slope_test_line = (Py-Ay)/(Px-Ax);
      else
	slope_test_line = numeric_limits<double>::infinity();
      if(slope_test_line >= slope_test_line)
	return true;
      else
	return false;
    }
}

bool Utilities::FileExists(string Filename)
{ 
  /*******************************************/
  /* Declaration/Initialization of Variables */
  /*******************************************/
  ifstream InFile;

  /***************************/
  /* Check existance of file */
  /***************************/
  InFile.open(Filename.c_str());
  if(InFile)
  { 
    InFile.close();
    return true; // If file exists
  }
  InFile.close();

  return false; // If file does not exist
}

bool Utilities::is_PointContained(double x, double y, vector < vector <double> > &Polygon)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  int nedges;
  int n_intersections;

  /******************************************************/
  /* Determine if point (x,y) resides inside of Polygon */
  /******************************************************/
  nedges = (int)Polygon.size();
  n_intersections = 0;
  for(int j=0; j<nedges; j++)
  {
    int k = (j+1)%nedges;
    if(do_LinesIntersect(x, y, Polygon[j][0], Polygon[j][1], Polygon[k][0], Polygon[k][1]))
      n_intersections++;
  }
  if(n_intersections%2 == 1)
    return true;
  
  return false;
}

// bool Utilities::int_equality_cmp(int &a, int &b)
// {
//   return (a == b);
// }

// bool Utilities::int_greater_than_cmp(int &a, int &b)
// {
//   return (a > b);
// }

// bool Utilities::int_less_than_cmp(int &a, int &b)
// {
//   return (a < b);
// }

// bool Utilities::string_equality_cmp(string &a, string &b)
// {
//   return (a.compare(b) == 0);
// }

// bool Utilities::string_greater_than_cmp(string &a, string &b)
// {
//   return (a > b);
// }

// bool Utilities::string_less_than_cmp(string &a, string &b)
// {
//   return (a < b);
// }

double Utilities::ArrayMaximum(double *arr, int n)
{
  double max = arr[0];
  for(int i=1; i<n; i++)
    max = (max > arr[i]) ? max : arr[i];

  return max;
}

double Utilities::ArrayMinimum(double *arr, int n)
{
  double min = arr[0];
  for(int i=1; i<n; i++)
    min = (min < arr[i]) ? min : arr[i];

  return min;
}

// double Utilities::Max(double v1, double v2)
// {
//   return (v1 > v2) ? v1 : v2;
// }

// double Utilities::Min(double v1, double v2)
// {
//   return (v1 < v2) ? v1 : v2;
// }

// int Utilities::IntVectorSearch(vector <int> &list, int m, int n, int value)
// {
//   if(n >= m)
//   {
//     /***********************************/
//     /* Calculate value of middle index */
//     /***********************************/
//     int midpoint = m+(n-m)/2;
    
//     /****************************************************/
//     /* Compare wanted value to value of middle element. */
//     /* If equal, return index of middle element.        */
//     /****************************************************/
//     if(int_equality_cmp(list[midpoint], value))
//     {
//       return midpoint;
//     }

//     /**************************************************/
//     /* If value of the middle element is smaller than */
//     /* the wanted value, then the wanted value must   */
//     /* reside in the right portion of the array.      */
//     /**************************************************/
//     if(int_less_than_cmp(list[midpoint], value))
//     {
//       return IntVectorSearch(list, midpoint+1, n, value);
//     }

//     /*************************************************/
//     /* If value of the middle element is larger than */
//     /* the wanted value, then the wanted value must  */
//     /* reside in the left portion of the array.      */
//     /*************************************************/
//     if(int_greater_than_cmp(list[midpoint], value))
//     {
//       return IntVectorSearch(list, m, midpoint-1, value);
//     }
//   }

//   /***********************************************************/
//   /* If value is not present in array, return negative index */
//   /***********************************************************/
//   return -1;
// }

// int Utilities::StringVectorSearch(vector <string> &list, int m, int n, string value)
// {
//   if(n >= m)
//   {
//     /***********************************/
//     /* Calculate value of middle index */
//     /***********************************/
//     int midpoint = m+(n-m)/2;
    
//     /****************************************************/
//     /* Compare wanted value to value of middle element. */
//     /* If equal, return index of middle element.        */
//     /****************************************************/
//     if(string_equality_cmp(list[midpoint], value))
//     {
//       return midpoint;
//     }

//     /**************************************************/
//     /* If value of the middle element is smaller than */
//     /* the wanted value, then the wanted value must   */
//     /* reside in the right portion of the array.      */
//     /**************************************************/
//     if(string_less_than_cmp(list[midpoint], value))
//     {
//       return StringVectorSearch(list, midpoint+1, n, value);
//     }

//     /*************************************************/
//     /* If value of the middle element is larger than */
//     /* the wanted value, then the wanted value must  */
//     /* reside in the left portion of the array.      */
//     /*************************************************/
//     if(string_greater_than_cmp(list[midpoint], value))
//     {
//       return StringVectorSearch(list, m, midpoint-1, value);
//     }
//   }

//   /***********************************************************/
//   /* If value is not present in array, return negative index */
//   /***********************************************************/
//   return -1;
// }

vector <double> Utilities::RetrieveUniqueIncidenceAngles(std::vector <IncidenceAngles> &incidenceangles)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  vector <double> ia;

  /**************************************************************/
  /* Sort incidenceangles vector based on incidenceangle column */
  /**************************************************************/
  SortIncidenceAngles sortincidenceangles(incidenceangles, "incidence_angle");
  sortincidenceangles.arrange();
  incidenceangles = sortincidenceangles.GetIncidenceangles();
  //ReadAuxilaryData::Display(incidenceangles); exit(0);

  /******************************************/
  /* Retrieve unique incidence angle values */
  /******************************************/
  for(int i=0; i<(int)incidenceangles.size(); i++)
  {
    double angle = incidenceangles[i].GetIncidence_angle();
    if(angle != incidenceangles[i-1].GetIncidence_angle())
      ia.push_back(angle);
  }

  return ia;
}

void Utilities::RetrieveCraterCatalog(double incidence_angle_1, double incidence_angle_2, vector <OverlappedImages> &OI, vector <Marks> &marks, vector <Marks> &RM1, vector <Marks> &RM2, vector <double> &OA1, vector <double> &OA2, vector <int> &AID1, vector <int> &AID2)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double incidence_angle_sum;
  int point_set_size;
  set < pair <double, double> > point;
  string field;
  vector <double> overlap_area_1;
  vector <double> overlap_area_2;
  vector <int> area_id_1;
  vector <int> area_id_2;
  vector <Marks> retained_marks_1;
  vector <Marks> retained_marks_2;
  vector < vector <double> > Polygon_Overlap(4, vector <double> (2));

  /*********************/
  /* Sort marks vector */
  /*********************/
  field = "image_id";
  SortMarks sortmarks(marks, field);
  sortmarks.arrange();
  marks = sortmarks.GetMarks();
  //RetrieveMarks::Display(marks); exit(0);
  
  /******************************************************/
  /* Used as rejection criterion for overlapping images */
  /******************************************************/
  incidence_angle_sum = incidence_angle_1+incidence_angle_2;
  
  /*********************************************/
  /* Iterate through overlapping images vector */
  /*********************************************/
  point_set_size = 0;
  int n = (int)marks.size();
  for(int i=0; i<(int)OI.size(); i++)
  {
    /*********************************************/
    /* Reject overlapping images whose incidence */
    /* angle sum doesn't match the sum above     */
    /*********************************************/
    if(incidence_angle_sum != OI[i].GetImage1_incidence_angle()+OI[i].GetImage2_incidence_angle())
      continue;

    /*********************/
    /* Image information */
    /*********************/
    int image1_id = OI[i].GetImage1_id();
    int image2_id = OI[i].GetImage2_id();
    
    /****************************************/
    /* Reject moon_mappers_tutorial_4 image */
    /****************************************/
    if((image1_id == 60639) || (image2_id == 60639))
      continue;
    
    /******************/
    /* Overlap region */
    /******************/
    Polygon_Overlap[0][0] = OI[i].GetOverlap_upper_left_longitude();
    Polygon_Overlap[0][1] = OI[i].GetOverlap_upper_left_latitude();
    Polygon_Overlap[1][0] = OI[i].GetOverlap_upper_right_longitude();
    Polygon_Overlap[1][1] = OI[i].GetOverlap_upper_right_latitude();
    Polygon_Overlap[2][0] = OI[i].GetOverlap_lower_right_longitude();
    Polygon_Overlap[2][1] = OI[i].GetOverlap_lower_right_latitude();
    Polygon_Overlap[3][0] = OI[i].GetOverlap_lower_left_longitude();
    Polygon_Overlap[3][1] = OI[i].GetOverlap_lower_left_latitude();
    
    /*********************************************************************/
    /* Isolate marks that are associated with current overlapping images */
    /*********************************************************************/
    int index1 = SearchMarks::FirstOccurence(marks, 0, n-1, field, &image1_id);
    int index2 = SearchMarks::LastOccurence(marks, 0, n-1, field, &image1_id);
    
    /***********************************************************************/
    /* Determine which marks are in overlap region and record unique marks */
    /***********************************************************************/
    for(int j=index1; j<index2; j++)
    {
      double longitude = marks[j].GetLongitude();
      double latitude = marks[j].GetLatitude();
      pair <double, double> entry(longitude, latitude);
      if(point.find(entry) == point.end())
      {
	if(is_PointContained(longitude, latitude, Polygon_Overlap))
	{
	  retained_marks_1.push_back(marks[j]);
	  overlap_area_1.push_back(OI[i].GetOverlap_area());
	  area_id_1.push_back(OI[i].GetId());
	  point.insert(entry);
	}
      }
    }
  
    /*********************************************************************/
    /* Isolate marks that are associated with current overlapping images */
    /*********************************************************************/
    index1 = SearchMarks::FirstOccurence(marks, 0, n-1, field, &image2_id);
    index2 = SearchMarks::LastOccurence(marks, 0, n-1, field, &image2_id);

    /***********************************************************************/
    /* Determine which marks are in overlap region and record unique marks */
    /***********************************************************************/
    for(int j=index1; j<index2; j++)
    {
      double longitude = marks[j].GetLongitude();
      double latitude = marks[j].GetLatitude();
      pair <double, double> entry(longitude, latitude);
      if(point.find(entry) == point.end())
      {
	if(is_PointContained(longitude, latitude, Polygon_Overlap))
	{
	  retained_marks_2.push_back(marks[j]);
	  overlap_area_2.push_back(OI[i].GetOverlap_area());
	  area_id_2.push_back(OI[i].GetId());
	  point.insert(entry);
	}
      }
    }
  }
  
  /****************************/
  /* Record surviving craters */
  /****************************/
  RM1 = retained_marks_1;
  RM2 = retained_marks_2;

  /**************************************************/
  /* Record area of overlapping region between both */
  /* NACs from which marks are associated with      */
  /**************************************************/
  OA1 = overlap_area_1;
  OA2 = overlap_area_2;

  /***************************************************/
  /* Record which areas are contributing to analysis */
  /***************************************************/
  AID1 = area_id_1;
  AID2 = area_id_2;
}

// vector <Marks> Utilities::RetrieveNACMarks(int global_imageid, int scale, vector <Images> &images, vector <Marks> &marks)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   int nelements;
//   string field;
//   vector <double> subimagex;
//   vector <double> subimagey;
//   vector <int> subimageids;
//   vector <Marks> selected_marks;

//   /********************************************/
//   /* Sort images vector based on image_set_id */
//   /********************************************/
//   field = "image_set_id";
//   SortImages sortimages(images, field);
//   sortimages.arrange();
//   images = sortimages.GetImages();
//   //RetrieveImages::Display(images); exit(0);

//   /********************************************************/
//   /* Select sub-image ids associated with global image id */
//   /********************************************************/
//   nelements = (int)images.size();
//   int starting_index = SearchImages::FirstOccurence(images, 0, nelements-1, field, &global_imageid);
//   int ending_index = SearchImages::LastOccurence(images, 0, nelements-1, field, &global_imageid);

//   /**************************/
//   /* Copy images sub vector */
//   /**************************/
//   vector <Images> temp_images;
//   std::copy(images.begin()+starting_index, images.begin()+ending_index, back_inserter(temp_images));

//   /********************************/
//   /* Sort temp vector based on id */
//   /********************************/
//   field = "id";
//   SortImages sortimages2(temp_images, field);
//   sortimages2.arrange();
//   temp_images = sortimages2.GetImages();
//   //RetrieveImages::Display(temp_images); exit(0);

//   /************************************************************/
//   /* Record all sub-image ids and x and y reference positions */
//   /************************************************************/
//   for(int i=0; i<(int)temp_images.size(); i++)
//   {
//     /****************************/
//     /* Retrieve sub-image scale */
//     /****************************/
//     int p1 = temp_images[i].GetName().find("_");    
//     int ss = stoi(temp_images[i].GetName().substr(p1+1, 1), NULL);

//     /**********************************/
//     /*Apply scale restriction, if any */
//     /**********************************/
//     if(scale == ss)
//     {
//       subimageids.push_back(temp_images[i].GetId());
//       subimagex.push_back(temp_images[i].GetX_relative());
//       subimagey.push_back(temp_images[i].GetY_relative());
//     }
//     if(scale > 2)
//     {
//       subimageids.push_back(temp_images[i].GetId());
//       subimagex.push_back(temp_images[i].GetX_relative());
//       subimagey.push_back(temp_images[i].GetY_relative());
//     }
//   }
//   temp_images.clear();

//   /***************************************/
//   /* Sort marks vector based on image_id */
//   /***************************************/
//   field = "image_id";
//   SortMarks sortmarks(marks, field);
//   sortmarks.arrange();
//   marks = sortmarks.GetMarks();
//   //RetrieveMarks::Display(marks); exit(0);

//   /*************************************/
//   /* Extract marks that are associated */
//   /* with extracted sub-image ids      */
//   /*************************************/
//   int index = 0;
//   nelements = (int)marks.size();
//   while(index < (int)subimageids.size())
//   {
//     /****************************************************************/
//     /* Find first occurence of current sub-image id in marks vector */
//     /****************************************************************/
//     int value = subimageids[index];
//     int first = SearchMarks::FirstOccurence(marks, 0, nelements-1, field, &value);
    
//     /*********************************************************/
//     /* Relative modify x and y position of mark using offset */
//     /*********************************************************/
//     double x_offset = subimagex[index];
//     double y_offset = subimagey[index];

//     /************************************************************/
//     /* Iterate through marks sub vector and record wanted marks */
//     /************************************************************/
//     int index2 = first;
//     while(value == marks[index2].GetImage_id())
//     {
//       /**************************/
//       /* Modify and Record mark */
//       /**************************/
//       Marks newmark = marks[index2];
//       newmark.SetX(x_offset+marks[index2].GetX());
//       newmark.SetY(y_offset+marks[index2].GetY());
//       selected_marks.push_back(newmark);

//       /*****************/
//       /* Update index2 */
//       /*****************/
//       index2++;
//     }

//     /****************/
//     /* Update index */
//     /****************/
//     index++;
//   }

//   return selected_marks;
// }

vector <OverlappedImages> Utilities::FindDifferentIncidenceAngleOverlappingImages(vector <OverlappedImages> &OI)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  string field;
  vector <OverlappedImages> DIA;

  /**************************************/
  /* Extracting overlapping images that */
  /* are at different incidence angles  */
  /**************************************/
  for(int i=0; i<(int)OI.size(); i++)
  {
    double incidenceangle1 = OI[i].GetImage1_incidence_angle();
    double incidenceangle2 = OI[i].GetImage2_incidence_angle();
    if(incidenceangle1 != incidenceangle2)
      DIA.push_back(OI[i]);
  } 
  
  return DIA;
}

vector <OverlappedImages> Utilities::FindOverlappingImages(vector <Images> &images, vector <IncidenceAngles> &incidenceangles)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int counter;
  int n1;
  int n2;
  string field1;
  string field2;
  vector <OverlappedImages> OLImages;

  /***********************/
  /* Define field values */
  /***********************/
  field1 = "minimum_longitude";
  field2 = "name";

  /***********************************************/
  /* Sort images vector based on "field1" column */
  /***********************************************/
  SortImages sortimages(images, field1);
  sortimages.arrange();
  images = sortimages.GetImages();
  //RetrieveImages::Display(images); exit(0);
  
  /********************************************************/
  /* Sort incidenceangles vector based on "field2" column */
  /********************************************************/
  SortIncidenceAngles sortincidenceangles(incidenceangles, field2);
  sortincidenceangles.arrange();
  incidenceangles = sortincidenceangles.GetIncidenceangles();
  //ReadAuxilaryData::Display(incidenceangles); exit(0);

  /*******************************/
  /* Iterate over all sub-images */
  /*******************************/
  counter = 0;
  n1 = (int)images.size();
  n2 = (int)incidenceangles.size();
  for(int i=0; i<n1; i++)
  { 
    /******************************************/
    /* Retrieve pertinent image 1 information */
    /******************************************/
    int image1_id = images[i].GetId();
    string image1_name = images[i].GetName();
    double image1_upper_left_longitude = images[i].GetUpper_left_longitude();
    double image1_upper_left_latitude = images[i].GetUpper_left_latitude();
    double image1_upper_right_longitude = images[i].GetUpper_right_longitude();
    double image1_upper_right_latitude = images[i].GetUpper_right_latitude();
    double image1_lower_right_longitude = images[i].GetLower_right_longitude();
    double image1_lower_right_latitude = images[i].GetLower_right_latitude();
    double image1_lower_left_longitude = images[i].GetLower_left_longitude();
    double image1_lower_left_latitude = images[i].GetLower_left_latitude();
    double image1_minimum_longitude = images[i].GetMinimum_longitude();
    double image1_minimum_latitude = images[i].GetMinimum_latitude();
    double image1_maximum_longitude = images[i].GetMaximum_longitude();
    double image1_maximum_latitude = images[i].GetMaximum_latitude();
    double image1_area = images[i].GetArea();
    vector < vector <double> > image1_shape_vector = images[i].GetShape_vector();
    int length = image1_name.find_first_of("_");
    string basename = image1_name.substr(0, length); 
    int nth_element = SearchIncidenceAngles::BinarySearch(incidenceangles, 0, n2-1, field2, &basename);
    double image1_incidence_angle = incidenceangles[nth_element].GetIncidence_angle();

    /**************************************************/
    /* Determine ending index of optimal search range */
    /**************************************************/
    int index = SearchImages::LastNearestValue(images, i+1, n1-1, field1, &image1_maximum_longitude);
    
    /************************************************************/
    /* Iterate over a select few sub-images after the ith image */
    /************************************************************/
    for(int j=i+1; j<index; j++)
    {      
      /**************************************/
      /* Retrieve image 2 shape information */
      /**************************************/
      double image2_minimum_longitude = images[j].GetMinimum_longitude();
      double image2_minimum_latitude = images[j].GetMinimum_latitude();
      double image2_maximum_longitude = images[j].GetMaximum_longitude();
      double image2_maximum_latitude = images[j].GetMaximum_latitude();
      double image2_area = images[j].GetArea();
      vector < vector <double> > image2_shape_vector = images[j].GetShape_vector();
      
      /*******************************/
      /* Check if two images overlap */
      /*******************************/
      CheckOverlap OL(image1_shape_vector,
		      image1_minimum_longitude, image1_minimum_latitude,
		      image1_maximum_longitude, image1_maximum_latitude,
		      image1_area,
		      image2_shape_vector,
		      image2_minimum_longitude, image2_minimum_latitude,
		      image2_maximum_longitude, image2_maximum_latitude,
		      image2_area);
      if(OL.are_Overlapping())
      {	
	/*****************************************************/
	/* Retrieve additional pertinent image 2 information */
	/*****************************************************/
	int image2_id = images[j].GetId();
	string image2_name = images[j].GetName();
	double image2_upper_left_longitude = images[j].GetUpper_left_longitude();
	double image2_upper_left_latitude = images[j].GetUpper_left_latitude();
	double image2_upper_right_longitude = images[j].GetUpper_right_longitude();
	double image2_upper_right_latitude = images[j].GetUpper_right_latitude();
	double image2_lower_right_longitude = images[j].GetLower_right_longitude();
	double image2_lower_right_latitude = images[j].GetLower_right_latitude();
	double image2_lower_left_longitude = images[j].GetLower_left_longitude();
	double image2_lower_left_latitude = images[j].GetLower_left_latitude();
        length = image2_name.find_first_of("_");
	basename = image2_name.substr(0, length);
	nth_element = SearchIncidenceAngles::BinarySearch(incidenceangles, 0, n2-1, field2, &basename);
	double image2_incidence_angle = incidenceangles[nth_element].GetIncidence_angle();
	
	/**********************************************/
	/* Calculate overlap bounding region and area */
	/**********************************************/
	OL.AuxilaryFunction();	
	vector < vector <double> > OverlappingBoundary = OL.GetPolygon_Overlap();
	double overlap_area = OL.GetPolygon_Overlap_Area();

	/*************************************/
	/* In case overlap exists on an edge */
	/*************************************/
	if(OverlappingBoundary.size() != 4)
	  continue;
	
	/***************************************/
	/* Retrieve overlap region information */
	/***************************************/
	double overlap_upper_left_longitude = OverlappingBoundary[0][0];
	double overlap_upper_left_latitude = OverlappingBoundary[0][1];
	double overlap_upper_right_longitude = OverlappingBoundary[1][0];
	double overlap_upper_right_latitude = OverlappingBoundary[1][1];
	double overlap_lower_right_longitude = OverlappingBoundary[2][0];
	double overlap_lower_right_latitude = OverlappingBoundary[2][1];
	double overlap_lower_left_longitude = OverlappingBoundary[3][0];
	double overlap_lower_left_latitude = OverlappingBoundary[3][1];
	
	/*****************************************/
	/* Record overlapping images information */
	/*****************************************/
	OLImages.push_back(OverlappedImages(counter,
					    image1_id,
					    image1_name,
					    image1_upper_left_longitude,
					    image1_upper_left_latitude,
					    image1_upper_right_longitude,
					    image1_upper_right_latitude,
					    image1_lower_right_longitude,
					    image1_lower_right_latitude,
					    image1_lower_left_longitude,
					    image1_lower_left_latitude,
					    image1_area,
					    image1_incidence_angle,
					    image2_id,
					    image2_name,
					    image2_upper_left_longitude,
					    image2_upper_left_latitude,
					    image2_upper_right_longitude,
					    image2_upper_right_latitude,
					    image2_lower_right_longitude,
					    image2_lower_right_latitude,
					    image2_lower_left_longitude,
					    image2_lower_left_latitude,
					    image2_area,
					    image2_incidence_angle,
					    overlap_upper_left_longitude,
					    overlap_upper_left_latitude,
					    overlap_upper_right_longitude,
					    overlap_upper_right_latitude,
					    overlap_lower_right_longitude,
					    overlap_lower_right_latitude,
					    overlap_lower_left_longitude,
					    overlap_lower_left_latitude,
					    overlap_area));
	counter++;
      }
    }
  }

  return OLImages;
}

vector <OverlappedImages> Utilities::FindSameScaleOverlappingImages(vector <OverlappedImages> &OI, int scale)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int p1;
  int p2;
  int length;
  string field;
  vector <OverlappedImages> SameScaleOverlappingImages;

  /*************************************************************/
  /* Retrieve all overlapping images with the same scale value */
  /*************************************************************/
  for(int i=0; i<(int)OI.size(); i++)
  {
    string image1_name = OI[i].GetImage1_name();
    string image2_name = OI[i].GetImage2_name();
    p1 = image1_name.find("_")+1;
    p2 = image1_name.rfind("_");
    length = p2-p1;
    int scale1 = stoi(image1_name.substr(p1, length), nullptr);
    p1 = image2_name.find("_")+1;
    p2 = image2_name.rfind("_");
    length = p2-p1;
    int scale2 = stoi(image2_name.substr(p1, length), nullptr);
    if(scale1 == scale2)
    {
      if(scale < 3)
      {
	if(scale1 == scale)
	  SameScaleOverlappingImages.push_back(OI[i]);
      }
      else
	SameScaleOverlappingImages.push_back(OI[i]);
    }
  }

  return SameScaleOverlappingImages;
}

// vector <OverlappedImages> Utilities::FindTotalOverlappingImages(vector <OverlappedImages> &OI, bool plot)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   string field;
//   vector <OverlappedImages> TOI;

//   /********************************************/
//   /* Sort overlap vector based on "id" column */
//   /********************************************/
//   field = "id";
//   SortOverlappedImages sortoverlappedimages(OI, field);
//   sortoverlappedimages.arrange();
//   OI = sortoverlappedimages.GetOverlappedimages();
//   //OverlappedImages::Display(OI); exit(0);

//   /****************************/
//   /* Retrieve neccessary data */
//   /****************************/
//   for(int i=0; i<(int)OI.size(); i++)
//   {
//     double imagearea1 = OI[i].GetImage1_area();
//     double imagearea2 = OI[i].GetImage2_area();
//     double oarea = OI[i].GetOverlap_area();
//     double overlap_percentage = 100*oarea/Utilities::Min(imagearea1, imagearea2);
//     if(overlap_percentage == 100)
//       TOI.push_back(OI[i]);
//   }

//   /********/
//   /* Plot */
//   /********/

//   return TOI;
// }

void Utilities::PrintCraterCatalog(double incidence_angle_1, double incidence_angle_2, vector <IncidenceAngles> &IA, vector <OverlappedImages> &OI, vector <Marks> &marks, bool print)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int index;
  int nelements;
  ofstream File;
  string field;
  string filename;
  string master_image_1_name;
  string master_image_2_name;
  vector <double> OA1;
  vector <double> OA2;
  vector <int> AID1;
  vector <int> AID2;
  vector <Marks> RM1;
  vector <Marks> RM2;
  
  /******************/
  /* Sort IA vector */
  /******************/
  SortIncidenceAngles sortincidenceangles(IA, "incidence_angle");
  sortincidenceangles.arrange();
  IA = sortincidenceangles.GetIncidenceangles();
  //ReadAuxilaryData::Display(IA); exit(0);
  
  /****************************/
  /* Retrieve NAC image names */
  /****************************/
  field = "incidence_angle";
  nelements = (int)IA.size();
  index = SearchIncidenceAngles::BinarySearch(IA, 0, nelements-1, field, &incidence_angle_1);
  master_image_1_name = IA[index].GetName();
  index = SearchIncidenceAngles::BinarySearch(IA, 0, nelements-1, field, &incidence_angle_2);
  master_image_2_name = IA[index].GetName();
  
  /**********************/
  /* Retrieve NAC marks */
  /**********************/
  RetrieveCraterCatalog(incidence_angle_1, incidence_angle_2, OI, marks, RM1, RM2, OA1, OA2, AID1, AID2);

  /**************************/
  /* Create output filename */
  /**************************/
  filename = "Crater_catalog_"+master_image_1_name+"_"+to_string(incidence_angle_1)+".txt";

  /***************************/
  /* Print to screen or file */
  /***************************/
  nelements = (int)RM1.size();
  if(print)
  {
    File.open(filename.c_str());
    File << "X\t\tY\t\tD\t\tC\t\tA\t\tID" << endl;
    for(int i=0; i<nelements; i++)
      File << setprecision(7) << setw(10) << left << RM1[i].GetPhysical_x() << "\t"
	   << setprecision(7) << setw(10) << left << RM1[i].GetPhysical_y() << "\t"
	   << setprecision(7) << setw(10) << left << RM1[i].GetPhysical_diameter() << "\t"
	   << setprecision(7) << setw(10) << left << 1 << "\t"
	   << setprecision(7) << setw(10) << left << OA1[i] << "\t"
	   << setprecision(7) << setw(10) << left << AID1[i]
	   << endl;
    File.close();
  }
  else
  {
    cout << "\nCrater Catalog 1: " << master_image_1_name << endl;
    cout << "Long\t\tLat\t\tX\t\tY\t\tD\t\tC\t\tA\t\tID" << endl;
    for(int i=0; i<nelements; i++)
      cout << setprecision(7) << setw(10) << left << RM1[i].GetLongitude() << "\t"
	   << setprecision(7) << setw(10) << left << RM1[i].GetLatitude() << "\t"
	   << setprecision(7) << setw(10) << left << RM1[i].GetPhysical_x() << "\t"
	   << setprecision(7) << setw(10) << left << RM1[i].GetPhysical_y() << "\t"
	   << setprecision(7) << setw(10) << left << RM1[i].GetPhysical_diameter() << "\t"
	   << setprecision(7) << setw(10) << left << 1 << "\t"
	   << setprecision(7) << setw(10) << left << OA1[i] << "\t"
	   << setprecision(7) << setw(10) << left << AID1[i] 
	   << endl;
  }

  /**************************/
  /* Create output filename */
  /**************************/
  filename = "Crater_catalog_"+master_image_2_name+"_"+to_string(incidence_angle_2)+".txt";

  /***************************/
  /* Print to screen or file */
  /***************************/
  nelements = (int)RM2.size();
  if(print)
  {
    File.open(filename.c_str());
    File << "X\t\tY\t\tD\t\tC\t\tA\t\tID" << endl;
    for(int i=0; i<nelements; i++)
      File << setprecision(7) << setw(10) << left << RM2[i].GetPhysical_x() << "\t"
	   << setprecision(7) << setw(10) << left << RM2[i].GetPhysical_y() << "\t"
	   << setprecision(7) << setw(10) << left << RM2[i].GetPhysical_diameter() << "\t"
	   << setprecision(7) << setw(10) << left << 1 << "\t"
	   << setprecision(7) << setw(10) << left << OA2[i] << "\t"
	   << setprecision(7) << setw(10) << left << AID2[i] 
	   << endl;
    File.close();
  }
  else
  {
    cout << "\nCrater Catalog 2: " << master_image_2_name << endl;
    cout << "Long\t\tLat\t\tX\t\tY\t\tD\t\tC\t\tA\t\tID" << endl;
    for(int i=0; i<nelements; i++)
      cout << setprecision(7) << setw(10) << left << RM2[i].GetLongitude() << "\t"
	   << setprecision(7) << setw(10) << left << RM2[i].GetLatitude() << "\t"
	   << setprecision(7) << setw(10) << left << RM2[i].GetPhysical_x() << "\t"
	   << setprecision(7) << setw(10) << left << RM2[i].GetPhysical_y() << "\t"
	   << setprecision(7) << setw(10) << left << RM2[i].GetPhysical_diameter() << "\t"
	   << setprecision(7) << setw(10) << left << 1 << "\t"
	   << setprecision(7) << setw(10) << left << OA2[i] << "\t"
	   << setprecision(7) << setw(10) << left << AID2[i] 
	   << endl;
  }
  
  return;
}

// void Utilities::PrintNACMarks(double incidence_angle, int scale, vector <IncidenceAngles> &ia, vector <ImageSets> &imagesets, vector <Images> &images, vector <Marks> &marks, bool print)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   int global_imageid = 0;
//   int nelements;
//   ofstream File;
//   string filename;
//   string global_imagename;
//   vector <Marks> selected_marks;

//   /*******************************/
//   /* Determine global image name */
//   /*******************************/
//   for(int i=0; i<(int)ia.size(); i++)
//     if(ia[i].GetIncidence_angle() == incidence_angle)
//     {
//       global_imagename = ia[i].GetName();
//       break;
//     }

//   /*****************************/
//   /* Determine global image id */
//   /*****************************/
//   for(int i=0; i<(int)imagesets.size(); i++)
//     if(imagesets[i].GetName() == global_imagename)
//     {
//       global_imageid = imagesets[i].GetId();
//       break;
//     }

//   /**********************/
//   /* Retrieve NAC marks */
//   /**********************/
//   selected_marks = RetrieveNACMarks(global_imageid, scale, images, marks);

//   /**************************/
//   /* Create output filename */
//   /**************************/
//   filename = global_imagename+"_crater_catalog.txt";

//   /***************************/
//   /* Print to screen or file */
//   /***************************/
//   nelements = (int)selected_marks.size();
//   if(print)
//   {
//     File.open(filename.c_str());
//     File << "X\tY\tD\tC" << endl;
//     for(int i=0; i<nelements; i++)
//       File << setprecision(7) << setw(7) << left << selected_marks[i].GetX() << "\t"
// 	   << setprecision(7) << setw(7) << left << selected_marks[i].GetY() << "\t"
// 	   << setprecision(7) << setw(7) << left << selected_marks[i].GetDiameter() << "\t"
// 	   << setprecision(7) << setw(7) << left << 1 
// 	   << endl;
//     File.close();
//   }
//   else
//   {
//     cout << "X\tY\tD\tC" << endl;
//     for(int i=0; i<nelements; i++)
//       cout << setprecision(7) << setw(7) << left << selected_marks[i].GetX() << "\t"
// 	   << setprecision(7) << setw(7) << left << selected_marks[i].GetY() << "\t"
// 	   << setprecision(7) << setw(7) << left << selected_marks[i].GetDiameter() << "\t"
// 	   << setprecision(7) << setw(7) << left << 1 
// 	   << endl;
//   }
  
//   return;
// }

void Utilities::ExecuteImagesAuxilaryFunction(vector <Images> &images, vector <ImageSets> &imagesets)
{
  /**********************************************/
  /* Sort imagesets vector based on name column */
  /**********************************************/
  SortImageSets sortimagesets(imagesets, "name");
  sortimagesets.arrange();
  imagesets = sortimagesets.GetImageSets();
  //RetrieveImageSets::Display(imagesets); exit(0);
  
  /*******************************************/
  /* Sort images vector based on name column */
  /*******************************************/
  SortImages sortimages(images, "name");
  sortimages.arrange();
  images = sortimages.GetImages();
  //RetrieveImages::Display(images); exit(0);

  /****************/
  /* Images index */
  /****************/
  int index = 0;

  /************************************/
  /* Iterate through imagesets vector */
  /************************************/
  for(int i=0; i<(int)imagesets.size(); i++)
  {
    /**************************************/
    /* Retrieve current master image name */
    /**************************************/
    string master_image_name = imagesets[i].GetName();
   
    /************************************************************************************/
    /* Retrieve x and y conditions for master image upper left corner as viewed by user */
    /************************************************************************************/
    string upper_left_x = imagesets[i].GetUpper_left_corner_x_status();
    string upper_left_y = imagesets[i].GetUpper_left_corner_y_status();

    /*************************************/
    /* Retrieve transformation matricies */
    /*************************************/
    ProjectiveTransformation pt = imagesets[i].GetProjective_transformation();
    
    /**************************************************/
    /* Determine length of current sub-image basename */
    /**************************************************/
    int p1 = images[index].GetName().find("_");
    
    /*********************************/
    /* Iterate through images vector */
    /*********************************/
    while(master_image_name.compare(images[index].GetName().substr(0, p1)) == 0)
    {
      /****************************/
      /* Execute AuxilaryFunction */
      /****************************/
      images[index].AuxilaryFunction(upper_left_x, upper_left_y, pt);

      /**************************/
      /* Increment images index */
      /**************************/
      index++;
    }
  }
}

void Utilities::ExecuteImageSetsAuxilaryFunction(vector <ImageSets> &imagesets)
{
  /*****************************************************************/
  /* Iterate through imagesets vector and execute AuxilaryFunction */
  /*****************************************************************/
  for(int i=0; i<(int)imagesets.size(); i++)
    imagesets[i].AuxilaryFunction();
  
  return;
}

void Utilities::ExecuteMarksAuxilaryFunction(vector <Marks> &marks, vector <Images> &images)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  int index;
  string field;
  
  /**********************************/
  /* Sort images vector based on id */
  /**********************************/
  field = "id";
  SortImages sortimages(images, field);
  sortimages.arrange();
  images = sortimages.GetImages();
  //RetrieveImages::Display(images); exit(0);

  /*********************/
  /* Sort marks vector */
  /*********************/
  field = "image_id";
  SortMarks sortmarks(marks, field);
  sortmarks.arrange();
  marks = sortmarks.GetMarks();
  //RetrieveMarks::Display(marks); exit(0);

  /*********************************/
  /* Iterate through images vector */
  /*********************************/
  index = 0;
  for(int i=0; i<(int)images.size(); i++)
  {
    /********************/
    /* Current image id */
    /********************/
    int image_id = images[i].GetId();

    /****************************************************/
    /* Current image upper left corner pixel coordinate */
    /****************************************************/
    double x_offset = images[i].GetX_relative();
    double y_offset = images[i].GetY_relative();
    
    /************************************************/
    /* Retrieve current coordinate transform matrix */
    /************************************************/
    ProjectiveTransformation pt = images[i].GetProjective_transformation();

    /****************************************/
    /* Reject moon_mappers_tutorial_4 image */
    /****************************************/
    if(image_id == 60639)
      continue;
    
    /***************************************************************************************/
    /* Calculate selenographic coordinates for all marks associated with current sub-image */
    /***************************************************************************************/
    while(image_id == marks[index].GetImage_id())
    {
      /*****************************************************************************/
      /* Global pixel coordinates (Mark pixel coordinate relative to master image) */
      /*****************************************************************************/
      double x = static_cast<int>(x_offset+marks[index].GetX());
      double y = static_cast<int>(y_offset+marks[index].GetY());
      
      /*********************************************/
      /* Calculate mark diameter in physical units */
      /*********************************************/
      double r = 0.5*marks[index].GetDiameter();
      double latitude_high = pt.ComputeTarget2SourceCoordinate_y(x, y+r);
      double latitude_low = pt.ComputeTarget2SourceCoordinate_y(x, y-r);
      double angular_change = fabs(latitude_high-latitude_low)*(M_PI/180); // Unit: radian
      double physical_diameter = EquirectangularProjection::CalculateY(angular_change, 0.0, 1737400.0);
      //double physical_diameter2 = SphericalLawofCosines::CalculateDistance(latitude_low, latitude_high, longitude, longitude, 1737400.0);
      
      /*****************************/
      /* Execute auxilary function */
      /*****************************/
      vector <double> adjustedpixelcoordinate{x, y};
      vector <double> selenographiccoordinate = pt.ComputeTarget2SourceCoordinates(x, y);
      double physical_x = EquirectangularProjection::CalculateX(selenographiccoordinate[0]*(M_PI/180), 0.0, 0.0, 1737400.0);
      double physical_y = EquirectangularProjection::CalculateY(selenographiccoordinate[1]*(M_PI/180), 0.0, 1737400.0);
      //double physical_x2 = SphericalLawofCosines::CalculateDistance(0.0, 0.0, 0.0, selenographiccoordinate[0], 1737400.0);
      //double physical_y2 = SphericalLawofCosines::CalculateDistance(0.0, selenographiccoordinate[1], 0.0, 0.0, 1737400.0);
      vector <double> cartesiancoordinate{physical_x, physical_y};
      marks[index].AuxilaryFunction(adjustedpixelcoordinate, selenographiccoordinate, cartesiancoordinate, physical_diameter);
      
      /****************/
      /* Update index */
      /****************/
      index++;
    }
  }
}
