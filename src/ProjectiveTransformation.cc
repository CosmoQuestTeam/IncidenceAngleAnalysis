#include "ProjectiveTransformation.h"

using namespace std;

ProjectiveTransformation::ProjectiveTransformation()
{
}

ProjectiveTransformation::ProjectiveTransformation(std::vector < std::vector <double> > &SOURCECOORDINATES, vector < vector <double> > &TARGETCOORDINATES)
{
  /***********************/
  /* Retrieve coorinates */
  /***********************/
  s_c = SOURCECOORDINATES;
  t_c = TARGETCOORDINATES;

  /*********************************************/
  /* Step 1: Compute source coefficient matrix */
  /*********************************************/
  s_c_m = ComputeCoefficientMatrix(s_c);
  
  /*****************************************/
  /* Step 2: Compute source scaling matrix */
  /*****************************************/
  s_s_m = ComputeScalingMatrix(s_c_m, s_c);
  
  /*********************************************/
  /* Step 3: Compute target coefficient matrix */
  /*********************************************/
  t_c_m = ComputeCoefficientMatrix(t_c);
  
  /*****************************************/
  /* Step 4: Compute target scaling matrix */
  /*****************************************/
  t_s_m = ComputeScalingMatrix(t_c_m, t_c);
  
  /************************************************************/
  /* Step 5: Compute the inverse of the source scaling matrix */
  /************************************************************/
  i_s_s_m = ComputeInvertedMatrix_3X3(s_s_m);

  /************************************************************/
  /* Step 6: Compute the inverse of the targer scaling matrix */
  /************************************************************/
  i_t_s_m = ComputeInvertedMatrix_3X3(t_s_m);
  
  /************************************************************************************/
  /* Step 7: Multiply the target scaling matrix by the inverted source scaling matrix */
  /************************************************************************************/
  Transform_Source2Target_Matrix = MultiplyMatricies(t_s_m, i_s_s_m);

  /************************************************************************************/
  /* Step 8: Multiply the source scaling matrix by the inverted target scaling matrix */
  /************************************************************************************/
  Transform_Target2Source_Matrix = MultiplyMatricies(s_s_m, i_t_s_m);
}

double ProjectiveTransformation::ComputeMatrixDeterminant_3X3(std::vector < std::vector <double> > &A)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double Det;
  double t1;
  double t2;
  double t3;

  /***********************/
  /* Compute determinant */
  /***********************/
  t1 = A[0][0]*((A[1][1])*(A[2][2])-(A[1][2])*(A[2][1]));
  t2 = A[0][1]*((A[1][0])*(A[2][2])-(A[1][2])*(A[2][0]));
  t3 = A[0][2]*((A[1][0])*(A[2][1])-(A[1][1])*(A[2][0]));
  Det = t1-t2+t3;
  
  return Det;
}

double ProjectiveTransformation::ComputeSource2TargetCoordinate_x(double x, double y)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double coordinate;
  vector <double> h_c(2); 

  /***************************************/
  /* Compute the homogenous x coordinate */
  /***************************************/
  h_c[0] = Transform_Source2Target_Matrix[0][0]*x + Transform_Source2Target_Matrix[0][1]*y + Transform_Source2Target_Matrix[0][2];
  h_c[1] = Transform_Source2Target_Matrix[2][0]*x + Transform_Source2Target_Matrix[2][1]*y + Transform_Source2Target_Matrix[2][2];
  
  /******************************/
  /* Compute target coordinates */
  /******************************/
  coordinate = h_c[0]/h_c[1];
  
  return coordinate;
}

double ProjectiveTransformation::ComputeSource2TargetCoordinate_y(double x, double y)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double coordinate;
  vector <double> h_c(2); 

  /***************************************/
  /* Compute the homogenous x coordinate */
  /***************************************/
  h_c[0] = Transform_Source2Target_Matrix[1][0]*x + Transform_Source2Target_Matrix[1][1]*y + Transform_Source2Target_Matrix[1][2];
  h_c[1] = Transform_Source2Target_Matrix[2][0]*x + Transform_Source2Target_Matrix[2][1]*y + Transform_Source2Target_Matrix[2][2];
  
  /******************************/
  /* Compute target coordinates */
  /******************************/
  coordinate = h_c[0]/h_c[1];
  
  return coordinate;
}

double ProjectiveTransformation::ComputeTarget2SourceCoordinate_x(double x, double y)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double coordinate;
  vector <double> h_c(2); 

  /***************************************/
  /* Compute the homogenous x coordinate */
  /***************************************/
  h_c[0] = Transform_Target2Source_Matrix[0][0]*x + Transform_Target2Source_Matrix[0][1]*y + Transform_Target2Source_Matrix[0][2];
  h_c[1] = Transform_Target2Source_Matrix[2][0]*x + Transform_Target2Source_Matrix[2][1]*y + Transform_Target2Source_Matrix[2][2];
  
  /******************************/
  /* Compute target coordinates */
  /******************************/
  coordinate = h_c[0]/h_c[1];
  
  return coordinate;
}

double ProjectiveTransformation::ComputeTarget2SourceCoordinate_y(double x, double y)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double coordinate;
  vector <double> h_c(2); 

  /***************************************/
  /* Compute the homogenous x coordinate */
  /***************************************/
  h_c[0] = Transform_Target2Source_Matrix[1][0]*x + Transform_Target2Source_Matrix[1][1]*y + Transform_Target2Source_Matrix[1][2];
  h_c[1] = Transform_Target2Source_Matrix[2][0]*x + Transform_Target2Source_Matrix[2][1]*y + Transform_Target2Source_Matrix[2][2];
  
  /******************************/
  /* Compute target coordinates */
  /******************************/
  coordinate = h_c[0]/h_c[1];
  
  return coordinate;
}

vector <double> ProjectiveTransformation::ComputeCoefficientMatrix(vector < vector <double> > &A)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double c1;
  double c2;
  double c3;
  double denominator;
  double numerator;
  vector <double> C(3);
  
  /*****************************/
  /* Compute third coefficient */
  /*****************************/
  numerator = (A[3][1]-A[0][1])*(A[1][0]-A[0][0])+(A[0][0]-A[3][0])*(A[1][1]-A[0][1]);
  denominator = (A[0][0]-A[2][0])*(A[1][1]-A[0][1])+(A[0][1]-A[2][1])*(A[0][0]-A[1][0]);
  c3 = numerator/denominator;
  
  /******************************/
  /* Compute second coefficient */
  /******************************/
  numerator = c3*(A[0][0]-A[2][0])+(A[3][0]-A[0][0]);
  denominator = (A[1][0]-A[0][0]);
  c2 = numerator/denominator;
  
  /*****************************/
  /* Compute first coefficient */
  /*****************************/
  c1 = 1-c2-c3;
  
  /*****************/
  /* Store results */
  /*****************/
  C[0] = c1;
  C[1] = c2;
  C[2] = c3;

  return C;
}

vector <double> ProjectiveTransformation::ComputeSource2TargetCoordinates(double x, double y)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector <double> h_c(3);
  vector <double> coordinates(2);

  /**************************************/
  /* Compute the homogenous coordinates */
  /**************************************/
  h_c[0] = Transform_Source2Target_Matrix[0][0]*x + Transform_Source2Target_Matrix[0][1]*y + Transform_Source2Target_Matrix[0][2];
  h_c[1] = Transform_Source2Target_Matrix[1][0]*x + Transform_Source2Target_Matrix[1][1]*y + Transform_Source2Target_Matrix[1][2];
  h_c[2] = Transform_Source2Target_Matrix[2][0]*x + Transform_Source2Target_Matrix[2][1]*y + Transform_Source2Target_Matrix[2][2];
  
  /******************************/
  /* Compute target coordinates */
  /******************************/
  coordinates[0] = h_c[0]/h_c[2];
  coordinates[1] = h_c[1]/h_c[2];
  
  return coordinates;
}

vector <double> ProjectiveTransformation::ComputeTarget2SourceCoordinates(double x, double y)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector <double> h_c(3);
  vector <double> coordinates(2);

  /**************************************/
  /* Compute the homogenous coordinates */
  /**************************************/
  h_c[0] = Transform_Target2Source_Matrix[0][0]*x + Transform_Target2Source_Matrix[0][1]*y + Transform_Target2Source_Matrix[0][2];
  h_c[1] = Transform_Target2Source_Matrix[1][0]*x + Transform_Target2Source_Matrix[1][1]*y + Transform_Target2Source_Matrix[1][2];
  h_c[2] = Transform_Target2Source_Matrix[2][0]*x + Transform_Target2Source_Matrix[2][1]*y + Transform_Target2Source_Matrix[2][2];
  
  /******************************/
  /* Compute target coordinates */
  /******************************/
  coordinates[0] = h_c[0]/h_c[2];
  coordinates[1] = h_c[1]/h_c[2];
  
  return coordinates;
}

vector < vector <double> > ProjectiveTransformation::ComputeCofactorMatrix_3X3(vector < vector <double> > &A)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector < vector <double> > C(3, vector <double>(3));

  /*****************************/
  /* Calculate cofactor matrix */
  /*****************************/
  C[0][0] = A[0][0];
  C[0][1] = -1*A[0][1];
  C[0][2] = A[0][2];
  C[1][0] = -1*A[1][0];
  C[1][1] = A[1][1];
  C[1][2] = -1*A[1][2];
  C[2][0] = A[2][0];
  C[2][1] = -1*A[2][1];
  C[2][2] = A[2][2];

  return C;
}

vector < vector <double> > ProjectiveTransformation::ComputeInvertedMatrix_3X3(vector < vector <double> > &A)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double Det;
  vector < vector <double> > C(3, vector <double>(3));
  vector < vector <double> > I(3, vector <double>(3));
  vector < vector <double> > M(3, vector <double>(3));
  vector < vector <double> > T(3, vector <double>(3));
  
  /******************************/
  /* Calculate matrix of minors */
  /******************************/
  M = ComputeMinorMatrix_3X3(A);
  
  /*********************************/
  /* Calculate matrix of cofactors */
  /*********************************/
  C = ComputeCofactorMatrix_3X3(M);
  
  /****************************/
  /* Calculate adjoint matrix */
  /****************************/
  T = ComputeTransposeMatrix_3X3(C);
  
  /*************************************/
  /* Calculate determinant of matrix A */
  /*************************************/
  Det = ComputeMatrixDeterminant_3X3(A);
  
  /**********************************/
  /* Inverted source scaling matrix */
  /**********************************/
  I = ScaleMatrix(T, Det);

  return I;
}

vector < vector <double> > ProjectiveTransformation::ComputeMinorMatrix_3X3(vector < vector <double> > &A)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector < vector <double> > M(3, vector <double>(3));

  /******************************/
  /* Calculate matrix of minors */
  /******************************/
  M[0][0] = (A[1][1])*(A[2][2])-(A[1][2])*(A[2][1]);
  M[0][1] = (A[1][0])*(A[2][2])-(A[1][2])*(A[2][0]);
  M[0][2] = (A[1][0])*(A[2][1])-(A[1][1])*(A[2][0]);
  M[1][0] = (A[0][1])*(A[2][2])-(A[0][2])*(A[2][1]);
  M[1][1] = (A[0][0])*(A[2][2])-(A[0][2])*(A[2][0]);
  M[1][2] = (A[0][0])*(A[2][1])-(A[0][1])*(A[2][0]);
  M[2][0] = (A[0][1])*(A[1][2])-(A[0][2])*(A[1][1]);
  M[2][1] = (A[0][0])*(A[1][2])-(A[0][2])*(A[1][0]);
  M[2][2] = (A[0][0])*(A[1][1])-(A[0][1])*(A[1][0]);

  return M;
}

vector < vector <double> > ProjectiveTransformation::ComputeTransposeMatrix_3X3(vector < vector <double> > &A)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector < vector <double> > T(3, vector <double>(3));

  /****************************/
  /* Calculate adjoint matrix */
  /****************************/
  T[0][0] = A[0][0];
  T[0][1] = A[1][0];
  T[0][2] = A[2][0];
  T[1][0] = A[0][1];
  T[1][1] = A[1][1];
  T[1][2] = A[2][1];
  T[2][0] = A[0][2];
  T[2][1] = A[1][2];
  T[2][2] = A[2][2];

  return T;
}

vector < vector <double> > ProjectiveTransformation::ScaleMatrix(vector < vector <double> > &A, double scalefactor)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector < vector <double> > B(3, vector <double>(3));

  /************************************************************/
  /* Scale elements of matrix A and store results in matrix B */
  /************************************************************/
  for(int i=0; i<(int)A.size(); i++)
    for(int j=0; j<(int)A[i].size(); j++)
      B[i][j] = scalefactor*A[i][j];

  return B;
}

vector < vector <double> > ProjectiveTransformation::MultiplyMatricies(vector < vector <double> > &A, vector < vector <double> > &B)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  int c1;
  int c2;
  int r1;
  
  /********************************************/
  /* Retrieve dimensions of matricies A and B */
  /********************************************/
  r1 = static_cast<int>(A.size());
  c1 = static_cast<int>(A[0].size());
  c2 = static_cast<int>(B[0].size());

  /******************************************************************/
  /* Reserve and initialize appropriate amount of space in matrix C */
  /******************************************************************/
  vector < vector <double> > C(r1, vector <double> (c2, 0.0));
  
  /******************************/
  /* Compute the product C = AB */
  /******************************/
  for(int i=0; i<r1; i++)
    for(int j=0; j<c2; j++)
      for(int k=0; k<c1; k++)
	C[i][j] += A[i][k]*B[k][j];

  return C;
}

vector < vector <double> > ProjectiveTransformation::ComputeScalingMatrix(vector <double> &A, vector < vector <double> > &B)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  vector < vector <double> > SM(3, vector <double> (3));
  
  /**************************************/
  /* Compute elements of scaling matrix */
  /**************************************/
  SM[0][0] = A[0]*B[0][0];
  SM[0][1] = A[1]*B[1][0];
  SM[0][2] = A[2]*B[2][0];
  SM[1][0] = A[0]*B[0][1];
  SM[1][1] = A[1]*B[1][1];
  SM[1][2] = A[2]*B[2][1];
  SM[2][0] = A[0];
  SM[2][1] = A[1];
  SM[2][2] = A[2];

  return SM;
}

void ProjectiveTransformation::PrintInvertedSourceScalingMatrix()
{
  printf("Inverted source scaling matrix:\n");
  for(int i=0; i<(int)i_s_s_m.size(); i++)
  {
    for(int j=0; j<(int)i_s_s_m[0].size(); j++)
      printf("%lf ", i_s_s_m[i][j]);
    printf("\n");
  }
}  

void ProjectiveTransformation::PrintInvertedTargetScalingMatrix()
{
  printf("Inverted target scaling matrix:\n");
  for(int i=0; i<(int)i_t_s_m.size(); i++)
  {
    for(int j=0; j<(int)i_t_s_m[0].size(); j++)
      printf("%lf ", i_t_s_m[i][j]);
    printf("\n");
  }
}

void ProjectiveTransformation::PrintSourceCoefficientMatrix()
{
  for(int i=0; i<(int)s_c_m.size(); i++)
    printf("Source Coefficient %d: %lf\n", i+1, s_c_m[i]);
}

void ProjectiveTransformation::PrintSourceCoordinates()
{
  for(int i=0; i<(int)s_c.size(); i++)
    printf("Corner %d: %lf degrees longitude and %lf degrees latitude\n", i+1, s_c[i][0], s_c[i][1]);
  printf("Corner assignments are based on a clockwise motion where corner 1 is the upper left hand corner of the source image.\n");
}

void ProjectiveTransformation::PrintSourceScalingMatrix()
{
  printf("Source scaling matrix:\n");
  for(int i=0; i<(int)s_s_m.size(); i++)
  {
    for(int j=0; j<(int)s_s_m[0].size(); j++)
      printf("%lf ", s_s_m[i][j]);
    printf("\n");
  }
}

void ProjectiveTransformation::PrintTargetCoefficientMatrix()
{
  for(int i=0; i<(int)t_c_m.size(); i++)
    printf("Target Coefficient %d: %lf\n", i+1, s_c_m[i]);
}

void ProjectiveTransformation::PrintTargetCoordinates()
{
  for(int i=0; i<(int)t_c.size(); i++)
    printf("Corner %d: %lf pixels in x and %lf pixels in y\n", i+1, t_c[i][0], t_c[i][1]);
  printf("Corner assignments are based on a clockwise motion where corner 1 is the upper left hand corner of the source image.\n");
}

void ProjectiveTransformation::PrintTargetScalingMatrix()
{
  printf("Target scaling matrix:\n");
  for(int i=0; i<(int)t_s_m.size(); i++)
  {
    for(int j=0; j<(int)t_s_m[0].size(); j++)
      printf("%lf ", t_s_m[i][j]);
    printf("\n");
  }
}

void ProjectiveTransformation::PrintTransformSource2TargetMatrix()
{
  printf("Transform source to target matrix:\n");
  for(int i=0; i<(int)Transform_Source2Target_Matrix.size(); i++)
  {
    for(int j=0; j<(int)Transform_Source2Target_Matrix[0].size(); j++)
      printf("%lf ", Transform_Source2Target_Matrix[i][j]);
    printf("\n");
  }
} 

void ProjectiveTransformation::PrintTransformTarget2SourceMatrix()
{
  printf("Transform target to source matrix:\n");
  for(int i=0; i<(int)Transform_Target2Source_Matrix.size(); i++)
  {
    for(int j=0; j<(int)Transform_Target2Source_Matrix[0].size(); j++)
      printf("%lf ", Transform_Target2Source_Matrix[i][j]);
    printf("\n");
  }
}
