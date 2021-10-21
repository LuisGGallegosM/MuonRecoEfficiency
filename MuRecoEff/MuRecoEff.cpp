
#include"MuRecoEff.h"

#include"../RootUtils/RootUtils.h"
#include"../TreeIO/TreeIO.h"
#include"../DataIO/DataIO.h"

#include<iostream>

void process(TTree* inputTree, TTree* passingTree, TTree* totalTree );

void MuRecoEff(const char* inputfilename, const char* outputfilename)
{
    auto inputFile= OpenFile(inputfilename);
    if (inputFile==nullptr) return;

    auto outputFile= CreateFile(outputfilename);
    if (outputFile==nullptr) return;

    TTree* inputTree = OpenTree(inputFile.get(),"hltMuTree/HLTMuTree");
    std::unique_ptr<TTree> passingTree= std::unique_ptr<TTree>(new TTree("passing","passing"));
    std::unique_ptr<TTree> totalTree = std::unique_ptr<TTree>(new TTree("total","total"));

    process(inputTree,passingTree.get(),totalTree.get());

    totalTree->Write();
    passingTree->Write();

    std::cout << "Success";

}

void process(TTree* inputTree, TTree* passingTree, TTree* totalTree )
{
    Reader<OniaInput> input(inputTree);
    Writer<OniaOutput> pass(passingTree);
    Writer<OniaOutput> total(totalTree);

    Long64_t entryNum= inputTree->GetEntries();
    Long64_t entryStep= entryNum/50;

    for(Long64_t entry=0;entry < entryNum;entry++)
    {
        if ((entry % 10000)==0) std::cout << "processing entries : " << round((100.0f*entry)/entryNum) << "% " << entry << " / " << entryNum << '\n';
        auto in = input.readEntry(entry);

        for (int iMu=0;iMu < in->glb_nptl ; iMu++)
        {
            OniaOutput out;
            out.pt=in->glb_pt[iMu];
            out.phi=in->glb_phi[iMu];
            out.eta=in->glb_eta[iMu];

            if (out.pt<100.0f)
            {
                total.writeEntry(&out);

                if (in->glb_glbChi2_ndof[iMu] < 10.0f)
                {
                    pass.writeEntry(&out);
                }
            }

        }

    }
}