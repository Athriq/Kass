#pragma once

#include "Core.h"

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
