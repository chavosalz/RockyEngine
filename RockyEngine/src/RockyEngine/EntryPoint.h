#pragma once

#ifdef RK_PLATFORM_WINDOWS

extern Rocky::Application* Rocky::CreateApplication();

int main(int argc, char** argv)
{
	Rocky::Log::Init();
	RK_INFO("What is up");
	int a = 5;
	RK_CORE_WARN("HELLO! Var={0}", a);

	auto app = Rocky::CreateApplication();
	app->Run();
	delete app;
}


#endif
