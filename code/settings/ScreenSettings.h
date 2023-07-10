#pragma once

class ScreenSettings
{
public:
	int GetScreenWidth() { return screenWidth; }
	int GetScreenHeight() { return screenHeight; }
	float GetScreenAspect() { return (float)screenWidth / (float)screenHeight; }

	void SetScreenWidth(int width)
	{
		screenWidth = width;
	}

	void SetScreenHeight(int height)
	{
		screenHeight = height;
	}

private:
	int screenWidth = 1000;
	int screenHeight = 1000;
};