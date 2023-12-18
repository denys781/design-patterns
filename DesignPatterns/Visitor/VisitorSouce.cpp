#include <memory>

namespace
{
    const double PI = 3.14;
}

namespace Visitor
{
    class IShape
    {
    public:
        virtual ~IShape() = default;

        // public shape interface
    };

    class Square;
    class Circle;

    class IShapeVisitor
    {
    public:
        virtual ~IShapeVisitor() = default;

        virtual double VisitSquare(const Square& square) = 0;
        virtual double VisitCircle(const Circle& circle) = 0;
    };

    class IVisitableShape
    {
    public:
        virtual ~IVisitableShape() = default;

        virtual double Accept(std::shared_ptr<IShapeVisitor> visitor) const = 0;
    };

    class Square : public IShape, public IVisitableShape
    {
    public:
        Square(double side)
            : side_(side)
        {
        }

        double GetSide() const
        {
            return side_;
        }

        double Accept(std::shared_ptr<IShapeVisitor> visitor) const override
        {
            return visitor->VisitSquare(*this);
        }

    private:
        double side_;
    };

    class Circle : public IShape, public IVisitableShape
    {
    public:
        Circle(double radius)
            : radius_(radius)
        {
        }

        double GetRadius() const
        {
            return radius_;
        }

        double Accept(std::shared_ptr<IShapeVisitor> visitor) const override
        {
            return visitor->VisitCircle(*this);
        }

    private:
        double radius_;
    };

    class SquareShapeVisitor : public IShapeVisitor
    {
    public:
        double VisitSquare(const Square& square)
        {
            return square.GetSide() * 2;
        }

        double VisitCircle(const Circle& circle)
        {
            return PI * (circle.GetRadius() * 2);
        }
    };

    // TODO: class PerimeterShapeVisitor and so on
}