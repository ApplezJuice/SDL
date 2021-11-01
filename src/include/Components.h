#pragma once
#include <SDL2/SDL_image.h>

struct TagComponent
{
	std::string Tag;
	TagComponent() = default;
	TagComponent(const TagComponent&) = default;
	TagComponent(const std::string tag) : Tag(tag) {}
};

struct Position
{
	float x,y,z;
};

struct TransformComponent
{
	Position position;
	TransformComponent() = default;
	TransformComponent(const TransformComponent&) = default;
	TransformComponent(const Position pos) : position(pos) {}
};

struct SpriteRendererComponent
{
	SDL_Texture* texture;
	SpriteRendererComponent() = default;
	SpriteRendererComponent(const SpriteRendererComponent&) = default;
	SpriteRendererComponent(SDL_Texture* tex) : texture(tex) {}
};