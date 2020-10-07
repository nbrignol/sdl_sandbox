#You will need globally installed sdl2 (port install, apt-get...)
g++ `sdl2-config --cflags --libs` -DMODE_CLI -lSDL2_Image application/*.cpp && ./a.out
