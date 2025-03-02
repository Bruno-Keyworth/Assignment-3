assignment-3:
	g++-11 main.cpp particle.cpp detector.cpp -o assignment-3.o -std=gnu++17

clean:
	rm assignment-3.o

run:
	g++-11 main.cpp particle.cpp detector.cpp -o assignment-3.o -std=gnu++17
	./assignment-3.o
