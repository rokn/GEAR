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
	
    void CreateWindow(int resolutionWidth, int resolutionHeight, bool fullscreen);
public:
    Engine();
    virtual ~Engine();
	int Run();
	void Exit(int code = 0);
	
protected:
	sf::Window& GetWindow();
	void virtual Initialize();
	void virtual HandleEvent(sf::Event windowEvent);
	void virtual Update(const sf::Time elapsedTime);
	void virtual Draw(const sf::Time elapsedTime);
};

#endif // Engine_H
