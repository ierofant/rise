#include <rise/svg.hpp>

rise::svg::svg(_xmlNode *_node)
    : rise::element(_node)
{
    set_namespace_declaration("http://www.w3.org/2000/svg");
}
