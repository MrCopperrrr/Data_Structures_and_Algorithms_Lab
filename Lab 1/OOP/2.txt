class Point
{
private:
    double x, y;

public:
    Point()
    {
        x=0;
        y=0;

    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y=y;

    }

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        return sqrt(pow(pointA.x - x, 2) + pow(pointA.y - y, 2));
    }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        center = Point(0, 0);
        radius = 0;
    }

    Circle(Point center, double radius)
    {
        this->center = center;
        this->radius =radius;
    }

    Circle(const Circle &circle)
    {
        this->center = circle.center;
        this->radius = circle.radius;
    }
    
    void setCenter(Point point)
    {
        this->center = point;
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    Point getCenter() const
    {
        return center;
    }

    double getRadius() const
    {
        return radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};