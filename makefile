CFLAGS = -I../..
ifeq ($(OS),Windows_NT)
		LDFLAGS = -s -lopengl32 -lgdi32
else
		UNAME_S := $(shell uname -s)
		ifeq ($(UNAME_S),Darwin)
				LDFLAGS = -framework OpenGL -framework Cocoa
		else ifeq ($(UNAME_S),Linux)
				LDFLAGS = -s -lGLU -lGL -lX11
		endif
endif

texto: texto.o tigr.o
	gcc -o texto texto.o tigr.o $(CFLAGS) $(LDFLAGS)
tigr.o: tigr/tigr.c
	gcc -c tigr/tigr.c

clean:
	del texto.exe texto.o tigr.o