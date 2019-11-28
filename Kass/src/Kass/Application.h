#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Kass {
	class KASS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
