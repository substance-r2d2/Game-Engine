#include <iostream>
#include <string>

#include "MainGame.h"

void fatalError(std::string errorMessage)
{
	std::cout << errorMessage << std::endl;
	std::cout << "PRESS ANY KEY TO QUIT" << std::endl;
	int a;
	std::cin >> a;
	SDL_Quit();
}

MainGame::MainGame()
{
	_window = nullptr;
	_screenHeight = 576;
	_screenWidth = 1024;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();

	gameLoop();
}

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr)
		fatalError("WINDOW CREATION ERROR!");

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
		fatalError("GL context could not be created!");

	GLenum error = glewInit();
	if (error != GLEW_OK)
		fatalError("glew Init error!");
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event input;

	while (SDL_PollEvent(&input))
	{
		switch (input.type)
		{
		case SDL_QUIT:
		{
			_gameState = GameState::EXIT;
			break;
		}

		default:
			break;
		}
	}
}
