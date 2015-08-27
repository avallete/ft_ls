FROM debian:latest
MAINTAINER avallete [at] student [dot] 42 [dot] fr

#Update apt repository and install necesarry for C devellopement
RUN	apt-get update && apt-get upgrade -y
RUN	apt-get install -y git
RUN	apt-get install -y curl
RUN	apt-get install -y gcc g++ clang gdb valgrind
RUN	apt-get install -y libncurses5 libncurses5-dev libacl1-dev
RUN	apt-get install -y nasm
RUN	apt-get install -y make
RUN	apt-get clean
RUN	chmod -R g+rwx /root
WORKDIR	myApp
RUN	chmod -R g+rwx /myApp
