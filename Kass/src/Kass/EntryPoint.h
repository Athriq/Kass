#pragma once

#ifdef KSS_PLATFORM_WINDOWS

extern Kass::Application* Kass::CreateApplication();

int main(int argc, char** argv) {
	Kass::Log::Init();
	KSS_CORE_WARN("Initialized Log!");
	KSS_INFO("Hello!");

	auto app = Kass::CreateApplication();
	app->Run();
	delete app;
}

#endif