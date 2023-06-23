#pragma once

#include <iostream>
#include <unordered_map>
#include <typeindex>

namespace Utilities
{
	class DI 
	{
	public:

		template <typename T>
		static void Register(std::shared_ptr<T> dependency)
		{
			std::type_index type = std::type_index(typeid(T));
			dependencies[type] = std::static_pointer_cast<void>(dependency);
		}

		template <typename T>
		static void UnRegister()
		{
			std::type_index type = std::type_index(typeid(T));
			if (dependencies.find(type) != dependencies.end())
			{
				dependencies.erase(type);
			}
		}

		template <typename T>
		static std::shared_ptr<T> Get()
		{
			std::type_index type = std::type_index(typeid(T));
			auto objectIterator = dependencies.find(type);

			if (objectIterator != dependencies.end())
			{
				return std::static_pointer_cast<T>(objectIterator->second);
			}

			return nullptr;
		}

	private:
		static std::unordered_map<std::type_index, std::shared_ptr<void>> dependencies;
	};
}