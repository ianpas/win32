#include "stdafx.h"
#include "Application.h"
#include "Window.h"

namespace Glorious
{
	Application::Application(HINSTANCE current_instance, int show_mode, LPCWSTR title, int width, int height)
	{
		m_Window = std::make_unique<Window>(current_instance, show_mode, title, width, height);
	}

	void Application::Run(std::function<void()> run) const
	{
		MSG msg{};

		while (msg.message != WM_QUIT)
		{
			if (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				// it's not necessary to translate keyboard message
				//TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
			else
			{
				run();
			}
		}
	}

	HWND Application::GetHandle() const
	{
		return m_Window->GetHandle();
	}
}
