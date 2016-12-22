#include "Engine.h"
using namespace BasicEngine;
using namespace Core;

Engine::Engine()
{

}

//You can set params for init
bool Engine::Init()
{
	WindowInfo window(std::string("Lab"),
		60, 20,
		1100, 700, true);
	ContextInfo context(4, 3, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);

	Init::Init_GLUT::init(window, context, frameBufferInfo);

	m_events_manager = new Managers::Events_Manager();
	//Init::Init_GLUT::setEventsListener(m_events_manager);

	m_scene_manager = new Managers::Scene_Manager();

	Init::Init_GLUT::setListener(m_scene_manager);

	//this was created in  scene manager constructor, now copy here
	m_shader_manager = new Managers::Shader_Manager();
	m_shader_manager->CreateProgram("colorShader",
		"..\\BasicEngine\\Shaders\\Vertex_Shader.glsl",
		"..\\BasicEngine\\Shaders\\Fragment_Shader.glsl");

	m_texture_loader = new TextureLoader();

	if (m_scene_manager && m_shader_manager)
	{
		m_models_manager = new Managers::Models_Manager();
		m_scene_manager->SetModelsManager(m_models_manager);
	}
	else
	{
		return false;
	}

	return true;
}

//Create the loop
void Engine::Run()
{
	Init::Init_GLUT::run();
}

Managers::Scene_Manager* Engine::GetScene_Manager() const
{
	return m_scene_manager;
}

Managers::Shader_Manager* Engine::GetShader_Manager() const
{
	return m_shader_manager;
}

Managers::Models_Manager* Engine::GetModels_Manager() const
{
	return m_models_manager;
}

Managers::Events_Manager* Engine::GetEvents_Manager() const
{
	return m_events_manager;
}

TextureLoader* Engine::GetTexture_Loader() const
{
	return m_texture_loader;
}

Engine::~Engine()
{
	if (m_scene_manager)
		delete m_scene_manager;

	if (m_shader_manager)
		delete m_shader_manager;

	if (m_models_manager)
		delete m_models_manager;

	if (m_texture_loader)
		delete m_texture_loader;

	if (m_events_manager)
		delete m_events_manager;
}