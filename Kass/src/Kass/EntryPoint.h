#pragma once

#ifdef KSS_PLATFORM_WINDOWS

extern Kass::Application* Kass::CreateApplication();

int main(int argc, char** argv) {
	auto app = Kass::CreateApplication();
	app->Run();
	delete app;
}

#endif