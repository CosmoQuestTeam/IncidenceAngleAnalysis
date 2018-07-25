#!/bin/bash

#################################################
# Declaration/Initialization of needed varables #
#################################################
CRATERCATALOGS="CraterCatalogList.txt"
EXE1_DIR="/Users/mrichardson/Desktop/Incidence_Angle_Analysis/bin/"
EXE1="IncidenceAngleAnalysis"
EXE1_AUXILARYFILE="LROCAuxilaryData.dat"
EXE2_DIR="/Users/mrichardson/Desktop/DBSCAN_Clustering_Code_Matt/"
EXE2="java -cp /Users/mrichardson/Desktop/DBSCAN_Clustering_Code_Matt/classes/ dbscan/Gui"
EXE2_MIN_MARKS_PER_CLUSTER="9"
EXE2_MAP_GRID_SPACING="100000"
EXE2_SEARCH_RADIUS="10"

#######################
# Retrieve parameters #
#######################

##########################
# Produce crater catalog #
##########################
arg="${EXE1_DIR}${EXE1} ${EXE1_DIR}${EXE1_AUXILARYFILE}"
eval ${arg}

##################################
# Copy crater catalogs into list #
##################################
arg="ls Crater_* > $CRATERCATALOGS"
eval ${arg}

##################################
# Produce reduced crater catalog #
##################################
REDUCEDCRATERCATALOGS=()
while read -r CRATERCATALOG
do
    arg="$EXE2 ${CRATERCATALOG} ${EXE2_MIN_MARKS_PER_CLUSTER} ${EXE2_MAP_GRID_SPACING} ${EXE2_SEARCH_RADIUS}"
    eval $arg
    filename="Reduced_c${CRATERCATALOG:1}"
    arg="cp out_short_1.txt ${filename}"
    eval ${arg}
    arg="rm -rf out_*.txt"
    eval $arg
    REDUCEDCRATERCATALOGS+=("${filename}");
done < "${CRATERCATALOGS}"

#################################################
# Create cumulative size-frequency distribution #
#################################################
arg="${EXE1_DIR}${EXE1} ${REDUCEDCRATERCATALOGS[0]} ${REDUCEDCRATERCATALOGS[1]}"
eval $arg
