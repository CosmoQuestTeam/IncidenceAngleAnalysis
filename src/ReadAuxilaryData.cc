#include "ReadAuxilaryData.h"

using namespace std;

ReadAuxilaryData::ReadAuxilaryData(string AUXILARYDATAFILE)
{
  /*********************/
  /* Retrieve filename */
  /*********************/
  AuxilaryDataFile = AUXILARYDATAFILE;
}

vector <IncidenceAngles> ReadAuxilaryData::GetIncidenceAngleData()
{
  return incidenceangledata;
}

void ReadAuxilaryData::Display(vector <IncidenceAngles> &list)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  int nelements;

  /********************/
  /* Print header row */
  /********************/
  printf("%-12s %-15s\n", "NAME", "Incidence_Angle");
  
  /********************/
  /* Print data rows */
  /********************/
  nelements = (int)list.size();
  for(int i=0; i<nelements; i++)
    printf("%-12s %-15.2lf\n", list[i].GetName().c_str(), list[i].GetIncidence_angle());

  return;
}

void ReadAuxilaryData::Read()
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  ifstream InFile;
  string buffer;
  string format;

  /*****************/
  /* Retrieve file */
  /*****************/
  if(Utilities::FileExists(AuxilaryDataFile))
    InFile.open(AuxilaryDataFile.c_str());
  else
  {
    printf("Error in function ReadAuxilaryData::Read(): File %s does not exist! Now terminating simulation ...\n", AuxilaryDataFile.c_str());
    exit(EXIT_FAILURE);
  }

  /*********************/
  /* Read-in data file */
  /*********************/
  format = "%s %lf";
  while(getline(InFile, buffer))
  {
    char str[250];
    double d1;
    int nelements = sscanf(buffer.c_str(), format.c_str(), str, &d1);
    if(nelements == 2)
    { 
      IncidenceAngles myDatapoint1(static_cast<string>(str), d1);
      incidenceangledata.push_back(myDatapoint1);
    }
  }
  InFile.close();
}
