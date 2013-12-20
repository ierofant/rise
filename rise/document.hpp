#ifndef RISE_DOCUMENT_HPP_INCLUDED
#define RISE_DOCUMENT_HPP_INCLUDED

#include <functional>
#include <map>
#include <libxml++/document.h>
#include <rise/element.hpp>

namespace rise
{
    class document : protected xmlpp::Document
    {
	public:
	    typedef std::function<element*(_xmlNode*)> factory;

	public:
	    virtual ~document() = default;

	public:
	    element* create_root_node();
	    void reg_factory(Glib::ustring const &_name, factory const &_factory);
	    void unreg_factory(Glib::ustring const &_name);

	private:
	    typedef std::map<Glib::ustring, factory> factory_map;

	private:
	    element* create_element(Glib::ustring const &_name, _xmlNode *_node);

	private:
	    factory_map f_map;
    };
}

#endif //RISE_DOCUMENT_HPP_INCLUDED
