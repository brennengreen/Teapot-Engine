#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Lights.h"
#include "Shader.h"
#include "Scene.h"
#include "Camera.h"
#include "Model.h"
#include "Cubemap.h"
#include "imgui.h"

#include <memory>


struct TeapotImguiConfigurations {
	ImVec4 clear_color = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	bool wireframe = false;
	bool hdr = false;
	float exposure = 1.0f;

	ImVec4 dir_light_pos = ImVec4(5.f, 700.f, 800.f, 0.0f);
	ImVec4 light_pos_1 = ImVec4(-1.0f,  1.0f, 1.0f, 0.0f);
	ImVec4 light_pos_2 = ImVec4(1.0f,  1.0f, 1.0f, 0.0f);
	ImVec4 light_pos_3 = ImVec4(-1.0f, -1.0f, 1.0f, 0.0f);
	ImVec4 light_pos_4 = ImVec4(1.0f, -1.0f, 1.0f, 0.0f);


	ImVec4 dir_light_amb = ImVec4(0.05f, 0.05f, 0.05f, 0.0f);
	ImVec4 light_amb_1 = ImVec4(1.f, 1.f, 1.f, 0.0f);
	ImVec4 light_amb_2 = ImVec4(1.f, 0.f, 0.f, 0.0f);
	ImVec4 light_amb_3 = ImVec4(0.f, 1.f, 0.f, 0.0f);
	ImVec4 light_amb_4 = ImVec4(0.f, 0.f, 1.f, 0.0f);

	float light_linear_1 = 0.00;
	float light_linear_2 = 1.0;
	float light_linear_3 = 1.0;
	float light_linear_4 = 1.0;

	float light_quadratic_1 = 0.00001;
	float light_quadratic_2 = 1.0;
	float light_quadratic_3 = 1.0;
	float light_quadratic_4 = 1.0;

	float model_scale = 0.0;
};

class Teapot {
public:
	Teapot();
	~Teapot();
	void Run();
	
	Camera Cam{};
	Scene mScene;
	TeapotImguiConfigurations RenderVars;

	void ProcessKeyboardState();
	void ProcessScrollState();
	void ProcessMousePosition();
private:
	void _init_pipelines();
	void _init_imgui();

	Shader _meshShader;

	// Shadow Stuff
	Shader _shadowShader;
	GLuint _FBO = 0;
	GLuint _depthCubemapFBO = 0;
	GLuint _depthTexture;
	GLuint _depthCubemap;

	// HDR Stuff
	Shader _hdrShader;
	GLuint _hdrFBO;
	GLuint _rboDepth;
	GLuint _colorBuffer;

	GLdouble _deltaTime {0};
	GLdouble _currentFrame {0};
	GLdouble _lastFrame {0};

	glm::vec2 _lastOffset {0, 0};

	void _shadow_pass();
	void _render_pass();
	void _imgui_pass();

private:
	unsigned int _load_cubemap(std::vector<std::string> faces);

};