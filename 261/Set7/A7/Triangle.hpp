# include <SFML/Graphics.hpp>
# include <iostream>
# include <cmath>
using namespace sf;
using namespace std;

class Triangle {
    private:
        Color color;
    
    protected:
        int vertices;
        double array[3][2];

    public:
        Triangle();
        void setColor(const Color colorNew);
        void draw(RenderTarget &window);
        virtual bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) = 0;
};

Triangle::Triangle(){
    color = Color::White;
    vertices = 3;
}

void Triangle::setColor(const Color colorNew){
    color = colorNew;
}

void Triangle::draw(RenderTarget &window){
    // Set all the points to the appropriate coordinates
    ConvexShape shape;
    shape.setPointCount(3);
    shape.setPoint(0, Vector2f(array[0][0], array[0][1]));
    shape.setPoint(1, Vector2f(array[1][0], array[1][1]));
    shape.setPoint(2, Vector2f(array[2][0], array[2][1]));
    shape.setFillColor(color);
    window.draw(shape);
}

class ScaleneTriangle : public Triangle{
    public:
        bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3){

            // find the lengths of the triangle
            
            double ls1, ls2, ls3;
            ls1 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2),0.5);
            ls2 = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2),0.5);
            ls3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2),0.5);

            // vlaidate the Scalene Triangle

            if (ls1 > 0 && ls2 > 0 && ls3 > 0){
                if ((ls1 + ls2) > ls3 && (ls1 + ls3) > ls2 && (ls2 + ls3) > ls1){
                    array[0][0] = x1;
                    array[0][1] = y1;
                    array[1][0] = x2;
                    array[1][1] = y2;
                    array[2][0] = x3;
                    array[2][1] = y3;

                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
};

class EquilateralTriangle : public Triangle{
    public:
    // Same things just for an equilateral triangle
        bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3){
            
            double ls1, ls2, ls3;
            ls1 = pow(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)),0.5);
            ls2 = pow(((x3 - x1)*(x3 - x1)) + ((y3 - y1)*(y3 - y1)),0.5);
            ls3 = pow(((x3 - x2)*(x3 - x2)) + ((y3 - y2)*(y3 - y2)),0.5);

            if (ls1 > 0 && ls2 > 0 && ls3 > 0){
                if ((ls1 + ls2) > ls3 && (ls1 + ls3) > ls2 && (ls2 + ls3) > ls1){
                    if ((int)ls1 == (int)ls2 && (int)ls1 == (int)ls3 && (int)ls2 == (int)ls3){
                        array[0][0] = x1;
                        array[0][1] = y1;
                        array[1][0] = x2;
                        array[1][1] = y2;
                        array[2][0] = x3;
                        array[2][1] = y3;

                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
};

class IsoscelesTriangle : public Triangle{
    public:
    // Same thing but for and isosceles triangle
        bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3){
            
            double ls1, ls2, ls3;
            ls1 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2),0.5);
            ls2 = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2),0.5);
            ls3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2),0.5);

            if (ls1 > 0 && ls2 > 0 && ls3 > 0){
                if ((ls1 + ls2) > ls3 && (ls1 + ls3) > ls2 && (ls2 + ls3) > ls1){
                    if (ls1 == ls2 || ls1 == ls3 || ls2 == ls3){
                        array[0][0] = x1;
                        array[0][1] = y1;
                        array[1][0] = x2;
                        array[1][1] = y2;
                        array[2][0] = x3;
                        array[2][1] = y3;

                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
};