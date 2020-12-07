// Isaiah Guardado
// CECS 282-05
// Prog 6 - Inheritance

#include <string>
#include <iostream>
#include <vector>


using namespace std;

class luggage {
protected:
	string type;
	static int count;

public:
	luggage(){
		cout << "creating luggage";
		type = "luggage";
		count++;
	}

	
	static int getCount() {
		return count;
	}

	~luggage() {
		count--;
	}
	
	
	
	string getType() {
		return type;
	}

	virtual double volume() = 0;
};

int luggage::count = 0;

class box :public luggage {
private:
	double width, height, length;
public:
	box(double w, double h, double l) {
		width = w;
		height = h;
		length = l;
		type = "Box";
	}
	
	double volume() {
		return length * width * height;
	}
};

class sphere : public luggage {
private:
	double radius;

public:
	sphere(double r) {
		radius = r;
		type = "Sphere";
	}

	double volume(){
		return ((4.0/3.0) * 3.14 * pow(radius, 3));
	}
};

class cube : public luggage {

private:
	double width;

public:
	cube(double w) {
		width = w;
		type = "Cube";
	}

	double volume(){
		return (pow(width, 3));
	}
};

class pyramid : public luggage {
private:
	double base, height;

public:
	pyramid(double b, double h) {
		base = b;
		height = h;
		type = "Pyramid";
	}

	double volume() {
		return ((1.0 / 3.0) * (base * height));
	
	}

};

class cylinder : public luggage {

private:
	double radius, length;

public:
	cylinder(double r, double l) {
		radius = r;
		length = l;
		type = "Cylinder";
	}

	double volume() {
		return (3.14 * pow(radius, 2) * length);
	}
};

class triprism : public luggage {

private:
	double base, height, length;

public:
	triprism(double b, double h, double l) {
		base = b;
		height = h;
		length = l;
		type = "Triangular Prism";
	}

	double volume() {
		return ((base * height * length) / 2);
	}
};

class traprism : public luggage {
private:
	double pointA, pointB, height, length;

public:
	traprism(double a, double b, double h, double l) {
		pointA = a;
		pointB = b;
		height = h;
		length = l;
		type = "Trapezoidal Prism";
	}

	double volume() {
		return (((pointA + pointB) / 2) * (height * length));
	}
};

class parabloid : public luggage {

private:
	double length, radius;

public:
	parabloid(double l, double r) {
		length = l;
		radius = r;
		type = "Parabloid";
	}

	double volume() {
		return ((1 / 2.0) * 3.14 * pow(radius, 2) * length);
	}
};

int main() {

	vector<luggage*> cargo;
	luggage* part;
	vector<luggage*>::iterator it;

	int mainChoice;
	int fd, take;
	int width, height, length, radius, base, a, b;

	cout << "1.)Add Luggage\n2.)Remove luggages from storage container\n3.)Show all luggage\n4.)Quit\n";
	cin >> mainChoice;
	while(mainChoice != 4){
		if (mainChoice == 1) {
			cout << "Luggage Availability:\n";
			cout << "1.Box\n2.Sphere\n3.Cube\n4.Pyramid\n5.Cylinder\n6.Triangular Prism\n7.Trapezoidal Prism\n8.Parabloid\n";
			cin >> fd;
			if (fd == 1) {
				cout << "Please input the width, height and length\n";
				cin >> width;
				cin >> height;
				cin >> length;
				luggage* b = new box(width, height, length);
				part = b;
				cargo.push_back(part);
			}
			else if (fd == 2) {
				cout << "Please input the radius\n";
				cin >> radius;
				luggage* r = new sphere(radius);
				part = r;
				cargo.push_back(r);
			}
			else if (fd == 3) {
				cout << "Please input the width\n";
				cin >> width;
				luggage* w = new cube(width);
				part = w;
				cargo.push_back(part);
			}
			else if (fd == 4) {
				cout << "Please input the base and height\n";
				cin >> base;
				cin >> height;
				luggage* p = new pyramid(base, height);
				part = p;
				cargo.push_back(part);
			}
			else if (fd == 5) {
				cout << "Please input the radius and length\n";
				cin >> radius;
				cin >> length;
				luggage* c = new cylinder(radius, length);
				part = c;
				cargo.push_back(part);
			}

			else if (fd == 6) {
				cout << "Please input base, height and length\n";
				cin >> base;
				cin >> height;
				cin >> length;
				luggage* ti = new triprism(base, height, length);
				part = ti;
				cargo.push_back(part);
			}

			else if (fd == 7) {
				cout << "Please input a, b, height and length\n";
				cin >> a;
				cin >> b;
				cin >> height;
				cin >> length;
				luggage* ta = new traprism(a, b, height, length);
				part = ta;
				cargo.push_back(part);
			}

			else if (fd == 8) {
				cout << "Please input length and radius\n";
				cin >> length;
				cin >> radius;
				luggage* c = new cylinder(length, radius);
				part = c;
				cargo.push_back(part);
			}
			cout << "\n1.) Add Luggage\n2.)Remove luggages from storage container\n3.)Show all luggage\n4.)Quit\n";
			cin >> mainChoice;
		}
		else if (mainChoice == 2) {
			if (cargo.size() == 0) {
				cout << "Cargo is null" << endl;
			}
			else {
				cout << "Select what do you want to take out\n";
				cin >> take;
				while (take < 1 || take > cargo.size()) {
					cout << "Please try again" << endl;
					cin >> take;
				}

				delete *(cargo.begin() + (take - 1));
				cargo.erase(cargo.begin() + (take - 1));

			}

			cout << "1.) Add Luggage\n2.)Remove luggages from storage container\n3.)Show all luggage\n4.)Quit\n";
			cin >> mainChoice;
		}
		else if (mainChoice == 3) {
			if (cargo.size() == 0) {
				cout << "Cargo is empty" << endl;
			}
			else {
				double totalVolume = 0;
				for (it = cargo.begin(); it != cargo.end(); it++) {
					cout << "Luggage:" << (*it)->getType() << " " << "Volume:" << (*it)->volume();
					totalVolume += (*it)->volume();
					cout << endl;
				}
				cout << "Total Volume:" << totalVolume << endl;
				cout << "getCount:" << luggage::getCount() << endl;
			}
			
			cout << "1.) Add Luggage\n2.)Remove luggages from storage container\n3.)Show all luggage\n4.)Quit\n";
			cin >> mainChoice;
		}
	}
}
