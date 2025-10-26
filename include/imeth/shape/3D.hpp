#pragma once

namespace shape_3d {

class Shape3D {
public:
    Shape3D() = default;
    virtual ~Shape3D() = default;

    virtual double area() const = 0;
    virtual double volume() const = 0;
};

class Sphere : public Shape3D {
public:
    explicit Sphere(double radius);
    ~Sphere() override = default;

    double area() const override;
    double volume() const override;

private:
    double radius_;
};

class Cube : public Shape3D {
public:
    explicit Cube(double side);
    ~Cube() override = default;

    double area() const override;
    double volume() const override;

private:
    double side_;
};

class Cylinder : public Shape3D {
public:
    Cylinder(double radius, double height);
    ~Cylinder() override = default;

    double area() const override;
    double volume() const override;

private:
    double radius_;
    double height_;
};

class Cone : public Shape3D {
public:
    Cone(double radius, double height);
    ~Cone() override = default;

    double area() const override;
    double volume() const override;

private:
    double radius_;
    double height_;
};

class Torus : public Shape3D {
public:
    Torus(double major_radius, double minor_radius);
    ~Torus() override = default;

    double area() const override;
    double volume() const override;

private:
    double major_radius_;
    double minor_radius_;
};

} // namespace shape_3d
