#pragma once
#include "Object.h"

class ObjectManager : public Singleton<ObjectManager>
{
public:
	ObjectManager();
	virtual ~ObjectManager();

	void Update();
	void Render();

private:
	list<Object*> mObjects;

public:
	template<typename T> T Create(T _object)
	{
		mObjects.push_back(_object);
		return _object;
	}

	template<typename T> T* Search()
	{
		for (auto iter : mObjects)
		{
			if (typeid(*iter) == typeid(T))
				return static_cast<T*>(iter);
		}

		T* cast;
		for (auto iter : mObjects)
		{
			cast = dynamic_cast<T*>(iter);
			if (cast) return cast;
		}

		cout << "Object couldn't search." << endl;

		return list;
	}

	template<typename T> list<T*> SearchAll()
	{
		list<T*> list;

		for (auto iter : mObjects)
		{
			if (typeid(*iter) == typeid(T))
				list.push_back(static_cast<T*>(iter));
		}

		if (!list.empty())
			return list;
		
		T* cast;
		for (auto iter : mObjects)
		{
			cast = dynamic_cast<T*>(iter);
			if (cast) list.push_back(cast);
		}

		if (list.empty())
			cout << "Object couldn't search." << endl;

		return list;
	}

};
