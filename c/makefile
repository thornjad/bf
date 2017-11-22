#  These directories are where bf install.
#
#    PREFIX/BINDIR  The bf translator will install here.
#    PREFIX/MANDIR  The bf man page will install here.
#
#  If these directories do not exist they are created.

prefix = /usr/local
bindir = $(prefix)/bin
mandir = $(prefix)/man/man1

options = -g -Wall -Wextra


#  make all
#  Compile bf from source, leaving it in the current directory.
#  You need not be root to do this

all:
	cc -c $(options) src/bf.c
	cc *.o -o bf
	rm -f *.o


#  make clean
#  Undo the effects of make all. You need not be root to do this

clean:
	rm -f Out.c a.out bf *.o


#  make install
#  Install bf, by doing these things.
#
#    01. Make bin directory if it doesn't exist
#    02. Make man directory if it doesn't exist
#    04. Compile the bf interpreter
#    05. Move the bf interpreter to the bin directory
#    06. Let root be the owner of the bf interpreter
#    07. Let nonroots read and run the bf interpreter, not write it
#    08. Copy the bf man page to man directory
#    09. Let root be the owner of the bf man page
#    10. Let nonroots read the bf man page, not run or write it
#
#  You must be root to do this

install:
	mkdir -p $(bindir)
	mkdir -p $(mandir)
	cc -c $(options) src/bf.c
	cc *.o -o bf
	rm -f *.o
	mv bf $(bindir)
	chown root $(bindir)/bf
	chmod go-w+rx $(bindir)/bf
	# cp bf.1 $(mandir)
	# chown root $(mandir)/bf.1
	# chmod go-wx+r $(mandir)/bf.1


#  make uninstall
#  Undo the effects of make install
#
#     1. Undo the effects of make all.
#     2. Remove the bf interpreter from bin directory.
#     3. Remove the bf man page from man directory.
#
#  You must be root to do this.

uninstall:
	rm -f Out.c a.out bf *.o
	rm -f $(bindir)/bf
	rm -f $(mandir)/bf.1
