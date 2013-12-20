#include <rise/document.hpp>
#include <rise/svg.hpp>

rise::document::document(Glib::ustring const &_version)
{
    set_internal_subset("svg", "-//W3C//DTD SVG 1.1//EN", "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd");
    reg_factory("svg", [](_xmlNode *_node){return new svg(_node);});
}

rise::element* rise::document::create_root_node()
{
    auto *el = xmlpp::Document::create_root_node("svg");
    auto *node = el->cobj();
    delete el;
    return create_element("svg", node); 
}

rise::element* rise::document::get_root_node()
{
    return static_cast<rise::element*>(xmlpp::Document::get_root_node());
}

void rise::document::reg_factory(Glib::ustring const &_name, factory const &_factory, Glib::ustring const &_prefix)
{
    f_map[std::make_pair(_name, _prefix)] = _factory;
}

void rise::document::unreg_factory(Glib::ustring const &_name, Glib::ustring const &_prefix)
{
    auto itr = f_map.find(std::make_pair(_name, _prefix));
    if(itr != f_map.end()) f_map.erase(itr);
}

rise::element* rise::document::create_element(Glib::ustring const &_name, _xmlNode *_node, Glib::ustring const &_prefix) const
{
    element *el = nullptr;
    auto itr = f_map.find(std::make_pair(_name, _prefix));
    if(itr != f_map.end()) el = (itr->second)(_node);
    else el = new element(_node);
    return el;
}
