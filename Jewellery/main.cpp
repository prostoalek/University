#include<iostream>

using namespace std;

enum Metal {
	Gold,
	Silver,
	None,
};

enum Stone {
	Diamond,
	Ruby,
};

class Ring {
protected:
	double price, weight;

public:
	Ring() : price(0), weight(0) {}

	Ring(double _price, double _weight) : price(_price), weight(_weight) {}

	double cost() {
		return this->price * this->weight;
	}

	virtual void print() {
		cout << "Cost per gramme : " << this->price
			 << "\nWeight: " << this->weight 
			 << "\nCost: " << cost() << "\n\n";
	}
};

class MetalRing : public Ring {
protected:
	Metal metal;
	string enumToString(Metal _metal) {
		switch (_metal) {
		case Gold:
			return "Gold";
			break;
		case Silver:
			return "Silver";
			break;
		case None:
			return "unknown";
			break;
		defauil:
			return "";
			break;
		}
	}

public:
	MetalRing() : Ring() {
		this->metal = None;
	}

	MetalRing(Metal _metal, double _price, double _weight) : Ring(_price, _weight) {
		metal = _metal;
	}

	void print() {
		cout << "\nMetal: " << enumToString(this->metal) << "\n";
		Ring::print();
	}

};

class StoneRing : public MetalRing {
protected:
	Stone stone;
	string enumToString(Stone _stone) {
		switch (_stone) {
		case Diamond:
			return "Diamond";
			break;
		case Ruby:
			return "ruby";
			break;
		case None:
			return "unknown";
			break;
		defauil:
			return "";
			break;
		}
	}
public:
	StoneRing() : MetalRing() {}

	StoneRing(Metal _metal, Stone _stone, double _price, double _weight) : MetalRing(_metal, _price, _weight) {
		stone = _stone;
	}

	void print() {
		cout << "Stone: " << enumToString(stone);
		MetalRing::print();
	}

};


int main() {

	const int n = 10;

	Ring* rings[n];
	
	rings[0] = new MetalRing(Gold, 10, 25);
	rings[1] = new MetalRing(Gold, 15, 16);
	rings[2] = new MetalRing(Gold, 44, 10);
	rings[3] = new MetalRing(Gold, 11, 50);
	rings[4] = new MetalRing(Gold, 75, 13);
	rings[5] = new StoneRing(Silver, Ruby, 5, 30);
	rings[6] = new StoneRing(Silver, Ruby, 7, 11);
	rings[7] = new StoneRing(Silver, Diamond, 17, 3);
	rings[8] = new StoneRing(Silver, Diamond, 14, 11);
	rings[9] = new StoneRing(Silver, Ruby, 6, 19);


	for (Ring* ring : rings) {
		ring->print();
	}

}