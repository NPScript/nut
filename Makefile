SOURCES=$(wildcard tools/*.c)
BIN=$(SOURCES:tools/%.c=build/%)
DESTDIR=/usr/local
DESTBIN=$(SOURCES:tools/%.c=$(DESTDIR)/bin/%)

all: $(BIN)

options:
	@echo "OBJ			= $(SOURCES)"
	@echo "BIN			= $(BIN)"
	@echo "DESTDIR	= $(DESTDIR)"
	@echo "DESTBIN	= $(DESTBIN)"

build:
	mkdir build

build/%: tools/%.c build
	gcc $< -o $@

clean:
	rm -rf build

install: all
	cp build/* $(DESTDIR)/bin/

uninstall:
	rm $(DESTBIN)
