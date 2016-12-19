#pragma once

#include <BasicEngine\Rendering\Models\Model.h>
#include<time.h>
#include<stdarg.h>


using namespace BasicEngine::Rendering;
using namespace Models;

class FloorModel : public Model
{
public:
	FloorModel();
	~FloorModel();
	void Create(double height);
	virtual void Draw(const glm::mat4& projection_matrix,
		const glm::mat4& view_matrix)
		override final;
	virtual void Update() override final;

private:
	time_t timer;
	std::vector<VertexFormat> vertices;
	glm::vec3 translate;
};