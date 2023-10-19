
OBJS=testapp.o gnlthread.o graph.o topo.o

test : ${OBJS}
	cc -o test ${OBJS}

testapp.o : testapp.c graph.h 
	cc -c testapp.c

graph.o : graph.c graph.h
	cc -c graph.c

topo.o : topo.c 
	cc -c topo.c

clean:
	rm *.o 
	rm test    
