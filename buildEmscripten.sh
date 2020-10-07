#You will need emscripten installed + a local web server (php, python...) to run
#--preload-file 
emcc  -DMODE_WEB  application/*.cpp -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -o out/project.html
#php -S 127.0.0.1:1234
