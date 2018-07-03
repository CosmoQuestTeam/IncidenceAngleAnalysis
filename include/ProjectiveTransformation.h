/* HEADER FILE: ProjectiveTransformation.h */
/* Procedure outlined at https://math.stackexchange.com/questions/296794/finding-the-transform-matrix-from-4-projected-points-with-javascript/339033#339033 */

#ifndef PROJECTIVETRANSFORMATION_H
#define PROJECTIVETRANSFORMATION_H
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

class ProjectiveTransformation
{
  /**********************************/
  /* Declaration of class variables */
  /**********************************/
  private:
    std::vector <double> s_c_m{3}; // Source coefficient matrix
    std::vector <double> t_c_m{3}; // Target coefficient matrix
    std::vector < std::vector <double> > i_s_s_m{3}; // Inverted source scaling matrix
    std::vector < std::vector <double> > i_t_s_m{3}; // Inverted target scaling matrix
    std::vector < std::vector <double> > s_c{4}; // Source coordinates
    std::vector < std::vector <double> > s_s_m{3}; // Source scaling matrix
    std::vector < std::vector <double> > t_c{4}; // Target coordinates
    std::vector < std::vector <double> > t_s_m{3}; // Target scaling matrix
    std::vector < std::vector <double> > Transform_Source2Target_Matrix{3}; // Transform source coordinates to target coordinates matrix
    std::vector < std::vector <double> > Transform_Target2Source_Matrix{3}; // Transform target coordinates to source coordinates matrix
  
  /**********************************/
  /* Declaration of class functions */
  /**********************************/
  public:
    ProjectiveTransformation();
    ProjectiveTransformation(std::vector < std::vector <double> > &, std::vector < std::vector <double> > &);
    double ComputeMatrixDeterminant_3X3(std::vector < std::vector <double> > &);
    std::vector <double> ComputeCoefficientMatrix(std::vector < std::vector <double> > &);
    std::vector <double> ComputeSource2TargetCoordinates(double, double);
    std::vector <double> ComputeTarget2SourceCoordinates(double, double);
    std::vector < std::vector <double> > ComputeCofactorMatrix_3X3(std::vector < std::vector <double> > &);
    std::vector < std::vector <double> > ComputeInvertedMatrix_3X3(std::vector < std::vector <double> > &);
    std::vector < std::vector <double> > ComputeMinorMatrix_3X3(std::vector < std::vector <double> > &);
    std::vector < std::vector <double> > ComputeScalingMatrix(std::vector <double> &, std::vector < std::vector <double> > &);
    std::vector < std::vector <double> > ComputeTransposeMatrix_3X3(std::vector < std::vector <double> > &);
    std::vector < std::vector <double> > MultiplyMatricies(std::vector < std::vector <double> > &, std::vector < std::vector <double> > &);
    std::vector < std::vector <double> > ScaleMatrix(std::vector < std::vector <double> > &, double);
    void PrintInvertedSourceScalingMatrix();
    void PrintInvertedTargetScalingMatrix();
    void PrintSourceCoefficientMatrix();
    void PrintSourceCoordinates();
    void PrintSourceScalingMatrix();
    void PrintTargetCoefficientMatrix();
    void PrintTargetCoordinates();
    void PrintTargetScalingMatrix();
    void PrintTransformSource2TargetMatrix();
    void PrintTransformTarget2SourceMatrix();
};

#endif
