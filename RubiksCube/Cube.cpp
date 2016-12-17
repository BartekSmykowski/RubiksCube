#include "Cube.h"
#include <vector>

using namespace RubiksCube;

Cube::Cube() {

	this->translation = glm::vec3(0, 0, 0);
	bricksContainer = new BricksContainer();
	this->size = 3;
	bricksContainer->fill(3);
};

Cube::Cube(int size) {
	this->translation = glm::vec3(0, 0, 0);
	bricksContainer = new BricksContainer(size);
	this->size = size;
	bricksContainer->fill(size);
}

RubiksCube::Cube::Cube(int size, glm::vec3 translation)
{
	this->translation = translation;
	bricksContainer = new BricksContainer(size, translation);
	this->size = size;
	bricksContainer->fill(size);
}

//zmienia wspó³¿edne klocków w kostce jednej œciany wall po obrocie w kierunku direction
//czyli zgodnie albo przeciwnie do ruchu wskazówek zegara
void Cube::rotate_wall(orientation_type wall, rotate_direction_t direction) {
	if (!this->bricksContainer->IsRotating()) {
		//obrócenie to transformacja p³aszcyzny wystarczy zamieniæ odpowiednie osie z innymi, albo je odwróciæ i przesun¹æ
		//na te osie mo¿na wyprowadziæ funkcje, s¹ one wyznaczane w poni¿szym case w zale¿noœci od tego któr¹ œcianê chcemy obracaæ
		//i wktór¹ stronê
		int axx = 0, ayx = 0, azx = 0, bx = 0;       //wpó³czyniki przy x, y, z i wolny przy obliczaniu wspó³rzêdnej x
		int axy = 0, ayy = 0, azy = 0, by = 0;       //wpó³czyniki przy x, y, z i wolny przy obliczaniu wspó³rzêdnej y
		int axz = 0, ayz = 0, azz = 0, bz = 0;       //wpó³czyniki przy x, y, z i wolny przy obliczaniu wspó³rzêdnej z
		int iprim = 0;         //wpó³rzêdne x po obróceniu
		int jprim = 0;         //wpó³rzêdne y po obróceniu
		int kprim = 0;         //wpó³rzêdne z po obróceniu
		int iloops = 0, iloope = size;    //pêtla prechodz¹ca po wspó³rzêdnej x
		int jloops = 0, jloope = size;    //pêtla prechodz¹ca po wspó³rzêdnej y
		int kloops = 0, kloope = size;    //pêtla prechodz¹ca po wspó³rzêdnej z

		switch (wall) {                 //ustalanie wspó³czynników funkcji i pocz¹tków i koñców pêtli
		case DOWN:                      //w zale¿noœci od kierunku i p³aszczyzny obrotu
			azx = -1; bx = size - 1;
			ayy = 1;
			axz = 1;
			jloope = 1;
			break;
		case UP:
			azx = 1;
			ayy = 1;
			axz = -1; bz = size - 1;
			jloops = size - 1;
			break;
		case RIGHT:
			axx = 1;
			azy = -1; by = size - 1;
			ayz = 1;
			iloops = size - 1;
			break;
		case LEFT:
			axx = 1;
			azy = 1;
			ayz = -1; bz = size - 1;
			iloope = 1;
			break;
		case BACK:
			ayx = 1;
			axy = -1; by = size - 1;
			azz = 1;
			kloope = 1;
			break;
		case FRONT:
			ayx = -1; bx = size - 1;
			axy = 1;
			azz = 1;
			kloops = size - 1;
			break;
		}

		int strona = 0;     //jak jest przeciwnie do ruchu wskazówek zegara to obrót nastêpuhje 3 razy
		if (direction == CLOCK) {
			strona = 1;
		}
		else {
			strona = 3;
		}

		BricksContainer *bricks_tmp = new BricksContainer(*bricksContainer);
		//inicjacja tablicy pomocniczej do przechowywania aktualnej kostki
		//pomaga to w rozwi¹zywaniu przypadku w którym chcemy przepisaæ ju¿ przepisany klocek

		for (; strona > 0; strona--) {  //licznik ile razy obróciæ œcianê
			for (int i = iloops; i < iloope; i++) {          //pêtla w której dokonuje siê w³aœciwy obrót
				for (int j = jloops; j < jloope; j++) {
					for (int k = kloops; k < kloope; k++) {
						iprim = axx*i + ayx*j + azx*k + bx;
						jprim = axy*i + ayy*j + azy*k + by;
						kprim = axz*i + ayz*j + azz*k + bz;
						bricks_tmp->setBrick(glm::vec3(i, j, k), bricksContainer->getBrick(glm::vec3(iprim, jprim, kprim)));
						if (bricks_tmp->getBrick(glm::vec3(i, j, k)) != nullptr) {
							bricks_tmp->getBrick(glm::vec3(i, j, k))->rotate(wall, direction);
							bricks_tmp->getBrick(glm::vec3(i, j, k))->StartAnimate(wall, direction);
						}
					}
				}
			}
			bricksContainer = bricks_tmp;
		}
	}

};

void Cube::KeyEventCallback(unsigned char key, int x, int y) {
	switch (key) {
	case 'u':
		rotate_wall(UP, CLOCK);
		break;
	}
}

//zwraca klocek o podanych wspó³¿êdych z kostki
Brick *Cube::get_brick(glm::vec3 w) {
	return bricksContainer->getBrick(w);
}

//zwraca kolor nankleki klocka [x][y][z] zwróconej w kierunku wall
Color_t Cube::get_brick_color(glm::vec3 w, orientation_type which) {
	if (bricksContainer->getBrick(w) != nullptr) {
		return bricksContainer->getBrick(w)->get_color(which);
	}
	return N;
}

void RubiksCube::Cube::setRotation(glm::vec3 rotation)
{
	animator.setRotationAngle(rotation);
}

glm::vec3 RubiksCube::Cube::getRotation()
{
	return animator.GetRotationAngle();
}

int RubiksCube::Cube::getSize()
{
	return size;
}

Cube::~Cube() {
	bricksContainer->~BricksContainer();
}
