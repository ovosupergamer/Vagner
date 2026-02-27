#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>

#ifndef Engine_h
#define Engine_h

class Engine
{
private:
protected:
public:
    class Math
    {
    private:
    protected:
    public:
        template<typename Type>
        static auto CalculateMedia(const std::vector<Type>& VectorToCalcMedia)
        {
            Type Result = 0;
            for (int loop1 = 0; loop1 < VectorToCalcMedia.size(); loop1++)
            {
                Result = Result + VectorToCalcMedia[loop1];
            }
            Result = Result / VectorToCalcMedia.size();
            return Result;
        }

        template<typename Type>
        static auto UniversalGravitacion(const Type& Gravity, const Type& MassInKG, const Type& OtherMassInKG, const Type& DistanceInMeters)
        {
            Type DistanceDoublePower = DistanceInMeters * DistanceInMeters;

            Type Force = Gravity * ((MassInKG * OtherMassInKG) / (DistanceDoublePower));
            return Force;
        }

        template<typename Type>
        static auto MachCalc(const Type& ObjectVelMetersForSecond)
        {
            Type Result = ObjectVelMetersForSecond / 343;

            return Result;
        }

        template<typename Type>
        static auto CalcVelUsingTwoPoints(const Type& DistanceOfTwoSensorsInMeters, const Type& TimeInSeconds)
        {
            Type Result = 0;
            Result = DistanceOfTwoSensorsInMeters / TimeInSeconds;
            return Result;
        }
    };

	class ObjectComponent
	{
	private:
	protected:
	public:
		virtual void Awake(){}
		virtual void Start(){}
		virtual void Update(){}
		virtual void FixedUpdate(){}
		virtual void OnDestroy(){}

		virtual ~ObjectComponent(){}
	};
	class EngineObject
	{
	private:
		std::vector<std::shared_ptr<ObjectComponent>> ObjectComponents;
	protected:
	public:
        EngineObject(){}
		EngineObject(std::vector<std::shared_ptr<ObjectComponent>>& InitialObjectComponents) : ObjectComponents(InitialObjectComponents) {}

		void AddObjectComponent(std::shared_ptr<ObjectComponent>& ObjectComponentToAdd)
		{
			ObjectComponents.push_back(std::move(ObjectComponentToAdd));
		}

		void AddObjectComponents(std::vector<std::shared_ptr<ObjectComponent>>& ObjectComponentsToAdd)
		{
			for (int loop1 = 0; loop1 < ObjectComponentsToAdd.size(); loop1++)
			{
				ObjectComponents.push_back(std::move(ObjectComponentsToAdd[loop1]));
			}
		}

		// Object components methods
		void AwakeAllObjectComponents()
		{
			for (int loop1 = 0; loop1 < ObjectComponents.size(); loop1++)
			{
				ObjectComponents[loop1]->Awake();
			}
		}

		void StartAllObjectComponents()
		{
			for (int loop1 = 0; loop1 < ObjectComponents.size(); loop1++)
			{
				ObjectComponents[loop1]->Start();
			}
		}

		void UpdateAllObjectComponents()
		{
			for (int loop1 = 0; loop1 < ObjectComponents.size(); loop1++)
			{
				ObjectComponents[loop1]->Update();
			}
		}

		void FixedUpdateAllObjectComponents()
		{
			for (int loop1 = 0; loop1 < ObjectComponents.size(); loop1++)
			{
				ObjectComponents[loop1]->FixedUpdate();
			}
		}

		void OnDestroyAllObjectComponents()
		{
			for (int loop1 = 0; loop1 < ObjectComponents.size(); loop1++)
			{
				ObjectComponents[loop1]->OnDestroy();
			}
		}
	};
};

#endif