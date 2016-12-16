#pragma once

#include <BasicEngine\Rendering\Models\Model.h>
#include<time.h>
#include<stdarg.h>
#include "RubiksCube\Cube.h"


using namespace BasicEngine::Rendering;
using namespace Models;
using namespace RubiksCube;

class BrickModel : public Model
{
public:
	BrickModel();
	~BrickModel();

	void Create(glm::vec3 wspolzedne, Brick *brick);
	virtual void Draw(const glm::mat4& projection_matrix,
		const glm::mat4& view_matrix)
		override final;
	virtual void Update() override final;
	void updateBrick(Brick *brick);
	void updateVertices();
	void setRotation(glm::vec3 rotation);
	glm::vec4 przypisz_kolor(Color_t kolor);

private:
	glm::vec3 rotation, rotation_speed;
	glm::vec3 summaryRotation;
	glm::vec3 rotation_sin;
	glm::vec3 arotation_sin;
	time_t timer;
	std::vector<VertexFormat> vertices;
	Brick *brick;
	glm::vec3 wspolzedne;
};