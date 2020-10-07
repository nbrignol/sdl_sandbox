+ How to install :

- somewhere/
-    SDL2/ --> Sources for SDL2 (no specific version)
-    SDL2_image/ --> Sources for SDL image (no specific version)
-    SDL_Sandbox/ --> Clone or fork of this project



++ Run SDL2/XCode-IOS/SDL/SDL.xcodeproj
- exclude "arm64" (Excluded Architecture / Any iOS simulator SDK -- debug and release)
- build all iOS (any iOS device)

++ Run SDL2_image/XCode-IOS/SDL/SDL.xcodeproj
- add reference to SDL2/headers
- exclude "arm64" (Excluded Architecture / Any iOS simulator SDK -- debug and release)
- build all iOS (any iOS device)

++ Run SDL_Sandbox.xcodeproj
- add references to SDL2/headers, SDL2_image/sdl_image.h
- add link to lib : libsdl.a, libsdl_image.a, AvFundation.framework, Metal.framework and CoreBluetooth.framework
- add the Bundle version string (short) in the plist
- build and run


Multiple targets for the SDL, SDL_Image, SDL_Mixer project : 

- iOS

Soon : 

- MacOS
- Linux
- Emscripten
- Android
- Windows