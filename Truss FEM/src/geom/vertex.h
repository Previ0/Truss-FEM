#ifndef VERTEX_H
#define VERTEX_H

struct Point
{
	float X;
	float Y;
protected:
	Point(float x, float y);
};

class Vertex : public Point{
private:
	bool x_blocked_; // can vertex be displaced in space
	bool y_blocked_; // can vertex be displaced in space
public:
	//Constructors
	Vertex();
	Vertex(float x, float y);

	bool operator== (const Vertex& other) const;
};

#endif // !VERTEX_H