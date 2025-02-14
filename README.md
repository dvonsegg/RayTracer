## HOW TO RUN THE RAYTRACER
* Zeroth) ZeroMQ, libpng, GLM, msgpack, and libPNGWriter are required (use brew except for pngwriter which needs to be git clone / cmake'd)
* First) Widget.o is required to link (this is my implementation of ZeroMQ over IPC, using a "setup/loop" methodology)
* Second) ControlChannel (found in zmq_widgets/bin) is required and must be started first! (this links the "broadcast" and "control" channels together -- note, this is by far the biggest performance bottleneck of the build -- should probably use separate channels for each function)
* Third) start Black, Background, ColorResults, DepthChart, IntersectResults, Lit, Reflection, Shader, and Writer (these are all services, so start them in separate windows / processes)
* Fourth) start IntersectWith sphere1 and IntersectWith sphere2 and ... (one instance per World object in libRayTracer2014/src/World.hpp)
* Finally) start PixelFactory (which creates the rays and starts running them through the channels)

PixelFactory will log lots of output
So will Writer and DepthChart
ColorResults will output lots when the objects get hit

once all the pixels have run through, a file called test.png will appear in the main folder. That's your traced file.

Change world objects by changing World.hpp (requires rebuild of most of the code)

Use build.sh to build all objects and put the executables in bin/ (you will have to create this folder the first time)
