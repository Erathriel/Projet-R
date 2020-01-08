
#include <gf/Color.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/Unused.h>

#include "../include/Ground.h"

Ground::Ground(){}

void Ground::render(gf::RenderTarget& target, const gf::RenderStates& states){
	gf::RectangleShape shape({Width, Height});
	shape.setPosition({0.0f,0.0f});
	shape.setAnchor(gf::Anchor::Center);
	shape.setColor(gf::Color::Black);
	target.draw(shape, states);
}