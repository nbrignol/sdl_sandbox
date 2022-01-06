

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL_image.h"
#include "test.h"

//#include "SDL_net.h"
//#include "SDL_mixer.h"
#include "SDL_ttf.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480

int
randomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

Uint8 r, g, b;

SDL_Rect rect;
SDL_Surface * image;
SDL_Surface * message;
SDL_Texture * texture;
SDL_Texture * textureMessage;

int msgH, msgW;

double rotation;
float scale;

SDL_bool quality;


void
render(SDL_Renderer *renderer, SDL_Rect screen, SDL_Rect rect)
{

    
    /* Clear the screen */
    SDL_SetRenderDrawColor(renderer, 0, 50, 0, 255);
    SDL_RenderClear(renderer);

    
    
    b++;
    rotation+= -0.1;
    scale += 0.001f;
    
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    
    SDL_Rect imgRect = {0,0, 4961, 4961};
    int imageW =static_cast<int>(4961 * scale);
    int imageH =static_cast<int>(4961 * scale);
    SDL_Rect destRect = {rect.x - (imageW/2), rect.y - (imageH/2), imageW, imageH};
    
    /*  Fill the rectangle in the color */
    SDL_RenderFillRect(renderer, &screen);
    SDL_RenderFillRect(renderer, &rect);
        
    
    
    SDL_RenderCopy(renderer, textureMessage, &(message->clip_rect), &(message->clip_rect));
    
    
    SDL_RenderCopyEx(renderer, texture, &imgRect, &destRect, rotation, NULL, SDL_FLIP_NONE);

    /* update screen */
    SDL_RenderPresent(renderer);
}

int
main(int argc, char *argv[])
{
    quality = SDL_FALSE;
    r = 50;
    g = 50;
    b = 50;
    rotation = 0;
    scale = 0.1;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    int done;
    SDL_Event event;

    /* initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL\n");
        return 1;
    }



    /* create fullscreen window and renderer */
    #ifdef MODE_CLI
    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    #else 
    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS);
    #endif
    
    if (!window) {
        printf("Could not initialize Window\n");
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        printf("Could not create renderer\n");
        return 1;
    }

    int rendererW;
    int rendererH;
    
    SDL_GetRendererOutputSize(renderer, &rendererW, &rendererH);
    
    SDL_Log(HELLO);
    
    SDL_Rect gScreenRect = { 0, 0, rendererW, rendererH };
    SDL_Log("SIZE : %d / %d", rendererW, rendererH);
   
    rect.x = 0;
    rect.y = 0;
    rect.w = gScreenRect.w;
    rect.h = gScreenRect.h;
    
    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    #ifdef MODE_CLI
    image = IMG_Load("resources/boson.png");
    #else 
    image = IMG_Load("boson.png");
    #endif
    //image = SDL_LoadBMP("hero.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, image);
    
    
    if (TTF_Init() == -1){
        SDL_Log("TTF INIT FAIL");
    }

    TTF_Font * font = NULL;
    #ifdef MODE_CLI
    font = TTF_OpenFont( "resources/OCRA.ttf", 70 );
    #else
    font = TTF_OpenFont( "OCRA.ttf", 70 );
    #endif
    
    if (font == NULL){
        SDL_Log("TTF open FAIL");
    }
    
    SDL_Color textColor = { 255, 255, 255 };
    //message = TTF_RenderText_Solid( font, "Well, hello SDL", textColor );
    message = TTF_RenderText_Blended( font, "Well, hello SDL", textColor );
    
    
    //TTF_SizeText(TTF_Font *font, const char *text, int *w, int *h)
    textureMessage = SDL_CreateTextureFromSurface(renderer, message);
    
    
    /* Enter render loop, waiting for user to quit */
    done = 0;
    while (!done) {
        
        //rect.y = rect.y + 1;
        
        
        while (SDL_PollEvent(&event)) {
            
            //SDL_Log("EVENT : %d", event.type);
            
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                //SDL_Log("SDL_MOUSEBUTTONDOWN");

                rect.x = event.button.x;
                rect.y = event.button.y;
                
                scale = 2;
            }
            
            if (event.type == SDL_MOUSEBUTTONUP) {
                //SDL_Log("SDL_MOUSEBUTTONUP");
            }
            
            if (event.type == SDL_FINGERDOWN) {
                SDL_Log("SDL_FINGERDOWN %lld", event.tfinger.fingerId);
                
                rect.x = event.tfinger.x * gScreenRect.w;
                rect.y = event.tfinger.y * gScreenRect.h;
                
                scale = 0.1;
                rotation = 0;
                
               
                
                
            }
            
            if (event.type == SDL_FINGERUP) {
                SDL_Log("SDL_FINGERUP %lld", event.tfinger.fingerId);
                
                
                
            }

            if (event.type == SDL_FINGERMOTION) {
                //SDL_Log("SDL_FINGERMOTION");
                
                rect.x = event.tfinger.x * gScreenRect.w ;
                rect.y = event.tfinger.y * gScreenRect.h;
                
            }
            
            /*if (event.type == SDL_MULTIGESTURE) {
                SDL_Log("SDL_MULTIGESTURE dist : %f", event.mgesture.dDist);
                SDL_Log("SDL_MULTIGESTURE dTheta : %f", event.mgesture.dTheta);
                
                //rect.x = event.mgesture.x * gScreenRect.w;
                //rect.y = event.mgesture.y * gScreenRect.h;
                
                //rect.h = event.mgesture.dDist * gScreenRect.w * 100;
                //rect.w = event.mgesture.dDist * gScreenRect.h * 100;
                
            }*/
            
            if (event.type == SDL_MOUSEMOTION) {
                //SDL_Log("SDL_MOUSEMOTION");
                rect.x = event.motion.x;
                rect.y = event.motion.y;
            }
            
            if (event.type == SDL_QUIT) {
                done = 1;
            }
        }
        render(renderer, gScreenRect, rect);
        SDL_Delay(1);
    }

    /* shutdown SDL */
    SDL_Quit();

    return 0;
}
