#include "Application.h"

const sf::Time App::TimePerFrame(sf::seconds(1.0f / 60.0f));

App::App()
	: window(sf::VideoMode(Width, Height), "Building Wrecker", sf::Style::Close)
	, camera(sf::Vector2f(static_cast<float>(Width) / 2, static_cast<float>(Height) / 2),
			 sf::Vector2f(static_cast<float>(Width), static_cast<float>(Height)))
	, gravity(0.0f, 19.80665f)
	, world(gravity)
	, timeStep(1.0f / 60.0f)
	, velocityIterations(6)
	, positionIterations(2)
	, box(world, sf::Color::Blue, 100.0f, 150.0f)
	, box2(world, sf::Color::Red, 150.0f, 130.0f)
	, ground(world, 400.0f, 595.0f, static_cast<float>(Width), 10.0f)
	, leftWall(world, 5.0f, 295.0f, 10.0f, 590.0f)
	, rightWall(world, static_cast<float>(Width)-5.0f, 295.0f, 10.0f, 590.0f)
	, roof(world, 400.0f, 5.0f, static_cast<float>(Width) - 20.0f, 10.0f)
{
	window.setFramerateLimit(60);

	world.SetDebugDraw(&b2Debugger);

	box.setFixtureStats(0.9f, 0.4f, 0.2f);
	box2.setFixtureStats(0.9f, 0.4f, 0.2f);
	box.setWorld(world);
	box2.setWorld(world);
}

void App::run()
{
	sf::Clock clock;
	sf::Time timePassed = sf::Time::Zero;

	while (window.isOpen())
	{
		world.Step(timeStep, velocityIterations, positionIterations);

		handleInput();
		timePassed += clock.restart();
		while (timePassed > TimePerFrame)
		{
			timePassed -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}

void App::handleInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				box.setVelocity(160.0f);
				box2.setVelocity(11.0f);
			}
		}
	}
}

void App::update(sf::Time dt)
{
	b2Debugger.SetFlags(b2Draw::e_shapeBit);

	ground.update(dt);
	leftWall.update(dt);
	rightWall.update(dt);
	roof.update(dt);

	box.update(dt);
	box2.update(dt);
}

void App::render()
{
	window.clear(sf::Color::White);

	ground.render(window);
	leftWall.render(window);
	rightWall.render(window);
	roof.render(window);

	box.render(window);
	box2.render(window);

	window.display();
}