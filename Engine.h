#ifndef Engine_H
#define Engine_H

#include "glrenderer.h"
#include "camera.h"
#include "SFML/Window.hpp"

class Engine
{
private:
	sf::Window _mainWindow;
	bool _running;
	int _exitCode;
	sf::Clock _runtimeClock;
	OGI::GLRenderer _renderer;
	OGI::Camera *_mainCamera;
	
    void CreateWindow(int resolutionWidth, int resolutionHeight, bool fullscreen);
	void HandleEvent(sf::Event windowEvent);
	void InitializeGlew();
	void ResetMousePos();
public:
    Engine();
    ~Engine();
	int Run();
	void Exit(int code = 0);
	
protected:
	sf::Window& GetWindow();
	void virtual Initialize();
	void virtual Update(const sf::Time elapsedTime);
	void virtual Draw(const sf::Time elapsedTime);
};

#endif // Engine_H
