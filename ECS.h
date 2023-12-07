#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class component;
class entity;

using componentID = std::size_t;

inline componentID getcomponentTypeID()
{
	static componentID lastID = 0;
	return lastID++;
}

template <typename T> inline componentID getcomponentTypeID() noexcept
{
	static componentID typeID = getcomponentTypeID();
	return typeID;
}

constexpr std::size_t maxcComponents = 32;

using componentBitSet = std::bitset<maxcComponents>;
using componentArray = std::array<component*, maxcComponents>;

class component
{
public:
	entity* entity;

	virtual void init() {}

	virtual void update() {}
	virtual void draw() {}

	virtual ~component() {}
};

class entity
{
private:
	bool active = true;
	std::vector<std::unique_ptr<component>> components;

	componentArray componentArray;
	componentBitSet componentBitSet;
public:
	void update()
	{
		for (auto& c : components) c->update();
		
	}
	void draw() 
	{
		for (auto& c : components) c->draw(); for (auto& c : components) c->draw();
	}
	bool isActive() const { return active; }
	void destroy() { active = false; }
	template <typename T> bool hascomponent() const
	{
		return componentBitSet[getcomponentTypeID<T>];
	}

	template <typename T, typename... TArgs>
	T& addcomponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getcomponentTypeID<T>()] = c;
		componentBitSet[getcomponentTypeID<T>()] = true;

		c->init();
		return *c;
	}
	template<typename T> T& getcomponent() const
	{
		auto ptr(componentArray[getcomponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
	//gameobject.getcomponent<positioncomponent>().setXpos(25);
};

class manager
{
private:
	std::vector<std::unique_ptr<entity>> entities;

public:
	void update()
	{
		for (auto& e : entities) e->update();
	}
	void draw()
	{
		for (auto& e : entities) e->draw();
	}

	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](std::unique_ptr<entity>& mentity)
			{
				return !mentity->isActive();
			}),
			std::end(entities));
	}
	entity& addentity()
	{
		entity* e = new entity();
		std::unique_ptr<entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e; 
	}
};
