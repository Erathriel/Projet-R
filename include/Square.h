#ifndef INCLUDE_SQUARE_H
#define INCLUDE_SQUARE_H

#include <gf/Direction.h>
#include <gf/Entity.h>
#include <gf/Font.h>
#include <gf/Rect.h>
#include <gf/Message.h>




class Square : public gf::Entity
{

public:
	static constexpr float Velocity = 75.0f;
	enum class Move{
		Up,
		Stop,
		Down,
		Right,
		Left,
	};

	Square(gf::Vector2f position, float size, gf::Color4f color);

	void move(Move m){
		m_move = m;
	}

	virtual void update(gf::Time time) override;
	virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;
	
private:
	gf::Vector2f m_position;
	float m_size;
	gf::Color4f m_color;
	Move m_move;
};

#endif // LOCAL_SQUARE_H