// Copyright 2019 Weicheng Pei and Minghao Yang

#ifndef MINI_ELEMENT_TRIANGLE_HPP_
#define MINI_ELEMENT_TRIANGLE_HPP_

#include <cstddef>
#include <initializer_list>

#include "mini/element/point.hpp"
#include "mini/element/surface.hpp"
#include "mini/geometry/surface.hpp"
#include "mini/geometry/triangle.hpp"

namespace mini {
namespace element {

template <class Real, int kDim>
class Triangle :
    virtual public Surface<Real, kDim>,
    public geometry::Triangle<Real, kDim> {
 public:
  // Types:
  using Id = std::size_t;
  using Point = Point<Real, kDim>;
  // Constructors:
  Triangle(Id i, Point* a, Point* b, Point* c)
      : i_(i), geometry::Triangle<Real, kDim>(a, b, c) {}
  Triangle(Point* a, Point* b, Point* c)
      : Triangle(this->DefaultId(), a, b, c) {}
  // Accessors:
  Id I() const override { return i_; }
  Point* GetPoint(int i) const override {
    return static_cast<Point*>(geometry::Triangle<Real, kDim>::GetPoint(i));
  }
  // Mesh methods:
 private:
  Id i_;
};

}  // namespace element
}  // namespace mini

#endif  // MINI_ELEMENT_TRIANGLE_HPP_
