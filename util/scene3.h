#ifndef SCENE3_H
#define SCENE3_H

#include <vector>
#include <objects/line3.h>
#include <objects/line2.h>
#include <objects/square3.h>
#include <objects/cube.h>
#include <QImage>

class Scene3 {
public:
    Scene3(const int &width, const int &height);
    QImage render(const Vector3 &position = Vector3(0,0,0),  Vector3 rotation = Vector3(0,0,0));
    void add(const Vector3 &point);
    void add(const Line3 &line);
    void add(const Square3 &square);
    void add(const Cube &cube);
private:
    int width;
    int height;
    constexpr static const double d = 1000;
QImage text = QImage(":/orig.jpg").scaledToWidth(500);
    Vector2 screenCenter;
    std::vector<Vector3> points;
    std::vector<Line3> lines;
    std::vector<Square3> squares;
    std::vector<Cube> cubes;

    static const int pointSize = 5;
bool inArea(Vector2);
    void drawLine(Line2 line, unsigned char *ptr, QColor color);
    void drawLine(Line3 line, unsigned char *ptr, QColor color, Vector3 center);

    void drawSquare(Square3 square,unsigned char *ptr, QColor color, Vector3 center);

    Vector2 convert(Vector3 vector, Vector3 center);

    void drawTriangle(Vector3 a, Vector3 b, Vector3 c, unsigned char *ptr,Vector3 center,bool t);
    void drawTriangle(Vector2 a, Vector2 b, Vector2 c, unsigned char *ptr, bool t);
    std::pair<double, double> bar(Vector2 p,Vector2 a,Vector2 b, Vector2 c);

    inline void draw(unsigned char *ptr, QColor color, const int &x, const int &y);
};

#endif // SCENE3_H
