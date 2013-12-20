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
	    document(Glib::ustring const &_version = "1.0");
	    virtual ~document() = default;

	public:
	    using xmlpp::Document::set_internal_subset;
	    using xmlpp::Document::get_encoding;
	    using xmlpp::Document::write_to_file;
	    using xmlpp::Document::write_to_file_formatted;
	    using xmlpp::Document::write_to_string;
	    using xmlpp::Document::write_to_string_formatted;
	    using xmlpp::Document::write_to_stream;
	    using xmlpp::Document::write_to_stream_formatted;
	    element* create_root_node();
	    element* get_root_node();
	    void reg_factory(Glib::ustring const &_name, factory const &_factory, Glib::ustring const &_prefix = Glib::ustring());
	    void unreg_factory(Glib::ustring const &_name, Glib::ustring const &_prefix = Glib::ustring());

	private:
	    typedef std::map<std::pair<Glib::ustring, Glib::ustring>, factory> factory_map;

	private:
	    element* create_element(Glib::ustring const &_name, _xmlNode *_node, Glib::ustring const &_prefix = Glib::ustring()) const;

	private:
	    factory_map f_map;

	friend class rise::element;
    };
}

#endif //RISE_DOCUMENT_HPP_INCLUDED
