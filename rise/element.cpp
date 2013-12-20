#include <libxml/tree.h>
#include <rise/element.hpp>
#include <rise/document.hpp>

rise::element::element(_xmlNode *_node)
    : xmlpp::Element(_node)
{

}

rise::element* rise::element::add_child(Glib::ustring const &_name, Glib::ustring const &_prefix)
{
    auto *el = xmlpp::Element::add_child(_name, _prefix);
    auto *node = el->cobj();
    delete el;

    return get_document()->create_element(_name, node, _prefix);
}

void rise::element::set_attribute(Glib::ustring const &_name, Glib::ustring const &_value, Glib::ustring const &_prefix)
{
    xmlpp::Element::set_attribute(_name, _value, _prefix);
}

rise::document const* rise::element::get_document() const
{
    auto *node = cobj();
    auto *cdoc = node->doc;
    return static_cast<document*>(cdoc->_private);
}
