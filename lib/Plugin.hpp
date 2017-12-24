#pragma once

#include "IPlugin.hpp"

class CPlugin final : public IPlugin
{
public:
	CPlugin() = default;
	~CPlugin() = default;
	
	void Init() override;
	void Shutdown() override;
};