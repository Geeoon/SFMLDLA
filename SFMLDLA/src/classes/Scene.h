#pragma once
#include <iostream>
#include "ParticleManager.h"
#include "UIManager.h"
class Scene
{
public:
	Scene();
	void start();
	void getInput();
private:
	int xresolution = 0;
	int yresolution = 0;
	int nParticles = 0;
	bool isDone = false;
	bool isFullscreen = false;
	std::unique_ptr<UIManager> ui;
	std::unique_ptr<ParticleManager> particles;
};

