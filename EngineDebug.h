#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <functional>
#include <chrono>

#ifndef EngineDebug_h
#define EngineDebug_h

class EngineDebug
{
private:
protected:
public:
    template<typename FunctionReturnType,typename Function, typename... FunctionArgs>
    static FunctionReturnType CalcElapsedTimeToExecFunction(Function& FunctionToCalc, FunctionArgs&&... args)
    {
        auto WhenStart = std::chrono::high_resolution_clock::now();

        FunctionReturnType FunctionReturn = FunctionToCalc(std::forward<FunctionArgs>(args)...);

        auto WhenEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> TimeElapsed = WhenEnd - WhenStart;
        std::cout << "Elapsed time: " << TimeElapsed.count() << "\n";
        return FunctionReturn;
    }

    template<typename Function, typename... FunctionArgs>
    static void CalcElapsedTimeToExecFunction(Function& FunctionToCalc, FunctionArgs&&... args)
    {
        auto WhenStart = std::chrono::high_resolution_clock::now();

        FunctionToCalc(std::forward<FunctionArgs>(args)...);

        auto WhenEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> TimeElapsed = WhenEnd - WhenStart;
        std::cout << "Elapsed time: " << TimeElapsed.count() << "\n";
    }
};

#endif