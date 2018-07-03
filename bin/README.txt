############################################
# Installation Instructions on Mac OSX 10.10.5 or later #
############################################

Step 1. If not already installed, install Homebrew by executing the following at a terminal prompt (more detailed description of Homebrew can be found at https://brew.sh):

     /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

Step 2. After successfully installing Homebrew, install Cern's Root library by executing the following at a terminal prompt (all environment variables should be setup with installation of Root):

     brew install root

Step 3. After successfully installing Root, copy the contents of CosmoQuestTeam/IncidenceAngleAnalysis repository to a directory on your computer. This directory will serve as the top directory for the analysis code.

################
# Run Instructions #
################

Step 1. Navigate to the top directory that holds the Makefile for the analysis code (should be in the directory you chose to copy the analysis code to)

Step 2. Compile the analysis code by executing the following at the command prompt:

     make 

Step 3. Navigate to /top directory/bin and execute the following command to run the analysis code:

     ./IncidenceAngleAnalysis LROCAuxilaryData.dat

####################
# Analysis code input(s) #
####################

The analysis code only requires 1 input which is the file entitled "LROCAuxilaryData.dat". This data file contains 6 columns which store the following information:

Column 1 - LRO NAC image name
Column 2 - LRO NAC incidence angle
Column 3 - Indicates if the upper left hand corner of NAC is the maximum or minimum latitude (Used to establish image orientation)
Column 4 - Indicates if the upper left hand corner of NAC is the maximum or minimum longitude (Used to establish image orientation)
Column 5 - Manually calculated NAC vertical resolution (Optional)
Column 6 - Manually calculated NAC horizontal resolution (Optional)

#####################
# Analysis main function #
#####################

Can be found in the src/ directory in the file entitled "IncidenceAngleAnalysis.cc".

###################
# Analysis code tasks #
###################

1) Extract data from our mysql database that stores information about the global images (LRO images), the sub-images (each global image has been cut up into sub-images so that citizen scientists can identify craters within smaller images at different scales), and the citizen scientist annotations.
2) Establish a coordinate system within the analysis code that will allow us to determine how the sub-images are spatially related to each other.
3) Determine and record which sub-images overlap and calculate key information about the overlap region (e.g., area or perimeter -- both of which the code can currently do)
4) Identify all user marks that are contained within the boundary of overlapping regions imaged at two different incidence angles (We have a few global images that were taken by the left and right cameras of the NAC system, so overlapping sub-images originating from "paired" NAC global images will essentially have the same incidence angle. We wish to specifically find overlapping images that don't originate from "paired" NAC images).
5) Use the aforementioned user marks to produce plots like the cumulative frequency distribution.
