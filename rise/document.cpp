#include <rise/document.hpp>

rise::element* rise::document::create_root_node()
{
    auto *el = xmlpp::Document::create_root_node("svg");
    auto *node = el->cobj();
    delete el;
    return create_element("svg", node); 
}

void rise::document::reg_factory(Glib::ustring const &_name, factory const &_factory)
{
    f_map[_name] = _factory;
}

void rise::document::unreg_factory(Glib::ustring const &_name)
{
    auto itr = f_map.find(_name);
    if(itr != f_map.end()) f_map.erase(itr);
}

rise::element* rise::document::create_element(Glib::ustring const &_name, _xmlNode *_node)
{
    element *el = nullptr;
    auto itr = f_map.find(_name);
    if(itr != f_map.end()) el = (itr->second)(_node);
    else el = new element(_node);
    return el;
}
