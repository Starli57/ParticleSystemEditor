#pragma once

class IContext
{
public:
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

	virtual void BeforeUpdate() = 0;
	virtual void Update() = 0;
	virtual void AfterUpdate() = 0;

	virtual void BeforeRender() = 0;
	virtual void Render() = 0;
	virtual void AfterRender() = 0;
};