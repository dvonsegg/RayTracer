/*
 * Shader.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: jiharris
 */

#ifndef INTERSECTWITH_HPP_
#define INTERSECTWITH_HPP_
#include "Widget.hpp"
#include "World.hpp"

class Shader : public Widget
{
public:
	Shader( char *_name, char *_subscription, char *_sub_endpoint, char *_publication, char *_pub_endpoint ) :
		Widget( _name, _subscription, _sub_endpoint, _publication, _pub_endpoint )
	{
	};
	~Shader(){};

protected:
	virtual void local_setup();
	virtual bool local_work( byte_vector *header, byte_vector *payload );
	virtual void local_shutdown();

private:
	World world;
};


#endif /* INTERSECTWITH_HPP_ */
