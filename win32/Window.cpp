#include "stdafx.h"
#include "Window.h"

namespace Glorious
{
	LRESULT Window::WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}

	Window::Window(HINSTANCE current_instance, int show_mode, LPCWSTR title, int width, int height)
	{
		//
		WNDCLASSEXW window_class{};
		window_class.cbSize = sizeof(WNDCLASSEXW);
		window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
		window_class.hInstance = current_instance;
		window_class.lpfnWndProc = &Window::WindowProcedure;
		window_class.lpszClassName = L"PashaWindow";
		window_class.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));	// without background, resizing window will leave black background.
		RegisterClassExW(&window_class);

		// window area is not the same as client area
		RECT rect{};
		rect.left = 0;
		rect.top = 0;
		rect.right = width;
		rect.bottom = height;
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		width = rect.right - rect.left;
		height = rect.bottom - rect.top;

		// place window in the center of screen
		POINT cursor;
		GetCursorPos(&cursor);
		HMONITOR monitor = MonitorFromPoint(cursor, MONITOR_DEFAULTTONEAREST);
		MONITORINFO info = { sizeof(MONITORINFO) };
		GetMonitorInfoW(monitor, &info);

		const int x = (info.rcWork.left + info.rcWork.right - width) / 2;
		const int y = (info.rcWork.top + info.rcWork.bottom - height) / 2;

		//
		m_Handle = CreateWindowExW
		(
			0, L"PashaWindow", title, WS_OVERLAPPEDWINDOW,
			x, y, width, height,
			nullptr, nullptr, current_instance, nullptr
		);


		if (!m_Handle)
		{
			throw std::exception{ "Create Window Failed." };
		}
		else
		{
			ShowWindow(m_Handle, show_mode);
			UpdateWindow(m_Handle);
		}
	}

	HWND Window::GetHandle() const
	{
		return m_Handle;
	}

}