#include <SDL2/SDL.h>

struct Vector2 {
    float x;
    float y;
};

class Game {
    public:
        Game();
        // Init game
        bool Initialize();
        // Runs game loop untill gameover
        void RunLoop();
        // Shuts Down the game
        void Shutdown();
    private:
        // Helper funcs for the game loop
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        // Window Created by SDL
        SDL_Window* mWindow;
        // SDL Renderer
        SDL_Renderer* mRenderer;
        // Game should continue to run
        bool mIsRunning;

        // paddle pos
        Vector2 mPaddlePos;
        // ball pos
        Vector2 mBallPos;
};
