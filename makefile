grafica1.png : datos1.txt
	python grafica1.py
datos1.txt : punto1.x
	./punto1.x > datos1.txt
punto1.x :
	c++ punto1.cpp -o punto1.x
clean:
	rm grafica1.png datos1.txt punto1.x
