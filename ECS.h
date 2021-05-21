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

inline ComponentID getComponentID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{

	static ComponentID typeID = getComponentID();					//will generate a new lastID for us, and put it in typeID
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
using ComponentBitSet = std::bitset<maxComponents>;

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
	ComponentBitSet componentBitset;

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
};




#endif