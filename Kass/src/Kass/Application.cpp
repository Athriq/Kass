#include "ksspch.h"
#include "Application.h"

#include "Kass/Events/ApplicationEvent.h"
#include "Kass/Log.h"

namespace Kass {
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			KSS_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			KSS_TRACE(e);
		}
		
		while (true);
	}
}
