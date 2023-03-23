#ifndef __MYCIRCLE_H__
#define __MYCIRCLE_H__

extern int g_numCircle = 0;

class MyCircle {
private:
	int m_idx;
	float m_r;
	float m_area;
	string m_name;

public:
	MyCircle() {		//생성자 오버로딩(OverLoading)
		/*m_idx = g_numCircle;
		setRadius(1.0f);
		m_name = "unnamed";
		cout << "[Circle:" << m_name << "] constructed" << endl;
		g_numCircle++;*/
	}
	MyCircle(float r, string name);
	~MyCircle();

	void print();
	//setter(mutator)
	void setRadius(float r) { m_r = r; }
	//getter(accessor)
	float getRadius() { return m_r; }



};

#endif