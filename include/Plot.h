/* HEADER FILE: Plot.h */

#ifndef PLOT_H
#define PLOT_H
#include <math.h>
#include <string>
#include <TBox.h>
#include <TCanvas.h>
#include <TEllipse.h>
#include <TF1.h>
#include <TGaxis.h>
#include <TH1.h>
#include <THStack.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TPolyLine.h>
#include <vector>
#include "Images.h"
#include "ImageSets.h"
/* #include "Marks.h" */
/* #include "OverlappedImages.h" */
/* #include "ReadAuxilaryData.h" */
/* #include "RetrieveImages.h" */
/* #include "RetrieveMarks.h" */
#include "SearchImages.h"
/* #include "SearchIncidenceAngles.h" */
/* #include "SearchMarks.h" */
/* #include "SortIncidenceAngles.h" */
#include "SortImages.h"
/* #include "SortMarks.h" */
/* #include "Utilities.h" */

class Plot
{
  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    /* static void CumulativeFrequency(); */
    /* static void DifferentIncidenceAngleStatistics(std::vector <OverlappedImages> &, std::vector <OverlappedImages> &);  */
    /* static void FractionalOverlap(std::vector <OverlappedImages> &, std::vector <OverlappedImages> &); */
    /* static void IncidenceAngleDistribution(std::vector <Images> &, std::vector <IncidenceAngles> &); */
    /* static void IncidenceAngleStatistics(double, double, int, std::vector <OverlappedImages> &, std::vector <Marks> &); */
    static void MasterImage(ImageSets, bool = true);
    /* static void MasterImages(ImageSets, ImageSets); */
    /* static void MasterImage_w_Craters(ImageSets, std::vector <Images> &, std::vector <Marks> &); */
    static void MasterImage_w_SubImages(ImageSets, std::vector <Images> &, bool = true);
    /* static void MasterImages_w_SubImages(ImageSets, ImageSets, std::vector <Images> &); */
    //static void PlotMasterImage(ImageSets);
    /* static void PlotOverlap(OverlappedImages, bool = false); */
    static void SubImage(Images, bool = true, bool = false);
    /* static void SubImages(Images, Images); */
    /* static void SubImage_w_craters(Images, std::vector <Marks> &); */
};

#endif
