#ifndef RENDER_H
#define RENDER_H

#include <Box2D/Common/b2Draw.h>
#include <Box2D/Common/b2Math.h>

struct b2AABB;
struct GLFWwindow;

class DebugDraw : public b2Draw
{
public:
						DebugDraw() { m_window = nullptr; }

	void				DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void				DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void				DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
	void				DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
	void				DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
	void				DrawTransform(const b2Transform& xf);
	void				DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
	void				DrawString(int x, int y, const char* string, ...);
	void				DrawString(const b2Vec2& p, const char* string, ...);
	void				DrawAABB(b2AABB* aabb, const b2Color& color);

	GLFWwindow*			m_window;

};

#endif