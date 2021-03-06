#pragma once

#include "mainpch.h"
#include "Utility/Log.h"

class Shader
{
public:
	Shader(const std::string& vertextSrc, const std::string& fragmentSrc);
	~Shader();

	void Bind() const;
	void Unbind() const;
private:
	uint32_t m_RendererID;
};