#include <libxml/tree.h>
#include <rise/element.hpp>
#include <rise/document.hpp>


rise::element::element(_xmlNode *_node)
    : xmlpp::Element(_node)
{

}

rise::element_list rise::element::get_children()
{
    auto nodes = xmlpp::Element::get_children();
    element_list list;
    for(auto *node:nodes) list.push_back(static_cast<rise::element*>(node));
    return list;
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

void rise::element::draw(Cairo::RefPtr<Cairo::Context> const &_cr)
{
    if(_cr)
    {
	_cr->save();
	draw_vfunc(_cr);
	auto children = get_children();
	for(auto *child:children) child->draw(_cr);
	_cr->restore();
    }
}

void rise::element::draw_vfunc(Cairo::RefPtr<Cairo::Context> const &_cr)
{

}

rise::document const* rise::element::get_document() const
{
    auto *node = cobj();
    auto *cdoc = node->doc;
    return static_cast<document*>(cdoc->_private);
}
