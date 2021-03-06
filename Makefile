OS = $(shell uname)
ifeq ($(OS), Linux)
	FLAGS += -lSDL2 -lSDL2_mixer -pthread -lSDL2_ttf -I/usr/local/include/ -g
else
ifeq ($(OS), Darwin)
	FLAGS += -F/Library/Frameworks -framework SDL2 -framework SDL2_mixer -framework SDL2_ttf -L/usr/local/lib -I/usr/local/include/ -g
endif
endif
all:
	@echo "Compiling Leylines Prototype"
	@g++ *.cpp -std=c++11 -o Axilya -lAxilya -lcurl $(FLAGS)
	@echo "Complete."
run: all
	./Axilya
clean:
	@rm -f Axilya