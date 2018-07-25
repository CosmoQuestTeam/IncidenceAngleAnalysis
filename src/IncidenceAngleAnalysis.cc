#include <stdlib.h>
#include <vector>

#include "Checkpoint.h"
#include "Images.h"
#include "ImageSets.h"
#include "IncidenceAngles.h"
#include "MySQLConnection.h"
#include "Marks.h"
#include "OverlappedImages.h"
#include "Plot.h"
#include "ReadAuxilaryData.h"
#include "RetrieveImages.h"
#include "RetrieveImageSets.h"
#include "RetrieveMarks.h"

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
  string datafile1;
  string datafile2;
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
  vector <Marks> marks;
  vector <OverlappedImages> different_incidence_angle_overlappedimages;
  vector <OverlappedImages> overlappedimages;
  //vector <OverlappedImages> TotalOverlapImages;
  vector <OverlappedImages> scale_0_different_incidence_angle_overlappedimages;
  //vector <string> UnmarkedImages;

  /***********************/
  /* Retrieve arguements */
  /***********************/
  if(argc == 2)
    auxilarydatafile = argv[1];
  else if(argc == 3)
  {
    datafile1 = argv[1];
    datafile2 = argv[2];
  }
  else
  {
    printf("Invalid number of arguements.\nUSAGE 1: %s [Auxilary datafile]\nUSAGE 2: %s [Reduced crater catalog file 1] [Reduced crater catalog file 2]\n", argv[0], argv[0]);
    exit(EXIT_FAILURE);
  }

  /*************************/
  /* Initialize checkpoint */
  /*************************/
  Checkpoint myCheckpoint;

  if(argc == 3)
  {
    /*************************************************/
    /* Cumulative Frequency versus Size Distribution */
    /*************************************************/
    Plot::CumulativeFrequencySizeDistribution(datafile1, datafile2);

    /**************/
    /* Checkpoint */
    /**************/
    buffer = "Elapsed time to plot cumulative frequency versus size distributions:";
    myCheckpoint.ElapsedTime(buffer);
    
    return 0;
  }
  
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
  
  /***********************************************************/
  /* Retrieve marks datatable from CosmoQuest MySQL database */
  /***********************************************************/
  table = "marks";
  field = "id, image_id, application_id, x, y, diameter";
  option = "";
  RetrieveMarks myMarks(conn, table, field, option);
  myMarks.Fetch();
  marks = myMarks.GetData();
  //RetrieveMarks::Display(marks); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to retrieve marks table from CosmoQuest mysql database:";
  myCheckpoint.ElapsedTime(buffer);

  /***********************************************/
  /* End connection to CosmoQuest MySQL database */
  /***********************************************/
  myConnection.Disconnect();

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to end connection to CosmoQuest mysql database:";
  myCheckpoint.ElapsedTime(buffer);

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
  buffer = "Elapsed time to execute imagesets auxilary function:";
  myCheckpoint.ElapsedTime(buffer);

  /*************************************/
  /* Execute images auxilary functions */
  /*************************************/
  Utilities::ExecuteImagesAuxilaryFunction(images, imagesets);
  //RetrieveImages::Display(images); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to execute images auxilary function:";
  myCheckpoint.ElapsedTime(buffer);

  /************************************/
  /* Execute marks auxilary functions */
  /************************************/
  Utilities::ExecuteMarksAuxilaryFunction(marks, images);
  //RetrieveMarks::Display(marks); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to execute marks auxilary function:";
  myCheckpoint.ElapsedTime(buffer);  

  /*************************************/
  /* Determine unique incidence angles */
  /*************************************/
  unique_incidenceangles = Utilities::RetrieveUniqueIncidenceAngles(incidenceangles);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to determine unique incidence angles:";
  myCheckpoint.ElapsedTime(buffer);

  /***********************************/
  /* Identify overlapping sub-images */
  /***********************************/
  overlappedimages = Utilities::FindOverlappingImages(images, incidenceangles);
  //OverlappedImages::Display(overlappedimages); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to identify overlapping images:";
  myCheckpoint.ElapsedTime(buffer);

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

  /********************************************************************/
  /* Identify overlapping sub-images with difference incidence angles */
  /********************************************************************/
  different_incidence_angle_overlappedimages = Utilities::FindDifferentIncidenceAngleOverlappingImages(overlappedimages);
  //OverlappedImages::Display(different_incidence_angle_overlappedimages); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to identify overlapping images with different incidence angles:";
  myCheckpoint.ElapsedTime(buffer);

  /****************************************************************************************/
  /* Identify overlapping sub-images with difference incidence angles at the same "scale" */
  /****************************************************************************************/
  scale_0_different_incidence_angle_overlappedimages = Utilities::FindSameScaleOverlappingImages(different_incidence_angle_overlappedimages, 0);
  //OverlappedImages::Display(scale_0_different_incidence_angle_overlappedimages); exit(0);

  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to identify overlapping images with different incidence angles that are at the same scale:";
  myCheckpoint.ElapsedTime(buffer);

  /************************************************************************************/
  /* Retrieve marks from overlapping regions for a pair of different incidence angles */
  /************************************************************************************/
  Utilities::PrintCraterCatalog(27.56, 58.21, incidenceangles, scale_0_different_incidence_angle_overlappedimages, marks, true);
  
  // Possible candidate 1: 27.56, 58.21
  // Possible candidate 2: 27.56, 82.82
  // Possible candidate 3: 27.56, 57.18
  // Possible candidate 4: 27.56, 59.46
  // Possible candidate 5: 27.56, 35.07
  
  /**************/
  /* Checkpoint */
  /**************/
  buffer = "Elapsed time to retrieve marks contained within wanted overlapping images:";
  myCheckpoint.ElapsedTime(buffer);
    
  return 0;
}
