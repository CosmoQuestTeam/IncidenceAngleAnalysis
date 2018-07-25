#include "RetrieveImages.h"

using namespace std;
using namespace sql;

RetrieveImages::RetrieveImages(Connection *CONN, string TABLE, string FIELD, string OPTION)
{
  /*******************************************************************/
  /* Retrieve needed information for database information extraction */
  /*******************************************************************/
  conn = CONN;
  table = TABLE;
  field = FIELD;
  option = OPTION;
}
    
vector <Images> RetrieveImages::GetData()
{
  return data;
}

void RetrieveImages::Display(vector <Images> &list)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int nelements;

  /********************/
  /* Print header row */
  /********************/
  printf("%-5s %-4s %-3s %-19s %11s %11s %11s %11s %11s %11s %11s %11s\n", 
	 "ID", 
	 "ISID", 
	 "AID", 
	 "NAME",
	 "ULX",
	 "ULY",
	 "URX",
	 "URY",
	 "LRX",
	 "LRY",
	 "LLX",
	 "LLY");
  
  /********************/
  /* Print data rows */
  /********************/
  nelements = (int)list.size();
  for(int i=0; i<nelements; i++)
    printf("%-5d %-4d %-3d %-19s %11.2lf %11.2lf %11.2lf %11.2lf %11.2lf %11.2lf %11.2lf %11.2lf\n", 
	   list[i].GetId(), 
	   list[i].GetImage_set_id(), 
	   list[i].GetApplication_id(), 
	   list[i].GetName().c_str(), 
	   list[i].GetUpper_left_x(), 
	   list[i].GetUpper_left_y(),
	   list[i].GetUpper_right_x(), 
	   list[i].GetUpper_right_y(),
	   list[i].GetLower_right_x(), 
	   list[i].GetLower_right_y(),
	   list[i].GetLower_left_x(), 
	   list[i].GetLower_left_y());

  return;
}

void RetrieveImages::Fetch()
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

    /*********************/
    /* Prepare Statement */
    /*********************/
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
	Images myImage(rs->getInt("id"), rs->getInt("image_set_id"), application_id, rs->getString("name"), "", 0, 0, 0, 0, rs->getString("details"), "", "");
	data.push_back(myImage);
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

