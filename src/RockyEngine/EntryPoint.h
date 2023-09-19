#pragma once

#ifdef RK_PLATFORM_WINDOWS

extern Rocky::Application* Rocky::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to the Rocky Engine!");
	auto app = Rocky::CreateApplication();
	app->Run();
	delete app;
}


#endif
