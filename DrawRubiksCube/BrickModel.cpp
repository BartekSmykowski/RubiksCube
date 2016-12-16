//RCube.cpp
#include "BrickModel.h"

using namespace BasicEngine;
using namespace Rendering;
using namespace Models;

#define PI 3.14159265

BrickModel::BrickModel(){
	
}

BrickModel::~BrickModel(){
}

void BrickModel::Create(glm::vec3 wspolzedne, Brick *brick)
{
	GLuint vao;
	GLuint vbo;

	time(&timer);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	this->wspolzedne = wspolzedne;
	this->brick = brick;
	updateVertices();
	 
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);

	rotation_speed = glm::vec3(10, 10, 0);
	rotation = glm::vec3(0, 0, 0);
	summaryRotation = glm::vec3(0, 0, 0);
}

glm::vec4 BrickModel::przypisz_kolor(Color_t kolor) {
	glm::vec4 color_out = glm::vec4(0.0,0.0,0.0,1.0); 
	switch (kolor) {
	case Y:
		color_out = glm::vec4(1.0, 1.0, 0.0, 1.0);
		break;
	case W:
		color_out = glm::vec4(1.0, 1.0, 1.0, 1.0);
		break;
	case B:
		color_out = glm::vec4(0.0, 0.0, 1.0, 1.0);
		break;
	case R:
		color_out = glm::vec4(1.0, 0.0, 0.0, 1.0);
		break;
	case G:
		color_out = glm::vec4(0.0, 1.0, 0.0, 1.0);
		break;
	case O:
		color_out = glm::vec4(1.0, 0.5, 0.0, 1.0);
		break;
	case N:
		color_out = glm::vec4(0.5, 0.5, 0.5, 1.0);
		break;
	}
	return color_out;
}

void BrickModel::Update()
{
	brick->Animate();
	summaryRotation = brick->getAnimationAngle();
	arotation_sin = glm::vec3(summaryRotation.x * PI / 180, summaryRotation.y * PI / 180, summaryRotation.z * PI / 180);

	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(VertexFormat) * vertices.size(), &vertices[0]);
}

void BrickModel::updateBrick(Brick *brick) {
	this->brick = brick;
}

void BrickModel::updateVertices() {
	vertices.clear();

	glm::vec4 COLORS[6][4];
	for (int j = 0; j < 6; j++) {
		Color_t kolor = brick->get_color((orientation_type)j);
		for (int i = 0; i < 1; i++) {
			COLORS[(orientation_type)j][i] = przypisz_kolor(kolor);
		}
	}

	double i = wspolzedne.x;
	double j = wspolzedne.y;
	double k = wspolzedne.z;
	double i_t = i * brick->getLengthOfEdge();
	double j_t = j * brick->getLengthOfEdge();
	double k_t = k * brick->getLengthOfEdge();
	double mjeden = -1.0;
	double ulamek = -1.0 + brick->getLengthOfEdge();
	//vertices for the front face of the RCube
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, ulamek + k_t), COLORS[FRONT][0]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, ulamek + k_t), COLORS[FRONT][1]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), COLORS[FRONT][2]));

	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), COLORS[FRONT][2]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), COLORS[FRONT][3]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, ulamek + k_t), COLORS[FRONT][0]));

	//vertices for the right face of the RCube
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), COLORS[RIGHT][2]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), COLORS[RIGHT][3]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, mjeden + k_t), COLORS[RIGHT][0]));

	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), COLORS[RIGHT][2]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, mjeden + k_t), COLORS[RIGHT][0]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, ulamek + k_t), COLORS[RIGHT][1]));

	//vertices for the back face of the RCube
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, mjeden + k_t), COLORS[BACK][2]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, mjeden + k_t), COLORS[BACK][0]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), COLORS[BACK][3]));

	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, mjeden + k_t), COLORS[BACK][2]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), COLORS[BACK][3]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, mjeden + k_t), COLORS[BACK][1]));

	//vertices for the left face of the RCube
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), COLORS[LEFT][2]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, mjeden + k_t), COLORS[LEFT][3]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, mjeden + k_t), COLORS[LEFT][0]));

	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), COLORS[LEFT][2]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, mjeden + k_t), COLORS[LEFT][0]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, ulamek + k_t), COLORS[LEFT][1]));

	//vertices for the upper face of the RCube
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), COLORS[UP][1]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), COLORS[UP][2]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), COLORS[UP][0]));

	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), COLORS[UP][2]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), COLORS[UP][0]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, mjeden + k_t), COLORS[UP][3]));

	//vertices for the bottom face of the RCube
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, ulamek + k_t), COLORS[DOWN][1]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, ulamek + k_t), COLORS[DOWN][3]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, mjeden + k_t), COLORS[DOWN][0]));

	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, ulamek + k_t), COLORS[DOWN][3]));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, mjeden + k_t), COLORS[DOWN][0]));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, mjeden + k_t), COLORS[DOWN][2]));
}

void BrickModel::setRotation(glm::vec3 rotation)
{
	this->rotation = rotation;
	rotation_sin = glm::vec3(rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180);
}

void BrickModel::Draw(const glm::mat4& projection_matrix,
	const glm::mat4& view_matrix)
{

	glUseProgram(program);
	glUniform3f(glGetUniformLocation(program, "rotation"),
		rotation_sin.x,
		rotation_sin.y,
		rotation_sin.z);
	glUniform3f(glGetUniformLocation(program, "animationRotation"),
		arotation_sin.x,
		arotation_sin.y,
		arotation_sin.z);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1,
		false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);

}