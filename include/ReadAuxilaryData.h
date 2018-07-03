/* HEADER FILE: ReadAuxilaryData.h */

#ifndef READAUXILARYDATA_H
#define READAUXILARYDATA_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "IncidenceAngles.h"
#include "Utilities.h"

class ReadAuxilaryData
{
  /**********************************/
  /* Declaration of class variables */
  /**********************************/
  private:
    std::string AuxilaryDataFile;
    std::vector <IncidenceAngles> incidenceangledata;

  /***********************************/
  /* Declaration of class functions */
  /***********************************/
  public:
    ReadAuxilaryData(std::string);
    std::vector <IncidenceAngles> GetIncidenceAngleData();
    void Read();
    static void Display(std::vector <IncidenceAngles> &);
};

#endif
