#include "Utilities.h"

using namespace boost;
using namespace std;

// bool Utilities::CheckOverlap(Rectangle r1, Rectangle r2)
// {
//   return ((r1.GetX_low() < r2.GetX_high()) && (r1.GetX_high() > r2.GetX_low()) && (r1.GetY_high() > r2.GetY_low()) && (r1.GetY_low() < r2.GetY_high()));
// }

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

// double Utilities::ArrayMaximum(double *arr, int n)
// {
//   double max = arr[0];
//   for(int i=1; i<n; i++)
//     max = (max > arr[i]) ? max : arr[i];

//   return max;
// }

// double Utilities::ArrayMinimum(double *arr, int n)
// {
//   double min = arr[0];
//   for(int i=1; i<n; i++)
//     min = (min < arr[i]) ? min : arr[i];

//   return min;
// }

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

// double Utilities::CalculateBottomEdge(Rectangle r1, Rectangle r2)
// {
//   return Max(r1.GetY_low(), r2.GetY_low());
// }

// double Utilities::CalculateLeftEdge(Rectangle r1, Rectangle r2)
// {
//   return Max(r1.GetX_low(), r2.GetX_low());
// }

// double Utilities::CalculateRightEdge(Rectangle r1, Rectangle r2)
// {
//   return Min(r1.GetX_high(), r2.GetX_high());
// }

// double Utilities::CalculateTopEdge(Rectangle r1, Rectangle r2)
// {
//   return Min(r1.GetY_high(), r2.GetY_high());
// }

// vector <double> Utilities::RetrieveUniqueIncidenceAngles(std::vector <IncidenceAngles> &incidenceangles)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   vector <double> ia;

//   /**************************************************************/
//   /* Sort incidenceangles vector based on incidenceangle column */
//   /**************************************************************/
//   SortIncidenceAngles sortincidenceangles(incidenceangles, "incidence_angle");
//   sortincidenceangles.arrange();
//   incidenceangles = sortincidenceangles.GetIncidenceangles();
//   //ReadAuxilaryData::Display(incidenceangles); exit(0);

//   /******************************************/
//   /* Retrieve unique incidence angle values */
//   /******************************************/
//   for(int i=0; i<(int)incidenceangles.size(); i++)
//   {
//     double angle = incidenceangles[i].GetIncidence_angle();
//     if(angle != incidenceangles[i-1].GetIncidence_angle())
//       ia.push_back(angle);
//   }

//   return ia;
// }

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

// vector <OverlappedImages> Utilities::FindDifferentIncidenceAngleOverlappingImages(vector <OverlappedImages> &OI, bool plot)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   string field;
//   vector <OverlappedImages> DIA;

//   /********************************************/
//   /* Sort overlap vector based on "id" column */
//   /********************************************/
//   field = "id";
//   SortOverlappedImages sortoverlappedimages(OI, field);
//   sortoverlappedimages.arrange();
//   OI = sortoverlappedimages.GetOverlappedimages();
//   //OverlappedImages::Display(OI); exit(0);

//   /**************************************/
//   /* Extracting overlapping images that */
//   /* are at different incidence angles  */
//   /**************************************/
//   for(int i=0; i<(int)OI.size(); i++)
//   {
//     double incidenceangle1 = OI[i].GetImage1_incidence_angle();
//     double incidenceangle2 = OI[i].GetImage2_incidence_angle();
//     if(incidenceangle1 != incidenceangle2)
//       DIA.push_back(OI[i]);
//   } 

//   /********/
//   /* Plot */
//   /********/
  
//   return DIA;
// }

// vector <OverlappedImages> Utilities::FindOverlappingImages(vector <Images> &images, vector <IncidenceAngles> &incidenceangles)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   int counter;
//   int n1;
//   int n2;
//   string field1;
//   string field2;
//   vector <OverlappedImages> OLImages;

//   /***********************/
//   /* Define field values */
//   /***********************/
//   field1 = "upper_left_x";
//   field2 = "name";

//   /***********************************************/
//   /* Sort images vector based on "field1" column */
//   /***********************************************/
//   SortImages sortimages(images, field1);
//   sortimages.arrange();
//   images = sortimages.GetImages();
//   //RetrieveImages::Display(images); exit(0);

//   /********************************************************/
//   /* Sort incidenceangles vector based on "field2" column */
//   /********************************************************/
//   SortIncidenceAngles sortincidenceangles(incidenceangles, field2);
//   sortincidenceangles.arrange();
//   incidenceangles = sortincidenceangles.GetIncidenceangles();
//   //ReadAuxilaryData::Display(incidenceangles); exit(0);

//   /*******************************/
//   /* Iterate over all sub-images */
//   /*******************************/
//   counter = 0;
//   n1 = (int)images.size();
//   n2 = (int)incidenceangles.size();
//   for(int i=0; i<n1; i++)
//   {
//     /****************************/
//     /* Retrieve ith image shape */
//     /****************************/
//     Rectangle r1(images[i].GetX_low(), 
// 		 images[i].GetX_high(), 
// 		 images[i].GetY_low(), 
// 		 images[i].GetY_high());

//     /**************************************************/
//     /* Determine ending index of optimal search range */
//     /**************************************************/
//     double value = images[i].GetUpper_left_x()+1.1*images[i].GetPhysical_width();
//     int index = SearchImages::LastNearestValue(images, i+1, n1-1, field1, &value);

//     /***************/
//     /* Image1 data */
//     /***************/
//     int image1_id = images[i].GetId();
//     string image1_name = images[i].GetName();
//     string image1_x_origin_condition = images[i].GetUpper_left_x();
//     string image1_y_origin_condition = images[i].GetUpper_left_y();
//     double image1_horizontal_resolution = images[i].GetHorizontal_resolution();
//     double image1_vertical_resolution = images[i].GetVertical_resolution();
//     double image1_x_low = images[i].GetX_low();
//     double image1_x_high = images[i].GetX_high();
//     double image1_y_low = images[i].GetY_low();
//     double image1_y_high = images[i].GetY_high();
//     int length = image1_name.find_first_of("_");
//     string basename = image1_name.substr(0, length); 
//     int nth_element = SearchIncidenceAngles::BinarySearch(incidenceangles, 0, n2-1, field2, &basename);
//     double image1_incidence_angle = incidenceangles[nth_element].GetIncidence_angle();

//     /************************************************************/
//     /* Iterate over a select few sub-images after the ith image */
//     /************************************************************/
//     for(int j=i+1; j<index; j++)
//     {
//       /****************************/
//       /* Retrieve jth image shape */
//       /****************************/
//       Rectangle r2(images[j].GetX_low(), 
// 		   images[j].GetX_high(), 
// 		   images[j].GetY_low(), 
// 		   images[j].GetY_high());

//       /*******************************/
//       /* Check if two images overlap */
//       /*******************************/
//       if(CheckOverlap(r1, r2))
//       {
// 	int image2_id = images[j].GetId();
// 	string image2_name = images[j].GetName();
// 	string image2_x_origin_condition = images[j].GetUpper_left_x();
// 	string image2_y_origin_condition = images[j].GetUpper_left_y();
// 	double image2_horizontal_resolution = images[j].GetHorizontal_resolution();
// 	double image2_vertical_resolution = images[j].GetVertical_resolution();
// 	double image2_x_low = images[j].GetX_low();
// 	double image2_x_high = images[j].GetX_high();
// 	double image2_y_low = images[j].GetY_low();
// 	double image2_y_high = images[j].GetY_high();	
//         length = image2_name.find_first_of("_");
// 	basename = image2_name.substr(0, length);
// 	nth_element = SearchIncidenceAngles::BinarySearch(incidenceangles, 0, n2-1, field2, &basename);
// 	double image2_incidence_angle = incidenceangles[nth_element].GetIncidence_angle();
// 	double overlap_x_low = CalculateLeftEdge(r1, r2);
// 	double overlap_y_high = CalculateTopEdge(r1, r2);
// 	double overlap_x_high = CalculateRightEdge(r1, r2);
// 	double overlap_y_low = CalculateBottomEdge(r1, r2);
// 	OLImages.push_back(OverlappedImages(counter, 
// 					    image1_id, image1_name,
// 					    image1_x_origin_condition, image1_y_origin_condition,
// 					    image1_horizontal_resolution, image1_vertical_resolution,
// 					    image1_x_low, image1_x_high, 
// 					    image1_y_low, image1_y_high,
// 					    image1_incidence_angle, 
// 					    image2_id, image2_name,
// 					    image2_x_origin_condition, image2_y_origin_condition,
// 					    image2_horizontal_resolution, image2_vertical_resolution,
// 					    image2_x_low, image2_x_high, 
// 					    image2_y_low, image2_y_high, 
// 					    image2_incidence_angle, 
// 					    overlap_x_low, overlap_x_high, 
// 					    overlap_y_low, overlap_y_high));
// 	counter++;
//       }
//     }
//   }

//   return OLImages;
// }

// vector <OverlappedImages> Utilities::FindSameScaleOverlappingImages(vector <OverlappedImages> &OI, int scale)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   int p1;
//   int p2;
//   int length;
//   string field;
//   vector <OverlappedImages> SameScaleOverlappingImages;

//   /********************************************/
//   /* Sort overlap vector based on "id" column */
//   /********************************************/
//   field = "id";
//   SortOverlappedImages sortoverlappedimages(OI, field);
//   sortoverlappedimages.arrange();
//   OI = sortoverlappedimages.GetOverlappedimages();
//   //OverlappedImages::Display(OI); exit(0);

//   /*************************************************************/
//   /* Retrieve all overlapping images with the same scale value */
//   /*************************************************************/
//   for(int i=0; i<(int)OI.size(); i++)
//   {
//     string image1_name = OI[i].GetImage1_name();
//     string image2_name = OI[i].GetImage2_name();
//     p1 = image1_name.find("_")+1;
//     p2 = image1_name.rfind("_");
//     length = p2-p1;
//     int scale1 = stoi(image1_name.substr(p1, length), nullptr);
//     p1 = image2_name.find("_")+1;
//     p2 = image2_name.rfind("_");
//     length = p2-p1;
//     int scale2 = stoi(image2_name.substr(p1, length), nullptr);
//     if(scale1 == scale2)
//     {
//       if(scale < 3)
//       {
// 	if(scale1 == scale)
// 	  SameScaleOverlappingImages.push_back(OI[i]);
//       }
//       else
// 	SameScaleOverlappingImages.push_back(OI[i]);
//     }
//   }

//   return SameScaleOverlappingImages;
// }

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

// void Utilities::SetPixelResolution(vector <ImageSets> &imagesets, vector <PixelResolution> &pixelresolutions)
// {
//   /**********************************************/
//   /* Sort imagesets vector based on name column */
//   /**********************************************/
//   SortImageSets sortimagesets(imagesets, "name");
//   sortimagesets.arrange();
//   imagesets = sortimagesets.GetImageSets();

//   /*****************************************************/
//   /* Sort pixelresolutions vector based on name column */
//   /*****************************************************/
//   SortPixelResolutions sortpixelresolutions(pixelresolutions, "name");
//   sortpixelresolutions.arrange();
//   pixelresolutions = sortpixelresolutions.GetPixelResolutions();
  
//   /******************************************************************/
//   /* Update imagesets vector with data from pixelresolutions vector */
//   /******************************************************************/
//   for(int i=0; i<(int)imagesets.size(); i++)
//   {
//     double vr = pixelresolutions[i].GetVertical_resolution();
//     double hr = pixelresolutions[i].GetHorizontal_resolution();
//     imagesets[i].SetVertical_resolution(vr);
//     imagesets[i].SetHorizontal_resolution(hr);
//   }
// }

// void Utilities::StringVectorSort(vector <string> &list)
// {
//   sort(list.begin(), list.end(), string_less_than_cmp);
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

    /*******************************************************/
    /* Retrieve pixel resolutions for current master image */
    /*******************************************************/
    double horizontal_resolution = imagesets[i].GetHorizontal_resolution();
    double pixel_resolution = imagesets[i].GetPixel_resolution();
    double vertical_resolution = imagesets[i].GetVertical_resolution();

    /*****************************************************/
    /* Retrieve x and y offsets for current master image */
    /*****************************************************/
    double x_offset = imagesets[i].GetUpper_left_x();
    double y_offset = imagesets[i].GetUpper_left_y();

    /****************************************************/
    /* Retrieve x and y shifts for current master image */
    /****************************************************/
    double x_shift = imagesets[i].GetX_shift();
    double y_shift = imagesets[i].GetY_shift();

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
      images[index].AuxilaryFunction(upper_left_x, upper_left_y, pixel_resolution, horizontal_resolution, vertical_resolution, x_offset, y_offset, x_shift, y_shift, pt);

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

