CXX = g++
CXXFLAGS = -Wall

proj4: Game.o Hero.o Area.o Enemy.o Creeper.o Mandarin.o Mannequin.o Weapon.o Plank.o Chainsaw.o Shotgun.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Hero.o Area.o Enemy.o Creeper.o Mandarin.o Mannequin.o Weapon.o Plank.o Chainsaw.o Shotgun.o proj4.cpp -o proj4

Game.o: Game.h Game.cpp Hero.o Area.o Enemy.o
	$(CXX) $(CXXFLAGS) -c Game.cpp

Hero.o: Hero.h Hero.cpp Weapon.o Plank.o Chainsaw.o Shotgun.o
	$(CXX) $(CXXFLAGS) -c Hero.cpp

Area.o: Area.h Area.cpp
	$(CXX) $(CXXFLAGS) -c Area.cpp

Enemy.o: Enemy.h Enemy.cpp
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Creeper.o: Creeper.h Creeper.cpp Enemy.o
	$(CXX) $(CXXFLAGS) -c Creeper.cpp

Mandarin.o: Mandarin.h Mandarin.cpp Enemy.o
	$(CXX) $(CXXFLAGS) -c Mandarin.cpp

Mannequin.o: Mannequin.h Mannequin.cpp Enemy.o
	$(CXX) $(CXXFLAGS) -c Mannequin.cpp

Weapon.o: Weapon.h Weapon.cpp
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Plank.o: Plank.h Plank.cpp Weapon.o
	$(CXX) $(CXXFLAGS) -c Plank.cpp

Chainsaw.o: Chainsaw.h Chainsaw.cpp Weapon.o
	$(CXX) $(CXXFLAGS) -c Chainsaw.cpp

Shotgun.o: Shotgun.h Shotgun.cpp Weapon.o
	$(CXX) $(CXXFLAGS) -c Shotgun.cpp

clean:
	rm *.o
	rm *~

run1:
	./proj4 proj4_map1.txt

run2:
	./proj4 proj4_map2.txt


val1:
	valgrind ./proj4 proj4_map1.txt

val2:
	valgrind ./proj4 proj4_map2.txt

submit:
	cp Game.h Game.cpp Hero.h Hero.cpp Area.h Area.cpp Enemy.h Enemy.cpp Creeper.h Creeper.cpp Mandarin.h Mandarin.cpp Mannequin.h Mannequin.cpp Weapon.h Weapon.cpp Plank.h Plank.cpp Chainsaw.h Chainsaw.cpp Shotgun.h Shotgun.cpp proj4.cpp ~/cs202proj/proj4

