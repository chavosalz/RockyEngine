#pragma once

#include "Core.h"

namespace Rocky {

	class ROCKY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

