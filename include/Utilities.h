/* HEADER FILE: Utilities.h */

#ifndef UTILITIES_H
#define UTILITIES_H
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Images.h"
#include "ImageSets.h"
#include "IncidenceAngles.h"
//#include "MasterImageOrientation.h"
//#include "Marks.h"
#include "OverlappedImages.h"
#include "ProjectiveTransformation.h"
#include "ReadAuxilaryData.h"
#include "Rectangle.h"
#include "RetrieveImages.h"
#include "RetrieveImageSets.h"
//#include "SearchImages.h"
//#include "SearchIncidenceAngles.h"
//#include "SearchMarks.h"
#include "SortImages.h"
#include "SortImageSets.h"
#include "SortIncidenceAngles.h"
//#include "SortMasterImageOrientation.h"
//#include "SortMarks.h"
//#include "SortOverlappedImages.h"
//#include "SortPixelResolutions.h"

class Utilities
{
  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    /* static bool CheckOverlap(Rectangle, Rectangle); */
    static bool FileExists(std::string);
    /* static bool int_equality_cmp(int &a, int &b); */
    /* static bool int_greater_than_cmp(int &a, int &b); */
    /* static bool int_less_than_cmp(int &a, int &b); */
    /* static bool string_equality_cmp(std::string &, std::string &); */
    /* static bool string_greater_than_cmp(std::string &, std::string &); */
    /* static bool string_less_than_cmp(std::string &, std::string &); */
    /* static double ArrayMaximum(double *, int); */
    /* static double ArrayMinimum(double *, int); */
    /* static double CalculateBottomEdge(Rectangle, Rectangle); */
    /* static double CalculateLeftEdge(Rectangle, Rectangle); */
    /* static double CalculateRightEdge(Rectangle, Rectangle); */
    /* static double CalculateTopEdge(Rectangle, Rectangle); */
    /* static double Max(double, double); */
    /* static double Min(double, double); */
    /* static int IntVectorSearch(std::vector <int> &, int m, int n, int); */
    /* static int StringVectorSearch(std::vector <std::string> &, int m, int n, std::string); */
    /* static std::vector <double> RetrieveUniqueIncidenceAngles(std::vector <IncidenceAngles> &); */
    /* static std::vector <Marks> RetrieveNACMarks(int, int, std::vector <Images> &, std::vector <Marks> &); */
    /* static std::vector <OverlappedImages> FindDifferentIncidenceAngleOverlappingImages(std::vector <OverlappedImages> &, bool = false); */
    /* static std::vector <OverlappedImages> FindOverlappingImages(std::vector <Images> &, std::vector <IncidenceAngles> &); */
    /* static std::vector <OverlappedImages> FindSameScaleOverlappingImages(std::vector <OverlappedImages> &, int = 3); */
    /* static std::vector <OverlappedImages> FindTotalOverlappingImages(std::vector <OverlappedImages> &, bool = false); */
    static void ExecuteImagesAuxilaryFunction(std::vector <Images> &, std::vector <ImageSets> &);
    static void ExecuteImageSetsAuxilaryFunction(std::vector <ImageSets> &);
    /* static void PrintNACMarks(double, int, std::vector <IncidenceAngles> &, std::vector <ImageSets> &, std::vector <Images> &, std::vector <Marks> &, bool = 0); */
    /* static void SetPixelResolution(std::vector <ImageSets> &, std::vector <PixelResolution> &); */
    /* static void StringVectorSort(std::vector <std::string> &); */
};

#endif
