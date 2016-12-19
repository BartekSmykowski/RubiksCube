#version 430 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 animationRotation;
uniform vec3 rotation;
uniform vec3 translation;

out vec4 color;

void main()
{

	color = in_color;

	
	mat4 arotate_x, arotate_y, arotate_z;

	arotate_x = mat4(1.0, 0.0, 0.0, 0.0,
					0.0, cos(animationRotation.x), sin(animationRotation.x), 0.0,
					0.0, -sin(animationRotation.x), cos(animationRotation.x), 0.0,
					0.0, 0.0, 0.0, 1.0);

	arotate_y = mat4(cos(animationRotation.y), 0.0, -sin(animationRotation.y), 0.0,
					0.0, 1.0, 0.0, 0.0,
					sin(animationRotation.y), 0.0, cos(animationRotation.y), 0.0,
					0.0, 0.0, 0.0, 1.0);

	arotate_z = mat4(cos(animationRotation.z), -sin(animationRotation.z), 0.0, 0.0,
					sin(animationRotation.z), cos(animationRotation.z), 0.0, 0.0,
					0.0, 0.0, 1.0, 0.0,
					0.0, 0.0, 0.0, 1.0);

	mat4 rotate_x, rotate_y, rotate_z;

	rotate_x = mat4(1.0, 0.0, 0.0, 0.0,
					0.0, cos(rotation.x), sin(rotation.x), 0.0,
					0.0, -sin(rotation.x), cos(rotation.x), 0.0,
					0.0, 0.0, 0.0, 1.0);

	rotate_y = mat4(cos(rotation.y), 0.0, -sin(rotation.y), 0.0,
					0.0, 1.0, 0.0, 0.0,
					sin(rotation.y), 0.0, cos(rotation.y), 0.0,
					0.0, 0.0, 0.0, 1.0);

	rotate_z = mat4(cos(rotation.z), -sin(rotation.z), 0.0, 0.0,
					sin(rotation.z), cos(rotation.z), 0.0, 0.0,
					0.0, 0.0, 1.0, 0.0,
					0.0, 0.0, 0.0, 1.0);

	mat4 translate;

	translate = mat4(1.0, 0.0, 0.0, 0.0,
					0.0, 1.0, 0.0, 0.0,
					0.0, 0.0, 1.0, 0.0,
					translation.x, translation.y, translation.z, 1.0);

	gl_Position = projection_matrix * view_matrix * translate * 
					rotate_y * rotate_x *rotate_z *
					arotate_y * arotate_x *arotate_z *
					vec4(in_position, 1);

}