#ifndef RISE_PARSER_HPP_INCLUDED
#define RISE_PARSER_HPP_INCLUDED

#include <stack>
#include <libxml++/parsers/saxparser.h>
#include <rise/document.hpp>

namespace rise
{
    class parser : public xmlpp::SaxParser
    {
	public:
	    parser(document &_doc);
	    virtual ~parser() = default;

	protected:
	    virtual void on_start_element(const Glib::ustring &_name,
                    			  const AttributeList &_attributes) override;
	    virtual void on_end_element(const Glib::ustring& name) override;
	    virtual void on_comment(Glib::ustring const &_comment);

	private:
	    document &doc;
	    std::stack<rise::element*> context;
    };
}

#endif //RISE_PARSER_HPP_INCLUDED
