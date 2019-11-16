#ifndef __TEST_CONTEXT__
#define __TEST_CONTEXT__

#include <Object.hpp>
#include <Intersection.hpp>

class Shape : public Object
{
public:
  Shape() {};

	bool local_intersect( const Ray &object, Intersection &i ) const {return false;};
	Direction local_normal_at( const Position object_pos ) const {return Direction(0);};
};

/*#######
##
## CONTEXT
##
#######*/
struct TestCtx
{
  glm::mat4 mat;
  glm::mat4 mat_b;
  glm::mat4 mat_c;
  glm::mat4 id = glm::mat4(1);

  glm::mat3 mat3;
  glm::mat2 mat2;

  Position pos;
  Position pos_b;

  Direction vec;
  Direction vec_b;

  Color col;
  Color col_b;

  Material mtl;
  Material mtl_b;

  Position origin;
  Direction direction;
  Ray ray;

  Shape shape;
  Sphere sphere;
  Intersection intersection;

  glm::mat4 result_mat;
  Position result_pos;
  Direction result_vec;
  Color result_col;
  Material result_mtl;
  float result_float;
  Ray result_ray;
};

#endif // __TEST_CONTEXT__
