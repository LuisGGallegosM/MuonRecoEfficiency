
#include"MuRecoEff.h"

#include<iostream>

int main(int argc, char **argv)
{
    if (argc==3)
        MuRecoEff(argv[1],argv[2]);
    else
        std::cerr << "Wrong number of parameters:\nUsage:\nOnia input filename , output filename\n";
    return 0;
}
