#include "game.hpp"

namespace game
{
	game::game()
	{
		reset_input_limiter();
		mBall = new entities::ball();
		mBlock = new entities::block();

		mRenderer.add_object(mBlock);
	
		mRenderer.add_object(mBall);
	}

	game::~game()
	{
		
	}

	void game::execute()
	{
		mRenderer.initialize_program_id();

		mRenderer.generate_buffers();

		
		
	}

	void game::update()
	{
		update_input();

		if (mInputLimiter != 0)
		{
			mInputLimiter--;
		}

	}

	void game::render()
	{

		mRenderer.render_objects();
	}

	void game::update_input()
	{
		if (mInputManager.T_IsPressed() && mInputLimiter == 0)
		{
			mRenderer.toggle_polygon_mode();

			reset_input_limiter();
		}

	}

	void game::reset_input_limiter()
	{
		mInputLimiter = 10;
	}

	void game::update_window_size(int pWidth, int pHeight)
	{
		mRenderer.update_window_size(pWidth, pHeight);
	}

}