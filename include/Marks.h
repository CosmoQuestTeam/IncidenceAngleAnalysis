/* HEADER FILE: Marks.h */

#ifndef MARKS_H
#define MARKS_H
#include <string>
#include <vector>

class Marks
{
  /***********************************/
  /* Declaration of class variables */
  /***********************************/
  private:
    double diameter;
    double latitude;
    double longitude;
    double physical_diameter;
    double physical_x;
    double physical_y;
    double score;
    double x;
    double x_adjusted;
    double y;
    double y_adjusted;
    int application_id;
    int confirmed;
    int id;
    int image_id;
    int image_user_id;
    int machine_mark_id;
    int shared_mark_id;
    int submit_time;
    int user_id;
    std::string created_at;
    std::string details;
    std::string sub_type;
    std::string type;
    std::string updated_at;

  /************************************/
  /* Declaration of class functions */
  /************************************/
  public:
    Marks(int, int, int, int, int, int, int, double, double, double, int, int, double, std::string, std::string, std::string, std::string, std::string);
    double GetDiameter();
    double GetLatitude();
    double GetLongitude();
    double GetPhysical_diameter();
    double GetPhysical_x();
    double GetPhysical_y();
    double GetScore();
    double GetX();
    double GetX_adjusted();
    double GetY();
    double GetY_adjusted();
    int GetApplication_id();
    int GetConfirmed();
    int GetId();
    int GetImage_id();
    int GetImage_user_id();
    int GetMachine_mark_id();
    int GetShared_mark_id();
    int GetSubmit_time();
    int GetUser_id();
    std::string GetCreated_at();
    std::string GetDetails();
    std::string GetSub_type();
    std::string GetType();
    std::string GetUpdated_at();
    void AuxilaryFunction(std::vector <double> &, std::vector <double> &, std::vector <double> &, double);
    void * GetValue(std::string);
    void SetX(double);
    void SetY(double);
};

#endif
