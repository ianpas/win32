#pragma once
#include "IWindow.h"

namespace Glorious
{
	class Window :public IWindow
	{
	private:
		HWND m_Handle;

	public:
		Window(HINSTANCE current_instance, int show_mode, LPCWSTR title, int width, int height);
		static LRESULT WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	public:
		HWND GetHandle() const override;

	};
}

