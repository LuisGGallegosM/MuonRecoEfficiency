
all:
	$(MAKE) -C TreeIO
	$(MAKE) -C OniaIO
	$(MAKE) -C RootUtils

clear:
	$(MAKE) clear -C TreeIO
	$(MAKE) clear -C OniaIO
	$(MAKE) clear -C RootUtils