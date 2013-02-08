all: stest

debug: 
	gcc -g -c stest.c
	gcc -g -c employee.c
	gcc -g stest.o employee.o -o stest

debugplus:
	gcc -g -c -DDEBUG stest.c
	gcc -g -c -DDEBUG employee.c
	gcc -g -DDEBUG stest.o employee.o -o stest 

stest: stest.o employee.o
	gcc -lreadline -lncurses stest.o employee.o -o stest

employee.o: employee.c employee.h
	gcc -c -lreadline -lncurses employee.c

stest.o: stest.c
	gcc -c -lreadline -lncurses stest.c


docs: Doxyfile
	doxygen
	chmod 755 latex html
	cp -rp /home/lpavel/courses/lab4_cs2303/html /home/lpavel/public_html/assig4
	cp -rp /home/lpavel/courses/lab4_cs2303/latex /home/lpavel/public_html/assig4
clean:
	rm -f *.o
	rm -f stest
