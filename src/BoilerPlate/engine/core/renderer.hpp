#pragma once

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader_utilities.hpp"
#include "texture_manager.hpp"
#include"../../game/objects/block.hpp"
#include "game_object.hpp"

const int MAX_TEXTURES = 16;



const GLuint SIZE_OF_VERTICES = 144;
const GLuint SIZE_OF_INDICES = 24;

namespace engine
{

	class renderer
	{
	public:

		renderer();
		~renderer();
		void load_vertices(engine::core::game_object* pGameObject);
		void initialize_program_id();
		void render(engine::core::game_object* pGameObject);
		void render_objects();
		void toggle_polygon_mode();
		void generate_buffers();
		void update_window_size(int pWidth, int pHeight);
		void add_object(engine::core::game_object* pGameObject);

	private:

		bool mPolygonMode;
		int mWidth;
		int mHeight;
		int mObjectIndex;

		GLuint mVertexArrayObject;
		GLuint mVertexBufferObject;
		GLuint mElementsBufferObject;
		GLuint mProgramID;

		shader_utilities mShaderUtilities;
		std::vector<engine::core::game_object*> mObjects;
		//engine::core::game_object* mObjects[20];
		texture mTextures[MAX_TEXTURES];

		//float vertices[];

	};

}

#endif