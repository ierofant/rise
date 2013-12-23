#include <rise/svg.hpp>

rise::svg::svg(_xmlNode *_node)
    : rise::element(_node),
      property_version(*this, "version"),
      property_width(*this, "width"),
      property_height(*this, "height")
{
    set_namespace_declaration("http://www.w3.org/2000/svg");
}
