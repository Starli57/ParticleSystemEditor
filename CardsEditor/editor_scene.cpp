
#include <GLFW/glfw3.h> 

#include "editor_scene.h"

namespace CardsEditor
{

	void EditorScene::Render() 
	{
		glBegin(GL_TRIANGLES);
		glVertex2f(-1, -1);
		glVertex2f( 0,  1);
		glVertex2f( 1, -1);
		glEnd();
	}
}