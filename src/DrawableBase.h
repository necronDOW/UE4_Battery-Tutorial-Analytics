#ifndef drawablebase_h_defined
#define drawablebase_h_defined

#include <GL/glew.h>
#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glProgram.h"
#include "DebugTools.h"

class DrawableBase
{
	public:
		DrawableBase(glProgram& program, glm::vec3 position);
		~DrawableBase();
		void Initialize();
		virtual void Draw();
		void SetDraw(bool value);
		bool IsDrawn();
		void Transform(glm::vec3 transform);
		glm::vec2 GetPositionV2();
		glm::vec3 GetPositionV3();

	protected:
		DrawableBase() { }
		bool InitializeVertexBuffer();
		void InitializeVertexArrayObject();
		void ReInitialize();
		void CreateVertex(glm::vec3 position, glm::vec3 color = glm::vec3(1.0));
		void CreateElement(int vertA, int vertB);
		void CreateElement(int vertA, int vertB, int vertC);
		virtual void MainDraw();

		GLuint _vao, _ebo = 0, _vbo = 0;
		GLint _svlPosition, _svlVertColor, _svlTranslate, _svlOffset;

		glm::vec3 _position;
		glm::mat4 _transformations;
		std::vector<GLfloat> _vData;
		std::vector<GLuint> _eData;
		int _vCount = 0, _eCount = 0, _eMax = 0;
		bool _draw = true;

	private:
		void SetUniforms();

		bool _isReady = false;
};

#endif