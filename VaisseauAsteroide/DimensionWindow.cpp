#include "DimensionWindow.h"

int DimensionWindow::width = 0;
int DimensionWindow::height = 0;

int DimensionWindow::getWidth(){
	return width;
}
int DimensionWindow::getHeight(){
	return height;
}
void DimensionWindow::setWidth(int newWidth){
	width = newWidth;
}
void DimensionWindow::setHeight(int newHeight){
	height = newHeight;
}
