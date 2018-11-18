# override TARGET if the project folder name is unsuitable
TARGET = demo
TSTTGT = testapp
MK = .

.SUFFIXES:

.PHONY: all
all:	$(TARGET) ## build prinary application

include mk/os_detect.mak
