#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <functional>
#include <chrono>

#include "EngineAPI.h"
#include "EngineDebug.h"
#include "EngineReflexionAPI.h"

int main()
{
	auto MyFunction = EngineReflexion::ReflectMethod<float,float,float>("MyFunction",{EngineReflexion::Type_Float,EngineReflexion::Type_Float},EngineReflexion::Type_Float,[](float First, float Second)
	{
		return First + Second;
	});

	std::cout << MyFunction.ExecuteFunction(15,15) << "\n";

	return 0;
}