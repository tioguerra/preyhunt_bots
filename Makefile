CFLAGS=-I/opt/local/include `sdl2-config --cflags`
LFLAGS=-lSDL2 -lSDL2_image

run: principal
	./principal

principal: principal.o huntbot.o preybot.o robot.o simulation.o
	g++ -o principal principal.o huntbot.o preybot.o robot.o simulation.o $(LFLAGS)

principal.o: principal.cpp robot.h simulation.h
	g++ $(CFLAGS) -c principal.cpp

simulation.o: simulation.cpp simulation.h
	g++ $(CFLAGS) -c simulation.cpp

robot.o: robot.cpp robot.h
	g++ $(CFLAGS) -c robot.cpp

preybot.o: preybot.cpp preybot.h
	g++ $(CFLAGS) -c preybot.cpp

huntbot.o: huntbot.cpp huntbot.h
	g++ $(CFLAGS) -c huntbot.cpp

clean:
	rm -rf principal *.o

