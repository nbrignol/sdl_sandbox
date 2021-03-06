# How to install :

- somewhere/
    - SDL2/ --> Sources for SDL2 (no specific version)
    - SDL2_image/ --> Sources for SDL image (no specific version)
    - SDL2_ttf/ --> Sources for SDL ttf (no specific version)
    - SDL2_net/ --> Sources for SDL net (no specific version)
    - SDL2_mixer/ --> Sources for SDL mixer (no specific version)
    - SDL_Sandbox/ --> Clone or fork of this project

## Run SDL2/XCode-IOS/SDL/SDL.xcodeproj
- exclude "arm64" (Excluded Architecture / Any iOS simulator SDK -- debug and release)
- build all iOS (any iOS device)

## Run SDL2_image/XCode-IOS/SDL/SDL.xcodeproj
- add reference to SDL2/headers
- exclude "arm64" (Excluded Architecture / Any iOS simulator SDK -- debug and release)
- build all iOS (any iOS device)

## Run SDL2_mixer/XCode-IOS/SDL/SDL.xcodeproj
- add reference to SDL2/headers
- exclude "arm64" (Excluded Architecture / Any iOS simulator SDK -- debug and release)
- build all iOS (any iOS device)

## Run SDL2_ttf/XCode-IOS/SDL/SDL.xcodeproj
- add reference to SDL2/headers
- exclude "arm64" (Excluded Architecture / Any iOS simulator SDK -- debug and release)
- build all iOS (any iOS device)

## Run SDL2_net/XCode-IOS/SDL/SDL.xcodeproj
- add reference to SDL2/headers
- exclude "arm64" (Excluded Architecture / Any iOS simulator SDK -- debug and release)
- build all iOS (any iOS device)


## Run SDL_Sandbox.xcodeproj
- add references to SDL2/headers, SDL2_image/sdl_image.h
- add link to lib : libsdl.a, libsdl_image.a, AvFoundation.framework, Metal.framework and CoreBluetooth.framework
- add the Bundle version string (short) in the plist
- build and run


# Goals

Multiple targets for the SDL, SDL_Image, SDL TTF project : 

- iOS
- Unix (Tested on MacOS)

Soon : 

- Emscripten (WIP)
- Android
- MacOS bundle
- Windows

- SDL Mixer
- SDL Net

Todo :

- Clean resources 
- Better sample app !