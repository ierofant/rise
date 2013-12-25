#include <rise/svg.hpp>

rise::svg::svg(_xmlNode *_node)
    : rise::element(_node),
      attribute_version(*this, "version"),
      attribute_width(*this, "width"),
      attribute_height(*this, "height")
{
    set_namespace_declaration("http://www.w3.org/2000/svg");
}
