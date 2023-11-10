#pragma once
#include "Events.h"
#include "Resources.h"
#include "Functions.h"

class Scene
{
public:
	virtual void update() {};
	virtual void draw()const {};
	virtual ~Scene() = default;
};

