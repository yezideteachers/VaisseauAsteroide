#pragma once

class DimensionWindow{
private:
	static int width;
	static int height;

public:
	static int getWidth();

	static int getHeight();

	static void setWidth(static int newWidth);

	static void setHeight(static int newHeight);

};