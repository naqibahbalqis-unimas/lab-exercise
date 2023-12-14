#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

const int TILE_SIZE = 80;
const int BOARD_SIZE = 10;
const int WINDOW_WIDTH = TILE_SIZE * BOARD_SIZE;
const int WINDOW_HEIGHT = TILE_SIZE * BOARD_SIZE;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* playerTexture = NULL;

typedef struct {
    int x;
    int y;
} Position;

Position players[2] = {{0, 0}, {0, 0}};
bool player1Turn = true;

void drawBoard() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Draw board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            SDL_Rect tileRect = {i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE};
            SDL_RenderDrawRect(renderer, &tileRect);
        }
    }

    // Draw players
    SDL_Rect playerRect = {players[0].x * TILE_SIZE, players[0].y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
    SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);

    SDL_Rect player2Rect = {players[1].x * TILE_SIZE, players[1].y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
    SDL_RenderCopy(renderer, playerTexture, NULL, &player2Rect);

    SDL_RenderPresent(renderer);
}

void movePlayer(int steps) {
    if (player1Turn) {
        players[0].x += steps;
        if (players[0].x >= BOARD_SIZE) {
            players[0].x = BOARD_SIZE - 1;
            players[0].y++;
        }
    } else {
        players[1].x += steps;
        if (players[1].x >= BOARD_SIZE) {
            players[1].x = BOARD_SIZE - 1;
            players[1].y++;
        }
    }
}

void handleEvent(SDL_Event* e) {
    if (e->type == SDL_QUIT) {
        exit(0);
    } else if (e->type == SDL_KEYDOWN) {
        switch (e->key.keysym.sym) {
            case SDLK_SPACE:
                movePlayer(rand() % 6 + 1);
                player1Turn = !player1Turn;
                break;
            default:
                break;
        }
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Snake and Ladders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* tempSurface = IMG_Load("player.png");
    if (!tempSurface) {
        printf("Failed to load player image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            handleEvent(&e);
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        drawBoard();
        SDL_Delay(16); // Cap the frame rate to approximately 60 frames per second
    }

    SDL_DestroyTexture(playerTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
