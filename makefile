targets=wattsup libwattsup.so test_library

all: $(targets)

wattsup: wattsup.c util.c config.c globals.c

libwattsup.so: util.c config.c globals.c
	$(CC) -fPIC -shared -Wl,-soname,$@ -o $@ $^

test_library: test_library.c libwattsup.so
	$(CC) -fPIC test_library.c -o $@ -L./ -lwattsup

install: all
	install -m 0555 wattsup /usr/local/bin/
	install -m 0444 libwattsup.so /usr/local/lib/

clean:
	rm -f *~ $(targets)
