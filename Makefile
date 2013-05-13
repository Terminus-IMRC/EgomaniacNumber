PROJ=EgomaniacNumber

X=5
# BE CAREFUL!
ELEM=275305224

DEBUGOPT=-g
WARNOPT=-Wall -Wextra -W -Wundef -Wshadow	\
	-Wcast-qual -Winline -Wno-long-long	\
	-fsigned-char -ansi -pedantic -Werror
OPTOPT=-O0

OBJS=EgomaniacNumber.c.o will_and_die.c.o isthetime_came.c.o

DEPS=$(MAKEFILE_LIST)

all: $(PROJ)

EgomaniacNumber: $(OBJS)
	$(LINK.o) $(OUTPUT_OPTION) $(OBJS)

EgomaniacNumber.c.o: defs.h
EgomaniacNumber.c.o: DEFS=-DX=$(X) -DELEM=$(ELEM)

will_and_die.c.o: DEFS=-DPROJNAME=\"$(PROJ)\"

%.c.o: %.c $(DEPS)
	$(COMPILE.c) $(OUTPUT_OPTION) $(DEFS) $(DEBUGOPT) $(WARNOPT) $(OPTOPT) $<

clean:
	$(RM) $(OBJS) $(PROJ)

run: EgomaniacNumber
	./$<

.PHONY: clean
