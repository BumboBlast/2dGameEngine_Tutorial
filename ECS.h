#ifndef ECS_H
#define ECS_H
#pragma once

#include "StandardForward.h"

/*
* Each "entity", such as an interactable sprite which would be drawn on the screen
* 
* They have "components" such as physics
* 
* entities will need to be initialized, updated, drawn, and deconstructed.
*/
class Component;
class Entity;












using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}
















/* dont understand this at all 
*/
template <typename T> inline ComponentID getComponentTypeID() noexcept
{

	static ComponentID typeID = getComponentTypeID();					//will generate a new lastID for us, and put it in typeID
	return typeID;
}














// the maximum amount of componenets an entity is able to hold.
constexpr std::size_t maxComponents = 32;

/*
*	If we need to find out if an entity has a selection of components. 
*	We can geneerate the bitset
* 
*	So the bitset is an optimization to store/compare components (as booleans?)
*	because boolean AND and OR is pretty nice!
*/
using ComponentBitset = std::bitset<maxComponents>;

/*
* stores the componenets?? 
*/
using ComponentArray = std::array<Component*, maxComponents>;



















class Component {

public:
	// so it has a reference to its owner
	Entity* entity;

	/*
	* virtual functions so we can "override them"
	* 
	* this is called "~RUNTIME POLYMORPHISM~"
	*/

	virtual void init()
	{

	}

	virtual void update()
	{

	}

	virtual void draw()
	{

	}

	virtual ~Component()
	{

	}
};























class Entity {

private:

	// if false. we can remove from the game.
	bool active = true;
	
	//"We'll call this list of components,  components."
	std::vector<std::unique_ptr<Component>> components;

	//"Then well have a ComponentArray, which we'll call componenetArray."
	ComponentArray componentArray;
	ComponentBitset componentBitset;

public:

	/*
	* well have the entity loop through all of its componenets, and call its update and draw methods
	*/
	void update()
	{
		for (auto& c : components) {c->update();}
		for (auto& c : components) {c->draw();}
	}
	void draw()
	{

	}

	bool isActive() const {return active;}

	/*
	* Because each component has reference to the owner (entity),
	* we can call the entity destory function from the component
	*/
	void destory() { active = false; }







	/* I dont understand this at all either
	*/
	template<typename T> bool hasComponenet() const
	{
		return componentBitset[getComponentTypeID<T>];
	}


	/*wtf is going on
	*/
	template<typename T, typename... TArgs>
	T& addComponenet(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitset[getComponentTypeID<T>()] = true;

		c->init();
		

		return *c;
	}




	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}


	/* all of this , so that i can do this:
	* 
	*	/gameobject/.getComponent</positioncomponent/>().setXpos(25);
	*/
};

























class Manager {
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	/*use the manager to update all of our entities*/
	void update()
	{
		for (auto& e : entities) {e->update();}
	}

	void draw()
	{
		for (auto& e : entities) {e->draw();}
	}



	/* bro wtf! */
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			}),
			std::end(entities));
	}


	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };

		entities.emplace_back(std::move(uPtr));

		return *e;
	}
};




#endif