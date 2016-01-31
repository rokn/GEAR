#ifndef Engine_H
#define Engine_H

#include "SFML/Window.hpp"

class Engine
{
private:
	sf::Window _mainWindow;
	bool _running;
	int _exitCode;
	sf::Clock _runtimeClock;
	
    void CreateWindow(int resolutionWidth, int resolutionHeight, bool fullscreen);
	void HandleEvent(sf::Event windowEvent);
	void InitializeGlew();
	
public:
    Engine();
    ~Engine();
	int Run();
	void Exit(int code = 0);
	
protected:
	sf::Window& GetWindow();
	void virtual Initialize();
	void virtual Update(sf::Time gameTime);
	void virtual Draw(sf::Time gameTime);
};

#endif // Engine_H
