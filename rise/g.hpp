#ifndef RISE_G_HPP_INCLUDED
#define RISE_G_HPP_INCLUDED

#include <rise/element.hpp>

namespace rise
{
    class g : public element
    {
	public:
	    g(_xmlNode *_node);
	    virtual ~g() = default;
    };
}

#endif //RISE_G_HPP_INCLUDED
