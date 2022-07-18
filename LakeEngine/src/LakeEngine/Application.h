#pragma once

#include "Core.h"

namespace LakeEngine {
	class LAKE_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}