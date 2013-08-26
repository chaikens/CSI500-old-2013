all : dumps hello run

OBJDUMP_OPTIONS = --all-headers --section .data --section .text  --disassemble --source --full-contents --reloc

.PHONY: dumps
dumps : hello.o.dumped hello.dumped

hello.o.dumped : hello.o
	objdump ${OBJDUMP_OPTIONS}  $< > $@

hello.dumped : hello
	objdump ${OBJDUMP_OPTIONS}  $< > $@


hello : hello.o
	ld -o $@ $<

hello.o : hello.s
	as -g  -o $@ $<

.PHONY: run
run :
	-./hello

.PHONY: clean
clean:
	rm -f *.o hello *.dumped* *~ *.ps *.pdf

.PHONY: pdfs
pdfs:
	mpage -1 -L73 hello.dumped > hello.dumped.ps
	mpage -1 -L73 hello.o.dumped > hello.o.dumped.ps
	ps2pdf hello.dumped.ps hello.dumped.pdf
	ps2pdf hello.o.dumped.ps hello.o.dumped.pdf
	mpage -1 hello.s > hello.s.ps
	mpage -1f Makefile > Makefile.ps
	ps2pdf hello.s.ps hello.s.pdf
	ps2pdf Makefile.ps > Makefile.pdf


