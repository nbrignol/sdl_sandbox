#You will need globally installed sdl2 (port install, apt-get...)
#macport : libSDL2, libSDL2_image, libSDL2_ttf
g++ `sdl2-config --cflags --libs` -DMODE_CLI -lSDL2_Image -lSDL2_TTF application/*.cpp -o out/app.out && out/app.out
