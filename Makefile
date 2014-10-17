CC=gcc
LD=gcc
STRIP=strip
RM=rm -rf
DIFF=diff
ECHO=echo

CFLAGS=
LDFLAGS=

RELEASE=1

ifdef RELEASE
    CFLAGS+=-O3
else
    CFLAGS+=-g
endif

PROJECT_NAME=ouroboros
HEADERS=
SOURCE=$(PROJECT_NAME).c
OBJECTS=$(PROJECT_NAME).o
EXECUTABLE=$(PROJECT_NAME)
OUTPUT=output.txt

.PHONY: all clean check

all: $(EXECUTABLE)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJECTS)
	$(LD) -o $@ $< $(LDFLAGS)
ifdef RELEASE
	$(STRIP) $@
endif

clean:
	$(RM) $(EXECUTABLE) $(OBJECTS) $(OUTPUT)

check: $(EXECUTABLE)
	./$(EXECUTABLE) > $(OUTPUT)
	$(DIFF) $(OUTPUT) $(SOURCE)
	@$(ECHO) "Source is the same as output"
