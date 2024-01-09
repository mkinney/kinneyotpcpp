.DEFAULT_GOAL := build

.PHONY:build

build: main.cpp otp.hpp key.hpp
	g++ -o otp main.cpp

FORCE: ;
