#pragma once

#include <BasicEngine\Rendering\Models\Model.h>
#include "..\MazeModel\Player.h"


using namespace BasicEngine::Rendering;
using namespace Models;
using namespace MazeModel;

namespace DrawMaze {
	class PlayerModel : public Model
	{
	public:
		PlayerModel();
		~PlayerModel();

		void Create(Player *player);
		virtual void Draw(const glm::mat4& projection_matrix,
			const glm::mat4& view_matrix)
			override final;
		virtual void Update() override final;

	private:
		std::vector<VertexFormat> vertices;
		std::vector<unsigned int> indices;
		Player *player;
		glm::vec3 wspolzedne;
	};
}