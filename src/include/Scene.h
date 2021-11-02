#pragma once

#include "RenderWindow.h"
#include "entt.h"
#include "Components.h"
#include "mainpch.h"
#include "Utility/Log.h"

class Entity;
class Scene
{
public:
	Scene();
	Entity CreateEntity(const std::string& name = std::string());
	void RenderSprites(RenderWindow* renderer);
	entt::registry* GetRegistry(){ return &m_Registry; }
	~Scene();
private:
	entt::registry m_Registry;

	friend class Entity;
};