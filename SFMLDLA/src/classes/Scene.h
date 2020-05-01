#pragma once
#include "ParticleManager.h"
#include "UIManager.h"
class Scene
{
public:
	Scene();
	void start();
private:
	UIManager ui;
	std::unique_ptr<ParticleManager> particles;
};

