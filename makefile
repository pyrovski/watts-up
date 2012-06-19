all: wattsup wattsup.so

wattsup: wattsup.c util.c config.c globals.c

wattsup.so: util.c config.c globals.c
	$(CC) -fPIC -shared -Wl,-soname,$@ -o $@ $^

install: all
	install -m 0555 wattsup /usr/local/bin/
	install -m 0444 wattsup.so /usr/local/lib/

clean:
	rm -f *~ wattsup wattsup.so
