/* HEADER FILE: Utilities.h */

#ifndef UTILITIES_H
#define UTILITIES_H
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>
#include "CheckOverlap.h"
#include "EquirectangularProjection.h"
#include "Images.h"
#include "ImageSets.h"
#include "IncidenceAngles.h"
#include "Marks.h"
#include "OverlappedImages.h"
#include "ProjectiveTransformation.h"
#include "Quadrilateral.h"
#include "ReadAuxilaryData.h"
#include "RetrieveImages.h"
#include "RetrieveImageSets.h"
#include "RetrieveMarks.h"
#include "SearchImages.h"
#include "SearchIncidenceAngles.h"
#include "SearchMarks.h"
#include "SortImages.h"
#include "SortImageSets.h"
#include "SortIncidenceAngles.h"
#include "SortMarks.h"
#include "SortOverlappedImages.h"
#include "SphericalLawofCosines.h"

class Utilities
{
  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    static bool do_LinesIntersect(double, double, double, double, double, double);
    static bool FileExists(std::string);
    static bool is_PointContained(double, double, std::vector < std::vector <double> > &);
    /* static bool int_equality_cmp(int &a, int &b); */
    /* static bool int_greater_than_cmp(int &a, int &b); */
    /* static bool int_less_than_cmp(int &a, int &b); */
    /* static bool string_equality_cmp(std::string &, std::string &); */
    /* static bool string_greater_than_cmp(std::string &, std::string &); */
    /* static bool string_less_than_cmp(std::string &, std::string &); */
    static double ArrayMaximum(double *, int);
    static double ArrayMinimum(double *, int);
    /* static double Max(double, double); */
    /* static double Min(double, double); */
    /* static int IntVectorSearch(std::vector <int> &, int m, int n, int); */
    /* static int StringVectorSearch(std::vector <std::string> &, int m, int n, std::string); */
    static std::vector <double> RetrieveUniqueIncidenceAngles(std::vector <IncidenceAngles> &);
    /* static std::vector <Marks> RetrieveNACMarks(int, int, std::vector <Images> &, std::vector <Marks> &); */
    static void RetrieveCraterCatalog(double, double, std::vector <OverlappedImages> &, std::vector <Marks> &, std::vector <Marks> &, std::vector <Marks> &, std::vector <double> &, std::vector <double> &, std::vector <int> &, std::vector <int> &);
    static std::vector <OverlappedImages> FindDifferentIncidenceAngleOverlappingImages(std::vector <OverlappedImages> &);
    static std::vector <OverlappedImages> FindOverlappingImages(std::vector <Images> &, std::vector <IncidenceAngles> &);
    static std::vector <OverlappedImages> FindSameScaleOverlappingImages(std::vector <OverlappedImages> &, int = 3);
    /* static std::vector <OverlappedImages> FindTotalOverlappingImages(std::vector <OverlappedImages> &, bool = false); */
    static void ExecuteImagesAuxilaryFunction(std::vector <Images> &, std::vector <ImageSets> &);
    static void ExecuteImageSetsAuxilaryFunction(std::vector <ImageSets> &);
    static void ExecuteMarksAuxilaryFunction(std::vector <Marks> &, std::vector <Images> &);
    static void PrintCraterCatalog(double, double, std::vector <IncidenceAngles> &, std::vector <OverlappedImages> &, std::vector <Marks> &, bool = false);
    /* static void PrintNACMarks(double, int, std::vector <IncidenceAngles> &, std::vector <ImageSets> &, std::vector <Images> &, std::vector <Marks> &, bool = 0); */
    /* static void StringVectorSort(std::vector <std::string> &); */
};

#endif
