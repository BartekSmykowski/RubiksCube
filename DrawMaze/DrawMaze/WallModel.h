#pragma once

#include <BasicEngine\Rendering\Models\Model.h>
#include "..\MazeModel\Enums.h"


using namespace BasicEngine::Rendering;
using namespace Models;
using namespace MazeModel;

namespace DrawMaze {
	class WallModel : public Model
	{
	public:
		WallModel();
		~WallModel();

		void Create(glm::vec3 wspolzedne, colorT type);
		//glm::vec4 przypisz_kolor(colorT type);
		virtual void Draw(const glm::mat4& projection_matrix,
			const glm::mat4& view_matrix)
			override final;
		virtual void Update() override final;

	private:
		std::vector<VertexFormat> vertices;
		char type;
		glm::vec3 wspolzedne;
	};
}