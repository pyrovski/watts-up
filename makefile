all: wattsup

install: all
	install -m 0555 wattsup /usr/local/bin

clean:
	rm -f wattsup
