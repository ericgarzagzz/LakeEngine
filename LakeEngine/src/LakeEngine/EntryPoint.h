#pragma once

#ifdef LE_PLATFORM_WINDOWS

extern LakeEngine::Application* LakeEngine::CreateApplication();

int main(int argc, char** argv)
{
	LakeEngine::Log::Init();
	LE_CORE_WARN("Logger initialized");
	LE_INFO("App initialized");

	auto app = LakeEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif // LE_PLATFORM_WINDOWS
