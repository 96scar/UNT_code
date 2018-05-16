//example code

#include <iostream>

using namespace std;

//Base class
class shape
{
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
protected:
	int width;
	int height;
};

class rectangle: public shape
{
public:
	int getArea()
	{
		return(width*height);
	}
};

int main()
{
	int w, h;

	rectangle rect;
	

	cout << "Width: ";
	cin >> w;
	cout << endl << "Height: ";
	cin >> h;

	rect.setWidth(w);
	rect.setHeight(h);

	//print the area of the object
	cout << endl << "Total area: " << rect.getArea() << endl;

	return 0;
}
