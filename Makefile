.POSIX:
CC	= cc
CFLAGS	= -Wall -pedantic
LDLIBS	= $(shell pkg-config --libs ncurses panel)
PREFIX	= /usr/local

rusty: rusty.c

install: rusty
	install -TDm 0755 rusty $(DESTDIR)$(PREFIX)/bin/rusty

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/rusty

clean:
	rm -f rusty

.PHONY: install uninstall clean
