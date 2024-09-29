#ifndef UICORE_H
#define UICORE_H

#ifdef _WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
namespace Syncio
{
    namespace UICore
    {

        // Predefined colors (using RGB format)
        struct Color
        {
            int r, g, b;
        };

        const Color RED = {255, 0, 0};
        const Color GREEN = {0, 255, 0};
        const Color BLUE = {0, 0, 255};
        const Color BLACK = {0, 0, 0};
        const Color WHITE = {255, 255, 255};
        const Color YELLOW = {255, 255, 0};
        const Color CYAN = {0, 255, 255};
        const Color MAGENTA = {255, 0, 255};

        // UIWindow class inside the Syncio::UICore namespace
        class UIWindow
        {
        public:
            UIWindow(const char *title, int width, int height);
            ~UIWindow();
            void mainloop();
            void render(const Color &color);
            void cleanup();

        private:
            int width;
            int height;
            bool isRunning;

#ifdef _WIN32
            HWND hwnd;
            HDC hdc;
            static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#else
            Display *display;
            Window window;
            GC gc;
#endif
        };

        // UIWindow C++ Constructor
        UIWindow::UIWindow(const char *title, int width, int height) : width(width), height(height), isRunning(true)
        {
#ifdef _WIN32
            WNDCLASS wc = {0};
            wc.lpfnWndProc = UIWindow::WindowProc;
            wc.hInstance = GetModuleHandle(NULL);
            wc.lpszClassName = "SyncioUICoreWindowClass";

            RegisterClass(&wc);

            hwnd = CreateWindowEx(
                0, "SyncioUICoreWindowClass", title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                NULL, NULL, GetModuleHandle(NULL), NULL);

            if (!hwnd)
            {
                printf("Failed to create window.\n");
                exit(1);
            }
            hdc = GetDC(hwnd);
#else
            display = XOpenDisplay(NULL);
            if (display == NULL)
            {
                printf("Failed to open X display.\n");
                exit(1);
            }

            int screen = DefaultScreen(display);
            window = XCreateSimpleWindow(
                display, RootWindow(display, screen),
                10, 10, width, height, 1,
                BlackPixel(display, screen), WhitePixel(display, screen));

            XSelectInput(display, window, ExposureMask | KeyPressMask);
            XMapWindow(display, window);

            gc = XCreateGC(display, window, 0, NULL);
#endif
        }

        // Windows-specific message handler
#ifdef _WIN32
        LRESULT CALLBACK UIWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
        {
            if (uMsg == WM_DESTROY)
            {
                PostQuitMessage(0);
            }
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
#endif

        // UIWindow Destructor
        UIWindow::~UIWindow()
        {
            cleanup();
        }

        // Render function
        void UIWindow::render(const Color &color)
        {
#ifdef _WIN32
            HBRUSH brush = CreateSolidBrush(RGB(color.r, color.g, color.b));
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, brush);
            DeleteObject(brush);
#else
            XSetForeground(display, gc, (color.r << 16) | (color.g << 8) | color.b);
            XFillRectangle(display, window, gc, 0, 0, width, height);
#endif
        }

        // Main event loop
        void UIWindow::mainloop()
        {
#ifdef _WIN32
            MSG msg;
            while (isRunning)
            {
                while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                {
                    if (msg.message == WM_QUIT)
                    {
                        isRunning = false;
                    }
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
                render(RED); // Example rendering with a predefined color
                Sleep(16);
            }
#else
            XEvent event;
            while (isRunning)
            {
                XNextEvent(display, &event);
                if (event.type == Expose)
                {
                    render(RED); // Example rendering with a predefined color
                }
                else if (event.type == KeyPress)
                {
                    isRunning = false;
                }
                usleep(16000);
            }
#endif
        }

        // Cleanup resources
        void UIWindow::cleanup()
        {
#ifdef _WIN32
            ReleaseDC(hwnd, hdc);
            DestroyWindow(hwnd);
            PostQuitMessage(0);
#else
            XDestroyWindow(display, window);
            XCloseDisplay(display);
#endif
        }

    }
}
#else
#error "UiCore is not suppoted"
#endif // __cplusplus

#endif // UICORE_H
