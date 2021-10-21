#!/bin/bash

INPUTFILE="../rootfiles/datasets/merged_HiForestMiniAOD.root"
OUTPUTFILE="../rootfiles/analysis/recoEffStudy/output.root"

./MuRecoEff/murecoeff ${INPUTFILE} ${OUTPUTFILE}