#include "Plot.h"

using namespace std;

// void Plot::CumulativeFrequency()
// {
//   return;
// }


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
    dot = 0.01*(a.GetPhysical_width());
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
    dot = 0.01*(a.GetPhysical_width());
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

    /************************/
    /* Increase scale level */
    /************************/
    scale++;
  }
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

// void Plot::PlotOverlap(OverlappedImages a, bool square)
// {
//   /*******************************************/
//   /* Declaration/Initialization of variables */
//   /*******************************************/
//   double area1;
//   double area2;
//   double b1_height;
//   double b1_width;
//   double b1_x0;
//   double b1_x1;
//   double b1_y0;
//   double b1_y1;
//   double b2_height;
//   double b2_width;
//   double b2_x0;
//   double b2_x1;
//   double b2_y0;
//   double b2_y1;
//   double b3_x0;
//   double b3_x1;
//   double b3_y0;
//   double b3_y1;
//   double max;
//   double max_x;
//   double max_y;
//   double min_x;
//   double min_y;
//   double image1_x_origin;
//   double image1_y_origin;
//   double image2_x_origin;
//   double image2_y_origin;
//   int canheight;
//   int canwidth;
//   string buffer;
//   string filename;
//   string image1_name;
//   string image1_x_origin_condition;
//   string image1_y_origin_condition;
//   string image2_name;
//   string image2_x_origin_condition;
//   string image2_y_origin_condition;
//   TBox *b1;
//   TBox *b2;
//   TBox *b3;
//   TCanvas *can;
//   TEllipse *el1;
//   TEllipse *el2;
//   TLegend *leg;

//   /*******************************/
//   /* Retrieve image1 information */
//   /*******************************/
//   image1_name = a.GetImage1_name();
//   image1_x_origin_condition = a.GetImage1_x_origin_condition();
//   image1_y_origin_condition = a.GetImage1_y_origin_condition();
//   b1_height = a.GetImage1_height();
//   b1_width = a.GetImage1_width();
//   b1_x0 = a.GetImage1_x_low();
//   b1_x1 = a.GetImage1_x_high();
//   b1_y0 = a.GetImage1_y_low();
//   b1_y1 = a.GetImage1_y_high();

//   /**********************/
//   /* Retrieve box1 area */
//   /**********************/
//   area1 = a.GetImage1_area();

//   /*****************************/
//   /* Retrieve box2 coordinates */
//   /*****************************/
//   image2_name = a.GetImage2_name();
//   image2_x_origin_condition = a.GetImage2_x_origin_condition();
//   image2_y_origin_condition = a.GetImage2_y_origin_condition();
//   b2_height = a.GetImage2_height();
//   b2_width = a.GetImage2_width();
//   b2_x0 = a.GetImage2_x_low();
//   b2_x1 = a.GetImage2_x_high();
//   b2_y0 = a.GetImage2_y_low();
//   b2_y1 = a.GetImage2_y_high();

//   /**********************/
//   /* Retrieve box2 area */
//   /**********************/
//   area2 = a.GetImage2_area();

//   /*****************************/
//   /* Retrieve box3 coordinates */
//   /*****************************/
//   b3_x0 = a.GetOverlap_x_low();
//   b3_x1 = a.GetOverlap_x_high();
//   b3_y0 = a.GetOverlap_y_low();
//   b3_y1 = a.GetOverlap_y_high();

//   /************************************/
//   /* Determine minimum x and y values */
//   /************************************/
//   min_x = (b1_x0 < b2_x0) ? fabs(b1_x0) : fabs(b2_x0);
//   min_y = (b1_y0 < b2_y0) ? fabs(b1_y0) : fabs(b2_y0);

//   /************************************************/
//   /* Translate boxes to first quadrant, if needed */
//   /************************************************/
//   if((b1_x0 < 0) || (b2_x0 < 0))
//   {
//     b1_x0 += min_x;
//     b1_x1 += min_x;
//     b2_x0 += min_x;
//     b2_x1 += min_x;
//     b3_x0 += min_x; 
//     b3_x1 += min_x;
//   }
//   if((b1_y0 < 0) || (b2_y0 < 0))
//   {
//     b1_y0 += min_y;
//     b1_y1 += min_y;
//     b2_y0 += min_y;
//     b2_y1 += min_y;
//     b3_y0 += min_y;
//     b3_y1 += min_y;
//   }

//   /**************************************/
//   /* Recalculate minimum x and y values */
//   /**************************************/
//   min_x = (b1_x0 < b2_x0) ? fabs(b1_x0) : fabs(b2_x0);
//   min_y = (b1_y0 < b2_y0) ? fabs(b1_y0) : fabs(b2_y0);

//   /******************************/
//   /* Shift boxes towards origin */
//   /******************************/
//   b1_x0 -= min_x;
//   b1_x1 -= min_x;
//   b1_y0 -= min_y;
//   b1_y1 -= min_y;
//   b2_x0 -= min_x;
//   b2_x1 -= min_x;
//   b2_y0 -= min_y;
//   b2_y1 -= min_y;
//   b3_x0 -= min_x;
//   b3_x1 -= min_x;
//   b3_y0 -= min_y;
//   b3_y1 -= min_y;

//   /***************************/
//   /* Determine maximum value */
//   /***************************/
//   max_x = (b1_x1 > b2_x1) ? b1_x1 : b2_x1;
//   max_y = (b1_y1 > b2_y1) ? b1_y1 : b2_y1;
//   max = (max_x > max_y) ? max_x : max_y;

//   /********************************/
//   /* Force boxes into unit square */
//   /********************************/
//   b1_height /= max;
//   b1_width /= max;
//   b1_x0 /= max; 
//   b1_x1 /= max;
//   b1_y0 /= max;
//   b1_y1 /= max;
//   b2_height /= max;
//   b2_width /= max;
//   b2_x0 /= max;
//   b2_x1 /= max;
//   b2_y0 /= max;
//   b2_y1 /= max;
//   b3_x0 /= max;
//   b3_x1 /= max;
//   b3_y0 /= max;
//   b3_y1 /= max;

//   /************************/
//   /* Define image origins */
//   /************************/
//   image1_x_origin = (image1_x_origin_condition.compare("MIN") == 0) ? b1_x0 : b1_x1;
//   image1_y_origin = (image1_y_origin_condition.compare("MIN") == 0) ? b1_y0 : b1_y1;
//   image2_x_origin = (image2_x_origin_condition.compare("MIN") == 0) ? b2_x0 : b2_x1;
//   image2_y_origin = (image2_y_origin_condition.compare("MIN") == 0) ? b2_y0 : b2_y1;

//   /*********************/
//   /* Initialize Canvas */
//   /*********************/
//   canheight = 800;
//   canwidth = 800;
//   can = new TCanvas("Canvas", "", canheight, canwidth);

//   /*************/
//   /* Draw axes */
//   /*************/
//   buffer = image1_name+" vs "+image2_name+" Overlap; Relative X Size; Relative Y Size";
//   can->DrawFrame(0.0, 0.0, 1.0, 1.0, buffer.c_str());

//   /***********************/
//   /* Plot overlap region */
//   /***********************/
//   b1 = new TBox(b1_x0, b1_y0, b1_x1, b1_y1);
//   b1->SetFillColor(kYellow);
//   b1->SetFillStyle(1001);
//   b1->SetLineColor(kBlack);
//   b2 = new TBox(b2_x0, b2_y0, b2_x1, b2_y1);
//   b2->SetFillColor(kBlue);
//   b2->SetFillStyle(1001);
//   b2->SetLineColor(kBlack);
//   b3 = new TBox(b3_x0, b3_y0, b3_x1, b3_y1);
//   b3->SetFillColor(kGreen);
//   b3->SetFillStyle(1001);
//   b3->SetLineColor(kBlack);
//   if(area1 > area2)
//   {
//     b1->Draw("l");
//     b2->Draw("l");
//   }
//   else
//   {
//     b2->Draw("l");
//     b1->Draw("l");
//   }
//   b3->Draw("l");
//   gPad->RedrawAxis();

//   /***********************/
//   /* Plot defined origin */
//   /***********************/
//   el1 = new TEllipse(image1_x_origin, image1_y_origin, 0.01);
//   el1->SetFillColor(kRed);
//   el1->Draw();

//   /***********************/
//   /* Plot defined origin */
//   /***********************/
//   el2 = new TEllipse(image2_x_origin, image2_y_origin, 0.01);
//   el2->SetFillColor(kViolet);
//   el2->Draw();

//   /**********/
//   /* Legend */
//   /**********/
//   leg = new TLegend(0.7,0.7,0.9,0.9);
//   //leg->SetHeader("","C"); // option "C" allows to center the header
//   buffer = "Image1: "+image1_name;
//   leg->AddEntry(b1, buffer.c_str(), "f");
//   buffer = "Image2: "+image2_name;
//   leg->AddEntry(b2, buffer.c_str(), "f");
//   leg->AddEntry(b3, "Overlap region", "f");
//   leg->AddEntry(el1, "Image1 Origin", "f");
//   leg->AddEntry(el2, "Image2 Origin", "f");
//   leg->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = "OverlapPlot.ps";
//   can->SaveAs(filename.c_str());

//   /***********************************/
//   /* Free memory reserved for canvas */
//   /***********************************/
//   delete b1;
//   delete b2;
//   delete b3;
//   delete el1;
//   delete el2;
//   delete leg;
//   delete can;
  
//   return;
// }

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
  canwidth = 650;
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
    dot = 0.01*(a.GetPhysical_width());
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

// void Plot::SubImages(Images a, Images b)
// {
//   /****************************************************/
//   /* Declaration/Initialization of function variables */
//   /****************************************************/
//   double spacing = 0.05E3;
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
//   double max_x;
//   double max_y;
//   double min_x;
//   double min_y;
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
//   max_x = (image1_x_high > image2_x_high) ? image1_x_high : image2_x_high;
//   max_y = (image1_y_high > image2_y_high) ? image1_y_high : image2_y_high;
//   min_x = (image1_x_low < image2_x_low) ? image1_x_low : image2_x_low;
//   min_y = (image1_y_low < image2_y_low) ? image1_y_low : image2_y_low;

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
//   TH1F * h1 = can->DrawFrame(min_x-spacing, min_y-spacing, max_x+spacing, max_y+spacing, buffer.c_str());
//   h1->GetYaxis()->SetNdivisions(5);
//   h1->GetYaxis()->SetTitleOffset(0.5);
//   h1->GetXaxis()->SetNdivisions(5);

//   /***************/
//   /* Plot image1 */
//   /***************/
//   box1 = new TBox(image1_x_low, image1_y_low, image1_x_high, image1_y_high);
//   box1->SetFillColor(kYellow);
//   box1->SetFillStyle(1001);
//   box1->SetLineColor(kBlack);
//   box1->SetLineWidth(2);
//   box1->Draw("l");
//   gPad->RedrawAxis();

//   /***************/
//   /* Plot image2 */
//   /***************/
//   box2 = new TBox(image2_x_low, image2_y_low, image2_x_high, image2_y_high);
//   box2->SetFillColor(kBlue);
//   box2->SetFillStyle(1001);
//   box2->SetLineColor(kBlack);
//   box2->SetLineWidth(2);
//   box2->Draw("l");
//   gPad->RedrawAxis();

//   /**********************************/
//   /* Plot defined origin for image1 */
//   /**********************************/
//   el1 = new TEllipse(image1_x_origin, image1_y_origin, 5.0);
//   el1->SetFillColor(kRed);
//   el1->Draw();

//   /**********************************/
//   /* Plot defined origin for image2 */
//   /**********************************/
//   el2 = new TEllipse(image2_x_origin, image2_y_origin, 5.0);
//   el2->SetFillColor(kViolet);
//   el2->Draw();
  
//   /**********/
//   /* Legend */
//   /**********/
//   leg = new TLegend(0.7,0.7,0.9,0.9);
//   //leg->SetHeader("","C"); // option "C" allows to center the header
//   buffer = "Sub-image: "+image1_name;
//   leg->AddEntry(box1, buffer.c_str(), "f");
//   buffer = "Sub-image: "+image2_name;
//   leg->AddEntry(box2, buffer.c_str(), "f");
//   leg->AddEntry(el1, "Image1 Origin", "f");
//   leg->AddEntry(el2, "Image2 Origin", "f");
//   leg->Draw();

//   /*********************/
//   /* Save plot to file */
//   /*********************/
//   filename = image1_name+"_vs_"+image2_name+"_Graphic.ps";
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
