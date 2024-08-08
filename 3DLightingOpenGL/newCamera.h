#pragma 
#include "config.h"
enum cameraInput
{
	FORWARD,
	BACKWARD,
	RIGHT,
	LEFT
};



class camera {

public: 
	
	float m_sensetivity;


	camera(glm::vec3 intitalLookingDirection,glm::vec3 globalUp,glm::vec3 intitalPos,float initialYaw, float intitalPitch,float intialZoom, float moveSpeed, float sensetivity);
	void processScrollWheel(float offsetY);
	void processMouseInput(float offestX, float offestY, bool constrainPitch);
	void processKeyboard(cameraInput inputDir, float dt );
	glm::mat4 getViewMatrix();
	void setPreviousMousePos(glm::vec2 previousMouse);
	glm::vec3 getPos();
	glm::vec2 getPreviousMousePos();
	glm::vec3 getDir();
	float getFovy();
private:
	float m_yaw;
	float m_pitch;
	float m_moveSpeed;
	glm::vec3 m_globalUp;
	glm::vec3 m_initialLookingDirection;
	glm::vec3 m_position;
	glm::vec3 m_up;
	glm::vec3 m_right;
	glm::vec2 previousMousePos = { 0.0f,0.0f };

	float m_zoom;
	
	void updateVectors();



};