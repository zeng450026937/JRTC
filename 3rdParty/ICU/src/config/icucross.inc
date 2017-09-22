CURR_FULL_DIR?=$(shell pwd | sed 's/ /\\ /g')
CURR_FULL_DIR?=$(subst \,/,$(shell cmd /c cd))#M# for Cygwin shell
