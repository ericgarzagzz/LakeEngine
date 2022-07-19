#pragma once

#include "Core.h"
#include "Events/Event.h"

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