#include <iostream>
#include <string>
using namespace std;
class MyColor {
private:
	string name;
	int R,G,B;
public:
	MyColor(string name, int r, int g, int b);
	void printColor();
	MyColor operator+(int n);
	MyColor operator+(MyColor in);
	MyColor operator+=(int n);
	MyColor operator++();

	friend MyColor operator+(int n, MyColor in);
	MyColor operator++(int x);

	friend ostream& operator<<(ostream& o, MyColor in);
};
MyColor::MyColor(string name, int r, int g, int b) {
	this->name = name;
	R = r;
	G = g;
	B = b;
}
void MyColor::printColor() {
	cout<<name<<"儀 : "<<R<<"/" << G <<"/" << B << endl;
}
MyColor MyColor::operator++() {
	MyColor out(name,R,G,B);
	R++;
	G++;
	B++;
	return out;
}
MyColor MyColor::operator+(int n) {
	MyColor out(name,R,G,B);
	out.R += n;
	out.G += n;
	out.B += n;
	return out;
}
MyColor MyColor::operator+(MyColor in) {
	MyColor out(name+in.name,R,G,B);
	out.R += in.R;
	out.G += in.G;
	out.B += in.B;
	return out;
}
MyColor MyColor::operator+=(int n) {
	this->R += n;
	this->G += n;
	this->B += n;
	return (*this);
}

MyColor operator+(int n, MyColor in) {
	MyColor out(in.name, in.R, in.G, in.B);
	out.R += n;
	out.G += n;
	out.B += n;
	return out;
}
MyColor MyColor::operator++(int x) {
	R++;
	G++;
	B++;
	return (*this);
}
ostream& operator<<(ostream& o, MyColor in) {
	o << in.name << "儀 : " << in.R << "/" << in.G << "/" << in.B << endl;
	return o;
}

int main() {
	MyColor palette[3] = {MyColor("Red", 255,0,0), MyColor("Blue",0,0,255), MyColor("Green",0,255,0)};

	MyColor redPlus3 = palette[0]+3;
	redPlus3.printColor();

	MyColor rb = palette[0]+palette[1];
	rb.printColor();

	MyColor bluePlus2 = 2+palette[1];
	bluePlus2.printColor();

	MyColor c("c",10,10,10);
	c.printColor();
	c += 4;
	c.printColor();

	cout<<"天天天天天天天天天天天天天"<<endl;

	MyColor d = c++;
	MyColor e = ++c;
	MyColor tmp = ++c;

	cout<<d<<e<<c<<endl;
	//for (int i = 0; i < 3; i++) {
	//	cout<<palatte[i]<<endl;
	//}

}