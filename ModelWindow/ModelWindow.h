#include <string>

using namespace std;

class ModelWindow
{
private:
	int X, Y;
	int Width, Height;

	bool IsVisible, IsFramed;

public:
	string Title;
	string Color;

	ModelWindow();

	ModelWindow(string title, string color, int x, int y, int width, int height, bool isVisible, bool isframed);

	~ModelWindow();


	string getTitle();

	string getColor();

	int getX();

	int getY();

	int getWidth();

	int getHeight();

	bool getIsVisible();

	bool getIsFramed();

private:
	void setTitle(string title);

	void setColor(string color);

	void setX(int x);

	void setY(int y);

	void setWidth(int sizeX);

	void setHeight(int sizeY);

	void setIsVisible(bool isVisible);

	void setIsFramed(bool isFramed);

public:
	void Move(int x, int y);
	void Resize(int height, int width);
	void ChangeColor(string color);
	void ChangeVisibility();
	string ToString();

};


