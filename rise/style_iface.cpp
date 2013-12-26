#include <rise/style_iface.hpp>

rise::style_iface::style_iface(rise::element &_element)
    : element(_element),
      attribute_style_(element, "style")
{

}

void rise::style_iface::draw(Cairo::RefPtr<Cairo::Context> const &_cr)
{

}
