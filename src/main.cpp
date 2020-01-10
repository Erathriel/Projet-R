#include <gf/Action.h>
#include <gf/Clock.h>
#include <gf/Color.h>
#include <gf/EntityContainer.h>
#include <gf/Event.h>
#include <gf/RenderWindow.h>
#include <gf/ViewContainer.h>
#include <gf/Views.h>
#include <gf/Window.h>

#include "../include/Square.h"
#include "../include/Ground.h"

int main() {
	static constexpr gf::Vector2u ScreenSize(1024, 576);
	static constexpr gf::Vector2f ViewSize(Ground::Width, Ground::Height);
	static constexpr gf::Vector2f ViewCenter(0.0f, 0.0f);
	//static constexpr gf::Vector2f ViewSize(400.0f,400.0f); // dummy values (echelle)
	//static constexpr gf::Vector2f ViewCenter(0.0f, 0.0f); // dummy values

	// initialisation

	gf::Window window("RPG", ScreenSize);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	gf::RenderWindow renderer(window);

	// Views

	gf::ViewContainer views;

	gf::ExtendView mainView(ViewCenter,ViewSize);
	views.addView(mainView);

	// HUD
	gf::ScreenView hudView;
	views.addView(hudView);

	views.setInitialScreenSize(ScreenSize);

	//actions

	gf::ActionContainer actions;

	gf::Action closeWindowAction("Close window");
	closeWindowAction.addCloseControl();
	closeWindowAction.addKeycodeKeyControl(gf::Keycode::Escape);
	actions.addAction(closeWindowAction);

	gf::Action fullscreenAction("Fullscreen");
	fullscreenAction.addKeycodeKeyControl(gf::Keycode::F);
	actions.addAction(fullscreenAction);

	gf::Action leftAction("Left");
	leftAction.addScancodeKeyControl(gf::Scancode::A);
	leftAction.addScancodeKeyControl(gf::Scancode::Left);
	leftAction.setContinuous();
	actions.addAction(leftAction);

	gf::Action rightAction("Right");
	rightAction.addScancodeKeyControl(gf::Scancode::D);
	rightAction.addScancodeKeyControl(gf::Scancode::Right);
	rightAction.setContinuous();
	actions.addAction(rightAction);

	gf::Action upAction("Up");
	upAction.addScancodeKeyControl(gf::Scancode::W);
	upAction.addScancodeKeyControl(gf::Scancode::Up);
	upAction.setContinuous();
	actions.addAction(upAction);

	gf::Action downAction("Down");
	downAction.addScancodeKeyControl(gf::Scancode::S);
	downAction.addScancodeKeyControl(gf::Scancode::Down);
	downAction.setContinuous();
	actions.addAction(downAction);

	//Entities

	gf::EntityContainer mainEntities;

	// map
	Ground map;
	mainEntities.addEntity(map);

	// square
	Square square(ViewCenter,40.0f,gf::Color::Blue);
	mainEntities.addEntity(square);

	// HUD
	gf::EntityContainer hudEntities;
	//add entities to hudEntities

	// background of the window
	renderer.clear(gf::Color::Black);

	// the clock
	gf::Clock clock;

	// game loop
	while (window.isOpen()) {

		// input
		gf::Event event;

		// Event on window
		while (window.pollEvent(event)) {
			actions.processEvent(event);
			views.processEvent(event);
		}
		if (closeWindowAction.isActive())
		{
			window.close();
		}
		if (fullscreenAction.isActive()) {
			window.toggleFullscreen();
		}
		// Move of the square
		if (rightAction.isActive()) {
		// do something
			square.move(Square::Move::Right);
		} else if (leftAction.isActive()) {
		// do something
			square.move(Square::Move::Left);
		} else if (upAction.isActive()) {
		// do something
			square.move(Square::Move::Up);
		} else if (downAction.isActive()) {
		// do something
			square.move(Square::Move::Down);
		} else {
		// do something
			square.move(Square::Move::Stop);
		}

		// update

		gf::Time time = clock.restart();

		// update of entities
		mainEntities.update(time);
		hudEntities.update(time);

		// draw

		renderer.clear();
		renderer.setView(mainView);
		mainEntities.render(renderer);
		renderer.setView(hudView);
		hudEntities.render(renderer);
		renderer.display();
		actions.reset();

	}

	return 0;
}