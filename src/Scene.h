#pragma once
#include "Events.h"
#include "Resources.h"

class Scene
{
public:
	virtual void update() {};
	virtual void draw() {};
	virtual ~Scene() = default;
};

