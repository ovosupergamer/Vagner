#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <functional>
#include <chrono>
#include <typeinfo>

#include "EngineAPI.h"
#include "EngineDebug.h"
#include "EngineReflexionAPI.h"

int main()
{
	auto Sun = EngineReflexion::ReflectMethod<double,double,double>("Sun",{EngineReflexion::Type_Double,EngineReflexion::Type_Double},EngineReflexion::Type_Double,[](double First, double Second)
	{
		return First + Second;
	});

	auto Event = EngineReflexion::ReflectMethod<void,std::string>("Event",{EngineReflexion::Type_StdString},EngineReflexion::Type_Void,[](std::string Message)
	{
		std::cout << Message << "\n";
	});

	std::cout << typeid(Event).name() << "\n";
	std::cout << typeid(Sun).name() << "\n";
	std::cout << Sun.ExecuteFunctionWithReturn(25,25) << "\n";
	Event.ExecuteFunctionWithNoReturn("cu");

	return 0;
}