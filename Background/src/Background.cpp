//============================================================================
// Name        : Background.cpp
// Author      : VT
// Version     :
// Copyright   : Copyright 2014 Jimbo S. Harris. All rights reserved.
// Description : Lighting hub, spawns off shadow, reflection, and refraction tests for each successful intersection
//============================================================================

#include <iostream>
using namespace std;
#include "Background.hpp"
#include "Lighting.hpp"

void Background::local_setup()
{

}

// You will get here if a Shadow test registers a hit with an object between the intersection and a particular light
bool Background::local_work(msgpack::sbuffer *header, msgpack::sbuffer *payload)
{
	Pixel pixel;
	msgpack::object obj;
	unPackPart( header, &obj );
	obj.convert( pixel );

	// TODO: get this from the World configuration
	//pixel.color = Color(0.2,0,0.23);
	pixel.color = Color(0.8,0,0.73);
	//pixel.color = Color(0.25,0.25,0.25);
	//pixel.color = Color(0.0,0.8,0.0);

	float fade = glm::dot( (glm::vec4)Direction(0,0,-1), (glm::vec4)pixel.primaryRay.direction );
	// multiply pixel.color by this (you get full color at the horizon, fading to black at zenith)
	// TODO: only do this if "above" horizon (if ray.direction.y > 0?)
	pixel.color *= fade;

	pixel.gothit = false;

	header->clear();

	msgpack::pack( header, pixel );
	payload->clear();

	Pixel pix2;
	msgpack::object obj2;
	unPackPart( header, &obj2 );
	obj2.convert( pix2 );

#ifdef DEBUG
	std::cout << "(" << pix2.x << "," << pix2.y << ") ";
	printvec("c", pix2.color);
	std::cout << std::endl;
#endif /* DEBUG */

	return true; // send an outbound message as a result of local_work()
}

void Background::local_shutdown()
{
	std::cout << "shutting down... ";
}

int main(int argc, char* argv[])
{
	cout << "starting up" << endl;

	// This will have several publisher outputs:
	// - Shadow intersection tests for each light
	// - Reflection test
	// - Refraction test
	// Finally, send off Ambient and Emissive color value.
	Background bak("Black", "BKG", "ipc:///tmp/feeds/broadcast", "COLOR", "ipc:///tmp/feeds/control");

	if( argc > 1 )
	{
		int foo = 1;
		//sh.world_object = argv[1];
	}
	cout << "running" << endl;
	bak.run();

	cout << "shutting down" << endl;
	return 0;
}
