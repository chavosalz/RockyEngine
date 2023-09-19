
#include <RockyEngine.h>

class WonderBox : public Rocky::Application
{
public:
	WonderBox()
	{

	}


	~WonderBox()
	{

	}

};

Rocky::Application* Rocky::CreateApplication()
{
	return new WonderBox();
}