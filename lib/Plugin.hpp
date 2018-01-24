#pragma once

#include "IPlugin.hpp"

class CPlugin final : public IPlugin
{
public:
	CPlugin() = default;
	~CPlugin() = default;
	
#ifndef WANNABECOM_INLINE_DESTRUCTOR
	void Release() override {delete this;}
#endif
	
	void Init() override;
	void Shutdown() override;
};