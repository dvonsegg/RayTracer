#!/bin/sh -x
gcc -o bin/AllSteps features/step_definitions/AllSteps.cpp -L/usr/local/lib -lcucumber-cpp -lc++ -lboost_program_options -lboost_regex -lboost_filesystem -lboost_system -lgtest -I../libRaytracer2014/src -std=c++11 -Wno-comment
#gcc -o bin/MatrixSteps features/step_definitions/MatrixSteps.cpp -L/usr/local/lib -lcucumber-cpp -lc++ -lboost_program_options -lboost_regex -lboost_filesystem -lboost_system -lgtest -I../libRaytracer2014/src -std=c++11 -Wno-comment
#gcc -o bin/TupleSteps features/step_definitions/TupleSteps.cpp -L/usr/local/lib -lcucumber-cpp -lc++ -lboost_program_options -lboost_regex -lboost_filesystem -lboost_system -lgtest -I../libRaytracer2014/src -std=c++11 -Wno-comment
#gcc -o bin/RaySteps features/step_definitions/RaySteps.cpp -L/usr/local/lib -lcucumber-cpp -lc++ -lboost_program_options -lboost_regex -lboost_filesystem -lboost_system -lgtest -I../libRaytracer2014/src -std=c++11 -Wno-comment
