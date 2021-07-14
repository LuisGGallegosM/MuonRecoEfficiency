#ifndef ROOTUTILS
#define ROOTUTILS

#include"TFile.h"
#include"TTree.h"
#include"TH1.h"
#include"TH2.h"
#include"TEfficiency.h"

const float padSizes[] = { 0.02f,0.1f,0.98f,0.9f };
const float canvasWidth = 1200.0f;
const float canvasHeight = 900.0f;

std::unique_ptr<TFile>  OpenFile(const std::string& filename);
std::unique_ptr<TFile>  CreateFile(const std::string& filename);
TTree* OpenTree(TFile* file ,const std::string& treeName);

void writeToCanvas(TH1* hist,const std::string& xname,const std::string& yname, const std::string& outname, bool yLog=false);
void writeToCanvas(TEfficiency* hist,const std::string& xname,const std::string& yname, const std::string& outname);
void writeToCanvas2D(TEfficiency* hist,const std::string& xname,const std::string& yname, const std::string& outname);

TH1* CreateTH1(const std::string& name,const std::string& title, const std::vector<double>& bins);
TH2* CreateTH2(const std::string& name,const std::string& title, const std::vector<double>& xbins, const std::vector<double>& ybins);

#endif