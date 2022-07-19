#include "Application.h"

#include "LakeEngine/Events/ApplicationEvent.h"
#include "LakeEngine/Log.h"

namespace LakeEngine {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1920, 1080);
		LE_TRACE(e);

		while (true);
	}
}