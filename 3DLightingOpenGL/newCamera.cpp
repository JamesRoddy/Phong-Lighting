#include "newCamera.h"


camera::camera(glm::vec3 initialDirection,glm::vec3 globalUp,glm::vec3 intialPosition,float initialYaw,float initialPitch, float initialZoom, float moveSpeed,float sensetivity){


	// initialsiing camera attributes for things such as rotation eulers and updating the associated vectors such as the looking direction of the camera  
	m_initialLookingDirection = initialDirection;
	m_globalUp = globalUp;
	m_position = intialPosition;
	m_yaw = initialYaw;
	m_pitch = initialPitch;
	m_zoom = initialZoom;
	m_sensetivity = sensetivity;
	m_moveSpeed = moveSpeed;
	updateVectors();

}

void camera::processKeyboard(cameraInput inputDirection, float dt) {


	if (inputDirection == FORWARD) {
		m_position += m_initialLookingDirection * (m_moveSpeed * dt); // use the normalized direction vector of the camera to control where it moves 


	}
	else if (inputDirection == BACKWARD) {
		m_position -= m_initialLookingDirection * (m_moveSpeed * dt);


	}
	
	if (inputDirection == RIGHT) {
		m_position += m_right * (m_moveSpeed * dt); // take the resulting cross product of the camera direction vector with the global up vector and use it for the starfing movement of the camera 


	}
	else if (inputDirection == LEFT) {
		m_position -= m_right * (m_moveSpeed * dt);


	}

	

}


glm::mat4 camera::getViewMatrix() {


	return glm::lookAt(m_position, m_position + m_initialLookingDirection, m_globalUp); // create the veiew matrix that consists of the cameras three basis vectors that are dervied from the cameras current target and its position 
	// we then inveret these using the tranpose and we also negate the cameras postion meaning when transformed through the view matrix all objects will be skewed as if they are being looked at by the camera 

}

void camera::setPreviousMousePos(glm::vec2 previousMouse) {
	previousMousePos = previousMouse; // used to keep track of the previous mouse position to keep track of camera movement 
}
glm::vec2 camera::getPreviousMousePos() {
	return previousMousePos;
}
float camera::getFovy() {
	return m_zoom;
}
glm::vec3 camera:: getPos() {
	return m_position;
}
void camera::processMouseInput(float offsetX, float offsetY, bool constrainPitch) {




	offsetX *= m_sensetivity; 
	offsetY *= m_sensetivity;

	m_yaw += offsetX;
	m_pitch += offsetY; 

	// yaw and pitch are used to represent the current rotation angles of the camera 
	// with pitch refering to looking up and down and yaw left to right 

	
	if (constrainPitch) {

		if (m_pitch < -89.0f) {
			m_pitch = -89.0f;
		}
		else if (m_pitch > 89.0f) {
			m_pitch = 89.0f;
		}


	} // constariing the pitch to ensure that the camera does not flip 


	updateVectors(); // update direction vectors according to new yaw and pitch values 
	



}

void camera::processScrollWheel(float offsetY) {

	m_zoom -= offsetY;

	if (m_zoom <1.0f) {
		m_zoom = 1.0f;
	}
	else if (m_zoom > 45.0f) {
		m_zoom = 45.0f;
	}



}

glm::vec3 camera::getDir() {
	return m_initialLookingDirection;
}




void camera::updateVectors() {

	
	glm::vec3 currentDirection = glm::vec3{
		cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch)),
		sin(glm::radians(m_pitch)),
		sin(glm::radians(m_yaw)) * cos(glm::radians( m_pitch))

	}; // get the current direction vector for the cameras movement 
	
	m_initialLookingDirection =  glm::normalize(currentDirection);

	m_right = glm::normalize(glm::cross(m_initialLookingDirection, m_globalUp)); // establish camera basis vectors 
	m_up = glm::normalize(glm::cross(m_right, m_initialLookingDirection));





}