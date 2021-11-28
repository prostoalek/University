#include "ModelWindow.h"


// Access descriptors

	string ModelWindow::getTitle() {
		return Title;
	}

	string ModelWindow::getColor() {
		return Color;
	}

	int ModelWindow::getX() {
		return X;
	}

	int ModelWindow::getY() {
		return Y;
	}

	int ModelWindow::getWidth() {
		return Width;
	}

	int ModelWindow::getHeight() {
		return Height;
	}

	bool ModelWindow::getIsVisible() {
		return IsVisible;
	}

	bool ModelWindow::getIsFramed() {
		return IsFramed;
	}


	// Methods

	void ModelWindow::setTitle(string title) {
		Title = title;
	}

	void ModelWindow::setColor(string color) {
		Color = color;
	}

	void ModelWindow::setX(int x) {
		X = x;
	}

	void ModelWindow::setY(int y) {
		Y = y;
	}

	void ModelWindow::setWidth(int width) {
		Width = width;
	}

	void ModelWindow::setHeight(int height) {
		Height = height;
	}

	void ModelWindow::setIsFramed(bool isFramed) {
		IsFramed = isFramed;
	}

	void ModelWindow::Move(int x, int y) {
		X = x;
		Y = y;
	}

	void ModelWindow::Resize(int height, int width) {
		Height = height;
		Width = width;
	}

	void ModelWindow::ChangeColor(string color) {
		Color = color;
	}

	void ModelWindow::ChangeVisibility() {
		IsVisible = !IsVisible;
	}

	string ModelWindow::ToString() {
		return "Title: " + getTitle() + "\nColor: " + getColor() + "\nX coordinate: " + to_string(getX()) + "\nY coordinate: " + to_string(getY()) +
			"\nWidth: " + to_string(getWidth()) + "\nHeight: " + to_string(getHeight()) + "\nVisibility form: " + (getIsVisible() ? "visible" : "invisible") +
			"\nIs Framed: " + (getIsFramed() ? "yes" : "no\n");
	}
	


	// Constructors and destructures
	
	ModelWindow::ModelWindow(string title, string color, int x, int y,
		int width, int height, bool isVisible, bool isframed)
	{
		Title = title;
		Color = color;
		X = x;
		Y = y;
		Width = width;
		Height = height;
		IsVisible = isVisible;
		IsFramed = isframed;
	}

	ModelWindow::ModelWindow()
	{
		Title = "NewTitle";
		X = 0;
		Y = 0;
		Width = 1;
		Height = 1;
		Color = "#000000";
		IsVisible = true;
		IsFramed = true;
	}

	ModelWindow::~ModelWindow()
	{
		//std::cout << "\nДеструктор сработал\n";
	}


