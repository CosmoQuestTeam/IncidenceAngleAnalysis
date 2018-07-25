#include "Plot.h"

using namespace std;

void Plot::CumulativeFrequencySizeDistribution(string CraterCatalogue1, string CraterCatalogue2)
{
  /*************************************/
  /* Declaration of function variables */
  /*************************************/
  double binwidth;
  double incidence_angle_1;
  double incidence_angle_2;
  double log10_xlow;
  double log10_xup;
  double m2km;
  double max1;
  double max2;
  double min1;
  double min2;
  double xlow;
  double xup;
  ifstream InFile;
  int canheight;
  int canwidth;
  int index1;
  int index2;
  int length;
  int nbins;
  string buffer;
  string format;
  string filename;
  string imagename1;
  string imagename2;
  TCanvas *can;
  TGraphErrors *TG1;
  TGraphErrors *TG2;
  TLegend *leg;
  vector <double> A1;
  vector <double> A2;
  vector <double> D1;
  vector <double> D2;
  vector <double> XAXISBIN;
  vector <double> XAXISBINLOG;
  vector < vector <double> > CC1;
  vector < vector <double> > CC2;
  
  /*******************************/
  /* Open and read-in Filename 1 */
  /*******************************/
  if(Utilities::FileExists(CraterCatalogue1))
    InFile.open(CraterCatalogue1.c_str());
  else
  {
    printf("Error: File %s does not exist!\n", CraterCatalogue1.c_str());
    exit(EXIT_FAILURE);
  }
  while(getline(InFile, buffer))
  {
    double v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
    format = "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf";
    int nelements = sscanf(buffer.c_str(), format.c_str(), &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8, &v9, &v10);
    if(nelements == 10)
    {
      vector <double> row(10, 0.0);
      row[0] = v1; // Cluster ID
      row[1] = v2; // Cluster center mean x position
      row[2] = v3; // Cluster center x standard deviation
      row[3] = v4; // Cluster center mean y position
      row[4] = v5; // Cluster center y standard deviation
      row[5] = v6; // Crater mean diameter
      row[6] = v7; // Crater diameter standard deviation
      row[7] = v8; // Confidence
      row[8] = v9; // Region area
      row[9] = v10; // Number of data points used to construct current row
      CC1.push_back(row);      
    }
  }
  InFile.close();

  /*******************************/
  /* Open and read-in Filename 2 */
  /*******************************/
  if(Utilities::FileExists(CraterCatalogue2))
    InFile.open(CraterCatalogue2.c_str());
  else
  {
    printf("Error: File %s does not exist!\n", CraterCatalogue2.c_str());
    exit(EXIT_FAILURE);
  }
  while(getline(InFile, buffer))
  {
    double v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
    format = "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf";
    int nelements = sscanf(buffer.c_str(), format.c_str(), &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8, &v9, &v10);
    if(nelements == 10)
    {
      vector <double> row(10, 0.0);
      row[0] = v1; // Cluster ID
      row[1] = v2; // Cluster center mean x position
      row[2] = v3; // Cluster center x standard deviation
      row[3] = v4; // Cluster center mean y position
      row[4] = v5; // Cluster center y standard deviation
      row[5] = v6; // Crater mean diameter
      row[6] = v7; // Crater diameter standard deviation
      row[7] = v8; // Confidence
      row[8] = v9; // Region area
      row[9] = v10; // Number of data points used to construct current row
      CC2.push_back(row);
    }
  }
  InFile.close();

  /******************************************************/
  /* Parse filename 1 to retrieve pertinent information */
  /******************************************************/
  index1 = CraterCatalogue1.find("_M")+1;
  index2 = CraterCatalogue1.find("E_")+1;
  length = index2-index1;
  imagename1 = CraterCatalogue1.substr(index1, length);
  index1 = index2+1;
  index2 = CraterCatalogue1.rfind(".");
  length = index2-index1;
  incidence_angle_1 = stod(CraterCatalogue1.substr(index1, length));

  /******************************************************/
  /* Parse filename 1 to retrieve pertinent information */
  /******************************************************/
  index1 = CraterCatalogue2.find("_M")+1;
  index2 = CraterCatalogue2.find("E_")+1;
  length = index2-index1;
  imagename2 = CraterCatalogue2.substr(index1, length);
  index1 = index2+1;
  index2 = CraterCatalogue2.rfind(".");
  length = index2-index1;
  incidence_angle_2 = stod(CraterCatalogue2.substr(index1, length));
  
  /***************/
  /* Select data */
  /***************/
  m2km = 1.0E-3;
  for(int i=0; i<(int)CC1.size(); i++)
  {
    D1.push_back(CC1[i][5]*m2km);
    A1.push_back(CC1[i][8]*m2km*m2km);
  }
  for(int i=0; i<(int)CC2.size(); i++)
  {
    D2.push_back(CC2[i][5]*m2km);
    A2.push_back(CC2[i][8]*m2km*m2km);
  }

  /***************/
  /* Data switch */
  /***************/
  if(D2.size() > D1.size())
  {
    D1.swap(D2);
    A1.swap(A2);
    imagename1.swap(imagename2);
    double temp = incidence_angle_1;
    incidence_angle_1 = incidence_angle_2;
    incidence_angle_2 = temp;
  }
  
  /*****************************************/
  /* Determine plot spacing and number of  */
  /* bins (Using even logarithmic spacing) */
  /*****************************************/
  binwidth = 1.0/27; // Unit: log_10(diameter [km])
  max1 = Utilities::ArrayMaximum(D1.data(), (int)D1.size());
  max2 = Utilities::ArrayMaximum(D2.data(), (int)D2.size()); 
  min1 = Utilities::ArrayMinimum(D1.data(), (int)D1.size());
  min2 = Utilities::ArrayMinimum(D2.data(), (int)D2.size());
  xlow = (min1 < min2) ? min1 : min2;
  xup = (max1 > max2) ? max1 : max2;
  log10_xlow = log10(xlow);
  log10_xup = log10(xup);
  nbins = (log10_xup-log10_xlow)/binwidth;

  /**********************************************/
  /* Calculate left edge and center of each bin */
  /**********************************************/
  for(int i=0; i<=nbins; i++)
  {
    XAXISBINLOG.push_back(log10_xlow+binwidth*i);
    XAXISBIN.push_back(pow(10, XAXISBINLOG.back()));
  }
  
  /**************************************/
  /* Calculate cumulative distributions */
  /**************************************/
  vector < set <double> > A_K_set1(nbins+1, set <double> ());
  vector < set <double> > A_K_set2(nbins+1, set <double> ());
  vector <double> A_K1(nbins+1, 0.0);
  vector <double> A_K2(nbins+1, 0.0);
  vector <double> Density1(nbins+1, 0.0);
  vector <double> Density2(nbins+1, 0.0);
  vector <double> Density1_Error(nbins+1, 0.0);
  vector <double> Density2_Error(nbins+1, 0.0);
  vector <double> n_K1(nbins+1, 0.0);
  vector <double> n_K2(nbins+1, 0.0);
  double bin_number = 1.0/binwidth;
  for(int i=0; i<(int)D1.size(); i++)
  {    
    /******************************************/
    /* Calculate common log value of diameter */
    /******************************************/
    double logD = log10(D1[i]);

    /************************/
    /* Determine bin number */
    /************************/
    int index = (logD-log10_xlow)*bin_number;
    
    /**************************************/
    /* Increment all bins associated with */
    /* diameters less than or equal logD  */
    /**************************************/
    n_K1[index]++;
    
    /***********************************************/
    /* Determine area of region from which craters */
    /* within the nth bin are associated with      */
    /***********************************************/
    A_K_set1[index].insert(A1[i]);
  }
  
  for(int i=0; i<(int)D2.size(); i++)
  {
    /******************************************/
    /* Calculate common log value of diameter */
    /******************************************/
    double logD = log10(D2[i]);

    /************************/
    /* Determine bin number */
    /************************/
    int index = (logD-log10_xlow)*bin_number;

    /***************************************/
    /* Increment bin associated with index */
    /***************************************/
    n_K2[index]++;

    /***********************************************/
    /* Determine area of region from which craters */
    /* within the nth bin are associated with      */
    /***********************************************/
    A_K_set2[index].insert(A2[i]);
  }
  
  /*************************************/
  /* Calculate total area for each bin */
  /*************************************/
  for(int i=0; i<=nbins; i++)
  {
    /*************************************************/
    /* Retrieve values from ith area of sets 1 and 2 */
    /*************************************************/
    vector <double> A_K1_Sum(A_K_set1[i].begin(), A_K_set1[i].end());
    vector <double> A_K2_Sum(A_K_set2[i].begin(), A_K_set2[i].end());
    
    /****************/
    /* Total area 1 */
    /****************/
    for(int j=0; j<(int)A_K1_Sum.size(); j++)
      A_K1[i] += A_K1_Sum[j];
      
    /****************/
    /* Total area 2 */
    /****************/
    for(int j=0; j<(int)A_K2_Sum.size(); j++)
      A_K2[i] += A_K2_Sum[j];
  }

  /***********************/
  /* Density calculation */
  /***********************/
  for(int i=nbins; i>=0; i--)
    for(int j=i; j<=nbins; j++)
    {
      Density1[i] += (A_K1[j] != 0) ? n_K1[j]/A_K1[j] : 0;
      Density2[i] += (A_K2[j] != 0) ? n_K2[j]/A_K2[j] : 0;
    }
  
  /*****************************/
  /* Density error calculation */
  /*****************************/
  for(int i=nbins; i>=0; i--)
  {
    double N1 = 0;
    double N2 = 0;
    for(int j=i; j<=nbins; j++)
    {
      N1 += n_K1[j];
      N2 += n_K1[j];
    }
    
    Density1_Error[i] = Density1[i]/sqrt(N1);
    Density2_Error[i] = Density2[i]/sqrt(N2);
  }
  
  /*********************/
  /* Initialize canvas */
  /*********************/
  canwidth = 900;
  canheight = 900;
  can = new TCanvas("Canvas", "", canwidth, canheight);
  can->SetLogy();
  can->SetLogx();
  can->SetGridx();
  can->SetGridy();
  
  /**********************/
  /* Initialize graph 1 */
  /**********************/
  TG1 = new TGraphErrors(nbins, XAXISBIN.data(), Density1.data(), 0, Density1_Error.data());
  
  /**********************/
  /* Initialize graph 2 */
  /**********************/
  TG2 = new TGraphErrors(nbins, XAXISBIN.data(), Density2.data(), 0, Density2_Error.data());
  
  /*****************/
  /* Plot settings */
  /*****************/
  TG1->SetTitle("");
  TG1->GetXaxis()->SetTitle("Diameter [km]");
  TG1->GetYaxis()->SetTitle("Cumulative Number of Craters [km^{-2}]");
  TG1->GetXaxis()->CenterTitle();
  TG1->GetYaxis()->CenterTitle();
  TG1->SetMarkerStyle(21);
  TG1->SetMarkerColor(kBlue);
  TG1->GetXaxis()->SetRangeUser(xlow, xup);
  TG1->Draw("AP");
  TG2->SetMarkerStyle(21);
  TG2->SetMarkerColor(kRed);
  TG2->Draw("P");

  /**********/
  /* Legend */
  /**********/
  //leg = new TLegend(0.7,0.7,0.9,0.9);
  leg = new TLegend(0.2,0.2,0.4,0.4);
  buffer = imagename1+", "+to_string(incidence_angle_1);
  leg->AddEntry(TG1, buffer.c_str(), "p");
  buffer = imagename2+", "+to_string(incidence_angle_2);
  leg->AddEntry(TG2, buffer.c_str(), "p");
  leg->Draw();
  
  /*********************/
  /* Save plot to file */
  /*********************/
  filename = "CumulativeFrequency_vs_SizeDistribution.ps";
  can->SaveAs(filename.c_str());

  /***********************************/
  /* Free memory reserved for canvas */
  /***********************************/
  delete can;
  delete TG1;
  delete TG2;

  return;
}

// void Plot::DifferentIncidenceAngleStatistics(std::vector <OverlappedImages> &OI, std::vector <OverlappedImages> &DIA)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double xlow;
//   double xup;
//   int canheight;
//   int canwidth;
//   int count_different;
//   int count_same;
//   int nbins;
//   string field;
//   string filename;
//   TCanvas *can;
//   TH1F *hist;
//   vector <string> label;

//   /********************************************/
//   /* Sort overlap vector based on "id" column */
//   /********************************************/
//   field = "id";
//   SortOverlappedImages sortoverlappedimages(OI, field);
//   sortoverlappedimages.arrange();
//   OI = sortoverlappedimages.GetOverlappedimages();
//   //OverlappedImages::Display(OI); exit(0);

//   /***************/
//   /* Axis labels */
//   /***************/
//   label.push_back("Same");
//   label.push_back("Different");

//   /*********************/
//   /* Initialize canvas */
//   /*********************/
//   canwidth = 1200;
//   canheight = 600;
//   can = new TCanvas("Canvas", "", canwidth, canheight);

//   /************************/
//   /* Initialize histogram */
//   /************************/
//   nbins = 2;
//   xlow = 0;
//   xup = 2;
//   hist = new TH1F("", "", nbins, xlow, xup);

//   /******************/
//   /* Fill histogram */
//   /******************/
//   count_different = 0;
//   count_same = 0;
//   for(int i=0; i<(int)OI.size(); i++)
//   {
//     double incidenceangle1 = OI[i].GetImage1_incidence_angle();
//     double incidenceangle2 = OI[i].GetImage2_incidence_angle();
//     if(incidenceangle1 == incidenceangle2)
//     {
//       hist->Fill(label[0].c_str(), 1);
//       count_same++;
//     }
//     else
//     {
//       hist->Fill(label[1].c_str(), 1);
//       DIA.push_back(OI[i]);
//       count_different++;
//     }
//   }

//   /*****************/
//   /* Plot settings */
//   /*****************/
//   hist->SetStats(false);
//   hist->SetTitle("Comparison between Incidence Angles of Overlapping Images");
//   hist->GetXaxis()->SetTitle("Incidence Angle");
//   hist->GetYaxis()->SetTitle("Frequency");
//   hist->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "Frequency_vs_IncidenceAngleComparison_per_OverlappingPair.ps";
//   can->SaveAs(filename.c_str());

//   /***********************************/
//   /* Free memory reserved for canvas */
//   /***********************************/
//   delete can;

//   return;
// }

// void Plot::FractionalOverlap(vector <OverlappedImages> &OI, vector <OverlappedImages> &TOI)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double xlow;
//   double xup;
//   int canheight;
//   int canwidth;
//   int nbins;
//   string field;
//   string filename;
//   TCanvas *can;
//   TH1F *hist;
//   vector <double> overlap_percentage;
//   vector <OverlappedImages> TotalOverlapImages;
//   vector <long int> imagearea1;
//   vector <long int> imagearea2;
//   vector <long int> oarea;

//   /********************************************/
//   /* Sort overlap vector based on "id" column */
//   /********************************************/
//   field = "id";
//   SortOverlappedImages sortoverlappedimages(OI, field);
//   sortoverlappedimages.arrange();
//   OI = sortoverlappedimages.GetOverlappedimages();
//   //OverlappedImages::Display(OI); exit(0);

//   /****************************/
//   /* Retrieve neccessary data */
//   /****************************/
//   for(int i=0; i<(int)OI.size(); i++)
//   {
//     imagearea1.push_back(OI[i].GetImage1_area());
//     imagearea2.push_back(OI[i].GetImage2_area());
//     oarea.push_back(OI[i].GetOverlap_area());
//     overlap_percentage.push_back(100*oarea[i]/Utilities::Min(imagearea1[i], imagearea2[i]));
//     if(overlap_percentage[i] == 100)
//       TotalOverlapImages.push_back(OI[i]);
//   }
//   TOI = TotalOverlapImages;

//   /*********************/
//   /* Initialize canvas */
//   /*********************/
//   canwidth = 1200;
//   canheight = 600;
//   can = new TCanvas("Canvas", "", canwidth, canheight);

//   /*******************/
//   /* Initialize plot */
//   /*******************/
//   nbins = 21;
//   xlow = 0; // Unit: Percentage
//   xup = 105; // Unit: Percentage
//   hist = new TH1F("", "", nbins, xlow, xup);

//   /******************/
//   /* Fill histogram */
//   /******************/
//   for(int i=0; i<(int)overlap_percentage.size(); i++)
//     hist->Fill(overlap_percentage[i]);
  
//   /*****************/
//   /* Plot settings */
//   /*****************/
//   hist->SetStats(false);
//   hist->SetTitle("Percentage of Overlap on the Smallest Image");
//   hist->GetXaxis()->SetTitle("Overlapped Area Fraction [%]");
//   hist->GetYaxis()->SetTitle("Frequency");
//   hist->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "OverlapPercentage.ps";
//   can->SaveAs(filename.c_str());

//   /***********************************/
//   /* Free memory reserved for canvas */
//   /***********************************/
//   delete hist;
//   delete can;

//   return;
// }

// void Plot::IncidenceAngleDistribution(vector <Images> &I, vector <IncidenceAngles> &IA)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double max_incidenceangle;
//   double min_incidenceangle;
//   double xlow;
//   double xup;
//   int canheight;
//   int canwidth;
//   int nbins;
//   string field;
//   string filename;
//   TCanvas *can;
//   TH1F *hist;
//   vector <double> incidenceangles;
//   vector <IncidenceAngles> ia;

//   /*****************************************/
//   /* Sort IA vector based on "name" column */
//   /*****************************************/
//   field = "name";
//   SortIncidenceAngles sortincidenceangles(IA, field);
//   sortincidenceangles.arrange();
//   ia = sortincidenceangles.GetIncidenceangles();
//   //ReadIncidenceAngles::Display(ia); exit(0);

//   /******************************************/
//   /* Determine incidence angle distribution */
//   /******************************************/
//   max_incidenceangle = 0;
//   min_incidenceangle = 0;
//   for(int i=0; i<(int)I.size(); i++)
//   {
//     /*******************************/
//     /* Retrieve current image name */
//     /*******************************/
//     string imagename = I[i].GetName();
//     int p = imagename.find_first_of("_");
//     string basename = imagename.substr(0, p);
    
//     /**********************************************/
//     /* Retrieve incidence angle for current image */
//     /**********************************************/
//     int index = SearchIncidenceAngles::BinarySearch(ia, 0, (int)ia.size(), field, &basename);
//     double current_incidenceangle = ia[index].GetIncidence_angle();
//     incidenceangles.push_back(current_incidenceangle);
//     max_incidenceangle = (max_incidenceangle > current_incidenceangle) ? max_incidenceangle : current_incidenceangle;
//     min_incidenceangle = (min_incidenceangle < current_incidenceangle) ? min_incidenceangle : current_incidenceangle;
//   }

//   /*********************/
//   /* Initialize canvas */
//   /*********************/
//   TGaxis::SetMaxDigits(3);
//   canwidth = 1200;
//   canheight = 600;
//   can = new TCanvas("Canvas", "", canwidth, canheight);

//   /************************/
//   /* Initialize histogram */
//   /************************/
//   nbins = 18;
//   xlow = 0; //min_incidenceangle;
//   xup = 90; //ceil(max_incidenceangle);
//   hist = new TH1F("", "", nbins, xlow, xup);

//   /******************/
//   /* Fill histogram */
//   /******************/
//   for(int i=0; i<(int)incidenceangles.size(); i++)
//     hist->Fill(incidenceangles[i]);

//   /*****************/
//   /* Plot settings */
//   /*****************/
//   hist->SetStats(false);
//   hist->SetTitle("Incidence Angle Distribution");
//   hist->GetXaxis()->SetTitle("Incidence Angle [Degree]");
//   hist->GetYaxis()->SetTitle("Frequency");
//   hist->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "IncidenceAngleDistribution.ps";
//   can->SaveAs(filename.c_str());

//   /***********************************/
//   /* Free memory reserved for canvas */
//   /***********************************/
//   delete hist;
//   delete can;

//   return;
// }

// void Plot::IncidenceAngleStatistics(double incidenceangle1, double incidenceangle2, int scale, vector <OverlappedImages> &OI, vector <Marks> &marks)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double isum;
//   double xlow;
//   double xup;
//   int canheight;
//   int canwidth;
//   int nbins;
//   int nelements1;
//   int nelements2;
//   int paircounter;
//   string buffer;
//   string field;
//   string filename;
//   string title;
//   TCanvas *can1;
//   TCanvas *can2;
//   TCanvas *can3;
//   TCanvas *can4;
//   TH1F *hist1;
//   TH1F *hist2;
//   THStack *bar;
//   TLegend *leg;
//   vector <double> histogram1_data; // Reserved for incidence angle 1
//   vector <double> histogram2_data; // Reserved for incidence angle 2
//   vector <int> mark_ids_1;
//   vector <int> mark_ids_2;
//   vector <Marks> myMarks;

//   /***************************************/
//   /* Sort marks vector based on image_id */
//   /***************************************/
//   field = "image_id";
//   SortMarks sortmarks(marks, field);
//   sortmarks.arrange();
//   marks = sortmarks.GetMarks();
//   //RetrieveMarks::Display(marks); exit(0);

//   /*********************/
//   /* Copy marks vector */
//   /*********************/
//   myMarks = marks;

//   /***********************************/
//   /* Calculate incidence angle sum   */
//   /* cheap hack assuming that the    */
//   /* sum of any two incidence angles */
//   /* is unique                       */
//   /***********************************/
//   isum = incidenceangle1+incidenceangle2;

//   /*************************************************/
//   /* Iterate through overlapping sub-images vector */
//   /*************************************************/
//   paircounter = 0;
//   for(int i=0; i<(int)OI.size(); i++)
//   {

//     /********************************/
//     /* Incidence angle verification */
//     /********************************/
//     if(isum != OI[i].GetImage1_incidence_angle()+OI[i].GetImage2_incidence_angle())
//       continue;
    
//     /***************************/
//     /* Check scaling of images */
//     /***************************/
//     string Imagename1 = OI[i].GetImage1_name();
//     string Imagename2 = OI[i].GetImage2_name();
//     int Position1 = Imagename2.find("_")+1;
//     int Position2 = Imagename2.find("_")+1;
//     string news1 = Imagename1.substr(Position1, 1);
//     string news2 = Imagename2.substr(Position2, 1);
//     int Image1_scale = stoi(news1);
//     int Image2_scale = stoi(news2);    
//     if((Image1_scale != scale) || (Image2_scale != scale))
//       continue;

//     /*********************/
//     /* Testing statement */
//     /*********************/
//     //cout << "Wanted scaling level: " << scale << " Scale level of image 1: " << Image1_scale << " " << " Scale level of image 2: " << Image1_scale << endl;

//     /***********************************************/
//     /* Find starting indicies for marks associated */
//     /* with current sub-images being evaluated     */
//     /***********************************************/
//     int nmarks = (int)myMarks.size();
//     int value1 = OI[i].GetImage1_id();
//     int value2 = OI[i].GetImage2_id();
//     int index1 = SearchMarks::FirstOccurence(myMarks, 0, nmarks-1, field, &value1);
//     int index2 = SearchMarks::FirstOccurence(myMarks, 0, nmarks-1, field, &value2);
//     int starting_index1 = index1;
//     int starting_index2 = index2;

//     /*************************************/
//     /* If an image has not been marked,  */
//     /* continue to next overlapping pair */
//     /*************************************/
//     if((index1 == -1) || (index2 == -1))
//       continue;
    
//     /*************************************/
//     /* Get boundaries for overlap region */
//     /*************************************/
//     double overlap_x_low = OI[i].GetOverlap_x_low();
//     double overlap_y_low = OI[i].GetOverlap_y_low();
//     double overlap_x_high = OI[i].GetOverlap_x_high();
//     double overlap_y_high = OI[i].GetOverlap_y_high();

//     /*************************************************************/
//     /* Get x and y global origin and pixel resolution of image 1 */
//     /*************************************************************/
//     double image1_horizontal_resolution = OI[i].GetImage1_horizontal_resolution();
//     double image1_vertical_resolution = OI[i].GetImage1_vertical_resolution();
//     double image1_crater_resolution = (image1_horizontal_resolution > image1_vertical_resolution) ?
//       image1_horizontal_resolution : image1_vertical_resolution;
//     string image1_x_origin_condition = OI[i].GetImage1_x_origin_condition();
//     string image1_y_origin_condition = OI[i].GetImage1_y_origin_condition();
//     double image1_x_origin = (image1_x_origin_condition.compare("MIN") == 0) ? OI[i].GetImage1_x_low() : OI[i].GetImage1_x_high();
//     double image1_y_origin = (image1_y_origin_condition.compare("MIN") == 0) ? OI[i].GetImage1_y_low() : OI[i].GetImage1_y_high();

//     /*************************************************************/
//     /* Get x and y global origin and pixel resolution of image 2 */
//     /*************************************************************/
//     double image2_horizontal_resolution = OI[i].GetImage2_horizontal_resolution();
//     double image2_vertical_resolution = OI[i].GetImage2_vertical_resolution();
//     double image2_crater_resolution = (image2_horizontal_resolution > image2_vertical_resolution) ?
//       image2_horizontal_resolution : image2_vertical_resolution;
//     string image2_x_origin_condition = OI[i].GetImage2_x_origin_condition();
//     string image2_y_origin_condition = OI[i].GetImage2_y_origin_condition();
//     double image2_x_origin = (image2_x_origin_condition.compare("MIN") == 0) ? OI[i].GetImage2_x_low() : OI[i].GetImage2_x_high();
//     double image2_y_origin = (image2_y_origin_condition.compare("MIN") == 0) ? OI[i].GetImage2_y_low() : OI[i].GetImage2_y_high();

//     /*********************************************************/
//     /* Iterate through selected marks associated with image1 */
//     /*********************************************************/
//     int counter1 = 0;
//     while(value1 == myMarks[index1].GetImage_id())
//     {
//       /*********************************************/
//       /* Calculate global x and y position of mark */
//       /*********************************************/
//       double x = (image1_x_origin_condition.compare("MIN") == 0) ? 
// 	image1_x_origin+image1_horizontal_resolution*myMarks[index1].GetX() :
// 	image1_x_origin-image1_horizontal_resolution*myMarks[index1].GetX();
//       double y = (image1_y_origin_condition.compare("MIN") == 0) ? 
// 	image1_y_origin+image1_vertical_resolution*myMarks[index1].GetY() :
// 	image1_y_origin-image1_vertical_resolution*myMarks[index1].GetY();

//       /**************************/
//       /* Check position of mark */
//       /* If position is within  */
//       /* overlapping region,    */
//       /* use the mark.          */
//       /**************************/
//       if((overlap_x_low < x) && (x < overlap_x_high) && (overlap_y_low < y) && (y < overlap_y_high))
//       {
// 	/****************************/
// 	/* Ignore marks that have a */
// 	/* diameter value of NULL.  */
// 	/****************************/
// 	if(myMarks[index1].GetDiameter() != 0)
// 	{
// 	  if(OI[i].GetImage1_incidence_angle() == incidenceangle1)
// 	    histogram1_data.push_back(image1_crater_resolution*myMarks[index1].GetDiameter());
// 	  else
// 	    histogram2_data.push_back(image1_crater_resolution*myMarks[index1].GetDiameter());

// 	  /******************/
// 	  /* Update counter */
// 	  /******************/
// 	  counter1++;
// 	}
//       }

//       /****************/
//       /* Update index */
//       /****************/
//       index1++;
//     }

//     /****************************************/
//     /* Remove evaluated marks from analysis */
//     /****************************************/
//     myMarks.erase(myMarks.begin()+starting_index1, myMarks.begin()+index1);

//     /*********************************************************/
//     /* Iterate through selected marks associated with image2 */
//     /*********************************************************/
//     int counter2 = 0;
//     while(value2 == myMarks[index2].GetImage_id())
//     {
//       /*********************************************/
//       /* Calculate global x and y position of mark */
//       /*********************************************/
//       double x = (image2_x_origin_condition.compare("MIN") == 0) ?
// 	image2_x_origin+image2_horizontal_resolution*myMarks[index2].GetX() :
// 	image2_x_origin-image2_horizontal_resolution*myMarks[index2].GetX();
//       double y = (image2_y_origin_condition.compare("MIN") == 0) ?
// 	image2_y_origin+image2_vertical_resolution*myMarks[index2].GetY() :
// 	image2_y_origin-image2_vertical_resolution*myMarks[index2].GetY();

//       /**************************/
//       /* Check position of mark */
//       /* If position is within  */
//       /* overlapping region,    */
//       /* use the mark.          */
//       /**************************/
//       if((overlap_x_low < x) && (x < overlap_x_high) && (overlap_y_low < y) && (y < overlap_y_high))
//       {
// 	/****************************/
// 	/* Ignore marks that have a */
// 	/* diameter value of NULL.  */
// 	/****************************/
// 	if(myMarks[index2].GetDiameter() != 0)
// 	{
// 	  if(OI[i].GetImage2_incidence_angle() == incidenceangle1)
// 	    histogram1_data.push_back(image2_crater_resolution*myMarks[index2].GetDiameter());
// 	  else
// 	    histogram2_data.push_back(image2_crater_resolution*myMarks[index2].GetDiameter());

// 	  /******************/
// 	  /* Update counter */
// 	  /******************/
// 	  counter2++;
// 	}
//       }

//       /****************/
//       /* Update index */
//       /****************/
//       index2++;
//     }
    
//     /****************************************/
//     /* Remove evaluated marks from analysis */
//     /****************************************/
//     myMarks.erase(myMarks.begin()+starting_index2, myMarks.begin()+index2);

//     /**********************/
//     /* Update paircounter */
//     /**********************/
//     if((counter1 > 0) && (counter2 > 0))
//       paircounter++;
//   }

//   /*******************************************************************/
//   /* Exit function if no data was retrieved for size-frequency plots */
//   /*******************************************************************/
//   if(paircounter == 0)
//     return;

//   /********************************************/
//   /* Number of elements in histograms 1 and 2 */
//   /********************************************/
//   nelements1 = (int)histogram1_data.size();
//   nelements2 = (int)histogram2_data.size();

//   /*********************/
//   /* Initialize canvas */
//   /*********************/
//   canwidth = 800;
//   canheight = 800;
//   can1 = new TCanvas("Canvas1", "", canwidth, canheight);
//   can1->Divide(1, 2);

//   /****************************************/
//   /* Determine histogram basic properties */
//   /****************************************/
//   double min1 = floor(Utilities::ArrayMinimum(histogram1_data.data(), nelements1));
//   double min2 = floor(Utilities::ArrayMinimum(histogram2_data.data(), nelements2));
//   double max1 = ceil(Utilities::ArrayMaximum(histogram1_data.data(), nelements1));
//   double max2 = ceil(Utilities::ArrayMaximum(histogram2_data.data(), nelements2));
//   xlow = (min1 < min2) ? min1 : min2; // Unit: m
//   xup = (max1 > max2) ? max1 : max2; // Unit: m
//   double binwidth = 5; // Unit: m
//   nbins = static_cast<int>((xup-xlow)/binwidth);

//   /**************************/
//   /* Initialize histogram 1 */
//   /**************************/
//   hist1 = new TH1F("Histogram1", "", nbins, xlow, xup);

//   /**************************/
//   /* Initialize histogram 2 */
//   /**************************/
//   hist2 = new TH1F("Histogram2", "", nbins, xlow, xup);

//   /********************/
//   /* Fill histogram 1 */
//   /********************/
//   for(int i=0; i<nelements1; i++)
//     hist1->Fill(histogram1_data[i]);

//   /********************/
//   /* Fill histogram 2 */
//   /********************/
//   for(int i=0; i<nelements2; i++)
//     hist2->Fill(histogram2_data[i]);

//   /*****************************/
//   /* Histogram 1 plot settings */
//   /*****************************/
//   title = "Frequency-Size Distribution @ Incidence Angle = "+to_string(incidenceangle1);
//   can1->cd(1);
//   hist1->SetStats(false);
//   hist1->SetTitle(title.c_str());
//   hist1->GetXaxis()->SetTitle("Crater Size [m]");
//   hist1->GetYaxis()->SetTitle("Frequency");
//   hist1->Draw();

//   /*****************************/
//   /* Histogram 2 plot settings */
//   /*****************************/
//   title = "Frequency-Size Distribution @ Incidence Angle = "+to_string(incidenceangle2);
//   can1->cd(2);
//   hist2->SetStats(false);
//   hist2->SetTitle(title.c_str());
//   hist2->GetXaxis()->SetTitle("Crater Size [m]");
//   hist2->GetYaxis()->SetTitle("Frequency");
//   hist2->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "NewPlot1.ps";
//   can1->SaveAs(filename.c_str());

//   /***********************/
//   /* Initialize canvas 2 */
//   /***********************/
//   canwidth = 800;
//   canheight = 800;
//   can2 = new TCanvas("Canvas2", "", canwidth, canheight);
//   TGaxis::SetMaxDigits(3);

//   /********************************/
//   /* Retrieve standard deviations */
//   /********************************/
//   double mean1 = hist1->GetMean();
//   double mean2 = hist2->GetMean();
//   double sd1 = hist1->GetStdDev();
//   double sd2 = hist2->GetStdDev();
//   double sigmarejection_low1 = mean1-5*sd1;
//   double sigmarejection_low2 = mean2-5*sd2;
//   double sigmarejection_high1 = mean1+5*sd1;
//   double sigmarejection_high2 = mean2+5*sd2;
//   double min_x;
//   double max_x;
//   if((0 < sigmarejection_low1) && (sigmarejection_low1 < sigmarejection_low2))
//     min_x = sigmarejection_low1;
//   else if((0 < sigmarejection_low2) && (sigmarejection_low2 < sigmarejection_low1))
//     min_x = sigmarejection_low2;
//   else
//     min_x = xlow;
//   max_x = (sigmarejection_high1 > sigmarejection_high2) ? sigmarejection_high1 : sigmarejection_high2;

//   /**************************/
//   /* Make stacked bar graph */
//   /**************************/
//   buffer = "Frequency-Size Distribution; Crater Size [m]; Frequency";
//   bar = new THStack("Bar", buffer.c_str());
//   hist1->SetFillColor(kRed);
//   bar->Add(hist1);
//   hist2->SetFillColor(kBlue);
//   bar->Add(hist2);
//   bar->Draw("hist");
//   bar->GetXaxis()->SetLimits(min_x, max_x);

//   /**********/
//   /* Legend */
//   /**********/
//   leg = new TLegend(0.7,0.7,0.9,0.9);
//   buffer = "Incidence Angle = "+to_string(incidenceangle1);
//   leg->AddEntry(hist1, buffer.c_str(), "f");
//   buffer = "Incidence Angle = "+to_string(incidenceangle2);
//   leg->AddEntry(hist2, buffer.c_str(), "f");
//   leg->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "NewPlot2.ps";
//   can2->SaveAs(filename.c_str());

//   /***********************/
//   /* Initialize canvas 3 */
//   /***********************/
//   canwidth = 800;
//   canheight = 800;
//   can3 = new TCanvas("Canvas3", "", canwidth, canheight);

//   /************************/
//   /* Over plot histograms */
//   /************************/
//   title = "Relative Frequency-Size Distribution";
  
//   double norm_constant1 = 1.0/nelements1;
//   hist1->Scale(norm_constant1);
//   hist1->SetTitle(title.c_str());
//   hist1->GetYaxis()->SetTitle("Relative Frequency");
//   hist1->SetLineColor(kRed);
//   hist1->GetYaxis()->SetTitleOffset(1.4);
//   hist1->Draw();

//   double norm_constant2 = 1.0/nelements2;
//   hist2->Scale(norm_constant2);
//   hist2->SetLineColor(kBlue);
//   hist2->Draw("same");

//   /**********/
//   /* Legend */
//   /**********/
//   //buffer = "Incidence Angle = "+to_string(incidenceangle1);
//   //leg->AddEntry(hist1, buffer.c_str(), "l");
//   //buffer = "Incidence Angle = "+to_string(incidenceangle2);
//   //leg->AddEntry(hist2, buffer.c_str(), "l");
//   leg->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "NewPlot3.ps";
//   can3->SaveAs(filename.c_str());
  
//   /***********************/
//   /* Initialize canvas 4 */
//   /***********************/
//   canwidth = 800;
//   canheight = 800;
//   can4 = new TCanvas("Canvas4", "", canwidth, canheight);
//   can4->SetLogy();
//   can4->SetLogx();
  
//   /************************/
//   /* Over plot histograms */
//   /************************/  
//   hist1->Draw();
//   hist2->Draw("same");

//   /******************************/
//   /* Initialize reference curve */
//   /******************************/
//   TH1F *hist3 = new TH1F("Histogram3", "", nbins, xlow, xup);

//   /******************************/
//   /* Histogram y = x^(-sqrt(2)) */
//   /******************************/
//   TF1 *myFunction = new TF1( "myFunction", "pow(x, -sqrt(2))", xlow, xup);
//   for(int i=0; i<20000; i++)
//     hist3->Fill(myFunction->GetRandom());
//   double norm_constant3 = 1.0/20000;
//   hist3->Scale(norm_constant3);
//   hist3->SetLineColor(kGreen);
//   hist3->Draw("same");

//   /**********/
//   /* Legend */
//   /**********/
//   buffer = "#frac{1}{x^{#sqrt{2}}}";
//   leg->AddEntry(hist3, buffer.c_str(), "l");
//   leg->Draw();
  
//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "NewPlot4.ps";
//   can4->SaveAs(filename.c_str());

//   /***********************************/
//   /* Free memory reserved for canvas */
//   /***********************************/
//   delete bar;
//   delete hist1;
//   delete hist2;
//   delete leg;
//   delete can1;
//   delete can2;
//   delete can3;
//   delete can4;

//   return;
// }

void Plot::MasterImage(ImageSets a, bool selenographic)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double dot;
  double lower_left_latitude;
  double lower_left_longitude;
  double lower_left_x;
  double lower_left_y;
  double lower_right_latitude;
  double lower_right_longitude;
  double lower_right_x;
  double lower_right_y;
  double spacing;
  double upper_left_latitude;
  double upper_left_longitude;
  double upper_left_x;
  double upper_left_y;
  double upper_right_latitude;
  double upper_right_longitude;
  double upper_right_x;
  double upper_right_y;
  double x_high;
  double x_low;
  double x_reference_point;
  double y_high;
  double y_low;
  double y_reference_point;
  int canheight;
  int canwidth;
  int n;
  string buffer;
  string filename;
  string image_name;
  TCanvas *can;
  TPolyLine *plot;
  TEllipse *el;
  TH1F *h1;
  TLegend *leg;
  vector <double> X_Coords;
  vector <double> Y_Coords;
    
  /******************************/
  /* Retrieve image information */
  /******************************/
  image_name = a.GetName();
  lower_left_latitude = a.GetLower_left_latitude();
  lower_left_longitude = a.GetLower_left_longitude();
  lower_left_x = a.GetLower_left_x();
  lower_left_y = a.GetLower_left_y();
  lower_right_latitude = a.GetLower_right_latitude();
  lower_right_longitude = a.GetLower_right_longitude();
  lower_right_x = a.GetLower_right_x();
  lower_right_y = a.GetLower_right_y();
  upper_left_latitude = a.GetUpper_left_latitude();
  upper_left_longitude = a.GetUpper_left_longitude();
  upper_left_x = a.GetUpper_left_x();
  upper_left_y = a.GetUpper_left_y();
  upper_right_latitude = a.GetUpper_right_latitude();
  upper_right_longitude = a.GetUpper_right_longitude();
  upper_right_x = a.GetUpper_right_x();
  upper_right_y = a.GetUpper_right_y();
  
  /*********************/
  /* Initialize Canvas */
  /*********************/
  canheight = 1200;
  canwidth = 800;
  can = new TCanvas("Canvas", "", canheight, canwidth);
  can->SetGridx();
  can->SetGridy();

  /*************/
  /* Draw axes */
  /*************/
  if(selenographic)
  {
    buffer = image_name+"; X [Degree]; Y [Degree]";
    x_high = a.GetMaximum_longitude();
    x_low = a.GetMinimum_longitude();
    x_reference_point = upper_left_longitude;
    y_high = a.GetMaximum_latitude();
    y_low = a.GetMinimum_latitude();
    y_reference_point = upper_left_latitude;
    spacing = 1E-2;
  }
  else
  {
    buffer = image_name+"; X [m]; Y [m]";
    x_high = a.GetMaximum_x();
    x_low = a.GetMinimum_x();
    x_reference_point = upper_left_x;
    y_high = a.GetMaximum_y();
    y_low = a.GetMinimum_y();
    y_reference_point = upper_left_y;
    spacing = 1E3;
  }
  h1 = can->DrawFrame(x_low-spacing, y_low-spacing, x_high+spacing, y_high+spacing, buffer.c_str());
  h1->GetYaxis()->SetNdivisions(5);
  h1->GetXaxis()->SetNdivisions(5);
    
  /**************/
  /* Plot image */
  /**************/
  if(selenographic)
  {
    X_Coords.push_back(upper_left_longitude);
    Y_Coords.push_back(upper_left_latitude);
    X_Coords.push_back(upper_right_longitude);
    Y_Coords.push_back(upper_right_latitude);    
    X_Coords.push_back(lower_right_longitude);
    Y_Coords.push_back(lower_right_latitude);
    X_Coords.push_back(lower_left_longitude);
    Y_Coords.push_back(lower_left_latitude);
    X_Coords.push_back(upper_left_longitude);
    Y_Coords.push_back(upper_left_latitude);
    dot = 0.01*abs(upper_left_longitude-upper_right_longitude);
  }
  else
  {
    X_Coords.push_back(upper_left_x);
    Y_Coords.push_back(upper_left_y);
    X_Coords.push_back(upper_right_x);
    Y_Coords.push_back(upper_right_y);
    X_Coords.push_back(lower_right_x);
    Y_Coords.push_back(lower_right_y);
    X_Coords.push_back(lower_left_x);
    Y_Coords.push_back(lower_left_y);
    X_Coords.push_back(upper_left_x);
    Y_Coords.push_back(upper_left_y);
    dot = 0.01*abs(upper_left_x-upper_right_x);
  }
  n = (int)X_Coords.size();
  plot = new TPolyLine(n, X_Coords.data(), Y_Coords.data());
  plot->SetLineColor(kGreen);
  plot->SetLineWidth(2);
  plot->Draw();
  gPad->RedrawAxis();

  /***********************/
  /* Plot defined origin */
  /***********************/
  el = new TEllipse(x_reference_point, y_reference_point, dot);
  el->SetFillColorAlpha(kRed, 0.50);
  el->SetFillStyle(4050);
  el->SetLineColor(kRed);
  el->Draw();

  /**********/
  /* Legend */
  /**********/
  leg = new TLegend(0.7,0.7,0.9,0.9);
  //leg->SetHeader("","C"); // option "C" allows to center the header
  buffer = "Image: "+image_name;
  leg->AddEntry(plot, buffer.c_str(), "f");
  leg->AddEntry(el, "Image Origin", "f");
  leg->Draw();

  /*********************/
  /* Save plot to file */
  /*********************/
  filename = image_name+"_Graphic.ps";
  can->SaveAs(filename.c_str());

  /***********************************/
  /* Free memory reserved for canvas */
  /***********************************/
  delete plot;
  delete el;
  delete leg;
  delete can;
}

// void Plot::MasterImages(ImageSets a, ImageSets b)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double spacing = 1E3;
//   double image1_x_high;
//   double image1_x_low;
//   double image1_x_origin;
//   double image1_y_high;
//   double image1_y_low;
//   double image1_y_origin;
//   double image2_x_high;
//   double image2_x_low;
//   double image2_x_origin;
//   double image2_y_high;
//   double image2_y_low;
//   double image2_y_origin;
//   double x_max;
//   double x_min;
//   double y_max;
//   double y_min;
//   int canheight;
//   int canwidth;
//   string buffer;
//   string filename;
//   string image1_name;
//   string image2_name;
//   TCanvas *can;
//   TBox *box1;
//   TBox *box2;
//   TEllipse *el1;
//   TEllipse *el2;
//   TLegend *leg;
    
//   /*******************************/
//   /* Retrieve image1 information */
//   /*******************************/
//   image1_name = a.GetName();
//   image1_x_high = a.GetX_high();
//   image1_x_low = a.GetX_low();
//   image1_x_origin = a.GetX_origin();
//   image1_y_high = a.GetY_high();
//   image1_y_low = a.GetY_low();
//   image1_y_origin = a.GetY_origin();

//   /*******************************/
//   /* Retrieve image2 information */
//   /*******************************/
//   image2_name = b.GetName();
//   image2_x_high = b.GetX_high();
//   image2_x_low = b.GetX_low();
//   image2_x_origin = b.GetX_origin();
//   image2_y_high = b.GetY_high();
//   image2_y_low = b.GetY_low();
//   image2_y_origin = b.GetY_origin();

//   /************************************************/
//   /* Determine minimum and maximum x and y values */
//   /************************************************/
//   x_max = (image1_x_high > image2_x_high) ? image1_x_high : image2_x_high;
//   x_min = (image1_x_low < image2_x_low) ? image1_x_low : image2_x_low;
//   y_max = (image1_y_high > image2_y_high) ? image1_y_high : image2_y_high;
//   y_min = (image1_y_low < image2_y_low) ? image1_y_low : image2_y_low;

//   /*********************/
//   /* Initialize Canvas */
//   /*********************/
//   canheight = 800;
//   canwidth = 800;
//   can = new TCanvas("Canvas", "", canheight, canwidth);
//   can->SetGridx();
//   can->SetGridy();

//   /*************/
//   /* Draw axes */
//   /*************/
//   buffer = image1_name+" vs "+image2_name+"; X [m]; Y [m]";
//   TH1F * h1 = can->DrawFrame(x_min-spacing, y_min-spacing, x_max+spacing, y_max+spacing, buffer.c_str());
//   h1->GetYaxis()->SetNdivisions(5);
//   h1->GetXaxis()->SetNdivisions(5);

//   /***************/
//   /* Plot image1 */
//   /***************/
//   box1 = new TBox(image1_x_low, image1_y_low, image1_x_high, image1_y_high);
//   box1->SetFillColorAlpha(kGreen, 1.00);
//   box1->SetFillStyle(4050);
//   box1->SetLineColor(kGreen);
//   box1->SetLineWidth(2);
//   box1->Draw("l");
//   gPad->RedrawAxis();

//   /******************************/
//   /* Plot defined image1 origin */
//   /******************************/
//   el1 = new TEllipse(image1_x_origin, image1_y_origin, 100.0);
//   el1->SetFillColorAlpha(kRed, 0.50);
//   el1->SetFillStyle(4050);
//   el1->SetLineColor(kRed);
//   el1->Draw();

//   /***************/
//   /* Plot image2 */
//   /***************/
//   box2 = new TBox(image2_x_low, image2_y_low, image2_x_high, image2_y_high);
//   box2->SetFillColorAlpha(kCyan, 1.00);
//   box2->SetFillStyle(4050);
//   box2->SetLineColor(kCyan);
//   box2->SetLineWidth(2);
//   box2->Draw("l");
//   gPad->RedrawAxis();

//   /******************************/
//   /* Plot defined image2 origin */
//   /******************************/
//   el2 = new TEllipse(image2_x_origin, image2_y_origin, 100.0);
//   el2->SetFillColorAlpha(kViolet, 0.50);
//   el2->SetFillStyle(4050);
//   el2->SetLineColor(kViolet);
//   el2->Draw();

//   /**********/
//   /* Legend */
//   /**********/
//   leg = new TLegend(0.7,0.7,0.9,0.9);
//   //leg->SetHeader("","C"); // option "C" allows to center the header
//   buffer = "Image1: "+image1_name;
//   leg->AddEntry(box1, buffer.c_str(), "f");
//   buffer = "Image2: "+image2_name;
//   leg->AddEntry(box2, buffer.c_str(), "f");
//   buffer = image1_name+" Origin";
//   leg->AddEntry(el1, buffer.c_str(), "f");
//   buffer = image2_name+" Origin";
//   leg->AddEntry(el2, buffer.c_str(), "f");
//   leg->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = image1_name+"_v_"+image2_name+"_Graphic.ps";
//   can->SaveAs(filename.c_str());

//   /***********************************/
//   /* Free memory reserved for canvas */
//   /***********************************/
//   delete box1;
//   delete box2;
//   delete el1;
//   delete el2;
//   delete leg;
//   delete can;
// }

// void Plot::MasterImage_w_Craters(ImageSets a, vector <Images> &b, vector <Marks> &c)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double spacing = 1E3;
//   double master_image_x_high;
//   double master_image_x_low;
//   double master_image_x_origin;
//   double master_image_y_high;
//   double master_image_y_low;
//   double master_image_y_origin;
//   int canheight;
//   int canwidth;  
//   int n;
//   int master_image_id;
//   int scale;
//   int sub_images_first_index;
//   int sub_images_last_index;
//   int value;
//   string buffer;
//   string field;
//   string filename;
//   string master_image_name;
//   TCanvas *can;
//   TBox *box;
//   TEllipse *el;
//   TEllipse *el2;
//   TLegend *leg;
    
//   /******************************/
//   /* Retrieve image information */
//   /******************************/
//   master_image_name = a.GetName();
//   master_image_id = a.GetId();
//   master_image_x_high = a.GetX_high();
//   master_image_x_low = a.GetX_low();
//   master_image_x_origin = a.GetX_origin();
//   master_image_y_high = a.GetY_high();
//   master_image_y_low = a.GetY_low();
//   master_image_y_origin = a.GetY_origin();

//   /******************************/
//   /* Sort sub images (b) vector */
//   /******************************/
//   field = "image_set_id";
//   SortImages sortimages(b, field);
//   sortimages.arrange();
//   b = sortimages.GetImages();
//   //RetrieveImages::Display(b); exit(0);

//   /*************************/
//   /* Sort marks (c) vector */
//   /*************************/
//   field = "image_id";
//   SortMarks sortmarks(c, field);
//   sortmarks.arrange();
//   c = sortmarks.GetMarks();
//   //RetrieveMarks::Display(c); exit(0);

//   /***********************************************************************/
//   /* Find first and last occurrence of image_set_id in images (b) vector */
//   /***********************************************************************/
//   n = (int)b.size();
//   field = "image_set_id";
//   value = master_image_id;
//   sub_images_first_index = SearchImages::FirstOccurence(b, 0, n-1, field, &value);
//   sub_images_last_index = SearchImages::LastOccurence(b, 0, n-1, field, &value);

//   scale = 0;
//   while(scale < 3)
//   {
//     /*********************/
//     /* Initialize Canvas */
//     /*********************/
//     canheight = 800;
//     canwidth = 800;
//     can = new TCanvas("Canvas", "", canheight, canwidth);
//     can->SetGridx();
//     can->SetGridy();

//     /*************/
//     /* Draw axes */
//     /*************/
//     buffer = master_image_name+"_"+to_string(scale)+"; X [m]; Y [m]";
//     TH1F * h1 = can->DrawFrame(master_image_x_low-spacing, 
// 			       master_image_y_low-spacing, 
// 			       master_image_x_high+spacing, 
// 			       master_image_y_high+spacing, 
// 			       buffer.c_str());
//     h1->GetYaxis()->SetNdivisions(5);
//     h1->GetXaxis()->SetNdivisions(5);

//     /*********************/
//     /* Plot master image */
//     /*********************/
//     box = new TBox(master_image_x_low, master_image_y_low, master_image_x_high, master_image_y_high);
//     box->SetFillColor(kGreen);
//     box->SetFillStyle(1001);
//     box->SetLineColor(kBlack);
//     box->SetLineWidth(2);
//     box->Draw("l");
//     gPad->RedrawAxis();

//     /***********************************************************/
//     /* Iterate through sub-images (b) vector for current scale */
//     /***********************************************************/
//     int counter1 = 0;
//     int counter2 = 0;
//     double scale_factor = pow(3, scale);
//     for(int i=sub_images_first_index; i<=sub_images_last_index; i++)
//     {
//       /*****************************/
//       /* Determine sub-image scale */
//       /*****************************/
//       string sub_image_name = b[i].GetName();
//       int p1 = sub_image_name.find("_")+1;
//       int scl = stoi(sub_image_name.substr(p1, 1), nullptr);
//       if(scl == scale)
//       {
// 	/**********************************/
// 	/* Retrieve sub_image information */
// 	/**********************************/
// 	int sub_image_id = b[i].GetId();
// 	double sub_image_horizontal_resolution = b[i].GetHorizontal_resolution();
// 	double sub_image_vertical_resolution = b[i].GetVertical_resolution();
// 	double sub_image_x_origin = b[i].GetX_origin();
// 	double sub_image_y_origin = b[i].GetY_origin();
// 	string sub_image_x_origin_condition = b[i].GetUpper_left_x();
// 	string sub_image_y_origin_condition = b[i].GetUpper_left_y();

// 	/******************************************************************/
// 	/* Find first and last occurrence of image_id in marks (b) vector */
// 	/******************************************************************/
// 	n = (int)c.size();
// 	field = "image_id";
// 	value = sub_image_id;
// 	int mark_first_index = SearchMarks::FirstOccurence(c, 0, n-1, field, &value);
// 	int mark_last_index = SearchMarks::LastOccurence(c, 0, n-1, field, &value);

// 	/*****************************************************/
// 	/* Iterate through marks (b) vector and plot craters */
// 	/*****************************************************/
// 	for(int j=mark_first_index; j<=mark_last_index; j++)
// 	{
// 	  /*********************************************/
// 	  /* Calculate global x and y position of mark */
// 	  /*********************************************/
// 	  double x = (sub_image_x_origin_condition.compare("MIN") == 0) ?
// 	    sub_image_x_origin+sub_image_horizontal_resolution*c[j].GetX()*scale_factor :
// 	    sub_image_x_origin-sub_image_horizontal_resolution*c[j].GetX()*scale_factor;
// 	  double y = (sub_image_y_origin_condition.compare("MIN") == 0) ?
// 	    sub_image_y_origin+sub_image_vertical_resolution*c[j].GetY()*scale_factor :
// 	    sub_image_y_origin-sub_image_vertical_resolution*c[j].GetY()*scale_factor;
// 	  double r1 = sub_image_horizontal_resolution*c[j].GetDiameter()*scale_factor;
// 	  double r2 = sub_image_vertical_resolution*c[j].GetDiameter()*scale_factor;
// 	  double r = (r1 < r2) ? r1 : r2;

// 	  /***************/
// 	  /* Plot crater */
// 	  /***************/
// 	  el2 = new TEllipse(x, y, r);
// 	  el2->SetFillColor(kBlue);
// 	  el2->Draw();
// 	  //gPad->RedrawAxis();
// 	  counter2++;
// 	}
// 	counter1++;
//       }
//     }
//     cout << "Scale level " << scale << " has " << counter1 << " images and " << counter2 << " craters." << endl;

//     /************************************/
//     /* Plot master image defined origin */
//     /************************************/
//     el = new TEllipse(master_image_x_origin, master_image_y_origin, 50.0);
//     el->SetFillColor(kRed);
//     el->Draw();

//     /**********/
//     /* Legend */
//     /**********/
//     leg = new TLegend(0.7,0.7,0.9,0.9);
//     //leg->SetHeader("","C"); // option "C" allows to center the header
//     buffer = "Image: "+master_image_name;
//     leg->AddEntry(box, buffer.c_str(), "f");
//     leg->AddEntry(el, "Image Origin", "f");
//     leg->AddEntry(el2, "Craters", "f");
//     leg->Draw();
    
//     /*********************/
//     /* Save plot to file */
//     /*********************/
//     filename = master_image_name+"_"+to_string(scale)+"_Craters_Graphic.png";
//     can->SaveAs(filename.c_str());
  
//     /***********************************/
//     /* Free memory reserved for canvas */
//     /***********************************/
//     delete box;
//     delete el;
//     delete leg;
//     delete can;

//     /************************/
//     /* Increase scale level */
//     /************************/
//     scale++;
//   }
// }

void Plot::MasterImage_w_SubImages(ImageSets a, vector <Images> &b, bool selenographic)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double dot;
  double lower_left_latitude;
  double lower_left_longitude;
  double lower_left_x;
  double lower_left_y;
  double lower_right_latitude;
  double lower_right_longitude;
  double lower_right_x;
  double lower_right_y;
  double spacing;
  double upper_left_latitude;
  double upper_left_longitude;
  double upper_left_x;
  double upper_left_y;
  double upper_right_latitude;
  double upper_right_longitude;
  double upper_right_x;
  double upper_right_y;
  double x_high;
  double x_low;
  double x_reference_point;
  double y_high;
  double y_low;
  double y_reference_point;
  int canheight;
  int canwidth;
  int first_index;
  int last_index;
  int master_image_id;
  int n;
  int scale;
  int value;
  string buffer;
  string field;
  string filename;
  string master_image_name;
  TCanvas *can;
  TPolyLine *plot;
  TEllipse *el;
  TH1F *h1;
  TLegend *leg;
  vector <double> X_Coords;
  vector <double> Y_Coords;
  
  /******************************/
  /* Retrieve image information */
  /******************************/
  master_image_name = a.GetName();
  master_image_id = a.GetId();
  lower_left_latitude = a.GetLower_left_latitude();
  lower_left_longitude = a.GetLower_left_longitude();
  lower_left_x = a.GetLower_left_x();
  lower_left_y = a.GetLower_left_y();
  lower_right_latitude = a.GetLower_right_latitude();
  lower_right_longitude = a.GetLower_right_longitude();
  lower_right_x = a.GetLower_right_x();
  lower_right_y = a.GetLower_right_y();
  upper_left_latitude = a.GetUpper_left_latitude();
  upper_left_longitude = a.GetUpper_left_longitude();
  upper_left_x = a.GetUpper_left_x();
  upper_left_y = a.GetUpper_left_y();
  upper_right_latitude = a.GetUpper_right_latitude();
  upper_right_longitude = a.GetUpper_right_longitude();
  upper_right_x = a.GetUpper_right_x();
  upper_right_y = a.GetUpper_right_y();

  /**************************/
  /* Sort images (b) vector */
  /**************************/
  field = "image_set_id";
  SortImages sortimages(b, field);
  sortimages.arrange();
  b = sortimages.GetImages();
  //RetrieveImages::Display(b); exit(0);

  /***********************************************************************/
  /* Find first and last occurrence of image_set_id in images (b) vector */
  /***********************************************************************/
  n = (int)b.size();
  value = master_image_id;
  first_index = SearchImages::FirstOccurence(b, 0, n-1, field, &value);
  last_index = SearchImages::LastOccurence(b, 0, n-1, field, &value);

  /*****************************/
  /* Boundary for master image */
  /*****************************/
  if(selenographic)
  {
    X_Coords.push_back(upper_left_longitude);
    Y_Coords.push_back(upper_left_latitude);
    X_Coords.push_back(upper_right_longitude);
    Y_Coords.push_back(upper_right_latitude);    
    X_Coords.push_back(lower_right_longitude);
    Y_Coords.push_back(lower_right_latitude);
    X_Coords.push_back(lower_left_longitude);
    Y_Coords.push_back(lower_left_latitude);
    X_Coords.push_back(upper_left_longitude);
    Y_Coords.push_back(upper_left_latitude);
    dot = 0.01*abs(upper_left_longitude-upper_right_longitude);
  }
  else
  {
    X_Coords.push_back(upper_left_x);
    Y_Coords.push_back(upper_left_y);
    X_Coords.push_back(upper_right_x);
    Y_Coords.push_back(upper_right_y);
    X_Coords.push_back(lower_right_x);
    Y_Coords.push_back(lower_right_y);
    X_Coords.push_back(lower_left_x);
    Y_Coords.push_back(lower_left_y);
    X_Coords.push_back(upper_left_x);
    Y_Coords.push_back(upper_left_y);
    dot = 0.01*abs(upper_left_x-upper_right_x);
  }
  n = (int)X_Coords.size();
  plot = new TPolyLine(n, X_Coords.data(), Y_Coords.data());
  plot->SetLineColor(kGreen);
  plot->SetLineWidth(2);
  
  /*****************/
  /* Axes settings */
  /*****************/
  if(selenographic)
  {
    buffer = master_image_name+"; X [Degree]; Y [Degree]";
    x_high = a.GetMaximum_longitude();
    x_low = a.GetMinimum_longitude();
    x_reference_point = upper_left_longitude;
    y_high = a.GetMaximum_latitude();
    y_low = a.GetMinimum_latitude();
    y_reference_point = upper_left_latitude;
    spacing = 1E-2;
  }
  else
  {
    buffer = master_image_name+"; X [m]; Y [m]";
    x_high = a.GetMaximum_x();
    x_low = a.GetMinimum_x();
    x_reference_point = upper_left_x;
    y_high = a.GetMaximum_y();
    y_low = a.GetMinimum_y();
    y_reference_point = upper_left_y;
    spacing = 1E3;
  }
  
  scale = 0;
  while(scale < 3)
  {
    /*********************/
    /* Initialize Canvas */
    /*********************/
    canheight = 1200;
    canwidth = 800;
    can = new TCanvas("Canvas", "", canheight, canwidth);
    can->SetGridx();
    can->SetGridy();

    /**************/
    /* Draw frame */
    /**************/
    h1 = can->DrawFrame(x_low-spacing, y_low-spacing, x_high+spacing, y_high+spacing, buffer.c_str());
    h1->GetYaxis()->SetNdivisions(5);
    h1->GetXaxis()->SetNdivisions(5);

    /*********************/
    /* Plot master image */
    /*********************/
    plot->Draw();
    //gPad->RedrawAxis();

    /***************************************************************************/
    /* Iterate through images (b) vector and plot sub-images for current scale */
    /***************************************************************************/
    TPolyLine *sub_image_plot;
    int counter = 0;
    for(int i=first_index; i<=last_index; i++)
    {
      /*****************************/
      /* Determine sub-image scale */
      /*****************************/
      string sub_image_name = b[i].GetName();
      int p1 = sub_image_name.find("_")+1;
      int scl = stoi(sub_image_name.substr(p1, 1), nullptr);
      if(scl == scale)
      {
	/******************************************/
	/* Retrieve bounding region for sub-image */
	/******************************************/
	double sub_image_lower_left_latitude = b[i].GetLower_left_latitude();
	double sub_image_lower_left_longitude = b[i].GetLower_left_longitude();
	double sub_image_lower_left_x = b[i].GetLower_left_x();
	double sub_image_lower_left_y = b[i].GetLower_left_y();
	double sub_image_lower_right_latitude = b[i].GetLower_right_latitude();
	double sub_image_lower_right_longitude = b[i].GetLower_right_longitude();
	double sub_image_lower_right_x = b[i].GetLower_right_x();
	double sub_image_lower_right_y = b[i].GetLower_right_y();
	double sub_image_upper_left_latitude = b[i].GetUpper_left_latitude();
	double sub_image_upper_left_longitude = b[i].GetUpper_left_longitude();
	double sub_image_upper_left_x = b[i].GetUpper_left_x();
	double sub_image_upper_left_y = b[i].GetUpper_left_y();
	double sub_image_upper_right_latitude = b[i].GetUpper_right_latitude();
	double sub_image_upper_right_longitude = b[i].GetUpper_right_longitude();
	double sub_image_upper_right_x = b[i].GetUpper_right_x();
	double sub_image_upper_right_y = b[i].GetUpper_right_y();

	/*****************************************************/
	/* Store wanted bounding region points for sub-image */
	/*****************************************************/
	vector <double> sub_image_x_coords;
	vector <double> sub_image_y_coords;
	if(selenographic)
	{
	  sub_image_x_coords.push_back(sub_image_upper_left_longitude);
	  sub_image_y_coords.push_back(sub_image_upper_left_latitude);
	  sub_image_x_coords.push_back(sub_image_upper_right_longitude);
	  sub_image_y_coords.push_back(sub_image_upper_right_latitude);    
	  sub_image_x_coords.push_back(sub_image_lower_right_longitude);
	  sub_image_y_coords.push_back(sub_image_lower_right_latitude);
	  sub_image_x_coords.push_back(sub_image_lower_left_longitude);
	  sub_image_y_coords.push_back(sub_image_lower_left_latitude);
	  sub_image_x_coords.push_back(sub_image_upper_left_longitude);
	  sub_image_y_coords.push_back(sub_image_upper_left_latitude);
	}
	else
	{
	  sub_image_x_coords.push_back(sub_image_upper_left_x);
	  sub_image_y_coords.push_back(sub_image_upper_left_y);
	  sub_image_x_coords.push_back(sub_image_upper_right_x);
	  sub_image_y_coords.push_back(sub_image_upper_right_y);
	  sub_image_x_coords.push_back(sub_image_lower_right_x);
	  sub_image_y_coords.push_back(sub_image_lower_right_y);
	  sub_image_x_coords.push_back(sub_image_lower_left_x);
	  sub_image_y_coords.push_back(sub_image_lower_left_y);
	  sub_image_x_coords.push_back(sub_image_upper_left_x);
	  sub_image_y_coords.push_back(sub_image_upper_left_y);
	}

	/******************/
	/* Plot sub-image */
	/******************/
	n = (int)sub_image_x_coords.size();
	sub_image_plot = new TPolyLine(n, sub_image_x_coords.data(), sub_image_y_coords.data());
	sub_image_plot->SetLineColor(kCyan);
	sub_image_plot->SetLineWidth(2);
	sub_image_plot->Draw();
	counter++;
      }
    }
    //cout << "Scale level " << scale << " has " << counter << " number of images." << endl;

    /***********************/
    /* Plot defined origin */
    /***********************/
    el = new TEllipse(x_reference_point, y_reference_point, dot);
    el->SetFillColorAlpha(kRed, 0.50);
    el->SetFillStyle(4050);
    el->SetLineColor(kRed);
    el->Draw();

    /**********/
    /* Legend */
    /**********/
    leg = new TLegend(0.7,0.7,0.9,0.9);
    //leg->SetHeader("","C"); // option "C" allows to center the header
    buffer = "Image: "+master_image_name;
    leg->AddEntry(plot, buffer.c_str(), "f");
    leg->AddEntry(sub_image_plot, "Sub-images", "f");
    leg->AddEntry(el, "Image Origin", "f");
    leg->Draw();

    /*********************/
    /* Save plot to file */
    /*********************/
    filename = master_image_name+"_"+to_string(scale)+"_Graphic.ps";
    can->SaveAs(filename.c_str());

    /***********************************/
    /* Free memory reserved for canvas */
    /***********************************/
    delete el;
    delete leg;
    delete can;
    delete sub_image_plot;

    /************************/
    /* Increase scale level */
    /************************/
    scale++;
  }

  /*********************************/
  /* Free memory reserved for plot */
  /*********************************/
  delete plot;
}

// void Plot::MasterImages_w_SubImages(ImageSets a, ImageSets b, vector <Images> &c)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double spacing = 1E3;
//   double image1_x_high;
//   double image1_x_low;
//   double image1_x_origin;
//   double image1_y_high;
//   double image1_y_low;
//   double image1_y_origin;
//   double image2_x_high;
//   double image2_x_low;
//   double image2_x_origin;
//   double image2_y_high;
//   double image2_y_low;
//   double image2_y_origin;
//   double x_max;
//   double x_min;
//   double y_max;
//   double y_min;
//   int canheight;
//   int canwidth;
//   int first_index1;
//   int first_index2;
//   int last_index1;
//   int last_index2;
//   int master_image1_id;
//   int master_image2_id;
//   int scale;
//   string buffer;
//   string field;
//   string filename;
//   string image1_name;
//   string image2_name;
//   TCanvas *can;
//   TBox *bb1;
//   TBox *bb2;
//   TBox *box1;
//   TBox *box2;
//   TEllipse *el1;
//   TEllipse *el2;
//   TLegend *leg;
    
//   /*******************************/
//   /* Retrieve image1 information */
//   /*******************************/
//   image1_name = a.GetName();
//   master_image1_id = a.GetId();
//   image1_x_high = a.GetX_high();
//   image1_x_low = a.GetX_low();
//   image1_x_origin = a.GetX_origin();
//   image1_y_high = a.GetY_high();
//   image1_y_low = a.GetY_low();
//   image1_y_origin = a.GetY_origin();

//   /*******************************/
//   /* Retrieve image2 information */
//   /*******************************/
//   image2_name = b.GetName();
//   master_image2_id = b.GetId();
//   image2_x_high = b.GetX_high();
//   image2_x_low = b.GetX_low();
//   image2_x_origin = b.GetX_origin();
//   image2_y_high = b.GetY_high();
//   image2_y_low = b.GetY_low();
//   image2_y_origin = b.GetY_origin();

//   /************************************************/
//   /* Determine minimum and maximum x and y values */
//   /************************************************/
//   x_max = (image1_x_high > image2_x_high) ? image1_x_high : image2_x_high;
//   x_min = (image1_x_low < image2_x_low) ? image1_x_low : image2_x_low;
//   y_max = (image1_y_high > image2_y_high) ? image1_y_high : image2_y_high;
//   y_min = (image1_y_low < image2_y_low) ? image1_y_low : image2_y_low;

//   /**************************/
//   /* Sort images (b) vector */
//   /**************************/
//   field = "image_set_id";
//   SortImages sortimages(c, field);
//   sortimages.arrange();
//   c = sortimages.GetImages();
//   //RetrieveImages::Display(c); exit(0);

//   /***********************************************************************/
//   /* Find first and last occurrence of image_set_id in images (b) vector */
//   /***********************************************************************/
//   int n = (int)c.size();
//   int value = master_image1_id;
//   first_index1 = SearchImages::FirstOccurence(c, 0, n-1, field, &value);
//   last_index1 = SearchImages::LastOccurence(c, 0, n-1, field, &value);
//   value = master_image2_id;
//   first_index2 = SearchImages::FirstOccurence(c, 0, n-1, field, &value);
//   last_index2 = SearchImages::LastOccurence(c, 0, n-1, field, &value);

//   scale = 0;
//   while(scale < 3)
//   {
//     /*********************/
//     /* Initialize Canvas */
//     /*********************/
//     canheight = 800;
//     canwidth = 800;
//     can = new TCanvas("Canvas", "", canheight, canwidth);
//     can->SetGridx();
//     can->SetGridy();

//     /*************/
//     /* Draw axes */
//     /*************/
//     buffer = image1_name+" vs "+image2_name+"; X [m]; Y [m]";
//     TH1F *h1 = can->DrawFrame(x_min-spacing, y_min-spacing, x_max+spacing, y_max+spacing, buffer.c_str());
//     h1->GetYaxis()->SetNdivisions(5);
//     h1->GetXaxis()->SetNdivisions(5);

//     /**********************/
//     /* Plot master image1 */
//     /**********************/
//     box1 = new TBox(image1_x_low, image1_y_low, image1_x_high, image1_y_high);
//     box1->SetFillColor(kGreen);
//     box1->SetFillStyle(1001);
//     box1->SetLineColor(kBlack);
//     box1->SetLineWidth(2);
//     box1->Draw("l");
//     gPad->RedrawAxis();

//     /**********************/
//     /* Plot master image2 */
//     /**********************/
//     box2 = new TBox(image2_x_low, image2_y_low, image2_x_high, image2_y_high);
//     box2->SetFillColor(kCyan);
//     box2->SetFillStyle(1001);
//     box2->SetLineColor(kBlack);
//     box2->SetLineWidth(2);
//     box2->Draw("l");
//     gPad->RedrawAxis();

//     /***************************************************************************/
//     /* Iterate through images (b) vector and plot sub-images for current scale */
//     /***************************************************************************/
//     int counter1 = 0;
//     for(int i=first_index1; i<=last_index1; i++)
//     {
//       /*****************************/
//       /* Determine sub-image scale */
//       /*****************************/
//       string cimage_name = c[i].GetName();
//       int p1 = cimage_name.find("_")+1;
//       int scl = stoi(cimage_name.substr(p1, 1), nullptr);
//       if(scl == scale)
//       {
// 	/******************************************/
// 	/* Retrieve bounding region for sub-image */
// 	/******************************************/
// 	double cx_high = c[i].GetX_high();
// 	double cx_low = c[i].GetX_low();
// 	double cy_high = c[i].GetY_high();
// 	double cy_low = c[i].GetY_low();

// 	/******************/
// 	/* Plot sub-image */
// 	/******************/
// 	bb1 = new TBox(cx_low, cy_low, cx_high, cy_high);
// 	bb1->SetFillColor(kBlue);
// 	bb1->SetFillStyle(1001);
// 	bb1->SetLineColor(kBlack);
// 	bb1->SetLineWidth(1);
// 	bb1->Draw("l");
// 	gPad->RedrawAxis();
// 	counter1++;
//       }
//     }
//     //cout << "Scale level " << scale << " has " << counter1 << " number of images." << endl;

//     int counter2 = 0;
//     for(int i=first_index2; i<=last_index2; i++)
//     {
//       /*****************************/
//       /* Determine sub-image scale */
//       /*****************************/
//       string cimage_name = c[i].GetName();
//       int p1 = cimage_name.find("_")+1;
//       int scl = stoi(cimage_name.substr(p1, 1), nullptr);
//       if(scl == scale)
//       {
// 	/******************************************/
// 	/* Retrieve bounding region for sub-image */
// 	/******************************************/
// 	double cx_high = c[i].GetX_high();
// 	double cx_low = c[i].GetX_low();
// 	double cy_high = c[i].GetY_high();
// 	double cy_low = c[i].GetY_low();

// 	/******************/
// 	/* Plot sub-image */
// 	/******************/
// 	bb2 = new TBox(cx_low, cy_low, cx_high, cy_high);
// 	bb2->SetFillColor(kBlue+3);
// 	bb2->SetFillStyle(1001);
// 	bb2->SetLineColor(kBlack);
// 	bb2->SetLineWidth(1);
// 	bb2->Draw("l");
// 	gPad->RedrawAxis();
// 	counter2++;
//       }
//     }
//     //cout << "Scale level " << scale << " has " << counter2 << " number of images." << endl;

//     /***********************/
//     /* Plot defined origin */
//     /***********************/
//     el1 = new TEllipse(image1_x_origin, image1_y_origin, 50.0);
//     el1->SetFillColor(kRed);
//     el1->Draw();

//     /***********************/
//     /* Plot defined origin */
//     /***********************/
//     el2 = new TEllipse(image2_x_origin, image2_y_origin, 50.0);
//     el2->SetFillColor(kViolet);
//     el2->Draw();
    
//     /**********/
//     /* Legend */
//     /**********/
//     leg = new TLegend(0.7,0.7,0.9,0.9);
//     //leg->SetHeader("","C"); // option "C" allows to center the header
//     buffer = "Image1: "+image1_name;
//     leg->AddEntry(box1, buffer.c_str(), "f");
//     buffer = "Image2: "+image2_name;
//     leg->AddEntry(box2, buffer.c_str(), "f");
//     leg->AddEntry(bb1, "Sub-images", "f");
//     leg->AddEntry(bb2, "Sub-images", "f");
//     leg->AddEntry(el1, "Image1 Origin", "f");
//     leg->AddEntry(el2, "Image2 Origin", "f");
//     leg->Draw();

//     /*********************/
//     /* Save plot to file */
//     /*********************/
//     filename = image1_name+"_"+to_string(scale)+"_vs_"+image2_name+"_"+to_string(scale)+"_Graphic.ps";
//     can->SaveAs(filename.c_str());

//     /***********************************/
//     /* Free memory reserved for canvas */
//     /***********************************/
//     delete box1;
//     delete box2;
//     delete el1;
//     delete el2;
//     delete leg;
//     delete can;

//     /************************/
//     /* Increase scale level */
//     /************************/
//     scale++;
//   }
// }

// // void Plot::PlotMasterImage(ImageSets image)
// // {
// //   /*******************************************/
// //   /* Declaration/Initialization of variables */
// //   /*******************************************/
// //   double xhigh;
// //   double xlow;
// //   double yhigh;
// //   double ylow;
  
// //   /***************************/
// //   /* Retrieve image boundary */
// //   /***************************/
// //   // xlow = ;
// //   // xhigh = ;
// //   // ylow = ;
// //   // yhigh = ;

// //   /*********************/
// //   /* Initialize Canvas */
// //   /*********************/

// //   return;
// // }

void Plot::PlotOverlap(OverlappedImages a, bool print_coordinates)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double dot;
  double image1_x_high;
  double image1_x_low;
  double image1_y_high;
  double image1_y_low;
  double image2_x_high;
  double image2_x_low;
  double image2_y_high;
  double image2_y_low;
  double spacing;
  double x_high;
  double x_low;
  double x_reference_point;
  double y_high;
  double y_low;
  double y_reference_point;
  int canheight;
  int canwidth;
  int n;
  string buffer;
  string filename;
  string image1_name;
  string image2_name;
  TCanvas *can;
  TPolyLine *plot1;
  TPolyLine *plot2;
  TPolyLine *plot3;
  TEllipse *el1;
  TEllipse *el2;
  TH1F *h1;
  TLegend *leg;
  vector <double> Image1_X_Coords;
  vector <double> Image1_Y_Coords;
  vector <double> Image2_X_Coords;
  vector <double> Image2_Y_Coords;
  vector <double> Overplot_X_Coords;
  vector <double> Overplot_Y_Coords;

  /***********************/
  /* Image 1 Information */
  /***********************/
  image1_name = a.GetImage1_name();
  Image1_X_Coords.push_back(a.GetImage1_upper_left_longitude());
  Image1_Y_Coords.push_back(a.GetImage1_upper_left_latitude());
  Image1_X_Coords.push_back(a.GetImage1_upper_right_longitude());
  Image1_Y_Coords.push_back(a.GetImage1_upper_right_latitude());    
  Image1_X_Coords.push_back(a.GetImage1_lower_right_longitude());
  Image1_Y_Coords.push_back(a.GetImage1_lower_right_latitude());
  Image1_X_Coords.push_back(a.GetImage1_lower_left_longitude());
  Image1_Y_Coords.push_back(a.GetImage1_lower_left_latitude());
  Image1_X_Coords.push_back(a.GetImage1_upper_left_longitude());
  Image1_Y_Coords.push_back(a.GetImage1_upper_left_latitude());

  /***********************/
  /* Image 2 Information */
  /***********************/
  image2_name = a.GetImage2_name();
  Image2_X_Coords.push_back(a.GetImage2_upper_left_longitude());
  Image2_Y_Coords.push_back(a.GetImage2_upper_left_latitude());
  Image2_X_Coords.push_back(a.GetImage2_upper_right_longitude());
  Image2_Y_Coords.push_back(a.GetImage2_upper_right_latitude());    
  Image2_X_Coords.push_back(a.GetImage2_lower_right_longitude());
  Image2_Y_Coords.push_back(a.GetImage2_lower_right_latitude());
  Image2_X_Coords.push_back(a.GetImage2_lower_left_longitude());
  Image2_Y_Coords.push_back(a.GetImage2_lower_left_latitude());
  Image2_X_Coords.push_back(a.GetImage2_upper_left_longitude());
  Image2_Y_Coords.push_back(a.GetImage2_upper_left_latitude());

  /*********************************/
  /* Overplot Plotting Coordinates */
  /*********************************/
  Overplot_X_Coords.push_back(a.GetOverlap_upper_left_longitude());
  Overplot_Y_Coords.push_back(a.GetOverlap_upper_left_latitude());
  Overplot_X_Coords.push_back(a.GetOverlap_upper_right_longitude());
  Overplot_Y_Coords.push_back(a.GetOverlap_upper_right_latitude());    
  Overplot_X_Coords.push_back(a.GetOverlap_lower_right_longitude());
  Overplot_Y_Coords.push_back(a.GetOverlap_lower_right_latitude());
  Overplot_X_Coords.push_back(a.GetOverlap_lower_left_longitude());
  Overplot_Y_Coords.push_back(a.GetOverlap_lower_left_latitude());
  Overplot_X_Coords.push_back(a.GetOverlap_upper_left_longitude());
  Overplot_Y_Coords.push_back(a.GetOverlap_upper_left_latitude());
  
  /*********************/
  /* Initialize Canvas */
  /*********************/
  canheight = 1200;
  canwidth = 500;
  can = new TCanvas("Canvas", "", canheight, canwidth);
  can->SetGridx();
  can->SetGridy();

  /***************************/
  /* Determine plotting area */
  /***************************/
  if(Image1_X_Coords[0] < Image1_X_Coords[1])
  {
    image1_x_high = (Image1_X_Coords[1] > Image1_X_Coords[2]) ? Image1_X_Coords[1] : Image1_X_Coords[2];
    image1_x_low  = (Image1_X_Coords[0] < Image1_X_Coords[3]) ? Image1_X_Coords[0] : Image1_X_Coords[3];
  }
  else
  {
    image1_x_high = (Image1_X_Coords[0] > Image1_X_Coords[3]) ? Image1_X_Coords[0] : Image1_X_Coords[3];
    image1_x_low  = (Image1_X_Coords[1] < Image1_X_Coords[2]) ? Image1_X_Coords[1] : Image1_X_Coords[2];
  }
  if(Image1_Y_Coords[0] < Image1_Y_Coords[3])
  {
    image1_y_high = (Image1_Y_Coords[2] > Image1_Y_Coords[3]) ? Image1_Y_Coords[2] : Image1_Y_Coords[3];
    image1_y_low  = (Image1_Y_Coords[0] < Image1_Y_Coords[1]) ? Image1_Y_Coords[0] : Image1_Y_Coords[1];
  }
  else
  {
    image1_y_high = (Image1_Y_Coords[0] > Image1_Y_Coords[1]) ? Image1_Y_Coords[0] : Image1_Y_Coords[1];
    image1_y_low  = (Image1_Y_Coords[2] < Image1_Y_Coords[3]) ? Image1_Y_Coords[2] : Image1_Y_Coords[3];
  }
  if(Image2_X_Coords[0] < Image2_X_Coords[1])
  {
    image2_x_high = (Image2_X_Coords[1] > Image2_X_Coords[2]) ? Image2_X_Coords[1] : Image2_X_Coords[2];
    image2_x_low  = (Image2_X_Coords[0] < Image2_X_Coords[3]) ? Image2_X_Coords[0] : Image2_X_Coords[3];
  }
  else
  {
    image2_x_high = (Image2_X_Coords[0] > Image2_X_Coords[3]) ? Image2_X_Coords[0] : Image2_X_Coords[3];
    image2_x_low  = (Image2_X_Coords[1] < Image2_X_Coords[2]) ? Image2_X_Coords[1] : Image2_X_Coords[2];
  }
  if(Image2_Y_Coords[0] < Image2_Y_Coords[3])
  {
    image2_y_high = (Image2_Y_Coords[2] > Image2_Y_Coords[3]) ? Image2_Y_Coords[2] : Image2_Y_Coords[3];
    image2_y_low  = (Image2_Y_Coords[0] < Image2_Y_Coords[1]) ? Image2_Y_Coords[0] : Image2_Y_Coords[1];
  }
  else
  {
    image2_y_high = (Image2_Y_Coords[0] > Image2_Y_Coords[1]) ? Image2_Y_Coords[0] : Image2_Y_Coords[1];
    image2_y_low  = (Image2_Y_Coords[2] < Image2_Y_Coords[3]) ? Image2_Y_Coords[2] : Image2_Y_Coords[3];
  }
  x_high = (image1_x_high > image2_x_high) ? image1_x_high : image2_x_high;
  x_low = (image1_x_low < image2_x_low) ? image1_x_low : image2_x_low;
  y_high = (image1_y_high > image2_y_high) ? image1_y_high : image2_y_high;
  y_low = (image1_y_low < image2_y_low) ? image1_y_low : image2_y_low;

  
  /*************/
  /* Draw axes */
  /*************/
  buffer = image1_name+" vs "+image2_name+"; X [Degree]; Y [Degree]";
  spacing = 1E-4;
  h1 = can->DrawFrame(x_low-spacing, y_low-spacing, x_high+spacing, y_high+spacing, buffer.c_str());
  h1->GetYaxis()->SetNdivisions(10);
  h1->GetXaxis()->SetNdivisions(10);
  
  /****************/
  /* Plot image 1 */
  /****************/
  n = (int)Image1_X_Coords.size();
  plot1 = new TPolyLine(n, Image1_X_Coords.data(), Image1_Y_Coords.data());
  plot1->SetLineColor(kBlue);
  plot1->SetLineWidth(2);
  plot1->Draw();

  /****************/
  /* Plot image 2 */
  /****************/
  n = (int)Image2_X_Coords.size();
  plot2 = new TPolyLine(n, Image2_X_Coords.data(), Image2_Y_Coords.data());
  plot2->SetLineColor(kYellow);
  plot2->SetLineWidth(2);
  plot2->Draw();

  /****************/
  /* Plot Overlap */
  /****************/
  n = (int)Overplot_X_Coords.size();
  plot3 = new TPolyLine(n, Overplot_X_Coords.data(), Overplot_Y_Coords.data());
  plot3->SetLineColor(kGreen);
  plot3->SetLineWidth(2);
  plot3->Draw();
  
  /*************************/
  /* Plot 1 defined origin */
  /*************************/
  x_reference_point = a.GetImage1_upper_left_longitude();
  y_reference_point = a.GetImage1_upper_left_latitude();
  dot = 0.01*abs(a.GetImage1_upper_left_longitude()-a.GetImage1_upper_right_longitude());
  el1 = new TEllipse(x_reference_point, y_reference_point, dot);
  el1->SetFillColorAlpha(kBlue, 0.50);
  el1->SetFillStyle(4050);
  el1->SetLineColor(kRed);
  el1->Draw();

  /*************************/
  /* Plot 2 defined origin */
  /*************************/
  x_reference_point = a.GetImage2_upper_left_longitude();
  y_reference_point = a.GetImage2_upper_left_latitude();
  dot = 0.01*abs(a.GetImage2_upper_left_longitude()-a.GetImage2_upper_right_longitude());
  el2 = new TEllipse(x_reference_point, y_reference_point, dot);
  el2->SetFillColorAlpha(kGreen, 0.50);
  el2->SetFillStyle(4050);
  el2->SetLineColor(kRed);
  el2->Draw();
  
  /**********/
  /* Legend */
  /**********/
  leg = new TLegend(0.7,0.7,0.9,0.9);
  //leg->SetHeader("","C"); // option "C" allows to center the header
  buffer = "Sub-image: "+image1_name;
  leg->AddEntry(plot1, buffer.c_str(), "f");
  buffer = "Sub-image: "+image2_name;
  leg->AddEntry(plot2, buffer.c_str(), "f");
  buffer = "Overplot Region";
  leg->AddEntry(plot3, buffer.c_str(), "f");
  leg->AddEntry(el1, "Image 1 Origin", "f");
  leg->AddEntry(el2, "Image 2 Origin", "f");
  leg->Draw();

  /*********************/
  /* Save plot to file */
  /*********************/
  filename = image1_name+"_vs_"+image2_name+"_Graphic.ps";
  can->SaveAs(filename.c_str());

  /*******************************/
  /* Print coordinates to screen */
  /*******************************/
  if(print_coordinates)
  {
    printf("Coordinates for image 1 %s.\n", image1_name.c_str());
    for(int i=0; i<n; i++)
    {
      printf("Corner %d: %lf degrees longitude and %lf degrees latitude\n", i+1, Image1_X_Coords[i], Image1_Y_Coords[i]);
    }
    printf("\nCoordinates for image 2 %s.\n", image2_name.c_str());
    for(int i=0; i<n; i++)
    {
      printf("Corner %d: %lf degrees longitude and %lf degrees latitude\n", i+1, Image2_X_Coords[i], Image2_Y_Coords[i]);
    }
    printf("\nCoordinates for overplot region.\n");
    for(int i=0; i<n; i++)
    {
      printf("Corner %d: %lf degrees longitude and %lf degrees latitude\n", i+1, Overplot_X_Coords[i], Overplot_Y_Coords[i]);
    }
  }
  
  /***********************************/
  /* Free memory reserved for canvas */
  /***********************************/
  delete plot1;
  delete plot2;
  delete plot3;
  delete el1;
  delete el2;
  delete leg;
  delete can;
}

void Plot::SubImage(Images a, bool selenographic, bool print_coordinates)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double dot;
  double lower_left_latitude;
  double lower_left_longitude;
  double lower_left_x;
  double lower_left_y;
  double lower_right_latitude;
  double lower_right_longitude;
  double lower_right_x;
  double lower_right_y;
  double spacing;
  double upper_left_latitude;
  double upper_left_longitude;
  double upper_left_x;
  double upper_left_y;
  double upper_right_latitude;
  double upper_right_longitude;
  double upper_right_x;
  double upper_right_y;
  double x_high;
  double x_low;
  double x_reference_point;
  double y_high;
  double y_low;
  double y_reference_point;
  int canheight;
  int canwidth;
  int n;
  string buffer;
  string filename;
  string image_name;
  TCanvas *can;
  TPolyLine *plot;
  TEllipse *el;
  TH1F *h1;
  TLegend *leg;
  vector <double> X_Coords;
  vector <double> Y_Coords;
    
  /******************************/
  /* Retrieve image information */
  /******************************/
  image_name = a.GetName();
  lower_left_latitude = a.GetLower_left_latitude();
  lower_left_longitude = a.GetLower_left_longitude();
  lower_left_x = a.GetLower_left_x();
  lower_left_y = a.GetLower_left_y();
  lower_right_latitude = a.GetLower_right_latitude();
  lower_right_longitude = a.GetLower_right_longitude();
  lower_right_x = a.GetLower_right_x();
  lower_right_y = a.GetLower_right_y();
  upper_left_latitude = a.GetUpper_left_latitude();
  upper_left_longitude = a.GetUpper_left_longitude();
  upper_left_x = a.GetUpper_left_x();
  upper_left_y = a.GetUpper_left_y();
  upper_right_latitude = a.GetUpper_right_latitude();
  upper_right_longitude = a.GetUpper_right_longitude();
  upper_right_x = a.GetUpper_right_x();
  upper_right_y = a.GetUpper_right_y();

  /*********************/
  /* Initialize Canvas */
  /*********************/
  canheight = 1200;
  canwidth = 600;
  can = new TCanvas("Canvas", "", canheight, canwidth);
  can->SetGridx();
  can->SetGridy();

  /*************/
  /* Draw axes */
  /*************/
  if(selenographic)
  {
    buffer = image_name+"; X [Degree]; Y [Degree]";
    x_high = a.GetMaximum_longitude();
    x_low = a.GetMinimum_longitude();
    x_reference_point = upper_left_longitude;
    y_high = a.GetMaximum_latitude();
    y_low = a.GetMinimum_latitude();
    y_reference_point = upper_left_latitude;
    spacing = 1E-4;
  }
  else
  {
    buffer = image_name+"; X [m]; Y [m]";
    x_high = a.GetMaximum_x();
    x_low = a.GetMinimum_x();
    x_reference_point = upper_left_x;
    y_high = a.GetMaximum_y();
    y_low = a.GetMinimum_y();
    y_reference_point = upper_left_y;
    spacing = 1E3;
  }
  h1 = can->DrawFrame(x_low-spacing, y_low-spacing, x_high+spacing, y_high+spacing, buffer.c_str());
  h1->GetYaxis()->SetNdivisions(10);
  h1->GetXaxis()->SetNdivisions(10);

  /**************/
  /* Plot image */
  /**************/
  if(selenographic)
  {
    X_Coords.push_back(upper_left_longitude);
    Y_Coords.push_back(upper_left_latitude);
    X_Coords.push_back(upper_right_longitude);
    Y_Coords.push_back(upper_right_latitude);    
    X_Coords.push_back(lower_right_longitude);
    Y_Coords.push_back(lower_right_latitude);
    X_Coords.push_back(lower_left_longitude);
    Y_Coords.push_back(lower_left_latitude);
    X_Coords.push_back(upper_left_longitude);
    Y_Coords.push_back(upper_left_latitude);
    dot = 0.01*abs(upper_left_longitude-upper_right_longitude);
  }
  else
  {
    X_Coords.push_back(upper_left_x);
    Y_Coords.push_back(upper_left_y);
    X_Coords.push_back(upper_right_x);
    Y_Coords.push_back(upper_right_y);
    X_Coords.push_back(lower_right_x);
    Y_Coords.push_back(lower_right_y);
    X_Coords.push_back(lower_left_x);
    Y_Coords.push_back(lower_left_y);
    X_Coords.push_back(upper_left_x);
    Y_Coords.push_back(upper_left_y);
    dot = 0.01*abs(upper_left_x-upper_right_x);
  }
  n = (int)X_Coords.size();
  plot = new TPolyLine(n, X_Coords.data(), Y_Coords.data());
  plot->SetLineColor(kGreen);
  plot->SetLineWidth(2);
  plot->Draw();

  /***********************/
  /* Plot defined origin */
  /***********************/
  el = new TEllipse(x_reference_point, y_reference_point, dot);
  el->SetFillColorAlpha(kRed, 0.50);
  el->SetFillStyle(4050);
  el->SetLineColor(kRed);
  el->Draw();

  /**********/
  /* Legend */
  /**********/
  leg = new TLegend(0.7,0.7,0.9,0.9);
  //leg->SetHeader("","C"); // option "C" allows to center the header
  buffer = "Sub-image: "+image_name;
  leg->AddEntry(plot, buffer.c_str(), "f");
  leg->AddEntry(el, "Image Origin", "f");
  leg->Draw();

  /*********************/
  /* Save plot to file */
  /*********************/
  filename = image_name+"_Graphic.ps";
  can->SaveAs(filename.c_str());

  /*******************************/
  /* Print coordinates to screen */
  /*******************************/
  if(print_coordinates)
  {
    printf("Coordinates for image %s.\n", image_name.c_str());
    for(int i=0; i<n; i++)
    {
      if(selenographic)
	printf("Corner %d: %lf degrees longitude and %lf degrees latitude\n", i+1, X_Coords[i], Y_Coords[i]);
      else
	printf("Corner %d: %lf meters in x and %lf meters in y\n", i+1, X_Coords[i], Y_Coords[i]);
    }
  }
  
  /***********************************/
  /* Free memory reserved for canvas */
  /***********************************/
  delete plot;
  delete el;
  delete leg;
  delete can;
}

void Plot::SubImages(Images a, Images b, bool selenographic, bool print_coordinates)
{
  /****************************************************/
  /* Declaration/Initialization of function variables */
  /****************************************************/
  double image1_dot;
  double image1_x_high;
  double image1_x_low;
  double image1_x_reference;
  double image1_y_high;
  double image1_y_low;
  double image1_y_reference;
  double image2_dot;
  double image2_x_high;
  double image2_x_low;
  double image2_x_reference;
  double image2_y_high;
  double image2_y_low;
  double image2_y_reference;
  double spacing;
  double x_high;
  double x_low;
  double y_high;
  double y_low;
  int canheight;
  int canwidth;
  int n;
  string buffer;
  string filename;
  string image1_name;
  string image2_name;
  TCanvas *can;
  TPolyLine *plot1;
  TPolyLine *plot2;
  TEllipse *el1;
  TEllipse *el2;
  TH1F *h1;
  TLegend *leg;
  vector <double> Image1_X_Coords;
  vector <double> Image1_Y_Coords;
  vector <double> Image2_X_Coords;
  vector <double> Image2_Y_Coords;

  /***********************/
  /* Image 1 Information */
  /***********************/
  image1_name = a.GetName();
  if(selenographic)
  {    
    Image1_X_Coords.push_back(a.GetUpper_left_longitude());
    Image1_Y_Coords.push_back(a.GetUpper_left_latitude());
    Image1_X_Coords.push_back(a.GetUpper_right_longitude());
    Image1_Y_Coords.push_back(a.GetUpper_right_latitude());    
    Image1_X_Coords.push_back(a.GetLower_right_longitude());
    Image1_Y_Coords.push_back(a.GetLower_right_latitude());
    Image1_X_Coords.push_back(a.GetLower_left_longitude());
    Image1_Y_Coords.push_back(a.GetLower_left_latitude());
    Image1_X_Coords.push_back(a.GetUpper_left_longitude());
    Image1_Y_Coords.push_back(a.GetUpper_left_latitude());
    image1_x_reference = a.GetUpper_left_longitude();
    image1_y_reference = a.GetUpper_left_latitude();
    image1_dot = 0.01*abs(a.GetUpper_left_longitude()-a.GetUpper_right_longitude());
  }
  else
  {
    Image1_X_Coords.push_back(a.GetUpper_left_x());
    Image1_Y_Coords.push_back(a.GetUpper_left_y());
    Image1_X_Coords.push_back(a.GetUpper_right_x());
    Image1_Y_Coords.push_back(a.GetUpper_right_y());    
    Image1_X_Coords.push_back(a.GetLower_right_x());
    Image1_Y_Coords.push_back(a.GetLower_right_y());
    Image1_X_Coords.push_back(a.GetLower_left_x());
    Image1_Y_Coords.push_back(a.GetLower_left_y());
    Image1_X_Coords.push_back(a.GetUpper_left_x());
    Image1_Y_Coords.push_back(a.GetUpper_left_y());
    image1_x_reference = a.GetUpper_left_x();
    image1_y_reference = a.GetUpper_left_y();
    image1_dot = 0.01*abs(a.GetUpper_left_x()-a.GetUpper_right_x());
  }
  
  /***********************/
  /* Image 2 Information */
  /***********************/
  image2_name = b.GetName();
  if(selenographic)
  {
    Image2_X_Coords.push_back(b.GetUpper_left_longitude());
    Image2_Y_Coords.push_back(b.GetUpper_left_latitude());
    Image2_X_Coords.push_back(b.GetUpper_right_longitude());
    Image2_Y_Coords.push_back(b.GetUpper_right_latitude());    
    Image2_X_Coords.push_back(b.GetLower_right_longitude());
    Image2_Y_Coords.push_back(b.GetLower_right_latitude());
    Image2_X_Coords.push_back(b.GetLower_left_longitude());
    Image2_Y_Coords.push_back(b.GetLower_left_latitude());
    Image2_X_Coords.push_back(b.GetUpper_left_longitude());
    Image2_Y_Coords.push_back(b.GetUpper_left_latitude());
    image2_x_reference = b.GetUpper_left_longitude();
    image2_y_reference = b.GetUpper_left_latitude();
    image2_dot = 0.01*abs(b.GetUpper_left_longitude()-b.GetUpper_right_longitude());
  }
  else
  {
    Image2_X_Coords.push_back(b.GetUpper_left_x());
    Image2_Y_Coords.push_back(b.GetUpper_left_y());
    Image2_X_Coords.push_back(b.GetUpper_right_x());
    Image2_Y_Coords.push_back(b.GetUpper_right_y());    
    Image2_X_Coords.push_back(b.GetLower_right_x());
    Image2_Y_Coords.push_back(b.GetLower_right_y());
    Image2_X_Coords.push_back(b.GetLower_left_x());
    Image2_Y_Coords.push_back(b.GetLower_left_y());
    Image2_X_Coords.push_back(b.GetUpper_left_x());
    Image2_Y_Coords.push_back(b.GetUpper_left_y());
    image2_x_reference = b.GetUpper_left_x();
    image2_y_reference = b.GetUpper_left_y();
    image2_dot = 0.01*abs(b.GetUpper_left_longitude()-b.GetUpper_right_longitude());
  }
  
  /*********************/
  /* Initialize Canvas */
  /*********************/
  canheight = 1200;
  canwidth = 500;
  can = new TCanvas("Canvas", "", canheight, canwidth);
  can->SetGridx();
  can->SetGridy();

  /***************************/
  /* Determine plotting area */
  /***************************/
  if(Image1_X_Coords[0] < Image1_X_Coords[1])
  {
    image1_x_high = (Image1_X_Coords[1] > Image1_X_Coords[2]) ? Image1_X_Coords[1] : Image1_X_Coords[2];
    image1_x_low  = (Image1_X_Coords[0] < Image1_X_Coords[3]) ? Image1_X_Coords[0] : Image1_X_Coords[3];
  }
  else
  {
    image1_x_high = (Image1_X_Coords[0] > Image1_X_Coords[3]) ? Image1_X_Coords[0] : Image1_X_Coords[3];
    image1_x_low  = (Image1_X_Coords[1] < Image1_X_Coords[2]) ? Image1_X_Coords[1] : Image1_X_Coords[2];
  }
  if(Image1_Y_Coords[0] < Image1_Y_Coords[3])
  {
    image1_y_high = (Image1_Y_Coords[2] > Image1_Y_Coords[3]) ? Image1_Y_Coords[2] : Image1_Y_Coords[3];
    image1_y_low  = (Image1_Y_Coords[0] < Image1_Y_Coords[1]) ? Image1_Y_Coords[0] : Image1_Y_Coords[1];
  }
  else
  {
    image1_y_high = (Image1_Y_Coords[0] > Image1_Y_Coords[1]) ? Image1_Y_Coords[0] : Image1_Y_Coords[1];
    image1_y_low  = (Image1_Y_Coords[2] < Image1_Y_Coords[3]) ? Image1_Y_Coords[2] : Image1_Y_Coords[3];
  }
  if(Image2_X_Coords[0] < Image2_X_Coords[1])
  {
    image2_x_high = (Image2_X_Coords[1] > Image2_X_Coords[2]) ? Image2_X_Coords[1] : Image2_X_Coords[2];
    image2_x_low  = (Image2_X_Coords[0] < Image2_X_Coords[3]) ? Image2_X_Coords[0] : Image2_X_Coords[3];
  }
  else
  {
    image2_x_high = (Image2_X_Coords[0] > Image2_X_Coords[3]) ? Image2_X_Coords[0] : Image2_X_Coords[3];
    image2_x_low  = (Image2_X_Coords[1] < Image2_X_Coords[2]) ? Image2_X_Coords[1] : Image2_X_Coords[2];
  }
  if(Image2_Y_Coords[0] < Image2_Y_Coords[3])
  {
    image2_y_high = (Image2_Y_Coords[2] > Image2_Y_Coords[3]) ? Image2_Y_Coords[2] : Image2_Y_Coords[3];
    image2_y_low  = (Image2_Y_Coords[0] < Image2_Y_Coords[1]) ? Image2_Y_Coords[0] : Image2_Y_Coords[1];
  }
  else
  {
    image2_y_high = (Image2_Y_Coords[0] > Image2_Y_Coords[1]) ? Image2_Y_Coords[0] : Image2_Y_Coords[1];
    image2_y_low  = (Image2_Y_Coords[2] < Image2_Y_Coords[3]) ? Image2_Y_Coords[2] : Image2_Y_Coords[3];
  }
  x_high = (image1_x_high > image2_x_high) ? image1_x_high : image2_x_high;
  x_low = (image1_x_low < image2_x_low) ? image1_x_low : image2_x_low;
  y_high = (image1_y_high > image2_y_high) ? image1_y_high : image2_y_high;
  y_low = (image1_y_low < image2_y_low) ? image1_y_low : image2_y_low;
  
  /*************/
  /* Draw axes */
  /*************/
  buffer = image1_name+" vs "+image2_name+"; X [Degree]; Y [Degree]";
  spacing = (selenographic) ? 1E-4 : 1E3;
  h1 = can->DrawFrame(x_low-spacing, y_low-spacing, x_high+spacing, y_high+spacing, buffer.c_str());
  h1->GetYaxis()->SetNdivisions(10);
  h1->GetXaxis()->SetNdivisions(10);
  
  /****************/
  /* Plot image 1 */
  /****************/
  n = (int)Image1_X_Coords.size();
  plot1 = new TPolyLine(n, Image1_X_Coords.data(), Image1_Y_Coords.data());
  plot1->SetLineColor(kBlue);
  plot1->SetLineWidth(2);
  plot1->Draw();

  /****************/
  /* Plot image 2 */
  /****************/
  n = (int)Image2_X_Coords.size();
  plot2 = new TPolyLine(n, Image2_X_Coords.data(), Image2_Y_Coords.data());
  plot2->SetLineColor(kGreen);
  plot2->SetLineWidth(2);
  plot2->Draw();
  
  /*************************/
  /* Plot 1 defined origin */
  /*************************/
  el1 = new TEllipse(image1_x_reference, image1_y_reference, image1_dot);
  el1->SetFillColorAlpha(kBlue, 0.50);
  el1->SetFillStyle(4050);
  el1->SetLineColor(kRed);
  el1->Draw();

  /*************************/
  /* Plot 2 defined origin */
  /*************************/
  el2 = new TEllipse(image2_x_reference, image2_y_reference, image2_dot);
  el2->SetFillColorAlpha(kGreen, 0.50);
  el2->SetFillStyle(4050);
  el2->SetLineColor(kRed);
  el2->Draw();
  
  /**********/
  /* Legend */
  /**********/
  leg = new TLegend(0.7,0.7,0.9,0.9);
  //leg->SetHeader("","C"); // option "C" allows to center the header
  buffer = "Sub-image: "+image1_name;
  leg->AddEntry(plot1, buffer.c_str(), "f");
  buffer = "Sub-image: "+image2_name;
  leg->AddEntry(plot2, buffer.c_str(), "f");
  leg->AddEntry(el1, "Image 1 Origin", "f");
  leg->AddEntry(el2, "Image 2 Origin", "f");
  leg->Draw();

  /*********************/
  /* Save plot to file */
  /*********************/
  filename = image1_name+"_vs_"+image2_name+"_Graphic.ps";
  can->SaveAs(filename.c_str());

  /*******************************/
  /* Print coordinates to screen */
  /*******************************/
  if(print_coordinates)
  {
    printf("Coordinates for image 1 %s.\n", image1_name.c_str());
    for(int i=0; i<n; i++)
      printf("Corner %d: %lf degrees longitude and %lf degrees latitude\n", i+1, Image1_X_Coords[i], Image1_Y_Coords[i]);
    printf("\nCoordinates for image 2 %s.\n", image2_name.c_str());
    for(int i=0; i<n; i++)
      printf("Corner %d: %lf degrees longitude and %lf degrees latitude\n", i+1, Image2_X_Coords[i], Image2_Y_Coords[i]);
  }
  
  /***********************************/
  /* Free memory reserved for canvas */
  /***********************************/
  delete plot1;
  delete plot2;
  delete el1;
  delete el2;
  delete leg;
  delete can;
}

// void Plot::SubImage_w_craters(Images a, std::vector <Marks> &b)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double spacing = 0.05E3;
//   double horizontal_resolution;
//   double vertical_resolution;
//   double x_high;
//   double x_low;
//   double x_origin;
//   double y_high;
//   double y_low;
//   double y_origin;
//   int canheight;
//   int canwidth;
//   int first_index;
//   int last_index;
//   int sub_image_id;
//   string buffer;
//   string field;
//   string filename;
//   string x_origin_condition;
//   string y_origin_condition;
//   string image_name;
//   TCanvas *can;
//   TBox *box;
//   TEllipse *el1;
//   TEllipse *el2;
//   TLegend *leg;
    
//   /******************************/
//   /* Retrieve image information */
//   /******************************/
//   image_name = a.GetName();
//   sub_image_id = a.GetId();
//   horizontal_resolution = a.GetHorizontal_resolution();
//   vertical_resolution = a.GetVertical_resolution();
//   x_high = a.GetX_high();
//   x_low = a.GetX_low();
//   x_origin = a.GetX_origin();
//   y_high = a.GetY_high();
//   y_low = a.GetY_low();
//   y_origin = a.GetY_origin();
//   x_origin_condition = a.GetUpper_left_x();
//   y_origin_condition = a.GetUpper_left_y();

//   /*************************/
//   /* Sort marks (b) vector */
//   /*************************/
//   field = "image_id";
//   SortMarks sortmarks(b, field);
//   sortmarks.arrange();
//   b = sortmarks.GetMarks();
//   //RetrieveMarks::Display(b); exit(0);

//   /******************************************************************/
//   /* Find first and last occurrence of image_id in marks (b) vector */
//   /******************************************************************/
//   int n = (int)b.size();
//   int value = sub_image_id;
//   first_index = SearchMarks::FirstOccurence(b, 0, n-1, field, &value);
//   last_index = SearchMarks::LastOccurence(b, 0, n-1, field, &value);

//   /*********************/
//   /* Initialize Canvas */
//   /*********************/
//   canheight = 800;
//   canwidth = 800;
//   can = new TCanvas("Canvas", "", canheight, canwidth);
//   can->SetGridx();
//   can->SetGridy();

//   /*************/
//   /* Draw axes */
//   /*************/
//   buffer = image_name+"; X [m]; Y [m]";
//   TH1F * h1 = can->DrawFrame(x_low-spacing, y_low-spacing, x_high+spacing, y_high+spacing, buffer.c_str());
//   h1->GetYaxis()->SetNdivisions(5);
//   h1->GetYaxis()->SetTitleOffset(0.5);
//   h1->GetXaxis()->SetNdivisions(5);
  
//   /******************/
//   /* Plot sub image */
//   /******************/
//   box = new TBox(x_low, y_low, x_high, y_high);
//   box->SetFillColor(kGreen);
//   box->SetFillStyle(1001);
//   box->SetLineColor(kBlack);
//   box->SetLineWidth(2);
//   box->Draw("l");
//   gPad->RedrawAxis();

//   /*****************************************************/
//   /* Iterate through marks (b) vector and plot craters */
//   /*****************************************************/
//   int counter = 0;
//   for(int i=first_index; i<=last_index; i++)
//   {
//     /*********************************************/
//     /* Calculate global x and y position of mark */
//     /*********************************************/
//     double x = (x_origin_condition.compare("MIN") == 0) ?
//       x_origin+horizontal_resolution*b[i].GetX() :
//       x_origin-horizontal_resolution*b[i].GetX();
//     double y = (y_origin_condition.compare("MIN") == 0) ?
//       y_origin+vertical_resolution*b[i].GetY() :
//       y_origin-vertical_resolution*b[i].GetY();
//     double r1 = horizontal_resolution*b[i].GetDiameter();
//     double r2 = vertical_resolution*b[i].GetDiameter();
//     double r = (r1 < r2) ? r1 : r2;

//     /***************/
//     /* Plot crater */
//     /***************/
//     el2 = new TEllipse(x, y, r);
//     el2->SetFillColor(kBlue);
//     el2->Draw();
//     gPad->RedrawAxis();
//     counter++;
//   }

//   /***********************/
//   /* Plot defined origin */
//   /***********************/
//   el1 = new TEllipse(x_origin, y_origin, 5.0);
//   el1->SetFillColor(kRed);
//   el1->Draw();

//   /**********/
//   /* Legend */
//   /**********/
//   leg = new TLegend(0.7,0.7,0.9,0.9);
//   //leg->SetHeader("","C"); // option "C" allows to center the header
//   buffer = "Sub-image: "+image_name;
//   leg->AddEntry(box, buffer.c_str(), "f");
//   leg->AddEntry(el2, "Crater Marks", "f");
//   leg->AddEntry(el1, "Image Origin", "f");
//   leg->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = image_name+"_w_craters_Graphic.ps";
//   can->SaveAs(filename.c_str());
  
//   /***********************************/
//   /* Free memory reserved for canvas */
//   /***********************************/
//   delete box;
//   delete el1;
//   delete el2;
//   delete leg;
//   delete can;
// }
