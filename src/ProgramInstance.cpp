#include "ProgramInstance.h"
#include "Renderer.h"

ProgramInstance::ProgramInstance()
{
	Initialize();
	Runtime();
}

ProgramInstance::~ProgramInstance() { }

void ProgramInstance::Initialize()
{
	_program.LinkShader(GL_VERTEX_SHADER, "../../shaders/vert_shader.vert");
	_program.LinkShader(GL_FRAGMENT_SHADER, "../../shaders/frag_shader.frag");
	_program.Initialize();

	_camera = Camera(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), &_program, 45.0f, 1.0f, 0.1f, 100.0f);
	_renderer = new Renderer(_program.GetProgram(), _context);
	_renderer->SetCamera(&_camera);

	_renderer->AddToRender(new Plane(_program, glm::vec3(0), glm::vec2(1.0f, 1.0f), 200, 200));

	DebugTools::SectionBreak();
}

void ProgramInstance::Runtime()
{
	glEnable(GL_DEPTH_TEST);

	while (!done)
	{
		HandleInput();
		FixedUpdate();
		Update();
		Render();
	}

	_context.CleanExit();
	SDL_Quit();
}

void ProgramInstance::HandleInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		SDL_Keycode key = event.key.keysym.sym;

		switch (event.type)
		{
			case SDL_QUIT:
				done = true;
				break;
			case SDL_KEYDOWN:
				if (key == SDLK_ESCAPE)
					done = true;
				break;

			case SDL_DROPFILE:
				std::vector<std::string> tmp;
				AssetManager::ReadFile(event.drop.file, tmp);
				t = new Trajectory(_program, _renderer, tmp);
				break;
		}

		_camera.HandleInput(event, _context);
	}
}

void ProgramInstance::FixedUpdate()
{

}

void ProgramInstance::Update()
{
	_camera.Update();
}

void ProgramInstance::Render()
{
	_renderer->PreRender();
	_renderer->Render();
	_renderer->PostRender();
}