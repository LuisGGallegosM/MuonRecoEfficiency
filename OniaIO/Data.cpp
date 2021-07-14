
#include"Data.h"

void OniaInput::registerInput(TreeReader* reader)
{
    reader->addInput("Event",&event);
    reader->addInput("Glb_nptl",&glb_nptl);
    reader->addInput("Glb_pt",&glb_pt);
    reader->addInput("Glb_eta",&glb_eta);
    reader->addInput("Glb_phi",&glb_phi);
    reader->addInput("Glb_nValMuHits",&glb_nValMuHits);
    reader->addInput("Glb_nValPixHits",&glb_nValPixHits);
    reader->addInput("Glb_nMatchedStations",&glb_nMatchedStations);
    reader->addInput("Glb_trkLayerWMeas",&glb_trkLayerWMeas);
    reader->addInput("Glb_glbChi2_ndof",&glb_glbChi2_ndof);
    reader->addInput("Glb_dxy",&glb_dxy);
    reader->addInput("Glb_dz",&glb_dz);
}

void OniaOutput::registerOutput(TreeWriter* writer)
{
    writer->addOutput("pt",&pt);
    writer->addOutput("eta",&eta);
    writer->addOutput("phi",&phi);
}

void OniaOutput::registerInput(TreeReader* reader)
{
    reader->addInput("pt",&pt);
    reader->addInput("eta",&eta);
    reader->addInput("phi",&phi);
}