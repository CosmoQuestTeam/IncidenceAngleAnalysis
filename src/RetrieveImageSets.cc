#include "RetrieveImageSets.h"

using namespace std;
using namespace sql;

RetrieveImageSets::RetrieveImageSets(Connection *CONN, string TABLE, string FIELD, string OPTION)
{
  /*******************************************************************/
  /* Retrieve needed information for database information extraction */
  /*******************************************************************/
  conn = CONN;
  table = TABLE;
  field = FIELD;
  option = OPTION;
}
    
vector <ImageSets> RetrieveImageSets::GetData()
{
  return data;
}

void RetrieveImageSets::Display(vector <ImageSets> &list)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int nelements;

  /********************/
  /* Print header row */
  /********************/
  printf("%-2s %-12s %-3s %8s %8s %8s %8s %8s %8s %8s %8s %-7s %4s %9s %9s\n", 
	 "ID",
	 "NAME",
	 "AID",
	 "ULLAT",
	 "ULLONG",
	 "URLAT", 
	 "URLONG",
	 "LRLAT",
	 "LRLONG",
	 "LLLAT", 
	 "LLLONG",
	 "DETAILS", 
	 "PR",
	 "ULXSTATUS", 
	 "ULYSTATUS");
  
  /********************/
  /* Print data rows */
  /********************/
  nelements = (int)list.size();
  for(int i=0; i<nelements; i++)
    printf("%-2d %-12s %-3d %8.4lf %8.4lf %8.4lf %8.4lf %8.4lf %8.4lf %8.4lf %8.4lf %-7.7s %4.2lf %9s %9s\n", 
	   list[i].GetId(), 
	   list[i].GetName().c_str(), 
	   list[i].GetApplication_id(), 
	   list[i].GetUpper_left_latitude(), 
	   list[i].GetUpper_left_longitude(), 
	   list[i].GetUpper_right_latitude(), 
	   list[i].GetUpper_right_longitude(),
	   list[i].GetLower_right_latitude(), 
	   list[i].GetLower_right_longitude(), 
	   list[i].GetLower_left_latitude(), 
	   list[i].GetLower_left_longitude(),
	   list[i].GetDetails().c_str(),
	   list[i].GetPixel_resolution(), 
	   list[i].GetUpper_left_corner_x_status().c_str(), 
	   list[i].GetUpper_left_corner_y_status().c_str());

  return;
}

void RetrieveImageSets::Fetch()
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int columnsNumber;
  PreparedStatement *pst;
  ResultSet *rs;
  ResultSetMetaData *rsmd;
  string query;

  try
  {
    /************************/
    /* Define SQL selection */
    /************************/
    query = "SELECT " + field + " FROM " + table + option;

    /********************/
    /* Create Statement */
    /********************/
    pst = conn->prepareStatement(query.c_str());
      
    /***************************/
    /* Execute selection query */
    /***************************/
    rs = pst->executeQuery();
    
    /*****************/
    /* Retrieve data */
    /*****************/
    rsmd = rs->getMetaData();
    columnsNumber = rsmd->getColumnCount();
    while(rs->next())
    {
      int application_id = rs->getInt("application_id");
      if(application_id == 1)
      {
	ImageSets myImageSet(rs->getInt("id"), rs->getString("name"), application_id, 0, 0, rs->getDouble("upper_left_latitude"), rs->getDouble("upper_left_longitude"), rs->getDouble("upper_right_latitude"), rs->getDouble("upper_right_longitude"), rs->getDouble("lower_right_latitude"), rs->getDouble("lower_right_longitude"), rs->getDouble("lower_left_latitude"), rs->getDouble("lower_left_longitude"), rs->getDouble("pixel_resolution"), "", rs->getString("details"), "", "");
	data.push_back(myImageSet);
      }
    }
  }
  catch(SQLException &e)
  {
    printf("%s\n", e.what());
    exit(EXIT_FAILURE);
  }

  /*********************/
  /* Deallocate memory */
  /*********************/
  if(rs != NULL)
  {
    try
    {
      rs->close();
      rs = NULL;
    }
    catch(SQLException &e)
    {
      printf("%s\n", e.what());
      exit(EXIT_FAILURE);
    }
  }
  if(pst != NULL)
  {
    try
    {
      pst->close();
      pst = NULL;
    }
    catch(SQLException &e)
    {
      printf("%s\n", e.what());
      exit(EXIT_FAILURE);
    }
  }

  return;
}
