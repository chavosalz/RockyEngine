#include "Application.h"

#include "RockyEngine/Events/ApplicationEvent.h"
#include "RockyEngine/Log.h"

namespace Rocky {



	Application::Application()
	{
	}

	Application::~Application() 
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		RK_TRACE(e);
		while (true);
	}
}