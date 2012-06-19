all: wattsup

wattsup: wattsup.c util.c config.c globals.c

install: all
	install -m 0555 wattsup /usr/local/bin

clean:
	rm -f *~ wattsup
