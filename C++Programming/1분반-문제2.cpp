#include <iostream>
using namespace std;
class CBox {
private:
	int m_width, m_height;
	char m_in;
public:
	CBox() {

	}
	CBox(int w, int h) {
		m_width = w;
		m_height = h;
		m_in = '*';
	}
	void draw();
	void setSize(int w, int h);
	void setFill(char c);
};
int main() {
	CBox b(10,2);
	b.draw();
	b.setSize(7,4);
	b.setFill('^');
	b.draw();
	return 0;
}

void CBox::draw()
{
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			cout<<m_in;
		}
		cout<<endl;
	}
}

void CBox::setSize(int w, int h)
{
	m_width = w;
	m_height = h;
}

void CBox::setFill(char c)
{
	m_in = c;
}
