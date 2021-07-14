#ifndef DATA
#define DATA

#include"TClonesArray.h"
#include<vector>

#include"../TreeIO/TreeReader.h"
#include"../TreeIO/TreeWriter.h"

const int maxArraySize=16;

struct OniaInput
{
    Int_t event;
    Int_t glb_nptl;
    Float_t glb_pt[maxArraySize];
    Float_t glb_eta[maxArraySize];
    Float_t glb_phi[maxArraySize];
    Int_t glb_nValMuHits[maxArraySize];
    Int_t glb_nValPixHits[maxArraySize];
    Int_t glb_nMatchedStations[maxArraySize];
    Int_t glb_trkLayerWMeas[maxArraySize];
    Float_t glb_glbChi2_ndof[maxArraySize];
    Float_t glb_dxy[maxArraySize];
    Float_t glb_dz[maxArraySize];

    void registerInput(TreeReader* reader);
};

struct OniaOutput
{
    Float_t pt;
    Float_t eta;
    Float_t phi;

    void registerInput(TreeReader* reader);
    void registerOutput(TreeWriter* writer);
};


#endif