#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void drawSquare(SDL_Renderer *renderer, int sx, int sy, int squareSize);
void drawPoints(SDL_Renderer *renderer, int sx, int sy, int squareSize);
void drawSides(SDL_Renderer *renderer, int sx, int sy, int squareSize);
void drawCup(SDL_Renderer *renderer, int sx, int sy, int squareSize);
int normalizeRGB(int squareSize, int i);

int main(int argc, char **argv)
{

    // INICIANDO A BIBLIOTECA
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    // CRIANDO CADA JANELA
    SDL_Window *window = SDL_CreateWindow("Computação Gráfica - Júlio Ernany", 300, 100, 300, 300, 0);

    SDL_Window *window2 = SDL_CreateWindow("Computação Gráfica - Júlio Ernany", 650, 100, 300, 300, 0);

    SDL_Window *window3 = SDL_CreateWindow("Computação Gráfica - Júlio Ernany", 300, 450, 300, 300, 0);

    SDL_Window *window4 = SDL_CreateWindow("Computação Gráfica - Júlio Ernany", 650, 450, 300, 300, 0);

    // CRIANDO OS RENDERER E PASSANDO O PARAMETRO A JANELA NO QUAL ELES VAO DESENHAR
    // RENDERER TOP LEFT, RENDERER TOP RIGHT, RENDERER BOTTOM LEFT E RENDERER BOTTOM RIGHT
    SDL_Renderer *renderer_tl = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Renderer *renderer_tr = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
    SDL_Renderer *renderer_bl = SDL_CreateRenderer(window3, -1, SDL_RENDERER_ACCELERATED);
    SDL_Renderer *renderer_br = SDL_CreateRenderer(window4, -1, SDL_RENDERER_ACCELERATED);

    // SETANDO A COR DE FUNDO PARA PRETO E EM SEGUIDA APRESENTANDO NA TELA
    SDL_SetRenderDrawColor(renderer_tl, 0, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer_tr, 0, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer_bl, 0, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer_br, 0, 0, 0, 255);
    SDL_RenderPresent(renderer_tl);
    SDL_RenderPresent(renderer_tr);
    SDL_RenderPresent(renderer_bl);
    SDL_RenderPresent(renderer_br);

    // ENTRANDO NO LOOP DO PROGRAMA
    // CONTROLE DE EVENTOS   
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
            }
        }

        // CHAMADA DE FUNÇÕES NA ORDEM CORRETA E PARAMETROS DESEJADOS, PODENDO MUDAR CASO QUEIRA.
        // OS PARAMETROS SAO COORDENADA X, COORDENADA Y E TAMANHO DO QUADRADO.      
        drawPoints(renderer_tl, 100, 100, 100);
        drawSides(renderer_tr, 100, 100, 100);
        drawCup(renderer_bl, 100, 100, 100);
        drawSquare(renderer_br, 100, 100, 100);
    }
    return 0;
}

// FUNÇÕES COM AS IMPLEMENTAÇÕES.
// SX =  STARTING X, SY = STARTING Y, SQUARESIZE = TAMANHO DO QUADRADO

void drawSides(SDL_Renderer *renderer, int sx, int sy, int squareSize)
{

    for (int i = 0; i < squareSize; i++)
    {
        SDL_Delay(50);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, sx, sy + i);
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawPoint(renderer, sx + squareSize, sy + i);
        SDL_RenderPresent(renderer);
    }
}

void drawPoints(SDL_Renderer *renderer, int sx, int sy, int squareSize)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // superior esquerda
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, sx, sy);

    // superior direita
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawPoint(renderer, sx + squareSize, sy);

    // inferior esquerda
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, sx, sy + squareSize);

    // inferior direita
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawPoint(renderer, sx + squareSize, sy + squareSize);

    SDL_RenderPresent(renderer);
}

void drawCup(SDL_Renderer *renderer, int sx, int sy, int squareSize)
{
    for (int i = 0; i < squareSize; i++)
    {
        SDL_Delay(50);
        // Linha Vertical Esquerda

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, sx, sy + i);

        // Linha Vertical Direita

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawPoint(renderer, sx + squareSize, sy + i);

        // Linha Horizontal Inferior
        if (i == squareSize-1)
        {
            for (int j = 0; j < squareSize; j++)
            {
                
                SDL_SetRenderDrawColor(renderer, -normalizeRGB(squareSize, j), 0, normalizeRGB(squareSize, j), 255);
                SDL_RenderDrawPoint(renderer, sx + j, sy + squareSize);
                SDL_Delay(50);
                SDL_RenderPresent(renderer);
            }
        }

        SDL_RenderPresent(renderer);
    }
}

void drawSquare(SDL_Renderer *renderer, int sx, int sy, int squareSize)
{
    for (int i = 0; i < squareSize; i++)
    {
        SDL_Delay(50);
        // Linha Vertical Esquerda

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, sx, sy + i);

        // Linha Vertical Direita

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawPoint(renderer, sx + squareSize, sy + i);

        // Linha Horizontal Superior

        SDL_SetRenderDrawColor(renderer, -normalizeRGB(squareSize, i), 0, normalizeRGB(squareSize, i), 255);
        SDL_RenderDrawPoint(renderer, sx + i, sy);

        // Linha Horizontal Inferior

        SDL_SetRenderDrawColor(renderer, -normalizeRGB(squareSize, i), 0, normalizeRGB(squareSize, i), 255);
        SDL_RenderDrawPoint(renderer, sx + i, sy + squareSize);

        SDL_RenderPresent(renderer);
    }
}


// FUNÇÃO PARA "NORMALIZAR O RGB", O TAMANHO DO QUADRADO É VARIÁVEL (DEFINIDO PELO USUÁRIO) 
// MAS AS CORES RGB VÃO ATÉ 255.
// ESSA FUNÇÃO FAZ COM QUE A INTERPOLAÇÃO DE CORES ACONTEÇA DE MANEIRA PROPORCIONAL ENTRE O TAMANHO DO
// QUADRADO (SQUARESIZE) E O NÚMERO MÁXIMO QUE O RGB ACEITA (255).

int normalizeRGB(int squareSize, int i)
{
    return ((i * 255) / squareSize);
}