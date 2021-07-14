
all:
	$(MAKE) -C TreeIO
	$(MAKE) -C RootUtils
	$(MAKE) -C MuRecoEff

clear:
	$(MAKE) clear -C TreeIO
	$(MAKE) clear -C RootUtils
	$(MAKE) clear -C MuRecoEff