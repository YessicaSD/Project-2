#include "j1App.h"
#include "Audio.h"
#include "Render.h"
#include "GUI.h"
#include "UIButton.h"
#include "p2Log.h"

UIButton::~UIButton()
{
}

bool UIButton::UIBlit()
{
	iPoint screen_pos = GetScreenPos();
	if (clipping && parent)
		App->render->Blit(App->gui->GetAtlas(), screen_pos.x, screen_pos.y, &rect_sprite, 0.0F, 0.0, INT_MAX, INT_MAX, &parent->GetScreenRect());
	else
		App->render->Blit(App->gui->GetAtlas(), screen_pos.x, screen_pos.y, &rect_sprite, 0.0F, 0.0, INT_MAX, INT_MAX);
	return true;
}

void UIButton::OnMouseClick()
{
	rect_sprite = anim[2];
	App->audio->PlayFx(sound);
	clicked = true;
}

void UIButton::OnMouseHover()
{
	rect_sprite = anim[1];
}

void UIButton::OnMouseRelease()
{
	rect_sprite = anim[1];
	clicked = false;
}

void UIButton::OnMouseExit()
{
	rect_sprite = anim[0];
}

bool UIButton::IsOnClick()
{
	return clicked;
}

void UIButton::SetLocked(bool value)
{
	interactable = value;
	rect_sprite = anim[interactable ? 0 : 3];
}

bool UIButton::CleanUp()
{
	delete[] anim;
	parent = nullptr;
	return true;
}

UIButton::UIButton(iPoint position, ButtonType type, bool is_interactable)
{
	interactable = is_interactable;
	rect_box = { position.x, position.y, 62,50 };

	anim = new SDL_Rect[4];
	switch (type) {
	case B_GI:
		anim[0] = { 0,0,62,50 };
		anim[1] = { 62,0,62,50 };
		anim[2] = { 0,50,62,50 };
		anim[3] = { 0,0,62,50 };
		break;

	case B_NAVY_SEAL:
		anim[0] = { 124,0,62,50 };
		anim[1] = { 188,0,62,50 };
		anim[2] = { 124,50,62,50 };
		anim[3] = { 0,0,62,50 };
		break;

	case B_SNIPER:
		anim[0] = { 250,0,62,50 };
		anim[1] = { 313,0,62,50 };
		anim[2] = { 250,50,62,50 };
		anim[3] = { 0,0,62,50 };
		break;

	default:
		LOG("Unit Type Incorrect!");
		break;
	}
	
	this->type = type;
	rect_sprite = anim[interactable ? 0 : 3];

	sound = App->audio->LoadFx("fx_button.wav");
}