
#include"MuRecoEff.h"

#include"../RootUtils/RootUtils.h"
#include"../TreeIO/TreeIO.h"
#include"DataIO.h"

#include<iostream>

void MuRecoEff(const char* inputfilename, const char* outputfilename)
{
    auto inputFile= OpenFile(inputfilename);
    if (inputFile==nullptr) return;

    auto outputFile= CreateFile(outputfilename);
    if (outputFile==nullptr) return;

    TTree* inputTree = OpenTree(inputFile.get(),"hltMuTree/HLTMuTree");
    std::unique_ptr<TTree> passingTree= std::unique_ptr<TTree>(new TTree("passing","passing"));
    std::unique_ptr<TTree> totalTree = std::unique_ptr<TTree>(new TTree("total","total"));

}

void process(TTree* inputTree, TTree* passingTree, TTree* totalTree )
{
    Reader<OniaInput> input(inputTree);
    Writer<OniaOutput> pass(passingTree);
    Writer<OniaOutput> total(totalTree);

    Long64_t entryNum= inputTree->GetEntries();

    for(Long64_t entry=0;entry < entryNum;entry++)
    {
        auto in = input.readEntry(entry);

        for (int iMu=0;iMu < in->glb_nptl ; iMu++)
        {
            float pt=in->glb_pt[iMu];
            float phi=in->glb_phi[iMu];
            float eta=in->glb_eta[iMu];
            total.output.pt=pt;
            total.output.phi= phi;
            total.output.eta=eta;
            total.writeEntry();

            if (in->glb_glbChi2_ndof[iMu] < 10.0f)
            {
                pass.output.pt=pt;
                pass.output.phi= phi;
                pass.output.eta=eta;
                pass.writeEntry();
            }
        }

    }
}