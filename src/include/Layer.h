#pragma once
#include "mainpch.h"

class RenderWindow;
class Layer
{
public:
	Layer(const std::string& name = "Layer");
	virtual ~Layer();

	virtual void OnAttach(RenderWindow* renderer) {}
	virtual void OnDetach() {}
	virtual void OnUpdate() {}
	virtual void OnImGuiRender() {}

	inline const std::string& GetName() const { return m_DebugName; }
protected:
	std::string m_DebugName;
};