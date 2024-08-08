#include "App.h"

// the app clas sis wha ties everhting together and fits between the model and view 
// giving the model everhting it needs from the view and the view everhting it needs from the model 

app::app() { // main constcuor for the app will set up glfw by creating a window and making it the current context along with loading glad and openGL itself
	srand(time(0));
	setUpGLFW();
	newScene = new scene(window);
	render = new renderer(window,this->width,this->height);
	

}
app::~app() {
	
	
	glfwTerminate();
	
}


void app::setUpGLFW() {

	if (!glfwInit()) { // check that glfw is availabe 
		std::cout << "couldn't initialise GLFW" << std::endl;
		glfwTerminate();
		
	}
	width = 800; // defining the window widht and height attributes 
	height = 600;
	window = glfwCreateWindow(width, height, "LERP", NULL, NULL); // create the window making sure that it doesnt appear on the second monitor and that it wont launch in full screen mode
	glfwMakeContextCurrent(window); // set the current context to be the window we just initialised 
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // set the input mode for the mouse to be enabled and hide the cursor 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { // loading openGL through the glad libaray
		std::cout << "couldn't load openGL" << std::endl;
		glfwTerminate();
		


	}



}

void app::run() {
	// the run method is where the main game looop will be and will call methods associated with the wrapper classes for the view and model 
	// with the model class having the scene and the view having the render with the rendering having the main draw/ update loop wihthin its methods and the scene being reposbile for updating the behaviours assocatied with game objects 
	float lastFrame = 0.0f;
	float currentFrame = glfwGetTime();
	render->make_assets();
	render->configure_OpenGL(window,newScene);

	
		
	while (!glfwWindowShouldClose(window)) {
		  
		 lastFrame = currentFrame;
		 currentFrame = glfwGetTime();
		
		float dt = currentFrame - lastFrame;
		
		if (dt > 0.15f) {
			dt = 0.15f;
		}
		
		
		if (appHandleInput(dt)) {
			break;
		}
		
		newScene->update(dt);
		render->render(newScene);
        


	}
	render->deleteDrawables();

}

void app::cursorCallBack(GLFWwindow* window, double mouseX, double  mouseY) {



	



}

bool app::appHandleInput(float dt) {

	

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		return true;
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		newScene->cam.processKeyboard(FORWARD, dt);

	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		newScene->cam.processKeyboard(BACKWARD, dt);
	}
	if (glfwGetKey(window, GLFW_KEY_A )== GLFW_PRESS) {
		newScene->cam.processKeyboard(LEFT, dt);


	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		newScene->cam.processKeyboard(RIGHT, dt);

	}
	
	double mouseX, mouseY;
	glfwGetCursorPos(window, &mouseX, &mouseY);

	glfwPollEvents();
	float differnceX = mouseX - newScene->cam.getPreviousMousePos().x; 
	float differnceY =  newScene->cam.getPreviousMousePos().y - mouseY;
	
	
	newScene->cam.setPreviousMousePos(glm::vec2((float)mouseX, (float)mouseY));



	newScene->rotateCamera(differnceX,differnceY,true);
	

	return false;


	

}





