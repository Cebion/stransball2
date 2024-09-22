TARGET=supertransball2
OBJS := \
	auxiliar.o           configuration.o     encoder.o \
	enemies.o            fonts.o       	 game.o \
	main.o               maps.o              replays.o \
	state_changepack.o   state_chooseship.o  state_endsequence.o \
	state_game.o         state_gameover.o    state_instructions.o \
	state_interphase.o   state_keyredefinition.o \
	state_levelfinished.o state_logo.o       state_mainmenu.o \
	state_replay.o       state_replaymanager.o \
	state_typetext.o     tiles.o             transball.o \

all: $(TARGET)


%.o: %.cpp
	$(CXX) -c -g3 -O3 $< -o $@ $(CPPFLAGS) $(CFLAGS) `sdl-config --cflags` -I/usr/local/include/SDL

# dynamically linked binary:
$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS) `sdl-config --libs` -lSDL_image -lSDL_mixer -lSGE -I/usr/local/include/SDL
	mv ./$(TARGET) ..

clean:
	rm -f ../$(TARGET)
	rm -f *.o

install:
	install -o root -g games -m 755 ../$(TARGET) $(DESTDIR)/usr/games

install-data:
	install -o root -g games -m 644 ../demos/* $(DESTDIR)/usr/share/games/supertransball2/demos/
	install -o root -g games -m 644 ../sound/* $(DESTDIR)/usr/share/games/supertransball2/sound/
	cp -r ../maps/* $(DESTDIR)/usr/share/games/supertransball2/maps/
	install -o root -g games -m 644 ../graphics/* $(DESTDIR)/usr/share/games/supertransball2/graphics/
