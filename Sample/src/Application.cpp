#include <LakeEngine.h>

class App : public LakeEngine::Application
{
public:
	App() {}
	~App() {}
};

LakeEngine::Application* LakeEngine::CreateApplication() {
	return new App();
}