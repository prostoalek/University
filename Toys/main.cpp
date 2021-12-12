#include<iostream>
#include<string>

using namespace std;

enum Color {
	red,
	green,
	blue,
	yellow,
	unknown
};


class Toy {
protected:
	string title;
	double cost;
	bool isPackaged;
	Color color;
public:
	Toy() : title("air"), cost(99.99), isPackaged(false), color(unknown) {}
	Toy(string _title, double _cost, bool _isPackaged, Color _color) : title(_title), cost(_cost), isPackaged(_isPackaged), color(_color) {}
	
	string enumToString(Color color) {
		switch (color) {
		case red:
			return
				"red";
		case green:
			return "green";
		case blue:
			return "blue";
		case yellow:
			return "yellow";
		case unknown:
			return "unknown";
		default:
			return "default";
			break;
		}
	}

	virtual string toString() {
		return title + "\n" + to_string(cost) + "\n" + (isPackaged ? "packaged" : "not packaged") + "\n" + enumToString(color) + "\n\n";
	}
};


class Car : public Toy {
public:
	Car() : Toy() {}
	Car(string _title, double _cost, bool _isPackaged, Color _color) : Toy(_title, _cost, _isPackaged, _color) {}
};


class Tractor : public Toy {
public:
	Tractor() : Toy() {}
	Tractor(string _title, double _cost, bool _isPackaged, Color _color) : Toy(_title, _cost, _isPackaged, _color) 
	{
		color = green;
	}
};


class Trailer : public Toy {
public:
	Trailer() : Toy() {}
	Trailer(string _title, double _cost, bool _isPackaged, Color _color) : Toy(_title, _cost, _isPackaged, _color)
	{
		switch (_color) {
		case red:
			break;
		case blue:
			break;
		case green:
			color = red;
			break;
		case yellow:
			color = blue;
			break;
		case unknown:
			color = red;
			break;
		default:
			color = red;
			break;
		}
	}
};

class TractorWithTrailer : public Tractor, public Trailer {
protected:
	Tractor tractor;
	Trailer trailer;
public:
	TractorWithTrailer() : tractor(), trailer() {}
	TractorWithTrailer(string tractorTitle, double tractorCost, bool tractorIsPackaged, Color tractorColor,
		string trailertitle, double trailerCost, bool trailerIsPackaged, Color trailerColor) :
		tractor(tractorTitle, tractorCost, tractorIsPackaged, tractorColor),
		trailer(trailertitle, trailerCost * 0.8, trailerIsPackaged, trailerColor) {}

	string toString() {
		return tractor.toString() + trailer.toString() + "\n\n";
	}
};



int main() {
	setlocale(0, "");

	Toy toy("Обычная игрушка", 49.90, true, green);
	Car car("Ferrari", 149.90, true, red);
	Tractor tractor("Трактор", 69.90, false, blue);
	Trailer trailer("Дом для одинокого волка", 99.90, false, yellow);
	TractorWithTrailer tractorWithTrailer("Юный тракторист", 299.90, true, red, "Прицеп для больших дядей", 39.90, true, green);

	cout << toy.toString() << car.toString() << tractor.toString() << trailer.toString() << tractorWithTrailer.toString();
}