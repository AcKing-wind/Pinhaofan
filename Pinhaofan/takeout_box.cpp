#include"takeout_box.h"

#include"resources_manager.h"
#include"cursor_mgr.h"

void TakeoutBox::on_cursor_up()
{
	if (meal == Meal::TakeoutBox)
	{
		switch (CursorMgr::instance()->get_picked())
		{
		case Meal::BraisedChicken_Box:
			meal = Meal::BraisedChicken_Cool;
			CursorMgr::instance()->set_picked(Meal::None);
			break;
		case Meal::MeatBall_Box:
			meal = Meal::MeatBall_Cool;
			CursorMgr::instance()->set_picked(Meal::None);
			break;
		case Meal::RedCookedPork_Box:
			meal = Meal::RedCookedPork_Cool;
			CursorMgr::instance()->set_picked(Meal::None);
			break;
		}
	}
	else if (meal == Meal::None && can_place(CursorMgr::instance()->get_picked()))
	{
		meal = CursorMgr::instance()->get_picked();
		CursorMgr::instance()->set_picked(Meal::None);
	}
}

void TakeoutBox::on_cursor_down()
{
	if (CursorMgr::instance()->get_picked() == Meal::None)
	{
		CursorMgr::instance()->set_picked(meal);
		meal = Meal::None;
	}
}

void TakeoutBox::on_render(SDL_Renderer* renderer)
{
	SDL_Texture* texture = nullptr;
	switch (meal)
	{
	case Meal::None:				break;
	case Meal::BraisedChicken_Hot:	texture = ResMgr::instance()->find_texture("bc_hot");	break;
	case Meal::BraisedChicken_Cool: texture = ResMgr::instance()->find_texture("bc_cold");	break;
	case Meal::MeatBall_Hot:		texture = ResMgr::instance()->find_texture("mb_hot");	break;
	case Meal::MeatBall_Cool:		texture = ResMgr::instance()->find_texture("mb_cold");	break;
	case Meal::RedCookedPork_Hot:	texture = ResMgr::instance()->find_texture("rcp_hot");	break;
	case Meal::RedCookedPork_Cool:	texture = ResMgr::instance()->find_texture("rcp_cold");	break;
	case Meal::TakeoutBox:			texture = ResMgr::instance()->find_texture("tb");		break;
	}
	if (texture)
	{
		SDL_Rect rect_texture = { rect.x ,rect.y ,0 ,0  };
		SDL_QueryTexture(texture, nullptr, nullptr, &rect_texture.w, &rect_texture.h);
		SDL_RenderCopy(renderer, texture, nullptr, &rect_texture);
	}
}

bool TakeoutBox::can_place(Meal target)
{
	return target == Meal::BraisedChicken_Hot || target == Meal::BraisedChicken_Cool
		|| target == Meal::MeatBall_Hot       || target == Meal::MeatBall_Cool
		|| target == Meal::RedCookedPork_Hot  || target == Meal::RedCookedPork_Cool
		|| target == Meal::TakeoutBox;
}