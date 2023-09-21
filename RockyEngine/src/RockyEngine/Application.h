#pragma once

#include "Core.h"
#include "Events/Event.h"

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

