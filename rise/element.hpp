#ifndef RISE_ELEMENT_HPP_INCLUDED
#define RISE_ELEMENT_HPP_INCLUDED

#include <libxml++/nodes/element.h>

namespace rise
{
    class document;
    class element : protected xmlpp::Element
    {
	public:
	    element(_xmlNode *_node);
	    virtual ~element() = default;

	public:
	    using xmlpp::Element::get_name;
	    using xmlpp::Element::get_namespace_prefix;
	    using xmlpp::Element::get_namespace_uri;
	    using xmlpp::Element::get_line;
	    using xmlpp::Element::get_path;
	    using xmlpp::Element::set_namespace_declaration;
	    using xmlpp::Element::get_attribute_value;
	    using xmlpp::Element::remove_attribute;
	    rise::element* add_child(Glib::ustring const &_name, Glib::ustring const &_prefix = Glib::ustring());
	    void set_attribute(Glib::ustring const &_name, Glib::ustring const &_value, Glib::ustring const &_prefix = Glib::ustring());

	private:
	    document const* get_document() const;

	friend class rise::document;
    };
}

#endif //RISE_ELEMENT_HPP_INCLUDED
