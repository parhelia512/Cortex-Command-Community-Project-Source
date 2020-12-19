#ifndef _SDLSCREEN_
#define _SDLSCREEN_
#include "GUI/Interface.h"
#include <SDL2/SDL.h>

namespace RTE {
	class SDLScreen : public GUIScreen {
  public:
		/// <summary>
		/// Constructor method used to instantiate a ScreenInterface object.
		/// </summary>
		/// <param name="pBackBuffer"> Pointer to a SDL_Suface</param>
		SDLScreen(SDL_Surface *pBackBuffer);

		/// <summary>
		/// Destructor method used to clean up a SDLScreen object before deletion.
		/// </summary>
		~SDLScreen() override { Destroy(); }

		/// <summary>
		/// Destroys and resets this SDLScreen object
		/// </summary>
		void Destroy() override;

		/// <summary>
		/// Creeates a bitmap from a file
		/// </summary>
		/// <param name="Filename"> Path to Bitmap file </param>
		GUIBitmap *CreateBitmap(const std::string filename) override;

		/// <summary>
		/// Creates an empty bitmap
		/// </summary>
		/// <param name = "Height"> Height of the bitmap </param>
		/// <param name = "Width"> Width of the bitmap </param>
		GUIBitmap *CreateBitmap(int width, int height) override;

		/// <summary>
		/// Draws a bitmap onto the back buffer
		/// </summary>
		void DrawBitmap(GUIBitmap *pGUIBitmap, int x, int y, GUIRect *pRect);

		/// <summary>
		/// Gets the Surface representing the Screen
		/// </summary>
		GUIBitmap *GetBitmap();

		/// <summary>
		/// Converts an 8-bit palette index to a valid pixel format.
		/// </summary>
		/// <param name="color">
		/// Color value in any bit depth to be converted to the
		/// specified color depth
		/// </param>
		/// <param name="targetDepth">
		/// Optional parameter to specify the target color depth, defaults to
		/// the current video color depth
		/// </param>
		unsigned long ConvertColor(unsigned long color, int targetDepth= 0) override;

	private:
		SDLBitmap *m_pBackBitmap;
	};
} // namespace RTE
#endif