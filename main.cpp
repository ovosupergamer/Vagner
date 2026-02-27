#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>

#include "GameEngineAPI.h"

class testing : public Engine::ObjectComponent
{
public:
	void Start() override
	{
		std::cout << "Start executed\n";
	}

	void FixedUpdate() override
	{
		std::cout << "Fixed updated execute\n";
	}
};

int main()
{

	return 0;
}