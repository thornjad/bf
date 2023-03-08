prefix = /usr/local
bindir = $(prefix)/bin

options ?= -g -Wall -Wextra

all: build

build:
	cc -c $(options) src/bf.c
	cc *.o -o bf
	rm -f *.o

clean:
	rm -f Out.c a.out bf *.o

install: build
	mkdir -p $(bindir)
	mv bf $(bindir)
	chown root $(bindir)/bf
	chmod go-w+rx $(bindir)/bf

uninstall: clean
	rm -f $(bindir)/bf
