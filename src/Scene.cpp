#include "Scene.h"
#include "Entity.h"

Scene::Scene()
{
	
}

Entity Scene::CreateEntity(const std::string& name)
{
	// Entity is just an uint32_t
	Entity entity = { m_Registry.create(), this};
	entity.AddComponent<TransformComponent>();
	auto& tag = entity.AddComponent<TagComponent>();
	tag.Tag = name.empty() ? "Entity" : name;
	return entity;
}

void Scene::RenderSprites(RenderWindow* renderer)
{
	renderer->clear();
	auto view = m_Registry.view<SpriteRendererComponent>();
	for (auto sprites : view)
	{
		SpriteRendererComponent& sprite = view.get<SpriteRendererComponent>(sprites);
		renderer->render(sprite.texture);
	}

	renderer->display();
}

Scene::~Scene(){}