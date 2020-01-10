#ifndef INCLUDE_GROUND_H
#define INCLUDE_GROUND_H

#include <gf/Entity.h>
#include <gf/Vector.h>

class Ground : public gf::Entity
{
public:
	static constexpr float Width = 3072.0f;
	static constexpr float Height = 1728.0f;

	Ground();

	virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

private:
};

#endif // LOCAL_GROUND_H