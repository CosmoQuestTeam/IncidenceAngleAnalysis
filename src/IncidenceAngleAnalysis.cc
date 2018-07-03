#include <stdlib.h>
#include <vector>

#include "Checkpoint.h"
#include "Images.h"
#include "ImageSets.h"
#include "IncidenceAngles.h"
#include "MySQLConnection.h"
#include "OverlappedImages.h"
#include "Plot.h"
#include "ReadAuxilaryData.h"
#include "RetrieveImages.h"
#include "RetrieveImageSets.h"

using namespace sql;
using namespace std;

int main(int argc, char *argv[])
{
  /*******************************************/
  /* Declaration/Initialization of variables */
  /*******************************************/
  Connection *conn;
  string auxilarydatafile;
  string buffer;
  string database;
  string field;
  string password;
  string option;
  string rejectedimage;
  string table;
  string url;
  string user;
  vector <double> unique_incidenceangles;
  vector <Images> images;
  vector <ImageSets> imagesets;
  vector <IncidenceAngles> incidenceangles;
  //vector <Marks> marks;
  //vector <MasterImageOrientation> masterimageorientations;
  //vector <OverlappedImages> DIATotalOverlapImages;
  //vector <OverlappedImages> overlappedimages;
  //vector <OverlappedImages> TotalOverlapImages;
  //vector <OverlappedImages> SSDIATotalOverlapImages;
  //vector <PixelResolution> pixelresolutions;
  //vector <string> UnmarkedImages;

  /***********************/
  /* Retrieve arguements */
  /***********************/
  if(argc != 2)
  {
    printf("Invalid number of arguements. USAGE: %s [Auxilary datafile]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  auxilarydatafile = argv[1];

  /*************************/
  /* Initialize checkpoint */
  /*************************/
  Checkpoint myCheckpoint;

  /*********************************/
  /* Parameters for MySQL database */
  /*********************************/
  url = "tcp://localhost:3306";
  user = "root";
  password = "00000000";
  database = "cosmoquest_matts_version";
  //database = "cosmoquest_original";
  
  /*****************************************************/
  /* Establish connection to CosmoQuest MySQL database */
  /*****************************************************/
  MySQLConnection myConnection(url, user, password, database);
  myConnection.Connect();
  conn = myConnection.GetConnection();

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to establish connection to CosmoQuest mysql database:";
  myCheckpoint.ElapsedTime(buffer);

  /************************************************/
  /* Test connection to CosmoQuest MySQL database */
  /************************************************/
  //myConnection.TestConnection();

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to test connection to CosmoQuest mysql database:";
  //myCheckpoint.ElapsedTime(buffer);

  /****************************************************************/
  /* Retrieve image_sets datatable from CosmoQuest MySQL database */
  /****************************************************************/
  table = "image_sets";
  field = "id, name, application_id, upper_left_latitude, upper_left_longitude, upper_right_latitude, upper_right_longitude, lower_right_latitude, lower_right_longitude, lower_left_latitude, lower_left_longitude, pixel_resolution, details";
  RetrieveImageSets myImageSets(conn, table, field, option);
  myImageSets.Fetch();
  imagesets = myImageSets.GetData();
  //RetrieveImageSets::Display(imagesets); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to retrieve image_sets table from CosmoQuest mysql database:";
  myCheckpoint.ElapsedTime(buffer);

  /************************************************************/
  /* Retrieve images datatable from CosmoQuest MySQL database */
  /************************************************************/
  table = "images";
  field = "id, image_set_id, application_id, name, details";
  RetrieveImages myImages(conn, table, field, option);
  myImages.Fetch();
  images = myImages.GetData();
  //RetrieveImages::Display(images); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to retrieve images table from CosmoQuest mysql database:";
  myCheckpoint.ElapsedTime(buffer);
  
  // /***********************************************************/
  // /* Retrieve marks datatable from CosmoQuest MySQL database */
  // /***********************************************************/
  // table = "marks";
  // field = "id, image_id, application_id, x, y, diameter";
  // option = "";
  // RetrieveMarks myMarks(conn, table, field, option);
  // myMarks.Fetch();
  // marks = myMarks.GetData();
  // //RetrieveMarks::Display(marks); exit(0);

  // /**************/
  // /* Checkpoint */
  // /**************/
  // buffer = "Elapsed time to retrieve marks table from CosmoQuest mysql database:";
  // myCheckpoint.ElapsedTime(buffer);

  // /***********************************************/
  // /* End connection to CosmoQuest MySQL database */
  // /***********************************************/
  // myConnection.Disconnect();

  // /**************/
  // /* Checkpoint */
  // /**************/
  // buffer = "Elapsed time to end connection to CosmoQuest mysql database:";
  // myCheckpoint.ElapsedTime(buffer);

  /******************************************************/
  /* Retrieve auxilary data from user supplied datafile */
  /******************************************************/
  ReadAuxilaryData myAuxilarydata(auxilarydatafile);
  myAuxilarydata.Read();
  incidenceangles = myAuxilarydata.GetIncidenceAngleData();
  //ReadAuxilaryData::Display(incidenceangles); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to retrieve auxilary data:";
  myCheckpoint.ElapsedTime(buffer);

  /****************************************/
  /* Execute imagesets auxilary functions */
  /****************************************/
  Utilities::ExecuteImageSetsAuxilaryFunction(imagesets);
  //RetrieveImageSets::Display(imagesets); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to execute imagesets auxilary functions:";
  myCheckpoint.ElapsedTime(buffer);

  /*************************************/
  /* Execute images auxilary functions */
  /*************************************/
  Utilities::ExecuteImagesAuxilaryFunction(images, imagesets);
  //RetrieveImages::Display(images); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to execute images auxilary functions:";
  myCheckpoint.ElapsedTime(buffer);

  /*******************/
  /* Sanity Checking */
  /*******************/
  int wanted_index = 0;
  Plot::MasterImage(imagesets[0]);
  Plot::MasterImage_w_SubImages(imagesets[0], images);
  for(int i=0; i<(int)images.size(); i++)
    if(images[i].GetName().compare("M109215691LE_0_9") == 0)
    {
      Plot::SubImage(images[i], true, true);
      wanted_index = i;
      break;
    }
  double wanted_x = images[wanted_index].GetX_relative();
  double wanted_y = images[wanted_index].GetY_relative();
  double wanted_width = images[wanted_index].GetWidth();
  double wanted_height = images[wanted_index].GetHeight();
  printf("Corner 1: %lf pixels in x and %lf pixels in y\n", wanted_x, wanted_y);
  printf("Corner 2: %lf pixels in x and %lf pixels in y\n", wanted_x+wanted_width, wanted_y);
  printf("Corner 3: %lf pixels in x and %lf pixels in y\n", wanted_x+wanted_width, wanted_y+wanted_height);
  printf("Corner 4: %lf pixels in x and %lf pixels in y\n", wanted_x, wanted_y+wanted_height);
  
  ProjectiveTransformation wanted_pt = images[wanted_index].GetProjective_transformation();
  vector <double> wanted_coords(2);
  //wanted_pt.PrintSourceCoordinates();
  //wanted_pt.PrintTargetCoordinates(); exit(0);
  wanted_coords = wanted_pt.ComputeTarget2SourceCoordinates(wanted_x, wanted_y);
  printf("Corner 1: %lf degrees longitude and %lf degrees latitude\n", wanted_coords[0], wanted_coords[1]);
  wanted_coords = wanted_pt.ComputeTarget2SourceCoordinates(wanted_x+wanted_width, wanted_y);
  printf("Corner 2: %lf degrees longitude and %lf degrees latitude\n", wanted_coords[0], wanted_coords[1]);
  wanted_coords = wanted_pt.ComputeTarget2SourceCoordinates(wanted_x+wanted_width, wanted_y+wanted_height);
  printf("Corner 3: %lf degrees longitude and %lf degrees latitude\n", wanted_coords[0], wanted_coords[1]);
  wanted_coords = wanted_pt.ComputeTarget2SourceCoordinates(wanted_x, wanted_y+wanted_height);
  printf("Corner 4: %lf degrees longitude and %lf degrees latitude\n", wanted_coords[0], wanted_coords[1]);
  // // for(int i=0; i<(int)imagesets.size(); i++)
  // // {
  // //   cout << i << " " << imagesets[i].GetName() << endl;
  // // } exit(0);
  // //Plot::MasterImage_w_Craters(imagesets[1], images, marks);
  // //Plot::MasterImage_w_Craters(imagesets[6], images, marks);
  // //exit(0);
  // //cout << imagesets[7].GetName() << " " << imagesets[8].GetName() << endl; exit(0);
  // Plot::MasterImages(imagesets[7], imagesets[8]); exit(0);
  // Plot::MasterImage_w_SubImages(imagesets[7], images); exit(0);
  // Plot::MasterImage_w_SubImages(imagesets[8], images); exit(0);
  // // for(int i=0; i<(int)imagesets.size(); i++)
  // //   Plot::MasterImage_w_SubImages(imagesets[i], images);
  // // for(int i=0; i<(int)images.size(); i++)
  // //   Plot::SubImage_w_craters(images[i], marks);
  // // int index1 = -1;
  // // int index2 = -1;
  // // for(int i=0; i<(int)images.size(); i++)
  // // {
  // //   if(images[i].GetName().compare("M115008450LE_0_540") == 0)
  // //     index1 = i;
  // //   if(images[i].GetName().compare("M138602853LE_0_1694") == 0)
  // //     index2 = i;
  // //   if((index1 != -1) && (index2 != -1))
  // // 	  break;
  // // }
  // // Plot::SubImages(images[index1], images[index2]); exit(0);

  // /**************/
  // /* Checkpoint */
  // /**************/
  // buffer = "Elapsed time to perform sanity check:";
  // myCheckpoint.ElapsedTime(buffer);

  /*************************************/
  /* Determine unique incidence angles */
  /*************************************/
  // unique_incidenceangles = Utilities::RetrieveUniqueIncidenceAngles(incidenceangles);

  /**************/
  /* Checkpoint */
  /**************/
  // buffer = "Elapsed time to determine unique incidence angles:";
  // myCheckpoint.ElapsedTime(buffer);

  /***********************************/
  /* Identify overlapping sub-images */
  /***********************************/
  // overlappedimages = Utilities::FindOverlappingImages(images, incidenceangles, masterimageorientations);
  //OverlappedImages::Display(overlappedimages); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  // buffer = "Elapsed time to identify overlapping images:";
  // myCheckpoint.ElapsedTime(buffer);

  // /*****************************************/
  // /* Identify total overlapping sub-images */
  // /*****************************************/
  // TotalOverlapImages = Utilities::FindTotalOverlappingImages(overlappedimages);
  // //OverlappedImages::Display(TotalOverlapImages); exit(0);

  // /**************/
  // /* Checkpoint */
  // /**************/
  // buffer = "Elapsed time to identify all total overlapped images:";
  // myCheckpoint.ElapsedTime(buffer);

  // /**************************************************************************/
  // /* Identify total overlapping sub-images with difference incidence angles */
  // /**************************************************************************/
  // DIATotalOverlapImages = Utilities::FindDifferentIncidenceAngleOverlappingImages(TotalOverlapImages);
  // //OverlappedImages::Display(DIATotalOverlapImages); exit(0);

  // /**************/
  // /* Checkpoint */
  // /**************/
  // buffer = "Elapsed time to identify total overlapping images with different incidence angles:";
  // myCheckpoint.ElapsedTime(buffer);

  // /**********************************************************************************************/
  // /* Identify total overlapping sub-images with difference incidence angles at the same "scale" */
  // /**********************************************************************************************/
  // SSDIATotalOverlapImages = Utilities::FindSameScaleOverlappingImages(DIATotalOverlapImages, 0);
  // //OverlappedImages::Display(SSDIATotalOverlapImages); exit(0);

  // /**************/
  // /* Checkpoint */
  // /**************/
  // buffer = "Elapsed time to identify total overlapping images with different incidence angles that are at the same scale:";
  // myCheckpoint.ElapsedTime(buffer);

  // /***************************************************************************************/
  // /* Sanity check (Checking to see if algorithm is correctly identifying overlap region) */
  // /***************************************************************************************/
  // int myindex = 0;
  // Plot::PlotOverlap(SSDIATotalOverlapImages[myindex]);
  // OverlappedImages::Display(SSDIATotalOverlapImages[myindex]); exit(0);

  // /********************************************/
  // /* Plotting algorithm still in construction */
  // /********************************************/
  // //Plot::IncidenceAngleStatistics(82.82, 76.48, 0, SameScaleOverlapImages, marks);

  // /**************/
  // /* Checkpoint */
  // /**************/
  // // buffer = "Elapsed time to make most important plot:";
  // // myCheckpoint.ElapsedTime(buffer);

  // /********************************************************/
  // /* Print all marks associated with a specific incidence */
  // /* angle to screen or to file (crater catalog creation) */
  // /********************************************************/
  // //Utilities::PrintNACMarks(76.48, 0, incidenceangles, imagesets, images, marks, true);

  // /**************/
  // /* Checkpoint */
  // /**************/
  // buffer = "Elapsed time to retrieve marks for at a specific incidence angle:";
  // //myCheckpoint.ElapsedTime(buffer);

  return 0;
}
