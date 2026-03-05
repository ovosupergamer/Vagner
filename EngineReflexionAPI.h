#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <functional>
#include <chrono>

#ifndef EngineReflexionAPI_h
#define EngineReflexionAPI_h


class EngineReflexion
{
private:
protected:
public:
    enum Type
    {
    Type_Undefined,
    Type_Void,
    Type_Int,
    Type_Float,
    Type_Double,
    Type_Char,
    Type_Boolean,
    Type_StdString
    };

    template<typename VarType>
    class ReflectVar
    {
    private:
        std::string VarName = "";
        Type TypeOfVar = Type_Undefined;
        VarType VarData;
    protected:
    public:
        ReflectVar(const std::string& GetVarName, const Type& GetTypeOfVar,VarType GetVarData)
        {
            VarData = GetVarData;
            TypeOfVar = GetTypeOfVar;
            VarData = GetVarData;
        }

        // Get methods
        const std::string& GetVarName()
        {
            return VarName;
        }

        const Type& GetTypeOfVar()
        {
            return TypeOfVar;
        }

        const auto& GetVarData()
        {
            return VarData;
        }

        // Set methods
        void SetVarData(VarType NewData)
        {
            VarData = NewData;
        }
    };

    template<typename FunctionReturnType, typename... FunctionArgs>
    class ReflectMethod
    {
    private:
        std::string FunctionName = "";
        std::function<FunctionReturnType(FunctionArgs...)> MethodToReflect;
        std::vector<Type> FunctionParameters;
        Type TypeOfFunctionReturnType = Type_Undefined;
    protected:
    public:
        ReflectMethod(const std::string& GetMethodName, const std::vector<Type>& GetFunctionParameters, const Type& GetFunctionReturnType, const std::function<FunctionReturnType(FunctionArgs...)>& GetMethodToReflect)
        {
            FunctionName = GetMethodName;
            FunctionParameters = GetFunctionParameters;
            TypeOfFunctionReturnType = GetFunctionReturnType;
            MethodToReflect = GetMethodToReflect;
        }

        // Get methods
        const std::string& GetFunctionName()
        {
            return FunctionName;
        }

        const Type& GetFunctionReturnType()
        {
            return TypeOfFunctionReturnType;
        }

        const auto& GetFunctionParametersType()
        {
            return FunctionParameters;
        }
        
        // ExecuteMethod
        // Do not use const & in this function, because when method ends, him delete de return variable, then you need to pass an copy
        template<typename... Args>
        auto ExecuteFunctionWithReturn(Args&&... args)
        {
            auto FunctionReturn = MethodToReflect(std::forward<Args>(args)...);
            return FunctionReturn;
        }

        template<typename... Args>
        void ExecuteFunctionWithNoReturn(Args&&... args)
        {
            MethodToReflect(std::forward<Args>(args)...);
        }
    };
};

#endif