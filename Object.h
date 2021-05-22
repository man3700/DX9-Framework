#pragma once

class Object abstract
{
public:
	Object() {}
	virtual ~Object() {}

	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	friend class ObjectManager;
	
	bool mIsActive = true;
	bool mIsDestroy = false;

public:
	void Active(bool _active) { mIsActive = _active; }
	void Destroy() { mIsDestroy = true; }

};
